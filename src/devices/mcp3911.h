#ifndef MCP3911_H
#define MCP3911_H

#include "stddefs.h"

#define MCP3911_CS_HIGH     PORTC |=  (1<<6);
#define MCP3911_CS_LOW      PORTC &= ~(1<<6);

#define MCP3911_SPI_BUS 1

typedef enum Mcp3911SpiOperations_e
{
    Mcp3911WriteOp = 0x00,
    Mcp3911ReadOp  = 0x01
} Mcp3911SpiOperations_t;

typedef enum Mcp3911RegisterMap_e
{
    Mcp3911Ch0 = 0x00,
    Mcp3911Ch1 = 0x03,

    Mcp3911Mod = 0x06,
    Mcp3911Phase = 0x07,
    Mcp3911Gain = 0x09,
    Mcp3911StatusCom = 0x0A,
    Mcp3911Config = 0x0C,

    // TODO: Add offcal/gaincal

} Mcp3911RegisterMap_t;

typedef enum Mcp3911GainBits_e
{
    GainBoost2    = 0xC0,
    GainBoost1    = 0x80,
    GainBoost0_66 = 0x40,
    GainBoost0_5  = 0x00,

    GainCh1Pga_32 = 0x28,
    GainCh1Pga_16 = 0x20,
    GainCh1Pga_8  = 0x18,
    GainCh1Pga_4  = 0x10,
    GainCh1Pga_2  = 0x08,
    GainCh1Pga_1  = 0x00,

    GainCh0Pga_32 = 0x05,
    GainCh0Pga_16 = 0x04,
    GainCh0Pga_8  = 0x03,
    GainCh0Pga_4  = 0x02,
    GainCh0Pga_2  = 0x01,
    GainCh0Pga_1  = 0x00,
} Mcp3911GainBits_t;

typedef enum Mcp3911StatusComBits_e
{
    StatusComModOut_Both = 0xC000,
    StatusComModOut_Ch1  = 0x8000,
    StatusComModOut_Ch0  = 0x4000,
    StatusComModOut_None = 0x0000,

    StatusComDrCtrl_HighZ       = 0x0000,
    StatusComDrCtrl_LogicHigh   = 0x1000,

    StatusComDrMode_Both        = 0x0C00,
    StatusComDrMode_Ch1         = 0x0800,
    StatusComDrMode_Ch0         = 0x0400,
    StatusComDrMode_None        = 0x0000,

            // read-only:
    StatusComDrStatus_Both = 0x0300,
    StatusComDrStatus_Ch1  = 0x0200,
    StatusComDrStatus_Ch0  = 0x0100,
    StatusComDrStatus_None = 0x0000,

    StatusComAddrRdLoop_CycleEntire    = 0x00C0,
    StatusComAddrRdLoop_Type           = 0x0080,
    StatusComAddrRdLoop_Group          = 0x0040,
    StatusComAddrRdLoop_None           = 0x0000,

    StatusComAddrWrLoop_CycleEntire  = 0x0020,
    StatusComAddrWrLoop_None         = 0x0000,

    StatusComAdcWidth_Ch1_24_Ch0_24    = 0x0018,
    StatusComAdcWidth_Ch1_24_Ch0_16    = 0x0010,
    StatusComAdcWidth_Ch1_16_Ch0_24    = 0x0008,
    StatusComAdcWidth_Ch1_16_Ch0_16    = 0x0000,

    StatusComEnableOffsetCalibration  = 0x0004,
    StatusComDisableOffsetCalibration = 0x0000,

    StatusComEnableGainCalibration  = 0x0002,
    StatusComDisableGainCalibration = 0x0000
}Mcp3911StatusComBits_t;

typedef enum Mcp3911ConfigBits_e
{
    ConfigAmClkPrescale_8 = 0xC000,
    ConfigAmClkPrescale_4 = 0x8000,
    ConfigAmClkPrescale_2 = 0x4000,
    ConfigAmClkPrescale_1 = 0x0000,

    ConfigOverSample_32   = 0x0000,
    ConfigOverSample_64   = 0x0800,
    ConfigOverSample_128  = 0x1000,
    ConfigOverSample_256  = 0x1800,
    ConfigOverSample_512  = 0x2000,
    ConfigOverSample_1024 = 0x2800,
    ConfigOverSample_2048 = 0x3000,
    ConfigOverSample_4096 = 0x3800,

    ConfigDither_Max = 0x0600,
    ConfigDither_Med = 0x0400,
    ConfigDither_Min = 0x0200,
    ConfigDither_Off = 0x0000,

    ConfigAutoZero_HighSpd = 0x0100,
    ConfigAutoZero_LowSpd = 0x0000,

    ConfigReset_Both = 0x00C0,
    ConfigReset_Ch1 = 0x0080,
    ConfigReset_Ch0 = 0x0040,
    ConfigReset_None = 0x0000,

    ConfigShdn_Both = 0x0030,
    ConfigShdn_Ch1  = 0x0020,
    ConfigShdn_Ch0  = 0x0010,
    ConfigShdn_None = 0x0000,

    ConfigVref_Ext = 0x0004,
    ConfigVref_Int = 0x0000,

    ConfigClk_Crystal = 0x0000,
    ConfigClk_Logic = 0x0002
} Mcp3911ConfigBits_t;


void Mcp3911Init();

UI32_t Mcp3911ReadReg24(UI08_t reg);
UI16_t Mcp3911ReadReg16(UI08_t reg);
UI08_t Mcp3911ReadReg8(UI08_t reg);

void Mcp3911WriteReg24(UI08_t reg, UI32_t value);
void Mcp3911WriteReg16(UI08_t reg, UI16_t value);
void Mcp3911WriteReg8(UI08_t reg, UI08_t value);

#endif