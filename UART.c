
#include "UART.h"
#include "stddefs.h"
#include "pps.h"


void  Uart_Init(UI08_t id)
{
    switch(id)
    {
        case 1:
            U1BRG = 3;// CLOCK_PERIPHERAL / (16* (UI32_t)9600 )-1;
            U1MODE	=	0x8000;
            U1STA	=	0x8400;
            IFS0bits.U1RXIF = 0;
            break;

        case 2:
            U2BRG = 23;//CLOCK_PERIPHERAL / (16* (UI32_t)9600 )-1;
            U2MODE	=	0x8000;
            U2STA	=	0x8400;
            IFS1bits.U2RXIF = 0;
            break;
    }
}

void  Uart_Tx(UI08_t id, UI08_t* buf, UI16_t length)
{
    // Polled
    UI16_t i = 0;
    while(length>i)
    {
        Uart_TxByte(id, *(buf+i));
        i++;
    }
}
void  Uart_Rx(UI08_t id, UI08_t* buf, UI16_t length)
{
    // Polled
    UI16_t i = 0;
    while(length>i)
    {
        *(buf+i) = Uart_RxByte(id);
        i++;
    }
}

void Uart_TxByte(UI08_t id, UI08_t b)
{
    switch(id)
    {
        case 1:
            while(U1STAbits.UTXBF == 1);
            U1TXREG = b;
            break;
        case 2:
            while(U2STAbits.UTXBF == 1);
            U2TXREG = b;
            break;
    }
}

UI08_t Uart_RxByte(UI08_t id)
{
    UI08_t b=0;
    switch(id)
    {
        case 1:
            while(IFS0bits.U1RXIF==0);
            b=U1RXREG;
            IFS0bits.U1RXIF=0;
            break;

        case 2:
            while(IFS1bits.U2RXIF==0);
            b=U2RXREG;
            IFS1bits.U2RXIF=0;
            break;
    }
    return b;
}

