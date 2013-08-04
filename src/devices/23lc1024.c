#include "stddefs.h"
#include "23lc1024.h"
#include "spi.h"
#include "insight.h"

typedef enum sram23lc1024Modes_e
{
    sramRead                = 0b00000011, // 0x03
    sramWrite               = 0b00000010, // 0x02
    sramEdio                = 0b00111011, // 0x3B
    sramEqio                = 0b00111000, // 0x38
    sramRstio               = 0b11111111, // 0xFF
    sramReadRegister        = 0b00000101, // 0x05
    sramWriteRegister       = 0b00000001  // 0x01
} sram23lc1024Modes_t;

void sram_23lc1024_init()
{
    // I use PORTA #10
    TRISA &= ~(1<<10);
    CS_23LC1024_HIGH;

    INSIGHT(23LC1024_INIT);
}

void sram_23lc1024_read(UI08_t bank, UI16_t address, UI08_t* bf,  UI16_t size)
{
    // Set pin low
    CS_23LC1024_LOW;

    // write mode
    SpiTx(2, sramRead); // read

    // write address
    SpiTx(2, bank);
    SpiTx(2, address>>8);
    SpiTx(2, address&0xFF);

    // Read data
    SpiRxBytes(2, bf, size);

    CS_23LC1024_HIGH;

    INSIGHT(23LC1024_READ, address, size);

}

void sram_23lc1024_write(UI08_t bank, UI16_t address, UI08_t* bf,  UI16_t size)
{
    // Set pin low
    CS_23LC1024_LOW;

    // write mode
    SpiTx(2, sramWrite); // read

    // write address
    SpiTx(2, bank);
    SpiTx(2, address>>8);
    SpiTx(2, address&0xFF);

    // Read data
    SpiTxBytes(2, bf, size);

    CS_23LC1024_HIGH;

    INSIGHT(23LC1024_WRITE, address, size);

}
 