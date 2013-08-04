#include "mcp6s26.h"
#include "spi.h"

void Mcp6s26Init()
{
    MCP6S26_CS_HIGH
    
    Mcp6s26SetChannel(4);
    Mcp6s26SetGain(Gain_4);
}

void Mcp6s26SetGain(Mcp6s26Gain_t gain)
{
    MCP6S26_CS_LOW

    SpiTx(MCP6S26_SPI_BUS, 0x40); // M1 = 1, A0 = 0
    SpiTx(MCP6S26_SPI_BUS, 1);

    MCP6S26_CS_HIGH
            
}

void Mcp6s26SetChannel(UI08_t channel)
{
    //
    MCP6S26_CS_LOW

    SpiTx(MCP6S26_SPI_BUS, 0x41); // M1 = 1, A0 = 1
    SpiTx(MCP6S26_SPI_BUS, channel);

    MCP6S26_CS_HIGH
            
}