#define MAIN_C

#include "stddefs.h"
#include "spi.h"
#include "uart.h"

#include <stdio.h>
#include "23lc1024.h"
#include "mcp3911.h"
#include "mcp6s26.h"
#include "insight.h"

_FBS(BWRP_WRPROTECT_OFF & BSS_NO_FLASH & RBS_NO_RAM)
_FSS(SWRP_WRPROTECT_OFF & SSS_NO_FLASH & RSS_NO_RAM)
_FGS(GWRP_OFF & GCP_OFF)
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF)
_FOSC(POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_OFF & FCKSM_CSECME)
_FWDT(WDTPOST_PS128 & WDTPRE_PR128 & WINDIS_OFF & FWDTEN_OFF)
_FPOR(FPWRT_PWR1 & ALTI2C_OFF)
_FICD(ICS_PGD2 & JTAGEN_OFF)

void dl()
{
    UI16_t i, j;

    for(i = 0; i < 250; i++)
    {
        for(j = 0; j < 250; j++);
    }
}

int main()
{
    UI08_t i =0;
    AD1PCFGL = 0xFFFF;

    SpiInit();
    UartInit();
    Mcp3911Init();
    Mcp6s26Init();
    UI08_t debugCnt = 0;

    while(1)
    {
        while ((Mcp3911ReadReg16(Mcp3911StatusCom) & StatusComDrStatus_Both) == StatusComDrStatus_Both);
        
        UI16_t ch0_value = Mcp3911ReadReg16(0);
        UI16_t ch1_value = Mcp3911ReadReg16(3);

        UartTx('$');
        UartTx('#');

        UartTx(ch0_value >> 8);
        UartTx(ch0_value & 0xFF);
        UartTx(00);
        UartTx(00);

        UartTx(ch1_value >> 8);
        UartTx(ch1_value & 0xFF);
        UartTx(00);
        UartTx(00);
    }
    return 0;
}
