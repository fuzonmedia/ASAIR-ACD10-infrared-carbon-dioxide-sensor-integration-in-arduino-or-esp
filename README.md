# ASAIR ACD10 CO₂ + DHT20 Sensor Integration with LCD (Arduino/ESP)

ACD10 - https://robu.in/product/co2-sensor-model-acd10/

This project demonstrates how to integrate the **ASAIR ACD10 infrared CO₂ sensor** and **DHT20 temperature/humidity sensor** with an **Arduino/ESP board**, displaying results on a **16x2 I²C LCD**.

---

## ✨ Features
- 📡 Read **CO₂ concentration (ppm)** via I²C from ACD10  
- 🌡️ Read **temperature & humidity** from DHT20  
- 🖥️ Display data on a **16x2 I²C LCD**  
- 🔌 Compatible with **Arduino, ESP8266, ESP32**

---

## 🔧 Hardware Required
- Arduino UNO / ESP8266 / ESP32  
- ASAIR ACD10 CO₂ Sensor (I²C mode, default address `0x2A`)  
- DHT20 Temperature & Humidity Sensor  
- 16x2 LCD with I²C module (default address `0x27`)  
- Jumper wires, breadboard  

---

## 📡 Wiring Diagram

| Device       | Pin (Arduino/ESP) |
|--------------|-------------------|
| ACD10 (I²C)  | SDA → D2, SCL → D1 |
| DHT20        | SDA → D2, SCL → D1 |
| LCD (I²C)    | SDA → D2, SCL → D1 |
| Power        | 3.3V/5V & GND     |

> ⚠️ Adjust pins for your board. ESP32/ESP8266 require correct GPIO mapping.

---

## 🚀 Installation

1. Install Arduino IDE libraries:
   - [`DHT20`](https://github.com/RobTillaart/DHT20)  
   - [`LiquidCrystal_I2C`](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)  
   - `Wire` (built-in)

2. Clone this repo and upload the sketch:

```bash
git clone https://github.com/fuzonmedia/ASAIR-ACD10-infrared-carbon-dioxide-sensor-integration-in-arduino-or-esp
