/*
********************************************************************************
File Include Section
********************************************************************************
*/
#include "types.h"
#include "sfr111.h"
#include "w5100.h"
#include "socket.h"
#include "dhcp.h"
#include <stdio.h>
#include <string.h>



/*
********************************************************************************
Define Part
********************************************************************************
*/

#define SOCK_DHCP	0 // socket 0

/*
********************************************************************************
Local Variable Declaration Section
********************************************************************************
*/

extern uint8 Mac[6];
extern uint8 Lip[4];
extern uint8 Subnet[4];
extern uint8 Gw[4];

uint8 DNS_Server_IP[4];

//extern CONFIG_MSG Config_Msg;

uint8 DHCP_SIP[4];
uint8 DHCP_SHA[6];
uint8 OLD_SIP[4];

char dhcp_state;
char retry_count;

un_l2cval lease_time;
uint32 my_time, next_time;

uint8 DHCP_timeout;
uint32 DHCP_XID;


//RIP_MSG * MSG;
RIP_MSG  MSG; 

char HOST_NAME[14];
uint8 Cip[4] = {0,0,0,0};

//extern void (*jump_function)(void);	
/*
********************************************************************************
Function Implementation Part
********************************************************************************
*/
/*
*********************************************************************************************************
*              SEND DHCP DISCOVER
*
* Description: This function sends DHCP DISCOVER message to DHCP server.
* Arguments  : s - is a socket number.
* Returns    : None.
* Note       : 
*********************************************************************************************************
*/
void send_DHCP_DISCOVER(uint8 s)
{
	uint16 i;
	uint8 ip[4];
	uint16 k = 0;

	MSG.op = DHCP_BOOTREQUEST;
	MSG.htype = DHCP_HTYPE10MB;
	MSG.hlen = DHCP_HLENETHERNET;
	MSG.hops = DHCP_HOPS;
	MSG.xid = DHCP_XID;
	MSG.secs = DHCP_SECS;
	MSG.flags = DHCP_FLAGSBROADCAST;

	MSG.ciaddr[0] = 0;
	MSG.ciaddr[1] = 0;
	MSG.ciaddr[2] = 0;
	MSG.ciaddr[3] = 0;

	MSG.yiaddr[0] = 0;
	MSG.yiaddr[1] = 0;
	MSG.yiaddr[2] = 0;
	MSG.yiaddr[3] = 0;

	MSG.siaddr[0] = 0;
	MSG.siaddr[1] = 0;
	MSG.siaddr[2] = 0;
	MSG.siaddr[3] = 0;

	MSG.giaddr[0] = 0;
	MSG.giaddr[1] = 0;
	MSG.giaddr[2] = 0;
	MSG.giaddr[3] = 0;

	MSG.chaddr[0] = Mac[0];
	MSG.chaddr[1] = Mac[1];
	MSG.chaddr[2] = Mac[2];
	MSG.chaddr[3] = Mac[3];
	MSG.chaddr[4] = Mac[4];
	MSG.chaddr[5] = Mac[5];

	for (i = 6; i < 16; i++) MSG.chaddr[i] = 0;
	for (i = 0; i < 64; i++) MSG.sname[i] = 0;
	for (i = 0; i < 128; i++) MSG.file[i] = 0;

	// MAGIC_COOKIE
	MSG.OPT[k++] = 0x63;
	MSG.OPT[k++] = 0x82;
	MSG.OPT[k++] = 0x53;
	MSG.OPT[k++] = 0x63;

	// Option Request Param
	MSG.OPT[k++] = dhcpMessageType;
	MSG.OPT[k++] = 0x01;
	MSG.OPT[k++] = DHCP_DISCOVER;
	
	// Client identifier
	MSG.OPT[k++] = dhcpClientIdentifier;
	MSG.OPT[k++] = 0x07;
	MSG.OPT[k++] = 0x01;
	MSG.OPT[k++] = Mac[0];
	MSG.OPT[k++] = Mac[1];
	MSG.OPT[k++] = Mac[2];
	MSG.OPT[k++] = Mac[3];
	MSG.OPT[k++] = Mac[4];
	MSG.OPT[k++] = Mac[5];
	
	// host name
	MSG.OPT[k++] = hostName;
	MSG.OPT[k++] = 14; // length of hostname
	MSG.OPT[k++] = HOST_NAME[0];
	MSG.OPT[k++] = HOST_NAME[1];
	MSG.OPT[k++] = HOST_NAME[2];
	MSG.OPT[k++] = HOST_NAME[3];
	MSG.OPT[k++] = HOST_NAME[4];
	MSG.OPT[k++] = HOST_NAME[5];
	MSG.OPT[k++] = HOST_NAME[6];
	MSG.OPT[k++] = HOST_NAME[7];
	MSG.OPT[k++] = HOST_NAME[8];
	MSG.OPT[k++] = HOST_NAME[9];
	MSG.OPT[k++] = HOST_NAME[10];
	MSG.OPT[k++] = HOST_NAME[11];
	MSG.OPT[k++] = HOST_NAME[12];
	MSG.OPT[k++] = HOST_NAME[13];


	MSG.OPT[k++] = dhcpParamRequest;
	MSG.OPT[k++] = 0x06;	// length of request
	MSG.OPT[k++] = subnetMask;
	MSG.OPT[k++] = routersOnSubnet;
	MSG.OPT[k++] = dns;
	MSG.OPT[k++] = domainName;
	MSG.OPT[k++] = dhcpT1value;
	MSG.OPT[k++] = dhcpT2value;
	MSG.OPT[k++] = endOption;

	for (i = k; i < OPT_SIZE; i++) MSG.OPT[i] = 0;

	// send broadcasting packet
	for (i = 0; i < 4; i++) ip[i] = 255;

	#ifdef DHCP_DEBUG
		printf("\r\n> send DHCP_DISCOVER");
	#endif
	
	sendto(s, (uint8 *)(&MSG.op), RIP_MSG_SIZE, ip, DHCP_SERVER_PORT);
}

