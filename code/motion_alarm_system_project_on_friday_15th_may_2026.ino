#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int ledpin = 8;
int buzzpin = 2;
int pirpin = 10;

int pirstate = LOW;
int val = 0;
int lcd_delay = 5000;
int buzz_delay = 500;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:

pinMode(ledpin, OUTPUT);
pinMode(buzzpin, OUTPUT);
pinMode(pirpin, INPUT);
lcd.init();
lcd.backlight();
lcd.setCursor(0, 0);
lcd.print("Hello Moses");

lcd.setCursor(0, 1);
lcd.print("Screen is Ready");

}

void repeat_alarm(){
  for(int i = 0; i < 10; i++){
    digitalWrite(buzzpin, HIGH);
    delay(buzz_delay);
    digitalWrite(buzzpin, LOW);
    delay(buzz_delay);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(pirpin);

Serial.print("The current pirstate is: ");

if (val == HIGH){
  if (pirstate == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Smart Security");
    lcd.setCursor(0,1);
    lcd.print("Motion Detected!!!");
    digitalWrite(ledpin, HIGH);
    repeat_alarm();
    delay(lcd_delay);
    digitalWrite(ledpin, LOW);
    pirstate = HIGH;
}
}
else{
  if (pirstate == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Smart Security");
    lcd.setCursor(4,1);
    lcd.print("No Motion");
    delay(lcd_delay);
    pirstate = LOW;
}

}

}
