//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8UB2_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS


// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	PCA_0_enter_DefaultMode_from_RESET();
	PCACH_0_enter_DefaultMode_from_RESET();
	PCACH_1_enter_DefaultMode_from_RESET();
	PCACH_2_enter_DefaultMode_from_RESET();
	PORTS_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PORTS_2_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	ADC_0_enter_DefaultMode_from_RESET();
	VREF_0_enter_DefaultMode_from_RESET();
	HFOSC_0_enter_DefaultMode_from_RESET();
	CLOCK_0_enter_DefaultMode_from_RESET();
	TIMER01_0_enter_DefaultMode_from_RESET();
	TIMER16_3_enter_DefaultMode_from_RESET();
	TIMER_SETUP_0_enter_DefaultMode_from_RESET();
	SPI_0_enter_DefaultMode_from_RESET();
	INTERRUPT_0_enter_DefaultMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$


}


//================================================================================
// PCA_0_enter_DefaultMode_from_RESET
//================================================================================
extern void PCA_0_enter_DefaultMode_from_RESET(void) {
	// $[PCA0MD - PCA Mode]
	/*
	// WDTE (Watchdog Timer Enable) = DISABLED (Disable Watchdog Timer.)
	// CPS (PCA Counter/Timer Pulse Select) = SYSCLK_DIV_12 (System clock
	//     divided by 12.)
	// CIDL (PCA Counter/Timer Idle Control) = NORMAL (PCA continues to
	//     function normally while the system controller is in Idle Mode.)
	// ECF (PCA Counter/Timer Overflow Interrupt Enable) = OVF_INT_DISABLED
	//     (Disable the CF interrupt.)
	// WDTE (Watchdog Timer Enable) = DISABLED (Disable Watchdog Timer.)
	// WDLCK (Watchdog Timer Lock) = UNLOCKED (Watchdog Timer Enable
	//     unlocked.)
	*/
	SFRPAGE = 0x00;
	PCA0MD &= ~PCA0MD_WDTE__BMASK;
	PCA0MD = PCA0MD_CPS__SYSCLK_DIV_12 | PCA0MD_CIDL__NORMAL | PCA0MD_ECF__OVF_INT_DISABLED
		 | PCA0MD_WDTE__DISABLED | PCA0MD_WDLCK__UNLOCKED;
	// [PCA0MD - PCA Mode]$

	// $[PCA0H - PCA Counter/Timer High Byte]
	// [PCA0H - PCA Counter/Timer High Byte]$

	// $[PCA0L - PCA Counter/Timer Low Byte]
	// [PCA0L - PCA Counter/Timer Low Byte]$

	// $[PCA0CN0 - PCA Control 0]
	/*
	// CR (PCA Counter/Timer Run Control) = RUN (Start the PCA Counter/Timer
	//     running.)
	*/
	PCA0CN0 |= PCA0CN0_CR__RUN;
	// [PCA0CN0 - PCA Control 0]$


}

//================================================================================
// PCACH_0_enter_DefaultMode_from_RESET
//================================================================================
extern void PCACH_0_enter_DefaultMode_from_RESET(void) {
	uint8_t PCA0CN0_CR_save = PCA0CN0 & PCA0CN0_CR__BMASK;
	PCA0CN0 |= PCA0CN0_CR_save;

	// $[PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]
	/*
	// CAPN (Channel 0 Capture Negative Function Enable) = DISABLED (Disable
	//     negative edge capture.)
	// ECCF (Channel 0 Capture/Compare Flag Interrupt Enable) = DISABLED
	//     (Disable CCF0 interrupts.)
	// MAT (Channel 0 Match Function Enable) = DISABLED (Disable match
	//     function.)
	// PWM16 (Channel 0 16-bit Pulse Width Modulation Enable) = 8_BIT (8-bit
	//     PWM selected.)
	// CAPP (Channel 0 Capture Positive Function Enable) = DISABLED (Disable
	//     positive edge capture.)
	// ECOM (Channel 0 Comparator Function Enable) = ENABLED (Enable
	//     comparator function.)
	// PWM (Channel 0 Pulse Width Modulation Mode Enable) = ENABLED (Enable
	//     PWM function.)
	// TOG (Channel 0 Toggle Function Enable) = DISABLED (Disable toggle
	//     function.)
	*/
	PCA0CPM0 = PCA0CPM0_CAPN__DISABLED | PCA0CPM0_ECCF__DISABLED | PCA0CPM0_MAT__DISABLED
		 | PCA0CPM0_PWM16__8_BIT | PCA0CPM0_CAPP__DISABLED | PCA0CPM0_ECOM__ENABLED
		 | PCA0CPM0_PWM__ENABLED | PCA0CPM0_TOG__DISABLED;
	// [PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]$

	// $[PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]
	// [PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]$

	// $[PCA0CPH0 - PCA Channel 0 Capture Module High Byte]
	// [PCA0CPH0 - PCA Channel 0 Capture Module High Byte]$


}