/*
*********************************************************************************************************
*              SEND DHCP REQUEST
*
* Description: This function sends DHCP REQUEST message to DHCP server.
* Arguments  : s - is a socket number.
* Returns    : None.
* Note       : 
*********************************************************************************************************
*/
void send_DHCP_REQUEST(uint8 s, uint8 *Cip, uint8 *d_addr)
{
	int i;
	uint8 ip[10];
	uint16 k = 0;

	MSG.op = DHCP_BOOTREQUEST;
	MSG.htype = DHCP_HTYPE10MB;
	MSG.hlen = DHCP_HLENETHERNET;
	MSG.hops = DHCP_HOPS;
	MSG.xid = DHCP_XID;
	MSG.secs = DHCP_SECS;
	//MSG.flags = DHCP_FLAGSBROADCAST;
	if (d_addr[0] == 0xff) 	MSG.flags = DHCP_FLAGSBROADCAST;
	else MSG.flags = 0;
	
	MSG.ciaddr[0] = Cip[0];
	MSG.ciaddr[1] = Cip[1];
	MSG.ciaddr[2] = Cip[2];
	MSG.ciaddr[3] = Cip[3];

	MSG.yiaddr[0] = 0;
	MSG.yiaddr[1] = 0;
	MSG.yiaddr[2] = 0;
	MSG.yiaddr[3] = 0;

	MSG.siaddr[0] = 0;
	MSG.siaddr[1] = 0;
	MSG.siaddr[2] = 0;
	MSG.siaddr[3] = 0;

	MSG.giaddr[0] = 0;
	MSG.giaddr[1] = 0;
	MSG.giaddr[2] = 0;
	MSG.giaddr[3] = 0;

	MSG.chaddr[0] = Mac[0];
	MSG.chaddr[1] = Mac[1];
	MSG.chaddr[2] = Mac[2];
	MSG.chaddr[3] = Mac[3];
	MSG.chaddr[4] = Mac[4];
	MSG.chaddr[5] = Mac[5];

	for (i = 6; i < 16; i++) MSG.chaddr[i] = 0;
	for (i = 0; i < 64; i++) MSG.sname[i] = 0;
	for (i = 0; i < 128; i++) MSG.file[i] = 0;

	// MAGIC_COOKIE 
	MSG.OPT[k++] = 0x63;
	MSG.OPT[k++] = 0x82;
	MSG.OPT[k++] = 0x53;
	MSG.OPT[k++] = 0x63;

	// Option Request Param.
	MSG.OPT[k++] = dhcpMessageType;
	MSG.OPT[k++] = 0x01;
	MSG.OPT[k++] = DHCP_REQUEST;

	MSG.OPT[k++] = dhcpClientIdentifier;
	MSG.OPT[k++] = 0x07;
	MSG.OPT[k++] = 0x01;
	MSG.OPT[k++] = Mac[0];
	MSG.OPT[k++] = Mac[1];
	MSG.OPT[k++] = Mac[2];
	MSG.OPT[k++] = Mac[3];
	MSG.OPT[k++] = Mac[4];
	MSG.OPT[k++] = Mac[5];

	if (d_addr[0] == 0xff) {
		MSG.OPT[k++] = dhcpRequestedIPaddr;
		MSG.OPT[k++] = 0x04;
		MSG.OPT[k++] = Lip[0];
		MSG.OPT[k++] = Lip[1];
		MSG.OPT[k++] = Lip[2];
		MSG.OPT[k++] = Lip[3];
	
		MSG.OPT[k++] = dhcpServerIdentifier;
		MSG.OPT[k++] = 0x04;
		MSG.OPT[k++] = DHCP_SIP[0];
		MSG.OPT[k++] = DHCP_SIP[1];
		MSG.OPT[k++] = DHCP_SIP[2];
		MSG.OPT[k++] = DHCP_SIP[3];
	}

	// host name
	MSG.OPT[k++] = hostName;
	MSG.OPT[k++] = 14; // length of hostname
	MSG.OPT[k++] = HOST_NAME[0];
	MSG.OPT[k++] = HOST_NAME[1];
	MSG.OPT[k++] = HOST_NAME[2];
	MSG.OPT[k++] = HOST_NAME[3];
	MSG.OPT[k++] = HOST_NAME[4];
	MSG.OPT[k++] = HOST_NAME[5];
	MSG.OPT[k++] = HOST_NAME[6];
	MSG.OPT[k++] = HOST_NAME[7];
	MSG.OPT[k++] = HOST_NAME[8];
	MSG.OPT[k++] = HOST_NAME[9];
	MSG.OPT[k++] = HOST_NAME[10];
	MSG.OPT[k++] = HOST_NAME[11];
	MSG.OPT[k++] = HOST_NAME[12];
	MSG.OPT[k++] = HOST_NAME[13];
	
	MSG.OPT[k++] = dhcpParamRequest;
	MSG.OPT[k++] = 0x08;
	MSG.OPT[k++] = subnetMask;
	MSG.OPT[k++] = routersOnSubnet;
	MSG.OPT[k++] = dns;
	MSG.OPT[k++] = domainName;
	MSG.OPT[k++] = dhcpT1value;
	MSG.OPT[k++] = dhcpT2value;
	MSG.OPT[k++] = performRouterDiscovery;
	MSG.OPT[k++] = staticRoute;
	MSG.OPT[k++] = endOption;

	for (i = k; i < OPT_SIZE; i++) MSG.OPT[i] = 0;

	// send broadcasting packet
	for (i = 0; i < 4; i++) ip[i] = d_addr[i];

#ifdef DHCP_DEBUG
	printf("\r\n> send DHCP_Request");
#endif
	
	sendto(s, (uint8 *)(&MSG.op), RIP_MSG_SIZE, ip, DHCP_SERVER_PORT);

}

