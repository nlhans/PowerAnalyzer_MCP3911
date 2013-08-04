
#ifndef UART_H
#define UART_H

#include "stddefs.h"



void UartInit();
void UartTx(UI08_t byte);
void UartTxString(char* str);

#endif