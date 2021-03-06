/***********************************************************************/
/*                                                                     */
/*  FILE        :main.c                                             */
/*  DATE        :Wed, Jul 08, 2009                                     */
/*  DESCRIPTION :main program file.                                    */
/*  CPU GROUP   :118                                                   */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.8).     */
/*                                                                     */
/***********************************************************************/

#include "w5100.h"
#include "hwsetup.h"
#include "string.h"
#include "socket.h"
#include "webserver.h"
#include "oled28.h"


uint8 sock_buf[MAX_BUF_SIZE];
extern uint8 LED_State[2];
extern u_char evb_lcd_text[MAX_LCD_SIZE]; // Max text message size

uint8 Mac[6] = {0x00, 0x08, 0xDC, 0x11, 0x22, 0x33};
uint8 Lip[4];
uint8 Subnet[4];
uint8 Gw[4];
uint8 Enable_DHCP;
                  
void Set_network(void)
{
	setSHAR(Mac);
    if (Enable_DHCP == 0)
	{
		Subnet[0]=255;	Subnet[1]=255;	Subnet[2]=255;	Subnet[3]=0;	// Subnet Mask
		Gw[0]=192;		Gw[1]=168;		Gw[2]=1;		Gw[3]=1;		// Gateway IP Address
		Lip[0]=192;		Lip[1]=168;		Lip[2]=1;		Lip[3]=123;		// static IP Address = No DHCP
    }
	setSUBR(Subnet);							// write into SUBR Register [0x0005 - 0x0008]
	setGAR(Gw);									// write into GWR Register [0x0001 - 0x0004]
	setSIPR(Lip);
	sysinit(0x55,0x55);							// Init X/RX Memory allocation, 0x55 = 4 Socket, each 2k
}


void W5100_PHY_Delay(unsigned long int units)
{
	unsigned long counter = units * 10000;
	
	while(counter--)
	{
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
	}
}

void main(void)
{
	uint8 i, sock_status;
	uint16 len;
	char param[20];
	
	HardwareSetup();
	init_S6E63D6_240X320_8Bit_80Mode();				// Init OLED Display

	printstring_l(2, 0, 0, 0, 0x00, 0xff, 0x00, 490, 5, " ELEKTOR Webserver 11/2009 ");	
	printstring_l(2, 0, 0, 0, 0x00, 0xff, 0x00, 470, 1, " WIZnet, GLYN & Dacom West ");	

//	OLED_RECT(100, 110, 0, 320, 0x00,0x00,0xFF);
//	printstring_l(2, 0, 0, 0, 0xFF, 0x00, 0x00, 370, 10, "1234567890");	
	
	W5100_Reset();									// Reset & Init SPI
	W5100_PHY_Delay(5000);							// wait for the link of the PHY

	Enable_DHCP = 1;
	if (Enable_DHCP == 1)							// DHCP success
	{
		printstring_l(2, 0, 0, 0, 0xFF, 0x00, 0x00, 450, 10, "IP address : DHCP");	
		if (getIP_DHCPS() == 1)						// Set the timer
		{
		}
		else										// DHCP fail
		{
			printstring_l(2, 0, 0, 0, 0xFF, 0x00, 0x00, 450, 10, " DHCP Fail");	
		}
	}
	else											// Set the static IP address
	{
		printstring_l(2, 0, 0, 0, 0xFF, 0x00, 0x00, 450, 10, "IP address : Static");	
		Set_network();	
	}

	sprintf(param,"IP:%d.%d.%d.%d",Lip[0],Lip[1],Lip[2], Lip[3]);	
	printstring_l(2, 0, 0, 0, 0xFF, 0x00, 0x00, 430, 10, (u_char*)param);	
	
	sprintf(param,"SN:%d.%d.%d.%d",Subnet[0],Subnet[1],Subnet[2], Subnet[3]);	
	printstring_l(2, 0, 0, 0, 0xFF, 0x00, 0x00, 410, 10, (u_char*)param);	
	
	sprintf(param,"GW:%d.%d.%d.%d",Gw[0],Gw[1],Gw[2], Gw[3]);	
	printstring_l(2, 0, 0, 0, 0xFF, 0x00, 0x00, 390, 10, (u_char*)param);	
	

 	LED_State[0]= LED_OFF;
 	LED_State[1]= LED_OFF;
	memset(&evb_lcd_text[0],' ',MAX_LCD_SIZE);

	i = 0;
	socket(i, Sn_MR_TCP, 5000, 0x20);
	listen(i);	

	while(1) {
		web_server(1);
		web_server(2);
		web_server(3);
		
		sock_status = getSn_SR(i);
		switch(sock_status) {
			
			case SOCK_ESTABLISHED :
				len = getSn_RX_RSR(i);
				if (len > 0) {
					if (len > MAX_BUF_SIZE) len = MAX_BUF_SIZE;
					len = recv(i, sock_buf, len);
					send(i,sock_buf, len);
					//send(i,"elektor\r\n", 9);
				}
				break;
			case SOCK_CLOSE_WAIT:
				disconnect(0);
				break;
			case SOCK_CLOSED:
				close(i);
				
				socket(i, Sn_MR_TCP, 5000, 0x20);
				listen(i);
				break;
		}
	}
	
	
}
