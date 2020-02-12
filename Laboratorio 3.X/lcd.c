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

void LCD_PROG (void){
    delay(20);
    LCD_INIT(0x30);
    delay(5);
    LCD_INIT(0x30);
    delay(10);
    LCD_INIT(0x38);
    LCD_INIT(0x10);
    LCD_INIT(0x01);
    LCD_INIT(0x06);
    LCD_INIT(0x0C);
    LCD_INIT(0x80);
}

void CHAR (unsigned char a){
    RS = 1;
    VAR_LCD=a;
    RW=0;
    EN=1;
    delay(30);
    EN=0;
}

void WRITE (char *a){
    int b;
    for (b==0;a[b]!='\0'; b++)
        CHAR (a[b]);
}
int delay()
{
   int c, d;
   
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
       
   return 0;
}