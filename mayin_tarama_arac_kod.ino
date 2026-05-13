#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD adres ve boyutu (adres genelde 0x27 olur)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin tanımları
const int sensorPin = 2;
const int buzzerPin = 8;
const int motor1A = 5;
const int motor1B = 6;
const int motor2A = 9;
const int motor2B = 10;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistem Basladi");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorState = digitalRead(sensorPin);

  if (sensorState == LOW) { // Metal (mayın) algılandı
    stopMotors();
    digitalWrite(buzzerPin, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(">>> TEHLIKE <<<");
    lcd.setCursor(0, 1);
    lcd.print("Mayin Tespit!");
    delay(3000);
  } else {
    moveForward();
    digitalWrite(buzzerPin, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tarama...");
    lcd.setCursor(0, 1);
    lcd.print("Alan Temiz");
  }

  delay(200);
}

void moveForward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void stopMotors() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}