//================================================================================
// PCACH_1_enter_DefaultMode_from_RESET
//================================================================================
extern void PCACH_1_enter_DefaultMode_from_RESET(void) {
	uint8_t PCA0CN0_CR_save = PCA0CN0 & PCA0CN0_CR__BMASK;
	PCA0CN0 |= PCA0CN0_CR_save;

	// $[PCA0CPM1 - PCA Channel 1 Capture/Compare Mode]
	/*
	// CAPN (Channel 1 Capture Negative Function Enable) = DISABLED (Disable
	//     negative edge capture.)
	// ECCF (Channel 1 Capture/Compare Flag Interrupt Enable) = DISABLED
	//     (Disable CCF1 interrupts.)
	// MAT (Channel 1 Match Function Enable) = DISABLED (Disable match
	//     function.)
	// PWM16 (Channel 1 16-bit Pulse Width Modulation Enable) = 8_BIT (8-bit
	//     PWM selected.)
	// CAPP (Channel 1 Capture Positive Function Enable) = DISABLED (Disable
	//     positive edge capture.)
	// ECOM (Channel 1 Comparator Function Enable) = ENABLED (Enable
	//     comparator function.)
	// PWM (Channel 1 Pulse Width Modulation Mode Enable) = ENABLED (Enable
	//     PWM function.)
	// TOG (Channel 1 Toggle Function Enable) = DISABLED (Disable toggle
	//     function.)
	*/
	PCA0CPM1 = PCA0CPM1_CAPN__DISABLED | PCA0CPM1_ECCF__DISABLED | PCA0CPM1_MAT__DISABLED
		 | PCA0CPM1_PWM16__8_BIT | PCA0CPM1_CAPP__DISABLED | PCA0CPM1_ECOM__ENABLED
		 | PCA0CPM1_PWM__ENABLED | PCA0CPM1_TOG__DISABLED;
	// [PCA0CPM1 - PCA Channel 1 Capture/Compare Mode]$

	// $[PCA0CPL1 - PCA Channel 1 Capture Module Low Byte]
	// [PCA0CPL1 - PCA Channel 1 Capture Module Low Byte]$

	// $[PCA0CPH1 - PCA Channel 1 Capture Module High Byte]
	// [PCA0CPH1 - PCA Channel 1 Capture Module High Byte]$


}

//================================================================================
// PCACH_2_enter_DefaultMode_from_RESET
//================================================================================
extern void PCACH_2_enter_DefaultMode_from_RESET(void) {
	uint8_t PCA0CN0_CR_save = PCA0CN0 & PCA0CN0_CR__BMASK;
	PCA0CN0 |= PCA0CN0_CR_save;

	// $[PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]
	/*
	// CAPN (Channel 2 Capture Negative Function Enable) = DISABLED (Disable
	//     negative edge capture.)
	// ECCF (Channel 2 Capture/Compare Flag Interrupt Enable) = DISABLED
	//     (Disable CCF2 interrupts.)
	// MAT (Channel 2 Match Function Enable) = DISABLED (Disable match
	//     function.)
	// PWM16 (Channel 2 16-bit Pulse Width Modulation Enable) = 8_BIT (8-bit
	//     PWM selected.)
	// CAPP (Channel 2 Capture Positive Function Enable) = DISABLED (Disable
	//     positive edge capture.)
	// ECOM (Channel 2 Comparator Function Enable) = ENABLED (Enable
	//     comparator function.)
	// PWM (Channel 2 Pulse Width Modulation Mode Enable) = ENABLED (Enable
	//     PWM function.)
	// TOG (Channel 2 Toggle Function Enable) = DISABLED (Disable toggle
	//     function.)
	*/
	PCA0CPM2 = PCA0CPM2_CAPN__DISABLED | PCA0CPM2_ECCF__DISABLED | PCA0CPM2_MAT__DISABLED
		 | PCA0CPM2_PWM16__8_BIT | PCA0CPM2_CAPP__DISABLED | PCA0CPM2_ECOM__ENABLED
		 | PCA0CPM2_PWM__ENABLED | PCA0CPM2_TOG__DISABLED;
	// [PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]$

	// $[PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]
	// [PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]$

	// $[PCA0CPH2 - PCA Channel 2 Capture Module High Byte]
	// [PCA0CPH2 - PCA Channel 2 Capture Module High Byte]$


}

