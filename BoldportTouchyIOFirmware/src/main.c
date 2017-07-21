/**
 * @file main.c
 * @author Keith Burzinski kbx81x@gmail.com @kbx81
 * @date 2017-07-08
 */
#include "main.h"
#include "touchy.h"
#include "stdlib.h"

// $[Generated Includes]
#include "cslib_config.h"
#include "cslib.h"
// [Generated Includes]$

/**
 * MUX_VALUE_ARRAY In inc/config/cslib_hwconfig.h should be set to this when updating the configurator
 */
// #define MUX_VALUE_ARRAY 0x0A, 0x0B, 0x0C, 0x02, 0x01, 0x09, 0x03, 0x06, 0x0D,


/**
 * Global variables ...yeah, I know...I know...
 */
uint8_t flags = SOF | RXERROR, rxBuffer[UART_BUFFERSIZE], txBuffer[UART_BUFFERSIZE];
volatile bool rxBufferReady = false, txReady = true;

/**
 * @brief main program
 */
int main(void) {
	uint16_t angle = 0;

	// call hardware initialization routine
	enter_DefaultMode_from_RESET();
	Tick_Init();

	// nifty little start-up blink-the-LEDs thing...so you can know it's alive
	TouchyLEDOn(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
	SimpleDelay(8000);
	TouchyLEDOff(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);

	// main application loop
	while (1) {
// $[Generated Run-time code]
		// -----------------------------------------------------------------------------
		// If low power features are enabled, this will either put the device into a low
		// power state until it is time to take another scan, or put the device into a
		// low-power sleep mode if no touches are active
		// -----------------------------------------------------------------------------
		CSLIB_lowPowerUpdate();

		// -----------------------------------------------------------------------------
		// Performs all scanning and data structure updates
		// -----------------------------------------------------------------------------
		CSLIB_update();

// [Generated Run-time code]$
		TouchyButtonRefresh();
#if DEF_SLEEP_MODE_ENABLE==1
		if (TouchySleepNow()) {
			TouchySleepLEDs();
		}
		else {
#endif
			if (txReady && (TouchyReadSliderRelative() || TouchyGetChangedButtons() || (flags & (TXERROR | RXERROR)))) {
				angle = TouchyReadSlider();
				txBuffer[3] = angle & 0xff;		// low byte
				txBuffer[2] = angle >> 8;		// high byte (well...bit...in this case...)
				txBuffer[1] = TouchyReadButtons();
				txBuffer[0] = SOF | flags;
				txReady = false;
				flags &= ~(RXERROR | TXERROR);	// clear the XXERROR bit(s) now that the state is buffered
				SCON0_TI = 1;		// Set transmit flag to 1 to begin transmission
				SimpleDelay(90);	// wait...because...I don't know why but everything breaks if we don't :smh:
			}

			if (rxBufferReady) {
				TouchySetLEDs(rxBuffer[1]);

				if (rxBuffer[0] & LED1) {
					TouchySetLEDIntensity(LED1, rxBuffer[2]);
				}

				if (rxBuffer[0] & LED6) {
					TouchySetLEDIntensity(LED6, rxBuffer[3]);
				}
			}
#if DEF_SLEEP_MODE_ENABLE==1
		}
#endif
	}
}


// Create a simple delay
void SimpleDelay(uint32_t delayLen)
{
	volatile uint32_t i = 0;

	for (i = 0; i < delayLen; i++)
	{
	}
}
