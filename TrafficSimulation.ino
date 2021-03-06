#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int GreenLed  = 10;
const int YellowLed = 9;
const int RedLed    = 8;
 
int state     = 0; // State 0 - Red only, State 1 - Red Yellow, State 2 - Green
                   // State 3 - Yellow
int light_delay[]   = { 2500, 2500, 2500, 2500 };
 
void setup() {
	pinMode(GreenLed, OUTPUT);
	pinMode(YellowLed,OUTPUT);
	pinMode(RedLed,OUTPUT);
        lcd.begin(16, 2);
        
        
}
 
void loop() {
   switch (state) {
              case 0 : 
	      digitalWrite(YellowLed, LOW);
              digitalWrite(RedLed, HIGH); 
              lcd.clear();
              lcd.print("Don't Walk");             
            break;
	   case 1 :
              digitalWrite(YellowLed, LOW);
	      break;
	   case 2 :
	      digitalWrite(YellowLed, LOW);
              digitalWrite(RedLed, LOW); 
              digitalWrite(GreenLed, HIGH);
	      lcd.clear();
              lcd.print("Walk");
              break;
	   case 3 :
	      digitalWrite(GreenLed, LOW);
	      digitalWrite(YellowLed, HIGH);
	      lcd.clear();
              lcd.print("Caution");
              break;          
   }
   
   delay(light_delay[state]);
   
   if (state == 3) {
	   state = 0;
   } else {
	   state += 1;
   }	
}
