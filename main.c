
#include "pps.h"
#include "uart.h"

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
// Do not watch thse comments, i adjusted the config without updating them.
_FBS(BWRP_WRPROTECT_OFF);      // No Boot Protect
_FGS(GSS_OFF);              // No Code Protect
_FOSCSEL(FNOSC_FRC);            // Fast RC to start
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF  & POSCMD_NONE);
// Primary disabled, clock switch, no monitor, allow multiple IOLOCKs
_FWDT(FWDTEN_OFF);            // Turn off Watchdog Timer
_FPOR(FPWRT_PWR1);            // Power-up Timer to 16msecs
_FICD(ICS_PGD2 & JTAGEN_OFF);   // Use PGC/D 2, no JTAG


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

const UI08_t device_ID = 0; // stupid device ID rubbish.

/**** REGISTER MAP ***/
typedef struct MCP3911_Register_s
{
    UI08_t addr;
    UI08_t size;
} MCP3911_Register_t;

MCP3911_Register_t MCP3911_RegisterMap[12] = {
    {0x00, 24}, // Channel 0 data
    {0x03, 24}, // Channel 1 data
    {0x06, 8}, // Modulation output
    {0x07, 16}, // Phase delay
    {0x09, 8}, // Gain/Boost
    {0x0A, 16}, // Status & Communication settings
    {0x0C, 16}, // Configuration
    {0x0E, 24}, // Offset correction, channel 0,
    {0x11, 24}, // Gain correction, channel 0
    {0x14, 24}, // Offset correction, channel 1
    {0x17, 24}, // Gain correction, channel 1
    {0x1A, 8}, // VREF Temperature coefficient.
};
typedef enum MCP3911_RegisterName_s
{
    MCP3911_REGS_CHANNEL0,
    MCP3911_REGS_CHANNEL1,
    MCP3911_REGS_MOD,
    MCP3911_REGS_PHASE,
    MCP3911_REGS_GAIN,
    MCP3911_REGS_STATUSCOM,
    MCP3911_REGS_CONFIG,
    MCP3911_REGS_OFFCAL_CH0,
    MCP3911_REGS_GAINCAL_CH0,
    MCP3911_REGS_OFFCAL_CH1,
    MCP3911_REGS_GAINCAL_CH1,
    MCP3911_REGS_VREFCAL
} MCP3911_RegisterName_e;
#define MCP3911_REGNUMS ((UI08_t)MCP3911_REGS_VREFCAL)

void Delay(void)
{
    UI08_t i =0;
    for( i = 0; i < 9;i++);
}

UI08_t MCP3911_TransferByte(UI08_t data)
{
    UI08_t read = 0;
    SI08_t i = 0;


    FGPIO_Write(PB, 6, 0); // data is clocked out at falling edge.
    FGPIO_Write(PB, 10, 0);
    for(i = 7; i >= 0; i--)
    {
        if(data!= 0){
        if((data >> i) & 0x1) // bit is high
        {
            FGPIO_Write(PB, 8, 1);
            FGPIO_Write(PB, 11, 1);
        }
        else
        {
            FGPIO_Write(PB, 8, 0);
            FGPIO_Write(PB, 11, 0);
        }
        }
        Delay();
        FGPIO_Write(PB, 10, 1);
        FGPIO_Write(PB, 6, 1); // data is clocked in at rising edge.
        Delay();
        FGPIO_Write(PB, 6, 0); // data is clocked out at falling edge.
        FGPIO_Write(PB, 10, 0);
        if(data== 0){
        if((PORTB >> 7) & 0x1){
        //if (FGPIO_Read(PB, 7) != 0){ // it is high!
            read |= 1<<i; // set this bit high.
            FGPIO_Write(PB, 11, 1);
            //printf(":d");
        }else{
            FGPIO_Write(PB, 11, 0);
        }}

    }
        Delay();
        Delay();
        Delay();
        Delay();
        Delay();
    FGPIO_Write(PB, 10, 0);
    FGPIO_Write(PB, 6, 0); // data is clocked out at falling edge.
    return read;
}

