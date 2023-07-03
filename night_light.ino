#include <LiquidCrystal.h>

// Create an LCD Object. Signals: [ RS, EN, D4, D5, D6, D7 ]
LiquidCrystal lcd(22, 21, 1, 3, 17, 16);

#define LIGHT_SENSOR_PIN 36 // ESP32 pin GPIO36 (ADC0)
#define LED_PIN 5

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  lcd.clear();
  lcd.setCursor(0, 0);

  if (analogValue < 40) {
    lcd.clear();
    lcd.print(" Bright");
    digitalWrite(LED_PIN, LOW);
  } else if (analogValue < 800) {
    lcd.clear();
    lcd.print(" Light");
    digitalWrite(LED_PIN, LOW);
  } else if (analogValue < 2000) {
    lcd.clear();
    lcd.print(" Dim");
    digitalWrite(LED_PIN, LOW);
  } else if (analogValue < 3200) {
    lcd.clear();
    lcd.print(" Dark");
    digitalWrite(LED_PIN, HIGH);
  } else {
    lcd.clear();
    lcd.print(" Black ");
    digitalWrite(LED_PIN, HIGH);
  }

}
