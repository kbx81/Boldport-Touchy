/**
 * @file touchy.c
 * @author Keith Burzinski kbx81x@gmail.com @kbx81
 * @date 2017-07-08
 */
#include <SI_EFM8SB1_Register_Enums.h>
#include "touchy.h"
#include "circle_slider.h"

#include "cslib_config.h"
#include "cslib.h"

/**
 * define the LED pins
 */
SI_SBIT (LED1pin, SFR_P0, 0);
SI_SBIT (LED2pin, SFR_P2, 7);
SI_SBIT (LED3pin, SFR_P1, 6);
SI_SBIT (LED4pin, SFR_P1, 7);
SI_SBIT (LED5pin, SFR_P1, 0);
SI_SBIT (LED6pin, SFR_P0, 7);

static volatile uint8_t ledState = 0, intensity1 = 0, intensity2 = 0, buttonState = 0, previousButtonState = 0, buttonsChanged = 0, sleepCounter = 0;
static volatile uint16_t angle = 0, previousAngle = 0;


uint8_t TouchyReadLEDs(void)
{
	return ledState;
}


void TouchySetLEDs(uint8_t leds)
{
	// Make sure only existing LEDs are specified
	leds &= (1 << LED_COUNT) - 1;

	// Update the saved state of all LEDs with the requested changes.
	ledState = leds;

	TouchyLEDRefresh();
}


void TouchyLEDOff(uint8_t leds)
{
	// Update the saved state of all LEDs with the requested changes
	ledState &= ~leds;

	TouchyLEDRefresh();
}


void TouchyLEDOn(uint8_t leds)
{
	// Make sure only existing LEDs are specified
	leds &= (1 << LED_COUNT) - 1;

	// Update the saved state of all LEDs with the requested changes
	ledState |= leds;

	TouchyLEDRefresh();
}


void TouchyLEDToggle(uint8_t leds)
{
	// Make sure only existing LEDs are specified
	leds &= (1 << LED_COUNT) - 1;

	// Update the saved state of all LEDs with the requested changes
	ledState = (~ledState & leds) | (ledState & ~leds);

	TouchyLEDRefresh();
}


void TouchySetLEDIntensity(uint8_t leds, uint8_t intensity)
{
	if (leds & LED1)
	{
		intensity1 = intensity;
		if (intensity == 255)
		{
			PCA0CPM0 &= ~PCA0CPM0_ECOM__ENABLED;
		}
	}

	if (leds & LED6)
	{
		intensity2 = intensity;
		if (intensity == 255)
		{
			PCA0CPM1 &= ~PCA0CPM1_ECOM__ENABLED;
		}
	}

	TouchyLEDRefresh();
}


uint8_t TouchyReadLEDIntensity(uint8_t leds)
{
	uint8_t intensity = 0;

	if (leds & LED1)
	{
		intensity = intensity1;
	}

	if (leds & LED6)
	{
		intensity = intensity2;
	}

	return intensity;
}


void TouchySleepLEDs(void)
{
	LED1pin = LED2pin = LED3pin = LED4pin = LED5pin = LED6pin = true;
	PCA0CPH0 = PCA0CPH1 = 0;

	return;
}


void TouchyLEDRefresh(void)
{
	LED1pin = !((ledState >> 0) & 0x01);
	LED2pin = !((ledState >> 1) & 0x01);
	LED3pin = !((ledState >> 2) & 0x01);
	LED4pin = !((ledState >> 3) & 0x01);
	LED5pin = !((ledState >> 4) & 0x01);
	LED6pin = !((ledState >> 5) & 0x01);

	PCA0CPH0 = intensity1;
	PCA0CPH1 = intensity2;
}


void TouchyButtonRefresh(void)
{
	buttonState = 0;

	if (CSLIB_isSensorSingleActive(TS_B1)) {
		buttonState |= BUTTON1;
	}

	if (CSLIB_isSensorSingleActive(TS_B2)) {
		buttonState |= BUTTON2;
	}

	if (CSLIB_isSensorSingleActive(TS_B3)) {
		buttonState |= BUTTON3;
	}

	if (CSLIB_isSensorSingleActive(TS_B4)) {
		buttonState |= BUTTON4;
	}

	if (CSLIB_isSensorSingleActive(TS_B5)) {
		buttonState |= BUTTON5;
	}

	if (CSLIB_isSensorSingleActive(TS_B6)) {
		buttonState |= BUTTON6;
	}

	buttonsChanged = buttonState ^ previousButtonState;
	previousButtonState = buttonState;

	if (buttonState) {
		sleepCounter = 0;
	}

	// Check if sum of sensors is above a minimum threshold for better touch release behavior
	if (IsTouchQualified())
	{
		previousAngle = angle;

		// Perform the centroid algorithm to determine the wheel angle position
		// (0 degrees is 12 o'clock, 90 degrees is 3 o'clock)
		angle = CalculatePosition();

		sleepCounter = 0;
	}

	sleepCounter++;
}


uint8_t TouchyReadButtons(void)
{
	return buttonState;
}


uint8_t TouchyGetChangedButtons(void)
{
	return buttonsChanged;
}


uint8_t TouchyGetPressedButtons(void)
{
	return buttonState & buttonsChanged;
}


uint8_t TouchyGetReleasedButtons(void)
{
	return ~buttonState & buttonsChanged;
}


uint16_t TouchyReadSlider(void)
{
	return angle;
}


bool TouchySleepNow(void)
{
	if (sleepCounter >= DEF_COUNTS_BEFORE_SLEEP) {
		return true;
	}

	return false;
}
