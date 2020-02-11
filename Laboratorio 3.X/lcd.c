#include <xc.h>
#include "lcd.h"

int EN;
int RS;
int RW;
int VAR_LCD;

//int delay();
//void LCD_INIT

void LCD_INIT (unsigned char VAR1){
    VAR_LCD = VAR1;
    EN=1;
    RS=0;
    RW=0;
    delay(5);
    return (0);
    EN=0;
}

void LCD_CLR (void){
    LCD_INIT(0);
    LCD_INIT(1);
}
int delay()
{
   int c, d;
   
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
       
   return 0;
}