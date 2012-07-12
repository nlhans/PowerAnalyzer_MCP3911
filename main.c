
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
    MCP3911_REGS_CHANNEL0,      //0x0
    MCP3911_REGS_CHANNEL1,      //0x1
    MCP3911_REGS_MOD,           //0x2
    MCP3911_REGS_PHASE,         //0x3
    MCP3911_REGS_GAIN,          //0x4
    MCP3911_REGS_STATUSCOM,     //0x5
    MCP3911_REGS_CONFIG,        //0x6
    MCP3911_REGS_OFFCAL_CH0,    //0x7
    MCP3911_REGS_GAINCAL_CH0,   //0x8
    MCP3911_REGS_OFFCAL_CH1,    //0x9
    MCP3911_REGS_GAINCAL_CH1,   //0xA
    MCP3911_REGS_VREFCAL        //0xB
} MCP3911_RegisterName_e;
#define MCP3911_REGNUMS ((UI08_t)MCP3911_REGS_VREFCAL)

#define MCP3911_ADDR_READ 1
#define MCP3911_ADDR_WRITE 0

void Delay(void)
{
    UI08_t i =0;
    for( i = 0; i < 3;i++);
}

UI08_t MCP3911_TransferByte(UI08_t data)
{
    UI08_t read = 0;
    SI08_t i = 0;


    FGPIO_Write(PB, 6, 0);

    for(i = 7; i >= 0; i--)
    {

        if((data >> i) & 0x1) // bit is high
        {
            FGPIO_Write(PB, 8, 1);
        }
        else
        {
            FGPIO_Write(PB, 8, 0);
        }

        FGPIO_Write(PB, 6, 1);

        asm volatile("nop");
        FGPIO_Write(PB, 6, 0);

        if (FGPIO_Read(PB, 7))
            read |= (1<<i); // set this bit high.
    }

    return read;
}

UI32_t MCP3911_ReadRegister(MCP3911_RegisterName_e reg)
{
    UI32_t read = 0;
    UI08_t addr = MCP3911_RegisterMap[reg].addr;
    UI08_t size = MCP3911_RegisterMap[reg].size;
    UI08_t size_bytes = size/8;

    FGPIO_Write(PB,5,0); // chipselect active-low
    MCP3911_TransferByte(((addr << 1) | MCP3911_ADDR_READ)); // 1 or 0?

    while(size_bytes != 0)
    {
        read = read << 8;
        read |= MCP3911_TransferByte(0);
        size_bytes --;
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
    MCP3911_TransferByte(((addr << 1) | MCP3911_ADDR_WRITE)); // 1 or 0?

    if(size_bytes >= 3)
        MCP3911_TransferByte((UI08_t)((data >> 16)&0xFF));
    if(size_bytes >= 2)
        MCP3911_TransferByte((UI08_t)((data >> 8)&0xFF));
    if(size_bytes >= 1)
        MCP3911_TransferByte((UI08_t)((data >> 0)&0xFF));
    FGPIO_Write(PB,5,1); // chipselect active-low
}

void MCP3911_Setup(void)
{
    MCP3911_ReadRegister(MCP3911_REGS_CHANNEL0);
    MCP3911_ReadRegister(MCP3911_REGS_CHANNEL1);
    // Setup to convert 2 channels at 1KSPS.
    MCP3911_WriteRegister(MCP3911_REGS_STATUSCOM,   0b0000001110111000);
    MCP3911_WriteRegister(MCP3911_REGS_GAIN,        0b10000000); // boost 1x, gain 1x (ch0+1)
    MCP3911_WriteRegister(MCP3911_REGS_CONFIG,      0b0011011000000010);

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

SI32_t a1;
SI32_t b1;
void MCP3911_Sample(void)
{
    SI32_t a = (MCP3911_ReadRegister(0));
    SI32_t b = (MCP3911_ReadRegister(1));
    if(a!= a1 && b!=b1){
        printf("%ld,%ld\r\n", a, b);
        a1 = a;
        b1 = b;
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
    FGPIO_Direction(PB, 1, OUTPUT); // blinky led
    UI32_t i = 0;

    // I/O Configuration:
    // DR       = RB9
    // SCK      = RB6
    // MOSI     = RB8
    // MISO     = RB7
    // CLKO     = RB2
    // CS       = RB5
    // TX       = RB15
    // RX       = RB14

    // Logic1 & Logic2 are logic probes of PICKIT2
    
    // No SPI used, bit-bang now.
    FGPIO_Direction(PB, 5, OUTPUT);      // CS
    FGPIO_Direction(PB, 6, OUTPUT);      // SCK
    FGPIO_Direction(PB, 7, INPUT);       // MISO
    FGPIO_Direction(PB, 8, OUTPUT);      // MOSI
    FGPIO_Direction(PB, 2, OUTPUT);      // CLKO (CLKI@MCP3911)
    FGPIO_Direction(PB, 9, INPUT);       // DR
    FGPIO_Direction(PB, 14, INPUT);      // RX
    FGPIO_Direction(PB, 15, OUTPUT);     // TX

    FGPIO_Direction(PB, 10, OUTPUT);     // logic1
    FGPIO_Direction(PB, 11, OUTPUT);     // logic2
    
    __builtin_write_OSCCONL(OSCCON & 0xBF);
    iPPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP14);
    iPPSOutput(OUT_PIN_PPS_RP15, OUT_FN_PPS_U1TX);
    iPPSOutput(OUT_PIN_PPS_RP2, OUT_FN_PPS_OC1);
    __builtin_write_OSCCONL(OSCCON | 0x40);
    Uart_Init(1);

    printf("**************************************\r\n");
    printf("**  DC power analyzer MCP3911 test! **\r\n");
    printf("**************************************\r\n");
    

    // Initialize Output Compare Module
    OC1CONbits.OCM = 0b000; // Disable Output Compare Module
    OC1R =0; // Write the duty cycle for the first PWM pulse
    OC1RS =1; // Write the duty cycle for the second PWM pulse
    OC1CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
    OC1R = 1; // Load the Compare Register Value
    OC1CONbits.OCM = 0b110; // Select the Output Compare mode
    // Initialize and enable Timer2
    T2CONbits.TON = 0; // Disable Timer
    T2CONbits.TCS = 0; // Select internal instruction cycle clock
    T2CONbits.TGATE = 0; // Disable Gated Timer mode
    T2CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
    TMR2 = 0x00; // Clear timer register
    PR2 = 1; // Load the period value
    IEC0bits.T2IE = 0; // Disable Timer 2 interrupt
    T2CONbits.TON = 1; // Start Timer

    // set all to zero
    FGPIO_Write(PB,5,1); // chipselect active-low
    FGPIO_Write(PB,6,0); // clock
    FGPIO_Write(PB,8,0); // data out

    MCP3911_Setup();
    MCP3911_Dump();

    while(1)
    {
        MCP3911_Sample();
        
    }

    return 0;
}