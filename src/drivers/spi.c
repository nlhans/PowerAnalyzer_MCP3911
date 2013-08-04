#include "spi.h"
#include "uart.h"
#include <stdio.h>
#include "pps.h"

// MCP3911 pin mapping     referred to slave
// (SPI bus 1)
    // Reset not connected, to 3.3V
    // SDI      = RC9 / RP25        Out     MOSI
    // SDO      = RC8 / RP24        In      MISO
    // SCK      = RC7 / RP23        Out     SCK
    // CS       = RC6 / RP22        Out     CS
    // DR       = RB9 / RP9         In      Aux.

// PGA/SRAM pin mapping     referred to slave
// (SPI bus 2)
    // SCK      = RB10 / RP10       Out     SCK
    // SDO      = RB11 / RP11       In      MISO
    // SDI      = RB12 / RP12       Out     MOSI
    // CS PGA   = RB13 / RP13       Out     CS
    // CS RAM   = N.C.              Out     CS

void SpiInit()
{
    // SPI bus 1 (ADC)
    TRISC &= ~(1<<9);   // SDI Output
    TRISC |=  (1<<8);   // SDO Input
    TRISC &= ~(1<<7);   // SCK Output
    TRISC &= ~(1<<6);   // CS  Output
    TRISB |=  (1<<9);   // DR  Input
    PORTB |=  (1<<9);   // Enable pull-up RB9/DR

    // SPI bus 2 (PGA, SRAM)
    TRISB &= ~(1<<12);   // SDI Output
    TRISB |=  (1<<11);   // SDO Input
    TRISB &= ~(1<<10);   // SCK Output
    TRISB &= ~(1<<13);   // CS  Output

    PPSUnLock;
    // SPI Bus 1 (ADC)
    iPPSOutput(OUT_PIN_PPS_RP23, OUT_FN_PPS_SCK1);
    iPPSOutput(OUT_PIN_PPS_RP25, OUT_FN_PPS_SDO1);
    iPPSInput(IN_FN_PPS_SDI1, IN_PIN_PPS_RP24);

    // SPI Bus 2 (PGA, SRAM)
    iPPSOutput(OUT_PIN_PPS_RP10, OUT_FN_PPS_SCK2);
    iPPSOutput(OUT_PIN_PPS_RP12, OUT_FN_PPS_SDO2);
    iPPSInput(IN_FN_PPS_SDI2, IN_PIN_PPS_RP11);
    
    PPSLock;

    // Configure SPI1 bus
    IFS0bits.SPI1IF = 0;
    IEC0bits.SPI1IE = 0;

    SPI1CON1 = 0b0000000100111010;
    SPI1CON2 = 0b0;
    SPI1STATbits.SPIEN = 1;

    // Configure SPI2 bus
    SPI2CON1 = 0b0000000100110000;
    SPI2CON2 = 0b0;
    SPI2STATbits.SPIEN = 1;
    
}

UI08_t SpiRx(UI08_t id)
{
    switch(id)
    {
        case 1:
            SPI1BUF = 0;
            while(SPI1STATbits.SPIRBF == 0);
            return SPI1BUF;
            break;

        case 2:
            SPI2BUF = 0;
            while(SPI2STATbits.SPIRBF == 0);
            return SPI2BUF;
            break;
    }

    return 0;
}

void SpiTx(UI08_t id, UI08_t data)
{
    volatile UI16_t temp = 0;
    switch(id)
    {
        case 1:
            SPI1BUF = data;
            while(SPI1STATbits.SPIRBF == 0);
            temp = SPI1BUF;
            break;

        case 2:
            SPI2BUF = data;
            while(SPI2STATbits.SPIRBF == 0);
            temp = SPI2BUF;
            break;
    }
}

void SpiRxBytes(UI08_t id, UI08_t* buffer, UI16_t size)
{
    UI16_t i = 0;
    while (size > i)
    {
        buffer[i] = SpiRx(id);
        i++;
    }
}

void SpiTxBytes(UI08_t id, UI08_t* buffer, UI16_t size)
{
    UI16_t i = 0;
    while (size > i)
    {
        SpiTx(id, buffer[i]);
        i++;
    }
}