/***********************************************************************************

FILE NAME  		clk_setup.h

DESCRIPTION		Clock Setup

Copyright   : 2008 Renesas Technology Europe Ltd.
Copyright   : 2008 Renesas Technology Corporation.
All Rights Reserved
***********************************************************************************/

/***********************************************************************************
Revision History
DD.MM.YYYY OSO-UID Description
01.10.2008 RTE-FLA First Release
***********************************************************************************/

#if CCD==3          // set value for CPU clock
#define _CCR1     0x04
#elif CCD==2
#define _CCR1     0x08
#elif CCD==1
#define _CCR1     0x0C
#elif CCD==4
#define _CCR1     0x00
#else
#error CCD not defined or invalid value
#endif

#if PCD==1          // set value for peripheral bus clock
#define CCR1     _CCR1
#define PBC      0x0000
#elif PCD==2
#define CCR1     _CCR1+0x10
#define PBC      0x0504
#elif PCD==3
#define CCR1     _CCR1+0x20
#define PBC      0x0A0D
#elif PCD==4
#define CCR1     _CCR1+0x30
#define PBC      0x0F0F
#else
#error PCD not defined or invalid value
#endif

#if BCD==6          // set value for bus clock
#define CCR2     CCR1
#elif BCD==4
#define CCR2     CCR1+0x01
#elif BCD==3
#define CCR2     CCR1+0x02
#elif BCD==2
#define CCR2     CCR1+0x03
#else
#error BCD not defined or invalid value
#endif

#if fXin==6          // set PLL values
#if PLL==96
#define _plc0    0x45
#define _plc1    0x01
#elif PLL==100
#define _plc0    0x09
#define _plc1    0x02
#elif PLL==120
#define _plc0    0x07
#define _plc1    0x01
#elif PLL==128
#define _plc0    0x8B
#define _plc1    0x02
#elif PLL==144
#define _plc0    0x68
#define _plc1    0x01
#elif PLL==160
#define _plc0    0x0F
#define _plc1    0x02
#elif PLL==180
#define _plc0    0x11
#define _plc1    0x02
#elif PLL==192
#define _plc0    0x8B
#define _plc1    0x01
#else
#error Invalid PLL frequency for f(Xin)=6MHz 
#endif
#elif fXin==8
#if PLL==96
#define _plc0    0x68
#define _plc1    0x03
#elif PLL==100
#define _plc0    0x04
#define _plc1    0x01
#elif PLL==120
#define _plc0    0x05
#define _plc1    0x01
#elif PLL==128
#define _plc0    0x45
#define _plc1    0x01
#elif PLL==144
#define _plc0    0x26
#define _plc1    0x01
#elif PLL==160
#define _plc0    0x07
#define _plc1    0x01
#elif PLL==180
#define _plc0    0x08
#define _plc1    0x01
#elif PLL==192
#define _plc0    0x68
#define _plc1    0x01
#else
#error Invalid PLL frequency for f(Xin)=8MHz 
#endif
#elif fXin==10
#if PLL==96
#define _plc0    0x68
#define _plc1    0x04
#elif PLL==100
#define _plc0    0xA6
#define _plc1    0x03
#elif PLL==120
#define _plc0    0x26
#define _plc1    0x02
#elif PLL==128
#define _plc0    0x8B
#define _plc1    0x04
#elif PLL==144
#define _plc0    0x4D
#define _plc1    0x04
#elif PLL==160
#define _plc0    0x45
#define _plc1    0x01
#elif PLL==180
#define _plc0    0x26
#define _plc1    0x02
#elif PLL==192
#define _plc0    0x32
#define _plc1    0x04
#else
#error Invalid PLL frequency for f(Xin)=10MHz 
#endif
#elif fXin==16
#if PLL==96
#define _plc0    0x68
#define _plc1    0x07
#elif PLL==100
#define _plc0    0x04
#define _plc1    0x03
#elif PLL==120
#define _plc0    0x05
#define _plc1    0x03
#elif PLL==128
#define _plc0    0x45
#define _plc1    0x03
#elif PLL==144
#define _plc0    0x26
#define _plc1    0x03
#elif PLL==160
#define _plc0    0x07
#define _plc1    0x03
#elif PLL==180
#define _plc0    0x08
#define _plc1    0x03
#elif PLL==192
#define _plc0    0x68
#define _plc1    0x03
#else
#error Invalid PLL frequency for f(Xin)=16MHz 
#endif
#else
#error Invalid f(Xin) value
#endif

#if PCL==2          // set value for pm3 to define peripheral clock
#define _pm3     0x060
#elif PCL==4
#define _pm3     0x040
#elif PCL==6
#define _pm3     0x020
#elif PCL==8
#define _pm3     0x000
#else
#error Invalid divider for peripheral clock 
#endif