/*
*********************************************************************************************************
*              SEND DHCP DHCPDECLINE
*
* Description: This function sends DHCP RELEASE message to DHCP server.
* Arguments  : s - is a socket number.
* Returns    : None.
* Note       : 
*********************************************************************************************************
*/
void send_DHCP_DECLINE(uint8 s)
{
	int i;
	uint8 ip[10];
	uint16 k = 0;

	MSG.op = DHCP_BOOTREQUEST;
	MSG.htype = DHCP_HTYPE10MB;
	MSG.hlen = DHCP_HLENETHERNET;
	MSG.hops = DHCP_HOPS;
	MSG.xid = DHCP_XID;
	MSG.secs = DHCP_SECS;
	MSG.flags = 0;

	MSG.ciaddr[0] = 0;
	MSG.ciaddr[1] = 0;
	MSG.ciaddr[2] = 0;
	MSG.ciaddr[3] = 0;

	MSG.yiaddr[0] = 0;
	MSG.yiaddr[1] = 0;
	MSG.yiaddr[2] = 0;
	MSG.yiaddr[3] = 0;

	MSG.siaddr[0] = 0;
	MSG.siaddr[1] = 0;
	MSG.siaddr[2] = 0;
	MSG.siaddr[3] = 0;

	MSG.giaddr[0] = 0;
	MSG.giaddr[1] = 0;
	MSG.giaddr[2] = 0;
	MSG.giaddr[3] = 0;

	MSG.chaddr[0] = Mac[0];
	MSG.chaddr[1] = Mac[1];
	MSG.chaddr[2] = Mac[2];
	MSG.chaddr[3] = Mac[3];
	MSG.chaddr[4] = Mac[4];
	MSG.chaddr[5] = Mac[5];

	for (i = 6; i < 16; i++) MSG.chaddr[i] = 0;
	for (i = 0; i < 64; i++) MSG.sname[i] = 0;
	for (i = 0; i < 128; i++) MSG.file[i] = 0;

	// MAGIC_COOKIE
	MSG.OPT[k++] = 0x63;
	MSG.OPT[k++] = 0x82;
	MSG.OPT[k++] = 0x53;
	MSG.OPT[k++] = 0x63;

	// Option Request Param.
	MSG.OPT[k++] = dhcpMessageType;
	MSG.OPT[k++] = 0x01;
	MSG.OPT[k++] = DHCP_DECLINE;

	MSG.OPT[k++] = dhcpClientIdentifier;
	MSG.OPT[k++] = 0x07;
	MSG.OPT[k++] = 0x01;
	MSG.OPT[k++] = Mac[0];
	MSG.OPT[k++] = Mac[1];
	MSG.OPT[k++] = Mac[2];
	MSG.OPT[k++] = Mac[3];
	MSG.OPT[k++] = Mac[4];
	MSG.OPT[k++] = Mac[5];

	MSG.OPT[k++] = dhcpRequestedIPaddr;
	MSG.OPT[k++] = 0x04;
	MSG.OPT[k++] = Lip[0];
	MSG.OPT[k++] = Lip[1];
	MSG.OPT[k++] = Lip[2];
	MSG.OPT[k++] = Lip[3];

	MSG.OPT[k++] = dhcpServerIdentifier;
	MSG.OPT[k++] = 0x04;
	MSG.OPT[k++] = DHCP_SIP[0];
	MSG.OPT[k++] = DHCP_SIP[1];
	MSG.OPT[k++] = DHCP_SIP[2];
	MSG.OPT[k++] = DHCP_SIP[3];

	MSG.OPT[k++] = endOption;

	for (i = k; i < OPT_SIZE; i++) MSG.OPT[i] = 0;

	//send broadcasting packet
	ip[0] = 255;
	ip[1] = 255;
	ip[2] = 255;
	ip[3] = 255;

//	printf("> send DHCP_Decline\r\n");

	sendto(s, (uint8 *)(&MSG.op), RIP_MSG_SIZE, ip, DHCP_SERVER_PORT);
}