//================================================================================
// PORTS_0_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTS_0_enter_DefaultMode_from_RESET(void) {
	// $[P0 - Port 0 Pin Latch]
	// [P0 - Port 0 Pin Latch]$

	// $[P0MDOUT - Port 0 Output Mode]
	/*
	// B0 (Port 0 Bit 0 Output Mode) = OPEN_DRAIN (P0.0 output is open-
	//     drain.)
	// B1 (Port 0 Bit 1 Output Mode) = PUSH_PULL (P0.1 output is push-pull.)
	// B2 (Port 0 Bit 2 Output Mode) = OPEN_DRAIN (P0.2 output is open-
	//     drain.)
	// B3 (Port 0 Bit 3 Output Mode) = OPEN_DRAIN (P0.3 output is open-
	//     drain.)
	// B4 (Port 0 Bit 4 Output Mode) = OPEN_DRAIN (P0.4 output is open-
	//     drain.)
	// B5 (Port 0 Bit 5 Output Mode) = OPEN_DRAIN (P0.5 output is open-
	//     drain.)
	// B6 (Port 0 Bit 6 Output Mode) = PUSH_PULL (P0.6 output is push-pull.)
	// B7 (Port 0 Bit 7 Output Mode) = OPEN_DRAIN (P0.7 output is open-
	//     drain.)
	*/
	P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__PUSH_PULL | P0MDOUT_B2__OPEN_DRAIN
		 | P0MDOUT_B3__OPEN_DRAIN | P0MDOUT_B4__OPEN_DRAIN | P0MDOUT_B5__OPEN_DRAIN
		 | P0MDOUT_B6__PUSH_PULL | P0MDOUT_B7__OPEN_DRAIN;
	// [P0MDOUT - Port 0 Output Mode]$

	// $[P0MDIN - Port 0 Input Mode]
	// [P0MDIN - Port 0 Input Mode]$

	// $[P0SKIP - Port 0 Skip]
	/*
	// B0 (Port 0 Bit 0 Skip) = SKIPPED (P0.0 pin is skipped by the
	//     crossbar.)
	// B1 (Port 0 Bit 1 Skip) = SKIPPED (P0.1 pin is skipped by the
	//     crossbar.)
	// B2 (Port 0 Bit 2 Skip) = SKIPPED (P0.2 pin is skipped by the
	//     crossbar.)
	// B3 (Port 0 Bit 3 Skip) = SKIPPED (P0.3 pin is skipped by the
	//     crossbar.)
	// B4 (Port 0 Bit 4 Skip) = SKIPPED (P0.4 pin is skipped by the
	//     crossbar.)
	// B5 (Port 0 Bit 5 Skip) = SKIPPED (P0.5 pin is skipped by the
	//     crossbar.)
	// B6 (Port 0 Bit 6 Skip) = NOT_SKIPPED (P0.6 pin is not skipped by the
	//     crossbar.)
	// B7 (Port 0 Bit 7 Skip) = NOT_SKIPPED (P0.7 pin is not skipped by the
	//     crossbar.)
	*/
	P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__SKIPPED | P0SKIP_B2__SKIPPED
		 | P0SKIP_B3__SKIPPED | P0SKIP_B4__SKIPPED | P0SKIP_B5__SKIPPED
		 | P0SKIP_B6__NOT_SKIPPED | P0SKIP_B7__NOT_SKIPPED;
	// [P0SKIP - Port 0 Skip]$


}

//================================================================================
// PORTS_1_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTS_1_enter_DefaultMode_from_RESET(void) {
	// $[P1 - Port 1 Pin Latch]
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	/*
	// B0 (Port 1 Bit 0 Output Mode) = PUSH_PULL (P1.0 output is push-pull.)
	// B1 (Port 1 Bit 1 Output Mode) = OPEN_DRAIN (P1.1 output is open-
	//     drain.)
	// B2 (Port 1 Bit 2 Output Mode) = OPEN_DRAIN (P1.2 output is open-
	//     drain.)
	// B3 (Port 1 Bit 3 Output Mode) = OPEN_DRAIN (P1.3 output is open-
	//     drain.)
	// B4 (Port 1 Bit 4 Output Mode) = PUSH_PULL (P1.4 output is push-pull.)
	// B5 (Port 1 Bit 5 Output Mode) = OPEN_DRAIN (P1.5 output is open-
	//     drain.)
	// B6 (Port 1 Bit 6 Output Mode) = PUSH_PULL (P1.6 output is push-pull.)
	// B7 (Port 1 Bit 7 Output Mode) = PUSH_PULL (P1.7 output is push-pull.)
	*/
	P1MDOUT = P1MDOUT_B0__PUSH_PULL | P1MDOUT_B1__OPEN_DRAIN | P1MDOUT_B2__OPEN_DRAIN
		 | P1MDOUT_B3__OPEN_DRAIN | P1MDOUT_B4__PUSH_PULL | P1MDOUT_B5__OPEN_DRAIN
		 | P1MDOUT_B6__PUSH_PULL | P1MDOUT_B7__PUSH_PULL;
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	/*
	// B0 (Port 1 Bit 0 Skip) = NOT_SKIPPED (P1.0 pin is not skipped by the
	//     crossbar.)
	// B1 (Port 1 Bit 1 Skip) = SKIPPED (P1.1 pin is skipped by the
	//     crossbar.)
	// B2 (Port 1 Bit 2 Skip) = SKIPPED (P1.2 pin is skipped by the
	//     crossbar.)
	// B3 (Port 1 Bit 3 Skip) = SKIPPED (P1.3 pin is skipped by the
	//     crossbar.)
	// B4 (Port 1 Bit 4 Skip) = SKIPPED (P1.4 pin is skipped by the
	//     crossbar.)
	// B5 (Port 1 Bit 5 Skip) = SKIPPED (P1.5 pin is skipped by the
	//     crossbar.)
	// B6 (Port 1 Bit 6 Skip) = NOT_SKIPPED (P1.6 pin is not skipped by the
	//     crossbar.)
	// B7 (Port 1 Bit 7 Skip) = NOT_SKIPPED (P1.7 pin is not skipped by the
	//     crossbar.)
	*/
	P1SKIP = P1SKIP_B0__NOT_SKIPPED | P1SKIP_B1__SKIPPED | P1SKIP_B2__SKIPPED
		 | P1SKIP_B3__SKIPPED | P1SKIP_B4__SKIPPED | P1SKIP_B5__SKIPPED
		 | P1SKIP_B6__NOT_SKIPPED | P1SKIP_B7__NOT_SKIPPED;
	// [P1SKIP - Port 1 Skip]$


}

