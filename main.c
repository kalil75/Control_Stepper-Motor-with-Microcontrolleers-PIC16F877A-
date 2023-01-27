/*
 * File:   main.c
 * Author: khalil7
 *
 * Created on 24 janvier 2023, 16:29
 */


#include <xc.h>
#include "config1.h"
#define _XTAL_FREQ 4000000

void main(void)
{
  // Create Bit-Shifting Variable
  unsigned char i=0;
  // Set PORTB 8-Pins To Be Output Pins
  TRISB = 0x00;
  // Set All PORTB Pins To Be OFF (Initially) !
  PORTB = 0x00;
  // Create The System's Main Routine !
  while(1)
  {
    // Turn One Side
    for (int j=0; j<48; j++)
    {
      PORTB = (1<<i);
      i++;
      __delay_ms(10);  // StepDelay
      if (i==4)
          i=0;
    }
    // Wait For a Second !
    __delay_ms(1000);
    // Turn The Other Side
    for (int j=0,i=0; j<48; j++)
    {
      PORTB = (8>>i);
      i++;
      __delay_ms(10); // StepDelay
      if (i==4)
          i=0;
    }
  }
  return;
}