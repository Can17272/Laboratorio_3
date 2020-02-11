#include <xc.h>
#include "lcd.h"

int EN;
int RS;
int RW;
int VAR_LCD;
char cursor;

//int delay();
//void LCD_INIT

void LCD_INIT (unsigned char VAR1){
    VAR_LCD = VAR1;
    EN=1;
    RS=0;
    RW=0;
    delay(5);
    EN=0;
}

void LCD_CLR (void){
    LCD_INIT(0);
    LCD_INIT(1);
}

void LCD_CURSOR (char a, char b){
    if (a==1){
        cursor =0x80+b-1;
        LCD_INIT(cursor);
    }
    if (a==2){
        cursor = 0xC0+b-1;
        LCD_INIT(cursor);
    }
}



int delay()
{
   int c, d;
   
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
       
   return 0;
}