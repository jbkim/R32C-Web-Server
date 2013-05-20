/*
@file		webserver.h
*/

#ifndef __WEBSERVER_H
#define __WEBSERVER_H


#define EVB_LED0_IMG		"$LED0_IMG$"
#define EVB_LED1_IMG		"$LED1_IMG$"
#define EVB_LCD_TEXT 	"$LCD_TEXT_VALUE$"

#define EVB_LED0_STAT	"$LED_0$"
#define EVB_LED1_STAT	"$LED_1$"

extern void web_server(u_char ch);

#endif
