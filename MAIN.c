


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000


void main(void)
{
  // Cr�er une variable de d�calage de bits
  unsigned char s=0;
  // D�finir PORTB 8 broches comme broches de sortie
  TRISB = 0x00;
  // R�glez toutes les broches PORTB sur OFF
  PORTB = 0x00;
  
  while(1)
  {
    // Tourner d'un c�t�
    for (int i=0; i<48; i++)
    {
      PORTB = (1<<s);
      s++;
      __delay_ms(10);  // StepDelay
      if (s==4)
          s=0;
    }
    // Wait For a Second !
    __delay_ms(1000);
    // Tourner de l'autre c�t�
    for (int j=0,i=0; j<48; j++)
    {
      PORTB = (8>>s);
      s++;
      __delay_ms(10); // StepDelay
      if (s==4)
          s=0;
    }
  }
  return;
}
