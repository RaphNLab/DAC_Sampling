#include "drivers/timer_drv.h"
#include "drivers/uart_drv.h"
#include "drivers/led_driver.h"
#include "dac_dvr.h"

int main(void)
{
	timer_sleep_setup();
	serial_debug_setup();
	clock_setup();

	//dma_setup();
	dac_setup();

	uint8_t max_val1 = 8;
	uint8_t max_val2 = 32;

	uint16_t idx1 = 0;
	uint16_t idx2 = 0;
	while (1)
	{
		dac_load_data_buffer_single(DAC1, escalator[idx1], DAC_ALIGN_RIGHT8, DAC_CHANNEL1);
		dac_load_data_buffer_single(DAC1, sine_wave[idx2], DAC_ALIGN_RIGHT12, DAC_CHANNEL2);
		idx1++;
		idx2++;
		if(idx1 == max_val1)
		{
			idx1 = 0;
		}

		if(idx2 == max_val2)
		{
			idx2 = 0;
		}
		//__asm__("wfi");
	}
	return 0;
}