/*
*********************************************************************************************************
*              PARSE REPLY MSG
*
* Description: This function parses the reply message from DHCP server.
* Arguments  : s      - is a socket number.
*              length - is a size data to receive.
* Returns    : None.
* Note       : 
*********************************************************************************************************
*/
char parseDHCPMSG(uint8 s, uint16 length)
{
	uint8 svr_addr[6];
	uint16  svr_port;

	uint16 i, len;
	uint8 * p;
	uint8 * e;
	uint8 type, opt_len;

	len = recvfrom(s, (uint8 *)&MSG.op, length, svr_addr, &svr_port);
	
	if (svr_port == DHCP_SERVER_PORT)
	{
		for (i = 0; i < 6; i++)
			if (MSG.chaddr[i] != Mac[i])
			{
				type = 0;
				goto PARSE_END;
			}

		for (i = 0; i < 4; i++)
		{
			Lip[i] = MSG.yiaddr[i];
		}
		
		type = 0;
		p = (uint8 *)(&MSG.op);
		p = p + 240;
		e = p + (len - 240);

		while ( p < e )
		{
			switch ( *p )
			{
			case endOption :
				goto PARSE_END;
       			case padOption :
				p++;
				break;
			case dhcpMessageType :
				p++;
				p++;
				type = *p++;
				break;
			case subnetMask :
				p++;
				p++;
				for (i = 0; i < 4; i++)	 Subnet[i] = *p++;
				break;
			case routersOnSubnet :
				p++;
				opt_len = *p++;       
				for (i = 0; i < 4; i++)	Gw[i] = *p++;
				for (i = 0; i < (opt_len-4); i++) p++;
				break;
			case dns :
				p++;                  
				opt_len = *p++;       
				for (i = 0; i < 4; i++)	DNS_Server_IP[i] = *p++;
				if (opt_len >= 8)
				{
					for (i = 0; i < 4; i++) DNS_Server_IP[i] = *p++;
				}
				for (i = 0; i < (opt_len-8); i++) p++;
				break;
				
			case dhcpIPaddrLeaseTime :
				p++;
				opt_len = *p++;
				lease_time.cVal[3] = *p++;
				lease_time.cVal[2] = *p++;
				lease_time.cVal[1] = *p++;
				lease_time.cVal[0] = *p++;
				break;

			case dhcpServerIdentifier :
				p++;
				opt_len = *p++;
				DHCP_SIP[0] = *p++;
				DHCP_SIP[1] = *p++;
				DHCP_SIP[2] = *p++;
				DHCP_SIP[3] = *p++;
				break;

			default :
				p++;
				opt_len = *p++;
				p += opt_len;
				break;
			} // switch
		} // while
	} // if

PARSE_END :
	return	type;
}

