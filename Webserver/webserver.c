/*
@file		webserver.c
@brief	Webserver example program for W5100

Remote LED control
*/

#include <stdio.h>
#include <string.h>

#include "types.h"
#include "sfr111.h"
#include "socket.h"
#include "httpd.h"

#include "w5100.h"
#include "webserver.h"
#include "searchfile.h"
#include "oled28.h"

// direction 
#define D_LED0			pd10_4
#define D_LED1			pd10_5
// port 
#define P_LED0			p10_4
#define P_LED1			p10_5

static u_char* http_response;		/**< Pointer to HTTP response */
static st_http_request *http_request;	/**< Pointer to HTTP request */

u_char LED_State[2];
u_char evb_lcd_text[MAX_LCD_SIZE]; // Max text message size

u_char bchannel_start[MAX_SOCK_NUM];

static u_int replace_sys_env_value(u_char* base,u_int len);	// Replace HTML's variables to system configuration value

/* http service */
static void proc_http(SOCKET, u_char *, int);		// processing HTTP


void led_off(u_char led)
{
       if (led == 0) {
		D_LED0 = OUT;
		P_LED0 = HI;
       	}else if (led == 1) {
		D_LED1 = OUT;
		P_LED1 = HI;
       	}
	LED_State[led] = LED_OFF;
}

void led_on(u_char led)
{
	if (led == 0) {
		D_LED0 = OUT;
		P_LED0 = LOW;
	}else if (led ==1) {
		D_LED1 = OUT;
		P_LED1 = LOW;
	}
	LED_State[led] = LED_ON;
}

u_char led_state(u_char led)
{
	return(LED_State[led]);
}

void web_server(u_char ch)
{
	int len;
	u_int wait_send=0;
	
	http_request = (st_http_request*)RX_BUF;		// struct of http request
	

	/* http service start */
	switch(getSn_SR(ch))
	{
	case SOCK_ESTABLISHED:	
		if(bchannel_start[ch]==1)
		{
			bchannel_start[ch] = 2;
		}
		if ((len = getSn_RX_RSR(ch)) > 0)		
		{
			if ((u_int)len > MAX_URI_SIZE) len = MAX_URI_SIZE;				
			len = recv(ch, (u_char*)http_request, len);
			*(((u_char*)http_request)+len) = 0;
			
			proc_http(ch, (u_char*)http_request, len);	// request is processed
			while(getSn_TX_FSR(ch)!= getIINCHIP_TxMAX(ch))
			{
				if(wait_send++ > 5000)
				{
					break;
				}
				
				W5100_Delay(5);
				
			}
			disconnect(ch);
		}
		break;
	case SOCK_CLOSE_WAIT:   
		disconnect(ch);
		bchannel_start[ch] = 0;
	case SOCK_CLOSED:                   
		if(!bchannel_start[ch])
		{
			bchannel_start[ch] = 1;
		}
		if(socket(ch,Sn_MR_TCP, HTTP_SERVER_PORT, 0x00) == 0)    /* reinitialize the socket */
		{
			bchannel_start[ch] = 0;
		}
		else	listen(ch);
		break;
	}	// end of switch 
}


