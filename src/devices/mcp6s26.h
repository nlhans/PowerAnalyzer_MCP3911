#ifndef MCP6S26_H
#define MCP6S26_H

#include "stddefs.h"

#define MCP6S26_SPI_BUS 2

#define MCP6S26_CS_HIGH     PORTB |=  (1<<13);
#define MCP6S26_CS_LOW      PORTB &= ~(1<<13);

typedef enum Mcp6s26Gain_e
{
    Gain_1 = 0,
    Gain_2 = 1,
    Gain_4 = 2,
    Gain_5 = 3,
    Gain_8 = 4,
    Gain_10 = 5,
    Gain_16 = 6,
    Gain_32 = 7,
} Mcp6s26Gain_t;

void Mcp6s26Init();
void Mcp6s26SetGain(Mcp6s26Gain_t gain);
void Mcp6s26SetChannel(UI08_t channel);

#endif