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

#define DELAY_LENGTH 70000

/**
 * @brief main program
 */
int main(void) {
	// call hardware initialization routine
	enter_DefaultMode_from_RESET();
	Tick_Init();

	// enable all interrupts
	IE |= IE_EA__ENABLED | IE_ET2__ENABLED;

	// blink LEDs at startup...just because it's fun
	TouchyLEDOn(LED3 | LED4);
	SimpleDelay(DELAY_LENGTH);

	TouchyLEDOn(LED2 | LED3 | LED4 | LED5);
	SimpleDelay(DELAY_LENGTH);

	TouchyLEDOn(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
	TouchySetLEDIntensity(LED1 | LED6, 255);
	SimpleDelay(DELAY_LENGTH);

	TouchyLEDOff(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
	TouchySetLEDIntensity(LED1 | LED6, 0);

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

		if (TouchySleepNow()) {
			TouchySleepLEDs();
		}
		else {
			UpdateLed(TouchyReadSlider());
			TouchyLEDToggle(TouchyGetPressedButtons() & (LED2 | LED3 | LED4 | LED5));

			if (TouchyGetPressedButtons() & BUTTON1) {
				TouchyLEDToggle(LED2 | LED3 | LED4 | LED5);
				TouchySetLEDIntensity(LED1, 255 - TouchyReadLEDIntensity(LED1));
				TouchySetLEDIntensity(LED6, 255 - TouchyReadLEDIntensity(LED6));
			}

			if (TouchyGetPressedButtons() & BUTTON6) {
				if (TouchyReadLEDs() || TouchyReadLEDIntensity(LED1) || TouchyReadLEDIntensity(LED6)) {
					TouchyLEDOff(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
					TouchySetLEDIntensity(LED1 | LED6, 0);
				}
				else {
					TouchyLEDOn(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
					TouchySetLEDIntensity(LED1 | LED6, 255);
				}
			}
		}
	}
}


// Update the LED brightness based on angle
// angle [0, 359] => intensity [0, 255]
void UpdateLed(uint16_t angle)
{
	static uint8_t lastIntensity = 0;

	// 256 / 360 reduces to 32 / 45
	uint8_t intensity = angle * 32 / 45;

	if (intensity != lastIntensity) {
		TouchySetLEDIntensity(LED1, intensity);
		TouchySetLEDIntensity(LED6, 255-intensity);
		lastIntensity = intensity;
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
