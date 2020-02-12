#include <xc.h>
#include "lcd.h"

int EN;
int RS;
int RW;
int VAR_LCD;
char cursor;

//int delay();
//void LCD_INIT

void LCD_INIT (unsigned char a){
    VAR_LCD = a;
    EN=1;
    RS=0;
    RW=0;
    delay(5);
    EN=0; //Bits de configuración de la LCD
}

void LCD_CLR (void){
    LCD_INIT(0);
    LCD_INIT(1); //Función qué borra los valores de la pantalla
}

void LCD_CURSOR (char a, char b){
    if (a==1){
        cursor =0x80+b-1;
        LCD_INIT(cursor);
    }
    if (a==2){
        cursor = 0xC0+b-1;
        LCD_INIT(cursor); //Se posiciona el cursor en el cuadro en el que se necesita escribir
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
    LCD_INIT(0x80); //Configuración de inicialización de la pantalla
}

void CHAR (unsigned char a){
    RS = 1;
    VAR_LCD=a;
    RW=0;
    EN=1;
    delay(30);
    EN=0; //Selección de valor "char"
}

void WRITE (char *a){
    int b;
    for (b=0;a[b]!='\0'; b++)
        CHAR (a[b]); //Función para escribir strings en la LCD
}
int delay()
{
   int c, d;
   
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
       
   return 0; //Delay
}