//================================================================================
// PORTS_2_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTS_2_enter_DefaultMode_from_RESET(void) {
	// $[P2 - Port 2 Pin Latch]
	// [P2 - Port 2 Pin Latch]$

	// $[P2MDOUT - Port 2 Output Mode]
	/*
	// B0 (Port 2 Bit 0 Output Mode) = PUSH_PULL (P2.0 output is push-pull.)
	// B1 (Port 2 Bit 1 Output Mode) = OPEN_DRAIN (P2.1 output is open-
	//     drain.)
	// B2 (Port 2 Bit 2 Output Mode) = OPEN_DRAIN (P2.2 output is open-
	//     drain.)
	// B3 (Port 2 Bit 3 Output Mode) = OPEN_DRAIN (P2.3 output is open-
	//     drain.)
	// B4 (Port 2 Bit 4 Output Mode) = OPEN_DRAIN (P2.4 output is open-
	//     drain.)
	// B5 (Port 2 Bit 5 Output Mode) = OPEN_DRAIN (P2.5 output is open-
	//     drain.)
	// B6 (Port 2 Bit 6 Output Mode) = OPEN_DRAIN (P2.6 output is open-
	//     drain.)
	// B7 (Port 2 Bit 7 Output Mode) = OPEN_DRAIN (P2.7 output is open-
	//     drain.)
	*/
	P2MDOUT = P2MDOUT_B0__PUSH_PULL | P2MDOUT_B1__OPEN_DRAIN | P2MDOUT_B2__OPEN_DRAIN
		 | P2MDOUT_B3__OPEN_DRAIN | P2MDOUT_B4__OPEN_DRAIN | P2MDOUT_B5__OPEN_DRAIN
		 | P2MDOUT_B6__OPEN_DRAIN | P2MDOUT_B7__OPEN_DRAIN;
	// [P2MDOUT - Port 2 Output Mode]$

	// $[P2MDIN - Port 2 Input Mode]
	/*
	// B0 (Port 2 Bit 0 Input Mode) = DIGITAL (P2.0 pin is configured for
	//     digital mode.)
	// B1 (Port 2 Bit 1 Input Mode) = DIGITAL (P2.1 pin is configured for
	//     digital mode.)
	// B2 (Port 2 Bit 2 Input Mode) = DIGITAL (P2.2 pin is configured for
	//     digital mode.)
	// B3 (Port 2 Bit 3 Input Mode) = DIGITAL (P2.3 pin is configured for
	//     digital mode.)
	// B4 (Port 2 Bit 4 Input Mode) = DIGITAL (P2.4 pin is configured for
	//     digital mode.)
	// B5 (Port 2 Bit 5 Input Mode) = ANALOG (P2.5 pin is configured for
	//     analog mode.)
	// B6 (Port 2 Bit 6 Input Mode) = DIGITAL (P2.6 pin is configured for
	//     digital mode.)
	// B7 (Port 2 Bit 7 Input Mode) = DIGITAL (P2.7 pin is configured for
	//     digital mode.)
	*/
	P2MDIN = P2MDIN_B0__DIGITAL | P2MDIN_B1__DIGITAL | P2MDIN_B2__DIGITAL
		 | P2MDIN_B3__DIGITAL | P2MDIN_B4__DIGITAL | P2MDIN_B5__ANALOG
		 | P2MDIN_B6__DIGITAL | P2MDIN_B7__DIGITAL;
	// [P2MDIN - Port 2 Input Mode]$

	// $[P2SKIP - Port 2 Skip]
	/*
	// B0 (Port 2 Bit 0 Skip) = NOT_SKIPPED (P2.0 pin is not skipped by the
	//     crossbar.)
	// B1 (Port 2 Bit 1 Skip) = NOT_SKIPPED (P2.1 pin is not skipped by the
	//     crossbar.)
	// B2 (Port 2 Bit 2 Skip) = NOT_SKIPPED (P2.2 pin is not skipped by the
	//     crossbar.)
	// B3 (Port 2 Bit 3 Skip) = NOT_SKIPPED (P2.3 pin is not skipped by the
	//     crossbar.)
	// B4 (Port 2 Bit 4 Skip) = NOT_SKIPPED (P2.4 pin is not skipped by the
	//     crossbar.)
	// B5 (Port 2 Bit 5 Skip) = SKIPPED (P2.5 pin is skipped by the
	//     crossbar.)
	// B6 (Port 2 Bit 6 Skip) = NOT_SKIPPED (P2.6 pin is not skipped by the
	//     crossbar.)
	// B7 (Port 2 Bit 7 Skip) = NOT_SKIPPED (P2.7 pin is not skipped by the
	//     crossbar.)
	*/
	P2SKIP = P2SKIP_B0__NOT_SKIPPED | P2SKIP_B1__NOT_SKIPPED | P2SKIP_B2__NOT_SKIPPED
		 | P2SKIP_B3__NOT_SKIPPED | P2SKIP_B4__NOT_SKIPPED | P2SKIP_B5__SKIPPED
		 | P2SKIP_B6__NOT_SKIPPED | P2SKIP_B7__NOT_SKIPPED;
	// [P2SKIP - Port 2 Skip]$


}

