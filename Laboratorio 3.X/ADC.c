#include <xc.h>
#include "ADC.h"
void ADC(void) {
    ADCON0bits.CHS0=0;
    ADCON0bits.CHS1=0;
    ADCON0bits.CHS2=1;
    ADCON0bits.CHS3=1;
    ADCON0bits.ADON=1;
    return;
}
void ADC1(void){
    ADCON0bits.CHS0=0;
    ADCON0bits.CHS1=1;
    ADCON0bits.CHS2=0;
    ADCON0bits.CHS3=1;
}
void INTERRUPCIONES(void){
    INTCONbits.GIE=1;
    INTCONbits.INTE=1;
    INTCONbits.PEIE=1;
    INTCONbits.T0IE=1;
    INTCONbits.T0IF=0; 
    
    ADCON1bits.ADFM=1;
    ADCON1bits.VCFG0=0;
    ADCON1bits.VCFG1=0;
    
    ADCON0bits.ADCS0=1;
    ADCON0bits.ADCS1=0;
    
    PIE1bits.ADIE=1; //Config. Interrupciones

}
