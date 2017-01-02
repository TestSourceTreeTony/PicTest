/* 
 * File:   interrupt_handler.h
 * Author: worker
 *
 * Created on December 28, 2016, 1:53 PM
 */

#ifndef INTERRUPT_HANDLER_H
#define	INTERRUPT_HANDLER_H
// comment

#ifdef	__cplusplus
extern "C" {
#endif

typedef union InterruptFlags_t{
    UINT8 flags ;
    struct flagBits_t{
        UINT8 timer0int:1 ;
    }flagBits;
};



#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPT_HANDLER_H */

