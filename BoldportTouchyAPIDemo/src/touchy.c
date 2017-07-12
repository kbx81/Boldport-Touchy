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

static uint16_t angle = 0, previousAngle = 0;
static uint8_t ledState = 0, buttonState = 0, previousButtonState = 0, buttonsChanged = 0, sleepCounter = 0;
#ifdef DIMMER1
static uint8_t intensity1 = 0;
#endif
#ifdef DIMMER2
static uint8_t intensity2 = 0;
#endif


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

#ifdef DIMMER1
	intensity1 = 0;

	if (leds & LED1) {
		intensity1 = 255;
	}
#endif
#ifdef DIMMER2
	intensity2 = 0;

	if (leds & LED6) {
		intensity2 = 255;
	}
#endif

	TouchyLEDRefresh();
}


void TouchyLEDOff(uint8_t leds)
{
	// Update the saved state of all LEDs with the requested changes
	ledState &= ~leds;

#ifdef DIMMER1
	if (leds & LED1) {
		intensity1 = 0;
	}
#endif
#ifdef DIMMER2
	if (leds & LED6) {
		intensity2 = 0;
	}
#endif
	TouchyLEDRefresh();
}


void TouchyLEDOn(uint8_t leds)
{
	// Make sure only existing LEDs are specified
	leds &= (1 << LED_COUNT) - 1;

	// Update the saved state of all LEDs with the requested changes
	ledState |= leds;

#ifdef DIMMER1
	if (leds & LED1) {
		intensity1 = 255;
	}
#endif
#ifdef DIMMER2
	if (leds & LED6) {
		intensity2 = 255;
	}
#endif
	TouchyLEDRefresh();
}


void TouchyLEDToggle(uint8_t leds)
{
	// Make sure only existing LEDs are specified
	leds &= (1 << LED_COUNT) - 1;

	// Update the saved state of all LEDs with the requested changes
	ledState = (~ledState & leds) | (ledState & ~leds);

#ifdef DIMMER1
	if (leds & LED1) {
		intensity1 = 255 - intensity1;
	}
#endif
#ifdef DIMMER2
	if (leds & LED6) {
		intensity2 = 255 - intensity2;
	}
#endif
	TouchyLEDRefresh();
}


void TouchySetLEDIntensity(uint8_t leds, uint8_t intensity)
{
#ifdef DIMMER1
	if (leds & LED1)
	{
		intensity1 = intensity;

		if (intensity) {
			ledState |= LED1;
		}
		else {
			ledState &= ~LED1;
		}

		if (intensity == 255)
		{
			PCA0CPM0 &= ~PCA0CPM0_ECOM__ENABLED;
		}
	}
#endif
#ifdef DIMMER2
	if (leds & LED6)
	{
		intensity2 = intensity;

		if (intensity) {
			ledState |= LED6;
		}
		else {
			ledState &= ~LED6;
		}

		if (intensity == 255)
		{
			PCA0CPM1 &= ~PCA0CPM1_ECOM__ENABLED;
		}
	}
#endif
	TouchyLEDRefresh();
}


uint8_t TouchyReadLEDIntensity(uint8_t leds)
{
	uint8_t intensity = 0;

#ifdef DIMMER1
	if (leds & LED1)
	{
		intensity = intensity1;
	}
#endif
#ifdef DIMMER2
	if (leds & LED6)
	{
		intensity = intensity2;
	}
#endif
	return intensity;
}


void TouchySleepLEDs(void)
{
	LED1pin = LED2pin = LED3pin = LED4pin = LED5pin = LED6pin = true;

#ifdef DIMMER1
	DIMMER1 = 0;
#endif
#ifdef DIMMER2
	DIMMER2 = 0;
#endif

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

#ifdef DIMMER1
	DIMMER1 = intensity1;
#endif
#ifdef DIMMER2
	DIMMER2 = intensity2;
#endif
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


int16_t TouchyReadSliderRelative(void)
{
	if (angle - previousAngle > 180)
	{
		return angle - previousAngle - 360;
	}

	if (previousAngle - angle > 180) {
		return angle - previousAngle + 360;
	}

	return angle - previousAngle;
}


bool TouchySleepNow(void)
{
	if (sleepCounter >= DEF_COUNTS_BEFORE_SLEEP) {
		return true;
	}

	return false;
}
