#include <LiquidCrystal.h> 
	LiquidCrystal lcd(12, 11, 9, 8, 7, 6);
	int Pin1 = 13;
	int Pin2 = 10; 
	int State = LOW;

	int currentState = 0;
	int previousState = 0;

	int value = 0; 
	int count = 0;
void setup() 
{
		pinMode(Pin1, OUTPUT);
		pinMode(Pin2, INPUT);	
		lcd.begin(16, 2);
		lcd.setCursor(4, 0);
		lcd.print("NO any motion");
}
void loop(){
		value = digitalRead(Pin2); 
		if (value == HIGH) 
		{ 	lcd.clear();
			digitalWrite(Pin1, HIGH); 
			
			if (State == LOW) 
			{
              lcd.print("Motion detect");
              currentState = 1;
              State = HIGH;
              delay(500);
			}
		}
		else 
		{
			digitalWrite(Pin1, LOW); 
			
			if (State == HIGH)
			{
              lcd.print("No Motion");
				currentState = 0;
				State = LOW;
			}
		}
		
		
}