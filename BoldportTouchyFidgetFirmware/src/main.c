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

#define MAX_SPEED 80
#define BREAKAWAY_CYCLES 80
#define DELAY_LENGTH 60000

/**
 * @brief main program
 */
int main(void) {
	uint8_t fidgetMode = 0, selectedMode = 0, sliderLevel = 0, ledState = 0, ledIntensity = 0, breakawayCounter = 0;
	int8_t levelOffset = 0, movementRate = MAX_SPEED / 2, movementTimer = 0;

	// call hardware initialization routine
	enter_DefaultMode_from_RESET();
	Tick_Init();

	// enable all interrupts
	IE |= IE_EA__ENABLED | IE_ET2__ENABLED;

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

		levelOffset = TouchyReadSliderRelative();

		if (TouchySleepNow()) {
			TouchySleepLEDs();
		}
		else {
			// check button 1, if it's active we increment our counter so we can
			//  eventually break out of whatever mode we're in and revert to the main menu
			if (TouchyReadButtons() & BUTTON1) {
				breakawayCounter++;

				if (breakawayCounter > BREAKAWAY_CYCLES) {
					breakawayCounter = 0;
					fidgetMode = 7;
					TouchyLEDOff(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
				}
			}
			else {
				breakawayCounter = 0;
			}

			switch (fidgetMode) {
			case 1:
				TouchySetLEDs(TouchyReadButtons());

				break;

			case 2:
				levelOffset /= 32;
				ledIntensity += levelOffset;

				if (levelOffset) {
					TouchySetLEDIntensity(LED1, ledIntensity);
					TouchySetLEDIntensity(LED6, 255-ledIntensity);
				}

				TouchyLEDToggle(TouchyGetPressedButtons() & (LED2 | LED3 | LED4 | LED5));

				if (TouchyGetPressedButtons() & BUTTON1) {
					TouchyLEDToggle(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
				}

				if (TouchyGetPressedButtons() & BUTTON6) {
					if (TouchyReadLEDs()) {
						TouchyLEDOff(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
					}
					else {
						TouchyLEDOn(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
					}
				}
				break;

			case 3:
				TouchyLEDToggle(TouchyGetPressedButtons());

				ledState = TouchyReadLEDs();

				if (levelOffset > 0) {
					ledState = ledState << 1;
				}
				if (levelOffset < 0) {
					ledState = ledState >> 1;
				}

				if (levelOffset) {
					TouchySetLEDs(ledState);
				}
				break;

			case 4:
				if (levelOffset > 0 && movementRate < MAX_SPEED) {
					movementRate++;
				}
				if (levelOffset < 0 && movementRate > -MAX_SPEED) {
					movementRate--;
				}

				ledState = TouchyReadLEDs();

				if (movementTimer++ > MAX_SPEED - abs(movementRate)) {
					movementTimer = 0;

					if (movementRate > 0) {
						ledState = ledState << 1;
					}
					if (movementRate < 0) {
						ledState = ledState >> 1;
					}
				}

				ledState |= TouchyReadButtons();

				TouchySetLEDs(ledState);

				break;

			case 5:
				if (TouchyReadButtons() || IsTouchQualified()) {
					ledIntensity++;
				}
				if (levelOffset || TouchyGetChangedButtons()) {
					ledIntensity += TouchyReadSlider() + movementRate;

					TouchySetLEDs(ledIntensity);
				}
				break;

			case 6:
				levelOffset /= 32;
				ledIntensity += levelOffset;
				ledIntensity |= TouchyGetPressedButtons();

				if (levelOffset || TouchyGetPressedButtons()) {
					TouchySetLEDs(ledIntensity);
				}
				break;

			case 7:
				if (TouchyReadButtons()) {
					TouchyLEDToggle(LED1 | LED2 | LED3 | LED4 | LED5 | LED6);
					SimpleDelay(25);
				}
				else {
					fidgetMode = 0;
				}
				break;

			default:
				levelOffset /= 16;

				if (sliderLevel + levelOffset > 254) {
					sliderLevel = 255;
				}
				else if (sliderLevel + levelOffset < 1) {
					sliderLevel = 0;
				}
				else {
					sliderLevel += levelOffset;
				}

				// we need six regions, so 256 / 6 ...but we have to cheat a little because integers
				selectedMode = sliderLevel / (258 / 6);

				TouchySetLEDs(1 << selectedMode);

				if (TouchyReadButtons() & BUTTON1) {
					fidgetMode = selectedMode + 1;
				}
				break;
			}
		}
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
