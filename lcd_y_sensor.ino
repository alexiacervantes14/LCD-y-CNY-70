#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
 pinMode(A0,INPUT);
 lcd.begin(16, 2);
 Serial.begin(9600);
 
}

void loop() {
  float vm,x1,x2;
  float a=.0146;
  float b=.5322;
  float c=3.8889;
  delay(1000);
  vm=analogRead(A0);
  vm=vm*(5.0/1023.0);
  lcd.setCursor(0,0);
  lcd.print("Voltaje:");
  lcd.setCursor(9,0);
  lcd.print(vm);
  lcd.setCursor(15,0);
  lcd.print("V");
  c=c-vm;
  x1 = (b + sqrt( (b*b) - (4 * a * c) ) ) / (2.0 * a);
  x2 = (b - sqrt( (b*b) - (4 * a * c) ) ) / (2.0 * a);
   Serial.print(" X1 ");
   Serial.println(x1);
   Serial.print(" x2 ");
   Serial.println(x2);
   lcd.setCursor(0,1);
   lcd.print("Distance:");
   lcd.setCursor(10,1);
   lcd.print(x2);
    lcd.setCursor(14,1);
   lcd.print("mm");
 }
