# 🧠 RFID-Based Attendance System Using Excel & Arduino

## 📋 Project Overview
This project records student attendance using **RFID tags**, an **Arduino board**, and **PLX-DAQ Excel interface**.  
When a registered RFID card is scanned, the system logs **Date, Time, Name, Roll Number, Branch, Card UID, and Status** into an Excel file in real time.  

---

## ⚙️ Components Used
- Arduino UNO / ESP32  
- RFID Module (RC522)  
- RFID Cards / Tags  
- Jumper Wires  
- Breadboard  
- Excel with PLX-DAQ Add-in  

---

## 💻 Software Requirements
- Arduino IDE  
- PLX-DAQ Excel Add-in  
- Microsoft Excel  

---

## 🧩 Circuit Schematic
Below is the circuit schematic showing the connection between the Arduino and the RFID module:

![Circuit Schematic](Schematic.png)

---

## 📊 Output Result
The attendance data is automatically logged into Excel through PLX-DAQ.  
Each record contains Date, Time, Name, Roll No, Branch, Card UID, and Status.  

### Example Excel Output
| Date | Time | Name | Roll No | Branch | Card UID | Status |
|------|------|------|----------|---------|-----------|---------|
| 06-03-2025 | 7:01:29 PM | Aakash | 2022/B/42 | ECE | E3 82 C2 E4 | Present |
| 06-03-2025 | 7:01:31 PM | Unknown | Unknown | — | 35 C2 33 2 | Not Register |
| 06-03-2025 | 7:01:35 PM | Aakash | 2022/B/42 | ECE | E3 82 C2 E4 | Present |

### Screenshot Output
![Excel Output](rfid_result.png)

---

## 📂 File Structure
```
RFID_Attendance/
│
├── RFID_Excel.ino          # Arduino code
├── Schematic.png           # Circuit diagram
├── rfid_result.png         # Excel output screenshot
└── README.md               # Documentation file
```

---

## 🧾 Working Principle
1. Each RFID card has a unique UID.  
2. When the card is scanned, the UID is read by the RFID module.  
3. The Arduino compares the UID with the stored list.  
4. If matched, PLX-DAQ logs “Present” with Date & Time in Excel.  
5. If not matched, it logs “Not Register.”  

---

## 🏁 Conclusion
This system provides a **low-cost, real-time attendance solution** suitable for schools and colleges.  
It eliminates manual entry errors and ensures accurate tracking.
