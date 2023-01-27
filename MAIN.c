


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000


void main(void)
{
  // Créer une variable de décalage de bits
  unsigned char s=0;
  // Définir PORTB 8 broches comme broches de sortie
  TRISB = 0x00;
  // Réglez toutes les broches PORTB sur OFF
  PORTB = 0x00;
  
  while(1)
  {
    // Tourner d'un côté
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
    // Tourner de l'autre côté
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
