/*
    Programm:   FotoAutomat.cpp
    Autor:      Jonas Blatzheim, Andreas Blatzheim
    Purpose:    Manage LUMIX G10 remote conrol to take n photos over a period of time t
                Let the user define n and t before the programm starts
                
*/

// include files 
#include <Wire.h>
#include <TimerOne.h>
#include "Encoder.h"
#include "rgb_lcd.h"
#include "FotoAutomat.h"

rgb_lcd lcd;

// Encoder is fixed in Library to use D2 for input 

#define encode_up    1
#define encode_down  0
#define encode_click 2

#define sw01 4
#define sw02 5


// Global Variables 
int photo_cnt;
int photo_wait_sec;
int photo_wait_min;
int photo_wait_h;


// setup the display, encoder and global variables 
void setup() {
// Setting up Display 
lcd.begin(lcd_col, lcd_row);
lcd.print("Loading");

// init global variables 

// init Encoder 
encoder.Timer_init();
pinMode(sw01,INPUT);
pinMode(sw02,INPUT);

Serial.begin(9600);

// move curser to 1,1
lcd.setCursor(0,0);
lcd.print("CNT:     ");
}

void loop() {
   char buffer[5];
   
   if (digitalRead(sw01)) {
    Serial.println("Switch 01");
   }
   if (digitalRead(sw02)) {
    Serial.println("Swicth 02");
   }

   if (encoder.rotate_flag ==1 ) {
        
        if (encoder.direct == 0) {
            photo_cnt++;
            if (photo_cnt > count_max) {
              photo_cnt = 0;
            }
            sprintf(buffer,"%04i",photo_cnt);
            
            lcd.setCursor(5,0);
            lcd.print(buffer);

            lcd.setCursor(5,1);
            lcd.print("     ");
        }
        if (encoder.direct == 1) {
            photo_cnt--;
            if (photo_cnt < 0 ) { 
              photo_cnt = count_max;
            }
            sprintf(buffer,"%04i",photo_cnt);
            
            lcd.setCursor(5,0);
            lcd.print(buffer);

            lcd.setCursor(5,1);
            lcd.print("     ");
        }
        encoder.rotate_flag = 0;
    }
    
}

// deliver a string based on a number 
