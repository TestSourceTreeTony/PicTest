

#include <GenericTypeDefs.h>
#include <p18f4550.h>
#include "interrupt_handler.h"


union InterruptFlags_t  InterruptFlags = { 0 };

#pragma code
#pragma interruptlow low_isr
void low_isr ()
{   
    if( INTCONbits.TMR0IF == 1  ) // Timer 0 interrupt flag
	{
        INTCONbits.TMR0IF = 0;
  	};

 
}

#pragma code
#pragma interrupt high_isr
void high_isr (void)
{
	if( INTCONbits.TMR0IF == 1  ) // Timer 0 interrupt flag
	{
        InterruptFlags.flagBits.timer0int = 1;
        INTCONbits.TMR0IF = 0;
	};
}




#pragma code low_vector_section=0x18
void interrupt_at_low_vector(void)
{
_asm GOTO low_isr _endasm
}


#pragma code high_vector_section=0x08
void interrupt_at_high_vector(void)
{
_asm GOTO high_isr _endasm
}
