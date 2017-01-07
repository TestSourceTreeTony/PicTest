

#include <usart.h>

#include "uart_redirection.h"


int _user_putc (char c)
{
    while ( BusyUSART() );

            putcUSART( c );
    
}



