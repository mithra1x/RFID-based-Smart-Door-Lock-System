#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define SS_PIN 10 
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD address 0x27

Servo lockServo;

byte authorizedUID[4] = {0xDE, 0xAD, 0xBE, 0xEF};  // Öz kartınızın UID-si ilə dəyişin

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");

  lockServo.attach(3);  // Servo PIN
  lockServo.write(0);   // Qapalı vəziyyət
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  lcd.clear();
  Serial.print("UID tag :");

  bool authorized = true;
  for (byte i = 0; i < 4; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    if (rfid.uid.uidByte[i] != authorizedUID[i]) {
      authorized = false;
    }
  }
  Serial.println();

  if (authorized) {
    lcd.setCursor(0, 0);
    lcd.print("Access Granted");
    lcd.setCursor(0, 1);
    lcd.print("Door is open");
    lockServo.write(90);  // Açıq vəziyyət
    delay(5000);          // Açıq qalma müddəti
    lockServo.write(0);   // Bağlı vəziyyət
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
  }

  delay(2000);
  lcd.clear();
  lcd.print("Scan your card");
  rfid.PICC_HaltA();
}
