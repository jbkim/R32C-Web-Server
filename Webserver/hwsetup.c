/***********************************************************************************
FILE NAME  		hwsetup.c
DESCRIPTION		Hardware Setup functions for R32C111

Copyright   : 2005 Renesas Technology Europe Ltd.
Copyright   : 2005 Renesas Technology Corporation.
All Rights Reserved
***********************************************************************************/

/***********************************************************************************
Revision History
DD.MM.YYYY OSO-UID Description
14.09.2005 RTE-DDE First Release
***********************************************************************************/

/***********************************************************************************
System Includes
***********************************************************************************/
// define settings for clock circuit
// select external clock
//#define fXin  6
#define fXin  8
//#define fXin  10
//#define fXin  16

// select PLL frequency
//#define PLL   96
//#define PLL   100
//#define PLL   120
//#define PLL   128
//#define PLL   144
//#define PLL   160
//#define PLL   180
#define PLL   192
  
// select divider for Base clock
// Base clock = PLL frequency / BCD
//#define BCD   2
#define BCD   3
//#define BCD   4
//#define BCD   6
  
// select divider for CPU clock
// CPU clock = Base clock / CCD
#define CCD   1
//#define CCD   2
//#define CCD   3
//#define CCD   4

// select divider for peripheral bus clock
// Peripheral bus clock = Base clock / PCD
//#define PCD   1
#define PCD   2
//#define PCD   3
//#define PCD   4

// select divider for peripheral clock
// Peripheral clock = PLL frequency / PCL
//#define PCL   2
//#define PCL   4
#define PCL   6
//#define PCL   8

/***********************************************************************************
User Includes
***********************************************************************************/
/* sfr111v010.h provides a structure to access all of the device registers. */
#include "sfr111v010.h"
/* rskR32C111def.h provides common defines for widely used items. */
//#include "rskR32C111def.h"
#include "hwsetup.h"
#include "clk_setup.h"
//#include "Interrupts.h"

/***********************************************************************************
User Program Code Prototypes
***********************************************************************************/
/* These functions are private so their prototypes are defined locally */
void ConfigureOperatingFrequency(void);
void EnablePeripheralModules(void);
void ConfigurePortPins(void);

/***********************************************************************************
User Program Code 
***********************************************************************************/

/***********************************************************************************
Function Name: 	HardwareSetup
Description:	Sets up hardware
Parameters: none
Return value: none
***********************************************************************************/

unsigned long i;

void HardwareSetup(void)
{    

	ConfigureOperatingFrequency();

//	ConfigurePortPins();

//	EnablePeripheralModules();

//	ConfigureInterrupts();

}

/***********************************************************************************
End of function HardwareSetup
***********************************************************************************/

/***********************************************************************************
Function Name: 	ConfigureOperatingFrequency
Description:	Sets up operating speed and start sub-clock
Parameters: none
Return value: none
***********************************************************************************/
void ConfigureOperatingFrequency(void)
{
  unsigned short wait;
  prcr = 0xFF;    // enable write to control registers
  prcr2 = 0x80;   // enable write to CM3 register
  prr = 0xAA;     // enable write to CCR, FMCR, PBC register
                  //  value depends on setting of CCR register
  pm2 |= 0x44;    // processor mode register 2: enable clock change
  cm0 = 0x00;     // system clock control register 0
  cm1 = 0x20;     // system clock control register 1
  cm2 = 0x00;     // oscillation stop detect register
  cm3 = 0x02;     // low speed mode clock control register
  tcspr = 0x00;   // count source prescaler register
  tcspr = 0x80;   // count source prescaler register
  cpsrf = 0x00;   // clock prescaler reset register
//  ebc0 = 0x4FCF;  // flash memory access control (?)
  pbc = PBC;   // Peripheral bus clock: /2
  ccr = CCR1;     // clock control register
  ccr = CCR2;     // clock control register
                  // 11: Base clock divide ratio:       /2
                  // 11: CPU clock divide ratio:        /1
                  // 01: Peripheral clock divide ratio: /2
  
  prcr = 0xFF;
  plc0 = _plc0;    // pll control register 0
  prcr = 0xFF;
  plc1 = _plc1;    // pll control register 1
                  // 0100: r-1
  seo = 0;        // pll mode
  while (wait<0x8000)
    wait++;
  bcs = 0;        // base clock source is PLL

  prcr = 0xFF;
  pm3 = _pm3;     // peripheral clock = PLL clock / 4
  pm2 &= ~0x02;   // processor mode register 2: disable clock change
  prcr = 0x00;
}
/***********************************************************************************
End of function ConfigureOperatingFrequency
***********************************************************************************/

/***********************************************************************************
Function Name: 	EnablePeripheralModules
Description:	Enables Peripheral Modules before use also enables data flash
Parameters: none
Return value: none
***********************************************************************************/
void EnablePeripheralModules(void)
{
	/* All modules are active in the M32C device */


}
/***********************************************************************************
End of function EnablePeripheralModules
***********************************************************************************/

/***********************************************************************************
Function Name: 	ConfigurePortPins
Description:	Configures port pins 
Parameters: none
Return value: none
***********************************************************************************/
void ConfigurePortPins(void)
{
/* Port pins default to inputs. To ensure safe initialisation set the pin states
before changing the data direction registers. This will avoid any unintentional
state changes on the external ports.
Many peripheral modules will override the setting of the port registers. Ensure
that the state is safe for external devices if the internal peripheral module is
disabled or powered down. */

/* General device configuration */
   				

/* Switch Port configuration */
	/* All pins are inputs by default */



/* Configure unused pins as output low */

//	prc30 =1;       /* allow writing to pd3, p3_is, pd7, p7_is, pd8, p8_is registers */
//	p0=p1=p2=p3=p4=p5=p6=p7=p9=/*p10=*/0x0;       
	/* lower half of port 4 has the LEDs on it so keep the LEDs off */
//	p4= 0x0f;
	/* configure direction registers as outputs*/
//	pd0=pd1=pd2=pd3=pd5=pd7= /*pd10 =*/ 0xff;
	pd2=pd4=0xff;
//	prc30 =1;       /* disable writing to pd3, p3_is, pd7, p7_is, pd8, p8_is registers */

	/* to set port9 direction register must first unprotect register do not step or set breakpoints
	between unprotecting register and modifying the direction register */
//	prc2=1;
//	pd9=0xff;
//	prc2 =0;

	/* port 6 is used by E8 do not modify upper half of port */
//	pd6 |= 0x0f;

	/* port 8 has switches, NMI and sub-clock only modify p8_0 and p8_1 */
//	p8_0 = p8_1 = 0;
//	pd8_0 = pd8_1 = 1;		
  pd5_3 = 1;
 			
}
/***********************************************************************************
End of function ConfigurePortPins
***********************************************************************************/