/**
 @brief	Analyse HTTP request and then services WEB.
*/
static void proc_http(
	SOCKET s, 		/**< http server socket */
	u_char * buf, 		/**< buffer pointer included http-request */
	int length		/**< size of buffer */
	)
{
	char * content;
	char* name;
	char * param;
	u_int file_len;
	u_int send_len;
	
	http_response = (u_char*)TX_BUF;			// buffer for response header 
	http_request = (st_http_request*)RX_BUF;		// struct of http request
	

	parse_http_request(http_request, buf);			// After analyze request, convert into http_request
	
	/* method Analyze */
	switch (http_request->METHOD)				
	{
	case METHOD_ERR :					
		send(s, (u_char *)ERROR_REQUEST_PAGE, strlen(ERROR_HTML_PAGE));
		break;
	case METHOD_HEAD:
	case METHOD_GET :
	case METHOD_POST :
		name = get_http_uri_name(http_request->URI);
		if (!strcmp(name, "/")) strcpy(name,"evbctrl.html");	// If URI is "/", respond by index.htm 
		find_http_uri_type(&http_request->TYPE, name);	//Check file type (HTML, TEXT, GIF, JPEG are included)
		if(http_request->TYPE == PTYPE_CGI)
		{
			if(strstr(name,"LCDNLED.CGI"))
			{

				if((param = get_http_param_value(http_request->URI,"lcd")))
				{
					*(param+MAX_LCD_SIZE) = 0;
					
					memset(evb_lcd_text,' ',MAX_LCD_SIZE);
					memcpy(evb_lcd_text,(u_char*)param,strlen((u_char*)param));
					
					//	OLED_RECT(100, 110, 0, 320, 0x00,0x00,0xFF);
					//	printstring_l(2, 0, 0, 0, 0xFF, 0x00, 0x00, 370, 10, "1234567890");	

					// clear
					OLED_RECT(100, 110, 0, 320, 0x00,0x00,0x00);	
					// write
					printstring_l(2, 0, 0, 0, 0x00, 0x00, 0xFF, 370, 10, (u_char*)param);	

				}
			
				if((param = get_http_param_value(http_request->URI,"led0")))
				{
					if(!strcmp(param,"on")) led_on(0);
					else			led_off(0);
				}
				else	led_off(0);
				
				
				if((param = get_http_param_value(http_request->URI,"led1")))
				{
					if(!strcmp(param,"on"))	led_on(1);
					else			led_off(1);
				}
				else	led_off(1);
				
				
				strcpy(name,"evbctrl.html");
				
				find_http_uri_type(&http_request->TYPE, name);
			}
		}
		
		/* Search the specified file in stored binaray html image */
		if (!search_file(name, &content, &file_len))		//if the file do not exist then
		{
			send(s, (u_char *)ERROR_HTML_PAGE, strlen(ERROR_HTML_PAGE));	
		} 
		else 						// if search file sucess 
		{
			make_http_response_head(http_response, http_request->TYPE, (u_long)file_len);			
			send(s, http_response, strlen(http_response));
			while (file_len) 
			{
				if (file_len >= MAX_BUF_SIZE-1)
					send_len = MAX_BUF_SIZE-1;
				else	send_len = file_len;
				memcpy(http_response, content, send_len);
				
				*(http_response+send_len+1) = 0;
				// Replace htmls' system environment value to real value
				if(http_request->TYPE==PTYPE_HTML)
					send_len = replace_sys_env_value(http_response,send_len);
				send(s, http_response, send_len);
				content += send_len;
				file_len -= send_len;
			}
        	}
		
		break;
	default :
		break;
	}
}


/**
 @brief	Replace HTML's variables to system configuration value
*/
static u_int replace_sys_env_value(
	u_char* base, 	/**< pointer to html document */
	u_int len
	)
{
	u_char str[18];	
	u_char *ptr,*tptr;
	tptr = ptr = base;

	while((ptr=strchr(tptr,'$')))
	{


		if((tptr=(u_char*)strstr((char*)ptr,EVB_LCD_TEXT)))
		{
			// REPLACE LCD TEXT
			memset(tptr,0x20,MAX_LCD_SIZE);
			memcpy(tptr, &evb_lcd_text[0], MAX_LCD_SIZE);
			tptr+=16;
		}
		else if((tptr=strstr(ptr,EVB_LED0_STAT)))
		{
			// REPLACE LED0 STAT
			memset(tptr,0x20,7);
			if(led_state(0)==LED_ON) memcpy(tptr,"checked",7);
			tptr+=7;
		}
		else if((tptr=strstr(ptr,EVB_LED0_IMG)))
		{
			// REPLACE LED0 IMG
			memset(tptr,0,10);
			if(led_state(0)==LED_ON) memcpy(tptr,"led_on.gif",10);
			else			 memcpy(tptr,"led_of.gif",10);
			tptr+=10;
		}
		else if((tptr=strstr(ptr,EVB_LED1_STAT)))
		{
			// REPLACE LED1 STAT
			memset(tptr,0x20,7);
			if(led_state(1)==LED_ON) memcpy(tptr,"checked",7);
			tptr+=7;
		}
		else if((tptr=strstr(ptr,EVB_LED1_IMG)))
		{
			// REPLACE LED1 IMG
			memset(tptr,0,10);
			if(led_state(1)==LED_ON) memcpy(tptr,"led_on.gif",10);
			else			 memcpy(tptr,"led_of.gif",10);
			tptr+=10;
		}
		else	// tptr == 0 && ptr!=0;
		{
			if(ptr==base)
			{
				// "$ Charater"
				return len;
			}
			// REPLACE CONTINUE
			tptr = ptr;
			break;
		}
	}
	if(!ptr) return len;
	return (u_int)(tptr-base);
}


