#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

// Pin Definitions
#define RST_PIN 9
#define SS_PIN 10
#define BUZZER_PIN 8
#define GREEN_LED A0
#define RED_LED A1

// Initialize RFID and I2C LCD
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27 for 16x2 LCD

// RFID UID to Student Data Mapping
struct Student {
  String name;
  String rollNo;
  String branch;
};

const int totalStudents = 4; // Adjust based on the number of students
Student studentData[totalStudents] = {
  {"Nitish ", "2022/B/43", "Electronics"},  // Replace with actual data
  {"Kaleem", "2022/B/41", "Computer"},   // Replace with actual data
  {"AAkash", "2022/B/42", "ECE"} 
};

String authorizedUIDs[totalStudents] = {
  "33 0 C4 E4",  // Replace with your card's UID
  "13 91 D6 D9",   // Replace with your card's UID
  "E3 82 C2 E4"
};

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize PLX-DAQ Header for Excel
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Date,Time,Name,Roll No,Branch,Card UID,Status");

  // Initialize RFID
  SPI.begin();
  mfrc522.PCD_Init();

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("RFID Attendance");

  // Initialize Buzzer and LEDs
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  // Check if RFID card is present
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
    return;

  // Read UID of the card
  String cardUID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    cardUID += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1)
      cardUID += " ";
  }
  cardUID.toUpperCase();

  // Check if the UID is authorized
  int index = getStudentIndex(cardUID);
  if (index >= 0) {
    // Access Granted
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Granted");
    lcd.setCursor(0, 1);
    lcd.print(studentData[index].name);

    // Send Data to PLX-DAQ in Excel
    sendToExcel(studentData[index].name, studentData[index].rollNo, studentData[index].branch, cardUID, "Granted");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    buzz(2, 100);
  } else {
    // Access Denied
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
    sendToExcel("Unknown", "Unknown", "Unknown", cardUID, "Denied");
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    buzz(3, 200);
  }

  delay(2000);  // Wait before clearing LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan a card...");
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // Halt PICC
  mfrc522.PICC_HaltA();
}

// Function to Get Student Index by UID
int getStudentIndex(String uid) {
  for (int i = 0; i < totalStudents; i++) {
    if (uid == authorizedUIDs[i]) {
      return i;
    }
  }
  return -1;
}

// Function to Send Data to Excel
void sendToExcel(String name, String rollNo, String branch, String cardUID, String status) {
  Serial.print("DATA,DATE,TIME,");
  Serial.print(name);
  Serial.print(",");
  Serial.print(rollNo);
  Serial.print(",");
  Serial.print(branch);
  Serial.print(",");
  Serial.print(cardUID);
  Serial.print(",");
  Serial.println(status);
}

// Function to Control Buzzer
void buzz(int times, int duration) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(duration);
    digitalWrite(BUZZER_PIN, LOW);
    delay(duration);
  }
}
