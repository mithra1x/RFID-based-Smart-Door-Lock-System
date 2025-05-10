# 🔐 RFID-Based Smart Door Lock System

This project is a **secure door locking system** built using an **RFID reader (RC522)**, **Arduino UNO**, **Servo motor**, and **16x2 I2C LCD display**. The system authenticates users via RFID tags and opens the door for authorized cards only.

---

## 🎯 Features

- 🔑 RFID card-based access control  
- 🚪 Servo-controlled door lock/unlock mechanism  
- 📟 LCD display for live feedback  
- 🔒 Unauthorized cards are denied access  
- ⏲ Auto-relock after 5 seconds  

---

## 🛠 Hardware Requirements

| Component            | Quantity |
|----------------------|----------|
| Arduino UNO          | 1        |
| RFID-RC522 Module     | 1        |
| Servo Motor (SG90)    | 1        |
| 16x2 I2C LCD Display  | 1        |
| RFID Tag/Card         | 1+       |
| Breadboard + Wires    | As needed |

---

## 🔌 Wiring Connections

| RFID RC522 | Arduino UNO |
|------------|-------------|
| SDA        | D10         |
| SCK        | D13         |
| MOSI       | D11         |
| MISO       | D12         |
| RST        | D9          |
| GND        | GND         |
| 3.3V       | 3.3V        |

| LCD (I2C) | Arduino UNO |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

| Servo Motor | Arduino UNO |
|-------------|-------------|
| Signal      | D3          |
| VCC         | 5V          |
| GND         | GND         |

---

