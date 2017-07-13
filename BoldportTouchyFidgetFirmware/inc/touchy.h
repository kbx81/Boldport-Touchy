/**
 * @file touchy.h
 * @author Keith Burzinski kbx81x@gmail.com @kbx81
 * @date 2017-07-08
 */

#ifndef INC_TOUCHY_H_
#define INC_TOUCHY_H_

/**
 * define PWM channel registers to be used as "dimmers"
 */
#define DIMMER1 PCA0CPH0
#define DIMMER2 PCA0CPH1

/**
 * define LED bits used for the API
 */
#define LED_COUNT  6
#define LED1  0x01
#define LED2  0x02
#define LED3  0x04
#define LED4  0x08
#define LED5  0x10
#define LED6  0x20

/**
 * define button numbers used for the API
 */
#define BUTTON_COUNT  6
#define BUTTON1  0x01
#define BUTTON2  0x02
#define BUTTON3  0x04
#define BUTTON4  0x08
#define BUTTON5  0x10
#define BUTTON6  0x20

/**
 * define touch sensor IDs for the CSLib API
 */
#define TS_B1  0
#define TS_B2  1
#define TS_B3  4
#define TS_B4  8
#define TS_B5  3
#define TS_B6  2
#define TS_CS0 5
#define TS_CS1 6
#define TS_CS2 7


/*! \brief Gets the last state of all LEDs set through the Touchy LED API
 *
 * \return State of all LEDs (1 bit per LED)
 */
uint8_t TouchyReadLEDs(void);

/*! \brief Sets the state of all LEDs
 *
 * \param leds New state of all LEDs (1 bit per LED)
 */
void TouchySetLEDs(uint8_t leds);

/*! \brief Turns off the specified LEDs
 *
 * \param leds LEDs to turn off (1 bit per LED)
 */
void TouchyLEDOff(uint8_t leds);

/*! \brief Turns on the specified LEDs
 *
 * \param leds LEDs to turn on (1 bit per LED)
 */
void TouchyLEDOn(uint8_t leds);

/*! \brief Toggles the specified LEDs
 *
 * \param leds LEDs to toggle (1 bit per LED)
 */
void TouchyLEDToggle(uint8_t leds);

/*! \brief Sets intensity for LEDs where PWM is enabled
 */
void TouchySetLEDIntensity(uint8_t leds, uint8_t intensity);

/*! \brief Returns intensity of most significant LED requested
 */
uint8_t TouchyReadLEDIntensity(uint8_t leds);

/*! \brief Turns off all LEDs but does not update LED state
 *
 * \note Call TouchyLEDRefresh() to recover LED state upon wake up
 */
void TouchySleepLEDs(void);

/*! \brief Refreshes the state of all LEDs
 */
void TouchyLEDRefresh(void);

/*! \brief Refreshes the state of all of Touchy's buttons
 */
void TouchyButtonRefresh(void);

/*! \brief Returns the state of all of Touchy's buttons
 */
uint8_t TouchyReadButtons(void);

/*! \brief Returns buttons that have changed state (pressed or released) since the previous refresh
 */
uint8_t TouchyGetChangedButtons(void);

/*! \brief Returns buttons that have been pressed since the previous refresh
 */
uint8_t TouchyGetPressedButtons(void);

/*! \brief Returns buttons that have been released since the previous refresh
 */
uint8_t TouchyGetReleasedButtons(void);

/*! \brief Returns the angle of Touchy's circle slider (0 degrees is 12 o'clock, 90 degrees is 3 o'clock, etc.)
 */
uint16_t TouchyReadSlider(void);

/*! \brief Returns the relative change of Touchy's circle slider; clockwise = positive, counter-clockwise = negative
 */
int16_t TouchyReadSliderRelative(void);

/*! \brief Returns true if Touchy should sleep now (based on lack of activity on touch sensors)
 */
bool TouchySleepNow(void);


#endif /* INC_TOUCHY_H_ */
