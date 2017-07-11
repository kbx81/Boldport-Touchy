/**
 * @file main.h
 * @author Keith Burzinski kbx81x@gmail.com @kbx81
 * @date 2017-07-08
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#include <SI_EFM8SB1_Register_Enums.h>
#include <stdlib.h>
#include "InitDevice.h"
#include "circle_slider.h"

#include "tick.h"

void UpdateLed(uint16_t angle);
void SimpleDelay(uint32_t delayLen);

#endif
