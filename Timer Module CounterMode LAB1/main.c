#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    TRISB = 0x00;
    PORTB = 0x00;
    //configure timer 1 to work in counter mode
    //first clear timer 1 module
    TMR1 = 0x00;
    //counter mode
    TMR1CS = 1; 
    //Counter mode is selected by setting bit TMR1CS. In this mode, the timer increments on every rising edge of
                //clock input on pin RC1/T1OSI/CCP2 when bit T1OSCEN is set
                //, or on pin RC0/T1OSO/T1CKI when bit T1OSCEN is cleared.
    //we will set OSCEN to 1 so we will be using RC0, and you don't need to set TRIS AND PORT for RC1 in that case
    T1OSCEN = 1; 
      //Timer1 External Clock Input Synchronization Control bit (NEGATIVE LOGIC, WORKS IN 0 NOT 1)
//When TMR1CS = 1:
//1 = Do not synchronize external clock input
//0 = Synchronize external clock input
    T1SYNC = 0; 
    //prescaler
    T1CKPS0 = 0;
    T1CKPS1 = 0;
    //turn on timer 1 module
    TMR1ON = 1;
    while(1){
        PORTB = TMR1; //TMR1 is a 16 bit register that is split into two 8-bits register which are TMR1L and TMR1H
                      //so when you set PORTB (which is 8-bit) to be equal to a 16 bit register
                      //it will then take only the first 8 bit of the timer 1 register so it will take TMR1L value only
                      //this value is 255 since ( (2^8) - 1 ) = 255
                      //this is fine because we will be using 3 LEDS only and it's maximum value is 7 as 111 = 7
    }
    return;
}
