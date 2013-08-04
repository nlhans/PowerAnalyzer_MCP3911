#include "mcp3911.h"
#include "spi.h"

void Mcp3911Init()
{
    Mcp3911WriteReg16(Mcp3911Phase, 0); // 0us phase difference Ch1 after Ch0.

    Mcp3911WriteReg8(Mcp3911Gain, GainBoost1 |
            GainCh1Pga_1 |
            GainCh0Pga_1);

    Mcp3911WriteReg16(Mcp3911StatusCom,
            StatusComModOut_None |
            StatusComDrCtrl_HighZ |
            StatusComDrMode_Both |
            StatusComAddrRdLoop_None |
            StatusComAddrWrLoop_None | 
            StatusComAdcWidth_Ch1_16_Ch0_16 |
            StatusComDisableOffsetCalibration | 
            StatusComDisableGainCalibration);

    Mcp3911WriteReg16(Mcp3911Config, ConfigAmClkPrescale_1 |
            ConfigOverSample_4096  |
            ConfigDither_Off |
            ConfigAutoZero_LowSpd |
            ConfigReset_None |
            ConfigShdn_None |
            ConfigVref_Int |
            ConfigClk_Crystal);

    MCP3911_CS_HIGH
}

void Mcp3911WriteReg24(UI08_t reg, UI32_t value)
{
    MCP3911_CS_LOW

    SpiTx(MCP3911_SPI_BUS, ((reg << 1) | Mcp3911WriteOp));
    
    SpiTx(MCP3911_SPI_BUS, value >> 16); // MSB
    SpiTx(MCP3911_SPI_BUS, value >> 8);  // NSB
    SpiTx(MCP3911_SPI_BUS, value);       // LSB

    MCP3911_CS_HIGH
}
void Mcp3911WriteReg16(UI08_t reg, UI16_t value)
{
    Mcp3911WriteReg8(reg, value >> 8);
    Mcp3911WriteReg8(reg+1, value & 0xFF);

    return;
    MCP3911_CS_LOW

    SpiTx(MCP3911_SPI_BUS, ((reg << 1) | Mcp3911WriteOp));

    SpiTx(MCP3911_SPI_BUS, 0xFF & (value >> 8));  // MSB
    SpiTx(MCP3911_SPI_BUS, 0xFF & value);       // LSB

    MCP3911_CS_HIGH
}
void Mcp3911WriteReg8(UI08_t reg, UI08_t value)
{
    MCP3911_CS_LOW

    SpiTx(MCP3911_SPI_BUS, ((reg << 1) | Mcp3911WriteOp));
    SpiTx(MCP3911_SPI_BUS, value);       // LSB

    MCP3911_CS_HIGH
}

UI32_t Mcp3911ReadReg24(UI08_t reg)
{
    return ((UI32_t)Mcp3911ReadReg8(reg) << 16) | (Mcp3911ReadReg8(reg+1) << 8) | Mcp3911ReadReg8(reg+2);
    UI32_t value = 0;

    MCP3911_CS_LOW

    SpiTx(MCP3911_SPI_BUS, ((reg << 1) | Mcp3911ReadOp));

    value = ((UI32_t) SpiRx(MCP3911_SPI_BUS) << 16);
    value = value | (SpiRx(MCP3911_SPI_BUS) << 8);
    value = value | (SpiRx(MCP3911_SPI_BUS));

    MCP3911_CS_HIGH

    return value;
}

UI16_t Mcp3911ReadReg16(UI08_t reg)
{
    return (Mcp3911ReadReg8(reg) << 8) | Mcp3911ReadReg8(reg+1);
    UI16_t value = 0;

    MCP3911_CS_LOW

    SpiTx(MCP3911_SPI_BUS, ((reg << 1) | Mcp3911ReadOp));

    value |= SpiRx(MCP3911_SPI_BUS) << 8;
    value |= SpiRx(MCP3911_SPI_BUS);

    MCP3911_CS_HIGH

    return value;
}

UI08_t Mcp3911ReadReg8(UI08_t reg)
{
    UI08_t value = 0;

    MCP3911_CS_LOW

    SpiTx(MCP3911_SPI_BUS, ((reg << 1) | Mcp3911ReadOp));

    value |= SpiRx(MCP3911_SPI_BUS);

    MCP3911_CS_HIGH

    return value;
}