//================================================================================
// PBCFG_0_enter_DefaultMode_from_RESET
//================================================================================
extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {
	// $[XBR1 - Port I/O Crossbar 1]
	/*
	// WEAKPUD (Port I/O Weak Pullup Disable) = PULL_UPS_ENABLED (Weak
	//     Pullups enabled (except for Ports whose I/O are configured for analog
	//     mode).)
	// XBARE (Crossbar Enable) = ENABLED (Crossbar enabled.)
	// PCA0ME (PCA Module I/O Enable) = CEX0_CEX1_CEX2 (CEX0, CEX1, CEX2
	//     routed to Port pins.)
	// ECIE (PCA0 External Counter Input Enable) = DISABLED (ECI unavailable
	//     at Port pin.)
	// T0E (T0 Enable) = DISABLED (T0 unavailable at Port pin.)
	// T1E (T1 Enable) = DISABLED (T1 unavailable at Port pin.)
	*/
	XBR1 = XBR1_WEAKPUD__PULL_UPS_ENABLED | XBR1_XBARE__ENABLED | XBR1_PCA0ME__CEX0_CEX1_CEX2
		 | XBR1_ECIE__DISABLED | XBR1_T0E__DISABLED | XBR1_T1E__DISABLED;
	// [XBR1 - Port I/O Crossbar 1]$

	// $[XBR0 - Port I/O Crossbar 0]
	/*
	// URT0E (UART0 I/O Output Enable) = DISABLED (UART0 I/O unavailable at
	//     Port pin.)
	// SPI0E (SPI I/O Enable) = ENABLED (SPI I/O routed to Port pins. The SPI
	//     can be assigned either 3 or 4 GPIO pins.)
	// SMB0E (SMBus0 I/O Enable) = DISABLED (SMBus0 I/O unavailable at Port
	//     pins.)
	// CP0E (Comparator0 Output Enable) = DISABLED (CP0 unavailable at Port
	//     pin.)
	// CP0AE (Comparator0 Asynchronous Output Enable) = DISABLED
	//     (Asynchronous CP0 unavailable at Port pin.)
	// CP1E (Comparator1 Output Enable) = DISABLED (CP1 unavailable at Port
	//     pin.)
	// CP1AE (Comparator1 Asynchronous Output Enable) = DISABLED
	//     (Asynchronous CP1 unavailable at Port pin.)
	// SYSCKE (SYSCLK Output Enable) = DISABLED (SYSCLK unavailable at Port
	//     pin.)
	*/
	XBR0 = XBR0_URT0E__DISABLED | XBR0_SPI0E__ENABLED | XBR0_SMB0E__DISABLED
		 | XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED | XBR0_CP1E__DISABLED
		 | XBR0_CP1AE__DISABLED | XBR0_SYSCKE__DISABLED;
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR2 - Port I/O Crossbar 2]
	// [XBR2 - Port I/O Crossbar 2]$


}

//================================================================================
// ADC_0_enter_DefaultMode_from_RESET
//================================================================================
extern void ADC_0_enter_DefaultMode_from_RESET(void) {
	// $[ADC0CF - ADC0 Configuration]
	/*
	// ADLJST (ADC0 Left Justify Select) = RIGHT_JUSTIFIED (Data in the
	//     ADC0H:ADC0L registers is right-justified.)
	// ADSC (SAR Clock Divider) = 0x07
	*/
	ADC0CF = ADC0CF_ADLJST__RIGHT_JUSTIFIED | (0x07 << ADC0CF_ADSC__SHIFT);
	// [ADC0CF - ADC0 Configuration]$

	// $[ADC0GTH - ADC0 Greater-Than High Byte]
	// [ADC0GTH - ADC0 Greater-Than High Byte]$

	// $[ADC0GTL - ADC0 Greater-Than Low Byte]
	// [ADC0GTL - ADC0 Greater-Than Low Byte]$

	// $[ADC0LTH - ADC0 Less-Than High Byte]
	// [ADC0LTH - ADC0 Less-Than High Byte]$

	// $[ADC0LTL - ADC0 Less-Than Low Byte]
	// [ADC0LTL - ADC0 Less-Than Low Byte]$

	// $[AMX0N - AMUX0 Negative Multiplexer Selection]
	/*
	// AMX0N (AMUX0 Negative Input Selection) = GND (Ground (single-ended
	//     mode).)
	*/
	AMX0N = AMX0N_AMX0N__GND;
	// [AMX0N - AMUX0 Negative Multiplexer Selection]$

	// $[AMX0P - AMUX0 Positive Multiplexer Selection]
	/*
	// AMX0P (AMUX0 Positive Input Selection) = ADC0P4 (Select ADC0P.4.)
	*/
	AMX0P = AMX0P_AMX0P__ADC0P4;
	// [AMX0P - AMUX0 Positive Multiplexer Selection]$

	// $[ADC0CN0 - ADC0 Control]
	/*
	// ADEN (ADC Enable) = ENABLED (ADC0 Enabled (active and ready for data
	//     conversions).)
	// ADCM (Start of Conversion Mode Select) = TIMER0 (ADC0 conversion
	//     initiated on overflow of Timer 0.)
	*/
	ADC0CN0 &= ~ADC0CN0_ADCM__FMASK;
	ADC0CN0 |= ADC0CN0_ADEN__ENABLED
		 | ADC0CN0_ADCM__TIMER0;
	// [ADC0CN0 - ADC0 Control]$


}

