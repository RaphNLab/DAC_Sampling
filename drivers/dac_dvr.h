/*
 * dac_dvr.h
 *
 *  Created on: Oct 19, 2024
 *      Author: silvere
 */

#ifndef DRIVERS_DAC_DVR_H_
#define DRIVERS_DAC_DVR_H_

#include "global.h"
#include <libopencm3/stm32/dac.h>
#include <libopencm3/stm32/dma.h>


#define DAC_DATA_REG (0x40007400UL + 0x08)



extern const uint16_t sine_wave[32];
extern const uint8_t escalator[8];

void clock_setup(void);
void dac_setup(void);
void dma_setup(void);


#endif /* DRIVERS_DAC_DVR_H_ */
