/* 
 * File:   newmain.c
 * Author: worker
 *
 * Created on 27. Dezember 2016, 23:40
 */

#include <p18f4550.h>
#include "config_bits.h"

#include <stdio.h>
#include <stdlib.h>

#include <timers.h>
#include <usart.h>

#include <GenericTypeDefs.h>
#include "interrupt_handler.h"


// Making conflict
// Add comment 1
// Add comment 2
// Add comment 3

// Comment 4

// ssada
//sdsds






void togglePin(void){
    
    static UCHAR8 toggleState = 1; 
    if (  toggleState ){
        LATAbits.LATA0 = 0;
    }else
    {
        LATAbits.LATA0 = 1;
    }
        toggleState  = !toggleState ;
    
    
}

static volatile UINT32 delayVar = 0;
void delay(void){
   
    delayVar = 0;
    while ( delayVar < 80000  ){
        delayVar += 1;
        
    }
    
    
}


extern union InterruptFlags_t  InterruptFlags ;



/*
 * 
 */
void main(void) {
  
    static UCHAR8 immertrue = 1;
    UCHAR8 config = 0;
  
    immertrue = immertrue + 1 ;
    
    TRISAbits.RA0 = 0; //LED Pin als Ausgang schalten
    LATAbits.LATA0 = 1;
    
    TRISDbits.RD2 = 0; // PIN RD2 = ausgang
    LATDbits.LATD2 = 1;
    
    
 
   

    
    

    
    
    config =   USART_TX_INT_OFF & USART_RX_INT_OFF & USART_BRGH_LOW & USART_EIGHT_BIT & USART_ASYNCH_MODE & USART_BRGH_LOW & USART_CONT_RX;
    OpenUSART( config , 51 );  // 16Mhz // 19200 Baud
    config = BAUD_IDLE_CLK_HIGH & BAUD_16_BIT_RATE & BAUD_AUTO_OFF ;
    baudUSART( config ) ;
    
    
    
    
    WriteTimer0( (UINT16) 5000  );
    OpenTimer0( TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_64  );
    
    
       
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.GIEH = 1;
    INTCONbits.TMR0IF = 0;
    
    while (immertrue){
       // delay();
       // togglePin();
        
        if (  0 != InterruptFlags.flagBits.timer0int  )
        { 
            WriteTimer0( (UINT16) 30000  );
            LATDbits.LATD2 = !LATDbits.LATD2 ;
            InterruptFlags.flagBits.timer0int = 0;
            
           
            printf("Hallo Tobi");
          //  while ( BusyUSART() );

           // putcUSART('H');
        }
    }
    
    
   
}