//================================================================================
// VREF_0_enter_DefaultMode_from_RESET
//================================================================================
extern void VREF_0_enter_DefaultMode_from_RESET(void) {
	// $[REF0CN - Voltage Reference Control]
	/*
	// TEMPE (Temperature Sensor Enable) = DISABLED (Disable the internal
	//     Temperature Sensor.)
	// REFBE (Internal Reference Buffer Enable) = DISABLED (Disable the
	//     internal reference buffer.)
	// REFBGS (Reference Buffer Gain Select) = GAIN_2 (The on-chip voltage
	//     reference buffer gain is 2.)
	// REGOVR (Regulator Reference Override) = REFSL (The REFSL bit selects
	//     the voltage reference source.)
	// REFSL (Voltage Reference Select) = VDD (Use VDD as the voltage
	//     reference.)
	*/
	REF0CN = REF0CN_TEMPE__DISABLED | REF0CN_REFBE__DISABLED | REF0CN_REFBGS__GAIN_2
		 | REF0CN_REGOVR__REFSL | REF0CN_REFSL__VDD;
	// [REF0CN - Voltage Reference Control]$


}

//================================================================================
// HFOSC_0_enter_DefaultMode_from_RESET
//================================================================================
extern void HFOSC_0_enter_DefaultMode_from_RESET(void) {
	// $[HFO0CN - High Frequency Oscillator Control]
	/*
	// IFCN (Oscillator Frequency Divider Control) = SYSCLK_DIV_1 (SYSCLK can
	//     be derived from Internal H-F Oscillator divided by 1 (12 MHz).)
	*/
	HFO0CN |= HFO0CN_IFCN__SYSCLK_DIV_1;
	// [HFO0CN - High Frequency Oscillator Control]$


}

//================================================================================
// CLOCK_0_enter_DefaultMode_from_RESET
//================================================================================
extern void CLOCK_0_enter_DefaultMode_from_RESET(void) {
	// $[CLKSEL - Clock Select]
	/*
	// CLKSL (System Clock Source Select Bits) = HFOSC_DIV_2 (Clock (SYSCLK)
	//     derived from the Internal High-Frequency Oscillator / 2.)
	// USBCLK (USB Clock Source Select Bits) = HFOSC (USB clock (USBCLK)
	//     derived from the Internal High-Frequency Oscillator.)
	// OUTCLK (Crossbar Clock Out Select) = SYSCLK (Enabling the Crossbar
	//     SYSCLK signal outputs SYSCLK.)
	*/
	CLKSEL = CLKSEL_CLKSL__HFOSC_DIV_2 | CLKSEL_USBCLK__HFOSC | CLKSEL_OUTCLK__SYSCLK;
	// [CLKSEL - Clock Select]$


}

//================================================================================
// TIMER01_0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER01_0_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	//Save Timer Configuration
	uint8_t TCON_save = TCON;
	//Stop Timers
	TCON &= TCON_TR0__BMASK & TCON_TR1__BMASK;

	// [Timer Initialization]$

	// $[TH0 - Timer 0 High Byte]
	/*
	// TH0 (Timer 0 High Byte) = 0x06
	*/
	TH0 = (0x06 << TH0_TH0__SHIFT);
	// [TH0 - Timer 0 High Byte]$

	// $[TL0 - Timer 0 Low Byte]
	/*
	// TL0 (Timer 0 Low Byte) = 0x06
	*/
	TL0 = (0x06 << TL0_TL0__SHIFT);
	// [TL0 - Timer 0 Low Byte]$

	// $[TH1 - Timer 1 High Byte]
	// [TH1 - Timer 1 High Byte]$

	// $[TL1 - Timer 1 Low Byte]
	// [TL1 - Timer 1 Low Byte]$

	// $[Timer Restoration]
	//Restore Timer Configuration
	TCON = TCON_save;

	// [Timer Restoration]$


}

