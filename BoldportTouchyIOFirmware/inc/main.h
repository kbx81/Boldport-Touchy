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

// #define ACTIVITY_LED	LED6
#define UART_BUFFERSIZE	4
#define RX_TIMEOUT		32

// flag bits used...to indicate things
#define RXERROR	0x20
#define TXERROR	0x40
#define SOF		0x80

extern uint8_t flags, rxTimer, rxBuffer[], txBuffer[];
extern bool rxBufferReady, txReady;

void SimpleDelay(uint32_t delayLen);

#endif
