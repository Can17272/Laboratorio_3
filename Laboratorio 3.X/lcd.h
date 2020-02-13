#ifndef __LCD_H_
#define	__LCD_H_

#include <xc.h> 

void LCD_INIT (unsigned char a);
void LCD_CLR (void);
void LCD_CURSOR (char a, char b);
void LCD_PROG (void);
void CHAR (unsigned char a);
void WRITE (char *a);
int delay();

#endif	/* XC_HEADER_TEMPLATE_H */

