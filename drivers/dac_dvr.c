/*
 * dac_dvr.c
 *
 *  Created on: Oct 19, 2024
 *      Author: silvere
 */

#include "dac_dvr.h"



const uint16_t sine_wave[32] =
{
	2047, 2447, 2831, 3185, 3498, 3750, 3939, 4056, 4095, 4056,
	3939, 3750, 3495, 3185, 2831, 2447, 2047, 1647, 1263, 909,
	599, 344, 155, 38, 0, 38, 155, 344, 599, 909, 1263, 1647
};

const uint8_t escalator[8] =
{
	0x0, 0x33, 0x66, 0x99, 0xCC, 0xFF
};

void clock_setup(void)
{
    rcc_clock_setup_pll(&rcc_clock_config[RCC_CLOCK_VRANGE1_HSI_PLL_32MHZ]);
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_DAC);
    rcc_periph_clock_enable(RCC_DMA1);
}

void dac_setup(void)
{
	gpio_mode_setup(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, (GPIO4|GPIO5));

	//dac_buffer_enable(DAC1, DAC_CHANNEL1);
	dac_buffer_enable(DAC1, DAC_CHANNEL2);

	//dac_set_waveform_characteristics(DAC1, DAC_CHANNEL1, 1000);
	//dac_set_waveform_generation(DAC1, DAC_CHANNEL1, DAC_WAVE_TRIANGLE);
	/*dac_set_trigger_source(DAC1, DAC_CR_TSEL1_T4);

	dac_trigger_enable(DAC1, DAC_CHANNEL1);
	dac_dma_enable(DAC1, DAC_CHANNEL1);
	dac_enable(DAC1, DAC_CHANNEL1);*/

	dac_set_trigger_source(DAC1, DAC_CR_TSEL2_T4);
	dac_trigger_enable(DAC1, DAC_CHANNEL2);
	dac_dma_enable(DAC1, DAC_CHANNEL2);
	dac_enable(DAC1, DAC_CHANNEL2);
}

void dma_setup(void)
{
	//nvic_enable_irq(NVIC_DMA1_CHANNEL2_IRQ);
	//nvic_enable_irq(NVIC_DMA1_CHANNEL3_IRQ);

	/*dma_channel_reset(DMA1, DMA_CHANNEL2);
	dma_set_peripheral_address(DMA1, DMA_CHANNEL2, (uint32_t)DAC_8BIT_DATA_REG);
	dma_set_memory_address(DMA1, DMA_CHANNEL2, (uint32_t)escalator);
	dma_set_number_of_data(DMA1, DMA_CHANNEL2, 8);
	dma_set_read_from_memory(DMA1, DMA_CHANNEL2);
	dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL2);
	dma_set_peripheral_size(DMA1, DMA_CHANNEL2, DMA_CCR_PSIZE_8BIT);
	dma_set_memory_size(DMA1, DMA_CHANNEL2, DMA_CCR_MSIZE_8BIT);
	dma_set_priority(DMA1, DMA_CHANNEL2, DMA_CCR_PL_MEDIUM);
	dma_enable_circular_mode(DMA1, DMA_CHANNEL2);
	dma_enable_transfer_complete_interrupt(DMA1, DMA_CHANNEL2);
	dma_enable_channel(DMA1, DMA_CHANNEL2);*/

	dma_channel_reset(DMA1, DMA_CHANNEL3);
	dma_set_peripheral_address(DMA1, DMA_CHANNEL3, (uint32_t)DAC_16BIT_DATA_REG);
	dma_set_memory_address(DMA1, DMA_CHANNEL3, (uint32_t)sine_wave);
	dma_set_number_of_data(DMA1, DMA_CHANNEL3, 32);
	dma_set_read_from_memory(DMA1, DMA_CHANNEL3);
	dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL3);
	dma_set_peripheral_size(DMA1, DMA_CHANNEL3, DMA_CCR_PSIZE_16BIT);
	dma_set_memory_size(DMA1, DMA_CHANNEL3, DMA_CCR_MSIZE_16BIT);
	dma_set_priority(DMA1, DMA_CHANNEL3, DMA_CCR_PL_LOW);
	dma_enable_circular_mode(DMA1, DMA_CHANNEL3);
	dma_enable_transfer_complete_interrupt(DMA1, DMA_CHANNEL3);
	dma_enable_channel(DMA1, DMA_CHANNEL3);
}





