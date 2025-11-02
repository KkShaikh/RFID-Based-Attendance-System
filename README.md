# 📟 RFID Based Attendance System with Arduino

This project demonstrates how to **interface the RFID RC522 module with Arduino UNO** to record attendance automatically. When a registered RFID tag is scanned, the system logs the **student’s ID, name, date, and time** — which can later be exported to **Excel** for attendance monitoring.

---

## 🧰 Components Required
- Arduino UNO  
- RFID Module (RC522)  
- RFID Tags/Cards  
- Jumper Wires  
- Breadboard (optional)  
- USB Cable for Arduino  

---

## 🔌 Circuit Diagram

![Circuit](Schematic.png)

**Connections Between RFID RC522 and Arduino UNO:**

| RFID Pin | Arduino Pin |
|-----------|--------------|
| VCC       | 3.3V         |
| GND       | GND          |
| RST       | 9            |
| MISO      | 12           |
| MOSI      | 11           |
| SCK       | 13           |
| SDA (SS)  | 10           |

---

## 💻 Code Overview

The main Arduino file is [`RFID_Excel.ino`](RFID_Excel.ino).  
This code performs the following:

1. Initializes the **RFID RC522** module.  
2. Reads unique RFID tag IDs when a tag/card is placed near the reader.  
3. Sends the data over **Serial communication** to the connected PC.  
4. The data can be captured into an **Excel sheet** or any logging software.  

---

## ⚙️ How to Run

1. Open `RFID_Excel.ino` in the **Arduino IDE**.  
2. Select the **Arduino UNO** board and correct **COM port**.  
3. Upload the code to the Arduino.  
4. Open the **Serial Monitor** (9600 baud rate).  
5. Place an RFID card near the reader to see its **unique ID** appear.  
6. You can log the IDs in **Excel** using the “Data → From Serial Port” option or via a Python/C# script.  

---

## 📄 Output Example

| Tag ID | Name | Date | Time |
|--------|------|------|------|
| 53 A1 6F 12 | Shubh | 2025-11-02 | 10:30 AM |
| 48 B2 7E 9C | Ritesh | 2025-11-02 | 10:32 AM |

---

## 🔮 Future Enhancements
- Integrate with **database or Google Sheets** for real-time updates.  
- Add **LCD display** for visual feedback.  
- Implement **buzzer and LED indicators** for authentication status.  
- Expand to a **Wi-Fi-based attendance system** using NodeMCU/ESP32.  

---


## 📝 License
This project is licensed under the **MIT License** — free to use and modify for educational purposes.
