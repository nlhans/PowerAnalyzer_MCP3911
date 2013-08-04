/* 
 * File:   spi.h
 * Author: Hans
 *
 * Created on March 9, 2013, 1:32 PM
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stddefs.h"

void SpiInit();

UI08_t SpiRx(UI08_t id);
void SpiTx(UI08_t id, UI08_t data);
void SpiRxBytes(UI08_t id, UI08_t* buffer, UI16_t size);
void SpiTxBytes(UI08_t id, UI08_t* buffer, UI16_t size);
#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

