
#include "pps.h"

#include "stddefs.h"

// TODO: Integrate Triton framework..

#define GPIO_PORT_A
#define GPIO_PORT_B
#define GPIO_PORT_C

#define IO_PA 0
#define IO_PB 1
#define IO_PC 1


IOPort_t IOPorts[3] = {
        {PTR16(0x2C0), PTR16(0x2C2), PTR16(0x2C4), PTR16(0x2C6)},
        {PTR16(0x2C8), PTR16(0x2CA), PTR16(0x2CC), PTR16(0x2CE)}
        ,{PTR16(0x2D0), PTR16(0x2D2), PTR16(0x2D4), PTR16(0x2D6)}
};

#define CFG_RCDIV 0
_FBS(BWRP_WRPROTECT_OFF);      // No Boot Protect
_FGS(GSS_OFF);              // No Code Protect
_FOSCSEL(FNOSC_FRCPLL);            // Fast RC to start
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF  & POSCMD_NONE);
// Primary disabled, clock switch, no monitor, allow multiple IOLOCKs
_FWDT(FWDTEN_OFF);            // Turn off Watchdog Timer
_FPOR(FPWRT_PWR1);            // Power-up Timer to 16msecs
_FICD(ICS_PGD2 & JTAGEN_OFF);   // Use PGC/D 2, no JTAG
#define CLOCK_CPU 40000000
#define CLOCK_PERIPHERAL CLOCK_CPU/2


/** TAKEN FROM EXAMPLES*/
void clrClkFail(void);

void __attribute__((__interrupt__)) _OscillatorFail(void);
void __attribute__((__interrupt__)) _AddressError(void);
void __attribute__((__interrupt__)) _StackError(void);
void __attribute__((__interrupt__)) _MathError(void);
void __attribute__((__interrupt__)) _DMACError(void);

void __attribute__((__interrupt__)) _AltOscillatorFail(void);
void __attribute__((__interrupt__)) _AltAddressError(void);
void __attribute__((__interrupt__)) _AltStackError(void);
void __attribute__((__interrupt__)) _AltMathError(void);
void __attribute__((__interrupt__)) _AltDMACError(void);

/*
Primary Exception Vector handlers:
These routines are used if INTCON2bits.ALTIVT = 0.
All trap service routines in this file simply ensure that device
continuously executes code within the trap service routine. Users
may modify the basic framework provided here to suit to the needs
of their application.
*/

/*On encountering a clock failure, if the fail-safe clock monitor (FSCM)
is enabled, device executes code using the FRC oscillator and code execution
reaches the Oscillatore Fail trap
*/

void __attribute__((interrupt, no_auto_psv)) _OscillatorFail(void)
{
        INTCON1bits.OSCFAIL = 0;        //Clear the trap flag
        while (1);

}

void __attribute__((interrupt, no_auto_psv)) _AddressError(void)
{
        INTCON1bits.ADDRERR = 0;        //Clear the trap flag
        while (1);
}
void __attribute__((interrupt, no_auto_psv)) _StackError(void)
{
        INTCON1bits.STKERR = 0;         //Clear the trap flag
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _MathError(void)
{
        INTCON1bits.MATHERR = 0;        //Clear the trap flag
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _DMACError(void)
{
        INTCON1bits.DMACERR = 0;        //Clear the trap flag
        while (1);
}





/*
Alternate Exception Vector handlers:
These routines are used if INTCON2bits.ALTIVT = 1.
All trap service routines in this file simply ensure that device
continuously executes code within the trap service routine. Users
may modify the basic framework provided here to suit to the needs
of their application.
*/

void __attribute__((interrupt, no_auto_psv)) _AltOscillatorFail(void)
{
        INTCON1bits.OSCFAIL = 0;
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltAddressError(void)
{
        INTCON1bits.ADDRERR = 0;
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltStackError(void)
{
        INTCON1bits.STKERR = 0;
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltMathError(void)
{
        INTCON1bits.MATHERR = 0;
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltDMACError(void)
{
        INTCON1bits.DMACERR = 0;        //Clear the trap flag
        while (1);
}

int main(void)
{
    FGPIO_Direction(PB, 1, OUTPUT);
    UI32_t i = 0;

    while(1)
    {
        FGPIO_Write(PB,1,1);
        for(i=0; i<100000; i++);
        FGPIO_Write(PB,1,0);
        for(i=0; i<100000; i++);
    }

    return 0;
}