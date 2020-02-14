/* 
 * File:   Lab3.c
 * Author: TOSHIBA
 *
 * Created on February 7, 2020, 4:39 PM
 */
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pic16F887.h>
#include "lcd.h"
#include "ADC.h"

/*void LCD_CLR(void);
void LCD_CURSOR(void);*/


uint16_t VAL_ADC;
uint16_t VAL_ADC2;
char BUFFER [16];
float POT1;
float POT2;

void SETUP (void){
    PORTA=0;
    PORTB=0;
    PORTC=0;
    PORTE=0;
    
    TRISA=0;
    TRISB=1;
    TRISC=0;
    TRISD=0;
    
    ANSEL=0;
    ANSELH=1;
}

void main(void) {
    SETUP();
    LCD_PROG();
    INTERRUPCIONES();
    LCD_CLR();
    LCD_CURSOR(1,1); //El cursor se pone en el primer cuadro de la primera fila
    WRITE("Pot1     POT2    CONT"); //Se escriben los char constantes de arriba en un string
    while(1){
        ADC();
        ADCON0bits.GO_DONE=1;
        PIR1bits.ADIF=0; //Interrupción del primer ADC
        
        VAL_ADC=ADRESH;
        VAL_ADC=VAL_ADC<<8;
        VAL_ADC=VAL_ADC + ADRESL;
        POT1=VAL_ADC*5.0;
        POT1=POT1/1024.0; //Se convierte el valor del ADC 1 a float y se opera para mostrarse en un rango de 0 a 5V
        
        ADC1();
        ADCON0bits.GO_DONE=1;
        PIR1bits.ADIF=0; //Interrupción del segundo ADC
        
        VAL_ADC2=ADRESH;
        VAL_ADC2=VAL_ADC2<<8;
        VAL_ADC2=VAL_ADC2+ADRESL;
        POT2=(VAL_ADC2*5.0);
        POT2=POT2/1024.0; //Se convierte el valor del ADC 2 a float y se opera para mostrarse en un rango de 0 a 5V
        
        sprintf(BUFFER,"%04.2f %04.2f",POT1,POT2);
        LCD_CURSOR(2,1);
        WRITE(BUFFER);
        LCD_CURSOR(2,5);
        WRITE("V");
        LCD_CURSOR(2,11);
        WRITE("V");
        
    }
    
    

}