//================================================================================
// TIMER16_3_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER16_3_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	// Save Timer Configuration
	uint8_t TMR3CN0_TR3_save = TMR3CN0 & TMR3CN0_TR3__BMASK;
	// Stop Timer
	TMR3CN0 &= ~(TMR3CN0_TR3__BMASK);
	// [Timer Initialization]$

	// $[TMR3CN0 - Timer 3 Control]
	// [TMR3CN0 - Timer 3 Control]$

	// $[TMR3H - Timer 3 High Byte]
	/*
	// TMR3H (Timer 3 High Byte) = 0xF8
	*/
	TMR3H = (0xF8 << TMR3H_TMR3H__SHIFT);
	// [TMR3H - Timer 3 High Byte]$

	// $[TMR3L - Timer 3 Low Byte]
	/*
	// TMR3L (Timer 3 Low Byte) = 0x30
	*/
	TMR3L = (0x30 << TMR3L_TMR3L__SHIFT);
	// [TMR3L - Timer 3 Low Byte]$

	// $[TMR3RLH - Timer 3 Reload High Byte]
	/*
	// TMR3RLH (Timer 3 Reload High Byte) = 0xF8
	*/
	TMR3RLH = (0xF8 << TMR3RLH_TMR3RLH__SHIFT);
	// [TMR3RLH - Timer 3 Reload High Byte]$

	// $[TMR3RLL - Timer 3 Reload Low Byte]
	/*
	// TMR3RLL (Timer 3 Reload Low Byte) = 0x30
	*/
	TMR3RLL = (0x30 << TMR3RLL_TMR3RLL__SHIFT);
	// [TMR3RLL - Timer 3 Reload Low Byte]$

	// $[TMR3CN0]
	/*
	// TR3 (Timer 3 Run Control) = RUN (Start Timer 3 running.)
	*/
	TMR3CN0 |= TMR3CN0_TR3__RUN;
	// [TMR3CN0]$

	// $[Timer Restoration]
	// Restore Timer Configuration
	TMR3CN0 |= TMR3CN0_TR3_save;
	// [Timer Restoration]$


}

//================================================================================
// TIMER_SETUP_0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER_SETUP_0_enter_DefaultMode_from_RESET(void) {
	// $[CKCON0 - Clock Control 0]
	/*
	// SCA (Timer 0/1 Prescale) = SYSCLK_DIV_48 (System clock divided by 48.)
	// T0M (Timer 0 Clock Select) = PRESCALE (Counter/Timer 0 uses the clock
	//     defined by the prescale field, SCA.)
	// T2MH (Timer 2 High Byte Clock Select) = EXTERNAL_CLOCK (Timer 2 high
	//     byte uses the clock defined by T2XCLK in TMR2CN0.)
	// T2ML (Timer 2 Low Byte Clock Select) = EXTERNAL_CLOCK (Timer 2 low
	//     byte uses the clock defined by T2XCLK in TMR2CN0.)
	// T3MH (Timer 3 High Byte Clock Select) = EXTERNAL_CLOCK (Timer 3 high
	//     byte uses the clock defined by T3XCLK in TMR3CN0.)
	// T3ML (Timer 3 Low Byte Clock Select) = EXTERNAL_CLOCK (Timer 3 low
	//     byte uses the clock defined by T3XCLK in TMR3CN0.)
	// T1M (Timer 1 Clock Select) = PRESCALE (Timer 1 uses the clock defined
	//     by the prescale field, SCA.)
	*/
	CKCON0 = CKCON0_SCA__SYSCLK_DIV_48 | CKCON0_T0M__PRESCALE | CKCON0_T2MH__EXTERNAL_CLOCK
		 | CKCON0_T2ML__EXTERNAL_CLOCK | CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
		 | CKCON0_T1M__PRESCALE;
	// [CKCON0 - Clock Control 0]$

	// $[CKCON1 - Clock Control 1]
	// [CKCON1 - Clock Control 1]$

	// $[TMOD - Timer 0/1 Mode]
	/*
	// T0M (Timer 0 Mode Select) = MODE2 (Mode 2, 8-bit Counter/Timer with
	//     Auto-Reload)
	// T1M (Timer 1 Mode Select) = MODE0 (Mode 0, 13-bit Counter/Timer)
	// CT0 (Counter/Timer 0 Select) = TIMER (Timer Mode. Timer 0 increments
	//     on the clock defined by T0M in the CKCON0 register.)
	// GATE0 (Timer 0 Gate Control) = DISABLED (Timer 0 enabled when TR0 = 1
	//     irrespective of INT0 logic level.)
	// CT1 (Counter/Timer 1 Select) = TIMER (Timer Mode. Timer 1 increments
	//     on the clock defined by T1M in the CKCON0 register.)
	// GATE1 (Timer 1 Gate Control) = DISABLED (Timer 1 enabled when TR1 = 1
	//     irrespective of INT1 logic level.)
	*/
	TMOD = TMOD_T0M__MODE2 | TMOD_T1M__MODE0 | TMOD_CT0__TIMER | TMOD_GATE0__DISABLED
		 | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
	// [TMOD - Timer 0/1 Mode]$

	// $[TCON - Timer 0/1 Control]
	/*
	// TR0 (Timer 0 Run Control) = RUN (Start Timer 0 running.)
	*/
	TCON |= TCON_TR0__RUN;
	// [TCON - Timer 0/1 Control]$


}

