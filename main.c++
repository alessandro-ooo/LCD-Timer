/*
*
*	AUTHOR: Alessandro Buonocore
*	GITHUB REPOSITORY: https://github.com/alessandro-ooo/LCD-Timer
*	TINKERCAD FILE: https://www.tinkercad.com/things/8gXjzF1gUxS-lcd-timer
*
*/

#include <Adafruit_LiquidCrystal.h>

const int increaserBtnPin = 4;
const int decreaserBtnPin = 2;
const int handleBtnPin = 7;

int increaserBtnState = LOW;
int decreaseBtnState = LOW;
int handleBtnState = LOW;
int seconds = 5;
bool isCounting = false;

Adafruit_LiquidCrystal timerLCD(0);

void setup()
{
	pinMode(increaserBtnPin, INPUT);
  	pinMode(decreaserBtnPin, INPUT);
    pinMode(handleBtnPin, INPUT);
  
  	timerLCD.begin(16, 2);
  	timerLCD.setCursor(7, 8);
  	printSeconds(seconds);
}

void printSeconds (int number) {
    timerLCD.clear();
    timerLCD.setCursor(7, 8);
    timerLCD.print(number); 
    return;
}

void tickLCD(int currentSeconds) {
  	
  	for(int sec = currentSeconds; sec >= 0; sec--){
        delay(1000);
        seconds -= 1;

        printSeconds(seconds);
    }
  
  	isCounting = false;
  	seconds = 5;
  	printSeconds(seconds);
}

void loop() {
    if(digitalRead(handleBtnPin) == HIGH) {
        delay(50);
        switch(isCounting) {
            case false: {
                tickLCD(seconds);
                isCounting = true;
                break;
            }

            case true: {
                isCounting = false;
                break;
            }
        }
    }

	if(digitalRead(increaserBtnPin) == HIGH) {
        delay(50);
		seconds += 5;

        printSeconds(seconds);
  	}
  
	if(digitalRead(decreaserBtnPin) == HIGH) {
        delay(50);
		seconds = (seconds - 5 <= 5) ? seconds = 5 : seconds -= 5;

        printSeconds(seconds);
  	}
}