/*
*********************************************************************************************************
*              CHECK DHCP STATE
*
* Description: This function checks the state of DHCP.
* Arguments  : None.
* Returns    : None.
* Note       : 
*********************************************************************************************************
*/
void check_DHCP_state(void) 
{
	uint16 len, i;
	uint8 type, flag;
	uint8 d_addr[4];
	
	type = 0;
	
	if ((len = getSn_RX_RSR(SOCK_DHCP)) > 0)
	{
		type = parseDHCPMSG(SOCK_DHCP, len);
	}
	
	switch ( dhcp_state )
	{
		case STATE_DHCP_DISCOVER :
			if (type == DHCP_OFFER)
			{
				#ifdef DHCP_DEBUG
					printf("\r\n< Receive DHCP_OFFER");
				#endif
				
				for (i = 0; i < 4; i++) d_addr[i] = 0xff;
				send_DHCP_REQUEST(SOCK_DHCP, Cip, d_addr);
				
				dhcp_state = STATE_DHCP_REQUEST;
			}
			else check_Timeout();
		break;

		case STATE_DHCP_REQUEST :
			if (type == DHCP_ACK)
			{
				my_time = 0;
				
				#ifdef DHCP_DEBUG
					printf("\r\n< Receive DHCP_ACK");
				#endif
				
				iinchip_init();
				Set_network();

				my_time = 0;
				next_time = my_time + DHCP_WAIT_TIME;
				retry_count = 0;
				dhcp_state = STATE_DHCP_LEASED;
			}
			else if (type == DHCP_NAK)
			{
				//printf("\r\n< Receive DHCP_NACK");
				my_time = 0;
				next_time = my_time + DHCP_WAIT_TIME;
				retry_count = 0;
				dhcp_state = STATE_DHCP_DISCOVER;
			}
			else check_Timeout();
		break;

		case STATE_DHCP_LEASED :
			if ((lease_time.lVal != 0xffffffff) && ((lease_time.lVal/2) < my_time))
			{				
				#ifdef DHCP_DEBUG
					printf("\r\nRenewal IP address ");
				#endif
				
				socket(SOCK_DHCP, Sn_MR_UDP, DHCP_CLIENT_PORT, 0x00);

				type = 0;
				for (i = 0; i < 4; i++)	OLD_SIP[i] = Lip[i];
				for (i = 0; i < 4; i++)	d_addr[i] = DHCP_SIP[i];
				
				DHCP_XID++;
				send_DHCP_REQUEST(SOCK_DHCP, Lip, d_addr);
				dhcp_state = STATE_DHCP_REREQUEST;

				//my_time = 0;
				next_time = my_time + DHCP_WAIT_TIME;
			}
		break;

		case STATE_DHCP_REREQUEST :
			if (type == DHCP_ACK)
			{
				retry_count = 0;
				flag = 0;
				for (i = 0; i < 4; i++)
				{
					if (OLD_SIP[i] != Lip[i])
					{
						flag = 1;
						break;
					}
				}
				
				// change to new IP address
				if (flag)
				{
					iinchip_init();
					Set_network();
				}
				
				
				#ifdef DHCP_DEBUG
					printf("\r\nACK");
				#endif

				my_time = 0;
				next_time = my_time + DHCP_WAIT_TIME;

				dhcp_state = STATE_DHCP_LEASED;
			}
			else if (type == DHCP_NAK)
			{
				my_time = 0;
				next_time = my_time + DHCP_WAIT_TIME;
				retry_count = 0;
				dhcp_state = STATE_DHCP_DISCOVER;
				//printf("state : STATE_DHCP_DISCOVER\r\n");
				#ifdef DHCP_DEBUG
					printf("\r\nNAK");
				#endif
			}
			else
			{
				#ifdef DHCP_DEBUG
					printf("\r\ncheck_Timeout");
				#endif
				check_Timeout();
			}
				
		break;

		case STATE_DHCP_RELEASE :
			break;
		default :
			break;
	}
}

