#ifndef TRITON_UART_H
#define TRITON_UART_H

#include "stddefs.h"


void  Uart_Init(UI08_t id);
void  Uart_Tx(UI08_t id, UI08_t* buf, UI16_t length);
void  Uart_Rx(UI08_t id, UI08_t* buf, UI16_t length);

UI08_t Uart_RxByte(UI08_t id);
void Uart_TxByte(UI08_t id, UI08_t b);

#endif