//================================================================================
// SPI_0_enter_DefaultMode_from_RESET
//================================================================================
extern void SPI_0_enter_DefaultMode_from_RESET(void) {
	// $[SPI0CKR - SPI0 Clock Rate]
	/*
	// SPI0CKR (SPI0 Clock Rate) = 0x0B
	*/
	SPI0CKR = (0x0B << SPI0CKR_SPI0CKR__SHIFT);
	// [SPI0CKR - SPI0 Clock Rate]$

	// $[SPI0CFG - SPI0 Configuration]
	/*
	// MSTEN (Master Mode Enable) = MASTER_ENABLED (Enable master mode.
	//     Operate as a master.)
	*/
	SPI0CFG |= SPI0CFG_MSTEN__MASTER_ENABLED;
	// [SPI0CFG - SPI0 Configuration]$

	// $[SPI0CN0 - SPI0 Control]
	/*
	// SPIEN (SPI0 Enable) = ENABLED (Enable the SPI module.)
	// NSSMD (Slave Select Mode) = 3_WIRE (3-Wire Slave or 3-Wire Master
	//     Mode. NSS signal is not routed to a port pin.)
	*/
	SPI0CN0 &= ~SPI0CN0_NSSMD__FMASK;
	SPI0CN0 |= SPI0CN0_SPIEN__ENABLED;
	// [SPI0CN0 - SPI0 Control]$


}

//================================================================================
// INTERRUPT_0_enter_DefaultMode_from_RESET
//================================================================================
extern void INTERRUPT_0_enter_DefaultMode_from_RESET(void) {
	// $[EIE1 - Extended Interrupt Enable 1]
	/*
	// EADC0 (ADC0 Conversion Complete Interrupt Enable) = ENABLED (Enable
	//     interrupt requests generated by the ADINT flag.)
	// EWADC0 (ADC0 Window Comparison Interrupt Enable) = DISABLED (Disable
	//     ADC0 Window Comparison interrupt.)
	// ECP0 (Comparator0 (CP0) Interrupt Enable) = DISABLED (Disable CP0
	//     interrupts.)
	// ECP1 (Comparator1 (CP1) Interrupt Enable) = DISABLED (Disable CP1
	//     interrupts.)
	// EPCA0 (Programmable Counter Array (PCA0) Interrupt Enable) = DISABLED
	//     (Disable all PCA0 interrupts.)
	// ESMB0 (SMBus (SMB0) Interrupt Enable) = DISABLED (Disable all SMB0
	//     interrupts.)
	// ET3 (Timer 3 Interrupt Enable) = ENABLED (Enable interrupt requests
	//     generated by the TF3L or TF3H flags.)
	// EUSB0 (USB (USB0) Interrupt Enable) = DISABLED (Disable all USB0
	//     interrupts.)
	*/
	EIE1 = EIE1_EADC0__ENABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
		 | EIE1_ECP1__DISABLED | EIE1_EPCA0__DISABLED | EIE1_ESMB0__DISABLED
		 | EIE1_ET3__ENABLED | EIE1_EUSB0__DISABLED;
	// [EIE1 - Extended Interrupt Enable 1]$

	// $[EIP1 - Extended Interrupt Priority 1]
	// [EIP1 - Extended Interrupt Priority 1]$

	// $[IE - Interrupt Enable]
	/*
	// EA (All Interrupts Enable) = DISABLED (Disable all interrupt sources.)
	// EX0 (External Interrupt 0 Enable) = DISABLED (Disable external
	//     interrupt 0.)
	// EX1 (External Interrupt 1 Enable) = DISABLED (Disable external
	//     interrupt 1.)
	// ESPI0 (SPI0 Interrupt Enable) = ENABLED (Enable interrupt requests
	//     generated by SPI0.)
	// ET0 (Timer 0 Interrupt Enable) = DISABLED (Disable all Timer 0
	//     interrupt.)
	// ET1 (Timer 1 Interrupt Enable) = DISABLED (Disable all Timer 1
	//     interrupt.)
	// ET2 (Timer 2 Interrupt Enable) = ENABLED (Enable interrupt requests
	//     generated by the TF2L or TF2H flags.)
	// ES0 (UART0 Interrupt Enable) = DISABLED (Disable UART0 interrupt.)
	*/
	IE = IE_EA__DISABLED | IE_EX0__DISABLED | IE_EX1__DISABLED | IE_ESPI0__ENABLED
		 | IE_ET0__DISABLED | IE_ET1__DISABLED | IE_ET2__ENABLED | IE_ES0__DISABLED;
	// [IE - Interrupt Enable]$

	// $[IP - Interrupt Priority]
	// [IP - Interrupt Priority]$

	// $[EIE2 - Extended Interrupt Enable 2]
	// [EIE2 - Extended Interrupt Enable 2]$

	// $[EIP2 - Extended Interrupt Priority 2]
	// [EIP2 - Extended Interrupt Priority 2]$


}