/*
*********************************************************************************************************
*              CHECK TIMEOUT
*
* Description: This function checks the timeout of DHCP in each state.
* Arguments  : None.
* Returns    : None.
* Note       : 
*********************************************************************************************************
*/
void check_Timeout(void)
{
	uint8 i, d_addr[4];

#ifdef DHCP_DEBUG
//	printf("\r\nnext time %d, my time %d",next_time, my_time);
#endif
	
	if (retry_count < MAX_DHCP_RETRY) {
		if (next_time < my_time) {
			my_time = 0;
			next_time = my_time + DHCP_WAIT_TIME;
			retry_count++;
			switch ( dhcp_state ) {
				case STATE_DHCP_DISCOVER :
					//printf("<<timeout>> state : STATE_DHCP_DISCOVER\r\n");
					send_DHCP_DISCOVER(SOCK_DHCP);
				break;
		
				case STATE_DHCP_REQUEST :
//					printf("<<timeout>> state : STATE_DHCP_REQUEST\r\n");

					for (i = 0; i < 4; i++) d_addr[i] = 0xff;
					send_DHCP_REQUEST(SOCK_DHCP, Cip, d_addr);
				break;

				case STATE_DHCP_REREQUEST :
//					printf("<<timeout>> state : STATE_DHCP_REREQUEST\r\n");
					
					for (i = 0; i < 4; i++)	d_addr[i] = DHCP_SIP[i];
					send_DHCP_REQUEST(SOCK_DHCP, Lip, d_addr);
					
				break;
		
				default :
				break;
			}
		}
	} else {
		my_time = 0;
		next_time = my_time + DHCP_WAIT_TIME;
		retry_count = 0;

		DHCP_timeout = 1;

		/* open a socket in IP RAW mode for DHCP */
		socket(SOCK_DHCP, Sn_MR_UDP, DHCP_CLIENT_PORT, 0x00);
		send_DHCP_DISCOVER(SOCK_DHCP);
		dhcp_state = STATE_DHCP_DISCOVER;
	}
}

/*
*********************************************************************************************************
*              Get an IP from the DHCP server.
*
* Description: 
* Arguments  : None.
* Returns    : None.
* Note       : 
*********************************************************************************************************
*/
unsigned char getIP_DHCPS(void)
{
	uint8 ip[4];
	
	DHCP_XID = 0x12345678;

	setSHAR(Mac);

	// SRC IP
	ip[0] = 0;
	ip[1] = 0;
	ip[2] = 0;
	ip[3] = 0;
	setSIPR(ip);
	setGAR(ip);
	setSUBR(ip);

	setRCR(3);
	sysinit(0x55, 0x55);

	sprintf(HOST_NAME,"W5100_%02x%02x%02x",Mac[3],Mac[4],Mac[5]);	

	W5100_Delay(1000);
	
	socket(SOCK_DHCP, Sn_MR_UDP, DHCP_CLIENT_PORT, 0x00);
	
	send_DHCP_DISCOVER(SOCK_DHCP);
	
	dhcp_state = STATE_DHCP_DISCOVER;
	DHCP_timeout = 0;
	my_time = 0;
	next_time = my_time + DHCP_WAIT_TIME;
	retry_count = 0;

	while (dhcp_state != STATE_DHCP_LEASED)
	{


		if (DHCP_timeout == 1) return(0);
		check_DHCP_state();
		
	}
	
	return 1;
}