UI32_t MCP3911_ReadRegister(MCP3911_RegisterName_e reg)
{
    UI32_t read = 0;
    UI08_t addr = MCP3911_RegisterMap[reg].addr;
    UI08_t size = MCP3911_RegisterMap[reg].size;
    UI08_t size_bytes = size/8;

    FGPIO_Write(PB,5,0); // chipselect active-low
    MCP3911_TransferByte(((addr << 1) + 0x0)); // 1 or 0?

    while(size_bytes != 0)
    {
        read = read << 8;
        UI08_t d = MCP3911_TransferByte(0);
        read |= d;
        size_bytes --;
        if(size_bytes == 0) break;
    }
    FGPIO_Write(PB,5,1); // chipselect active-low

    return read;
    
}

void MCP3911_WriteRegister(MCP3911_RegisterName_e reg, UI32_t data)
{
    UI08_t addr = MCP3911_RegisterMap[reg].addr;
    UI08_t size = MCP3911_RegisterMap[reg].size;
    UI08_t size_bytes = size/8;

    // Write address.
    FGPIO_Write(PB,5,0); // chipselect active-low
    MCP3911_TransferByte(((addr << 1) | 0x0)); // 1 or 0?

    while(size_bytes >= 1 && size_bytes < 10)
    {
        MCP3911_TransferByte((UI08_t)(data & 0xFF));
        data = data >> 8;
        size_bytes --;
    }
    FGPIO_Write(PB,5,1); // chipselect active-low
}

void MCP3911_Setup(void)
{
    // Setup to convert 2 channels at 1KSPS.

}

void MCP3911_Dump(void)
{
    UI08_t i =0;
    printf("MCP3911 memory dump\r\n");
    // Dump all registers
    for( i = 0; i < MCP3911_REGNUMS; i++)
    {
        UI32_t data  =MCP3911_ReadRegister(i );
        printf("0x%X: 0x%X %X\r\n", i, (UI16_t) (data&0xFFFF), (UI16_t)(data >> 16));
    }
    
}

int main(void)
{
    CLKDIVbits.ROI = 0;
    CLKDIVbits.DOZE = 0;
    CLKDIVbits.DOZEN = 1; // divide by 2.
    CLKDIVbits.FRCDIV = 0;
    AD1PCFGL = 0xFFFF;
    //CLKDIV
    FGPIO_Direction(PB, 1, OUTPUT);
    UI32_t i = 0;

    // I/O Configuration:
    // DR       = RB9
    // SCK      = RB6
    // MOSI     = RB8
    // MISO     = RB7
    // CS       = RB5
    // TX       = RB15
    // RX       = RB14

    // No SPI used, bit-bang now.
    FGPIO_Direction(PB, 5, OUTPUT);     // CS
    FGPIO_Direction(PB, 6, OUTPUT);     // SCK
    FGPIO_Direction(PB, 7, INPUT);     // MISO
    FGPIO_Direction(PB, 8, OUTPUT);     // MOSI
    FGPIO_Direction(PB, 9, INPUT);     // DR
    FGPIO_Direction(PB, 14, INPUT);     //RX
    FGPIO_Direction(PB, 15, OUTPUT);     //TX

    FGPIO_Direction(PB, 10, OUTPUT);     // logic1
    FGPIO_Direction(PB, 11, OUTPUT);     // logic2

    __builtin_write_OSCCONL(OSCCON & 0xBF);
    iPPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP14);
    iPPSOutput(OUT_PIN_PPS_RP15, OUT_FN_PPS_U1TX);
    __builtin_write_OSCCONL(OSCCON | 0x40);
    Uart_Init(1);
    printf("Hey!");

    // set all to zero
    FGPIO_Write(PB,5,1); // chipselect active-low
    FGPIO_Write(PB,6,0); // clock
    FGPIO_Write(PB,8,0); // data out

    while(1)
    {
        FGPIO_Write(PB,1,1);
        for(i=0; i<100000; i++);
        FGPIO_Write(PB,1,0);
        for(i=0; i<100000; i++);
        MCP3911_Dump();
    }

    return 0;
}