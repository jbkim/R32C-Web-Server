/**
 @file		httpd.c
 @brief 		functions associated http processing
 */


#include <stdio.h>
#include <string.h>

#include "types.h"
#include "socket.h"
#include "httpd.h"

//#define HTTPD_DEBUG

/**
@brief	CONVERT CHAR INTO HEX
@return	HEX
  
This function converts HEX(0-F) to a character
*/
char C2D(
	u_char c	/**< is a character('0'-'F') to convert to HEX */
	)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return 10 + c -'a';
	if (c >= 'A' && c <= 'F')
		return 10 + c -'A';

	return (char)c;
}

/**
@brief	replace the specified character in a string with new character
*/ 
void replacetochar(
	char * str, 		/**< pointer to be replaced */
	char oldchar, 	/**< old character */
	char newchar	/**< new character */
	)
{
	int x;
	for (x = 0; str[x]; x++) 
		if (str[x] == oldchar) str[x] = newchar;	
}



/**
 @brief	convert escape characters(%XX) to ascii charater 
 */ 
void unescape_http_url(
	char * url	/**< pointer to be conveted ( escape characters )*/
	)
{
	int x, y;

	for (x = 0, y = 0; url[y]; ++x, ++y) {
		if ((url[x] = url[y]) == '%') {
			url[x] = C2D(url[y+1])*0x10+C2D(url[y+2]);
			y+=2;
		}
	}
	url[x] = '\0';
}


/**
 @brief	make reponse header such as html, gif, jpeg,etc.
 */ 
void make_http_response_head(
	char * buf, 	/**< pointer to response header to be made */
	char type, 	/**< response type */
	u_long len	/**< size of response header */
	)
{
	char * head;
	char tmp[10];

	/*  file type*/
	if 	(type == PTYPE_HTML)	head = RES_HTMLHEAD_OK;
	else if (type == PTYPE_GIF)	head = RES_GIFHEAD_OK;
	else if (type == PTYPE_TEXT)	head = RES_TEXTHEAD_OK;
	else if (type == PTYPE_JPEG)	head = RES_JPEGHEAD_OK;
	else if (type == PTYPE_FLASH)	head = RES_FLASHHEAD_OK;
	else if (type == PTYPE_MPEG)	head = RES_MPEGHEAD_OK;
	else if (type == PTYPE_PDF)	head = RES_PDFHEAD_OK;

	sprintf(tmp,"%ld", len);	
	strcpy(buf, head);
	strcat(buf, tmp);
	strcat(buf, "\r\n\r\n");
}


/**
 @brief	find MIME type of a file
 */ 
void find_http_uri_type(
	u_char * type, 	/**< type to be returned */
	char * buf		/**< file name */
	) 
{
	/* Decide type according to extention*/
	if 	(strstr(buf, ".htm"))				*type = PTYPE_HTML;
	else if (strstr(buf, ".gif"))				*type = PTYPE_GIF;
	else if (strstr(buf, ".text") || strstr(buf,".txt"))	*type = PTYPE_TEXT;
	else if (strstr(buf, ".jpeg") || strstr(buf,".jpg"))	*type = PTYPE_JPEG;
	else if (strstr(buf, ".swf")) 				*type = PTYPE_FLASH;
	else if (strstr(buf, ".mpeg") || strstr(buf,".mpg"))	*type = PTYPE_MPEG;
	else if (strstr(buf, ".pdf")) 				*type = PTYPE_PDF;
	else if (strstr(buf, ".cgi") || strstr(buf,".CGI"))	*type = PTYPE_CGI;
	else 							*type = PTYPE_ERR;
}


/**
 @brief	parse http request from a peer
 */ 
void parse_http_request(
	st_http_request * request, 	/**< request to be returned */
	u_char * buf				/**< pointer to be parsed */
	)
{
	char * nexttok;
	nexttok = strtok((char*)buf," ");
	if(!nexttok)
	{
		request->METHOD = METHOD_ERR;
		return;
	}
	if 	(!strcmp(nexttok, "GET") || !strcmp(nexttok,"get"))
	{
		request->METHOD = METHOD_GET;
		nexttok = strtok(NULL," ");
	}
	else if (!strcmp(nexttok, "HEAD") || !strcmp(nexttok,"head"))	
	{
		request->METHOD = METHOD_HEAD;
		nexttok = strtok(NULL," ");
	}
	else if (!strcmp(nexttok, "POST") || !strcmp(nexttok,"post"))
	{
		nexttok = strtok(NULL,"\0");
		request->METHOD = METHOD_POST;
	}
	else
	{
		request->METHOD = METHOD_ERR;
}	
	
	if(!nexttok)
	{
		request->METHOD = METHOD_ERR;
		return;
	}
	strcpy(request->URI,nexttok);
	
}


/**
 @brief	get next parameter value in the request
 */ 
char* get_http_param_value(
	char* uri, 
	char* param_name
	)
{
	char tempURI[MAX_URI_SIZE];
	u_char* name=0;
	if(!uri || !param_name) return 0;
	
	strcpy((char*)tempURI,uri);
	if((name=strstr(tempURI,param_name)))
	{
		name += strlen(param_name) + 1; // strlen(para_name) + strlen("=")
		if((name = strtok(name,"& \r\n\t\0")))
		{
			unescape_http_url(name);
			replacetochar(name,'+',' ');
		}
	}
	return name;		
}


char* get_http_uri_name(char* uri)
{
	char tempURI[MAX_URI_SIZE];
	u_char* uri_name;
	if(!uri) return 0;
	strcpy((char*)tempURI,uri);
	uri_name = strtok(tempURI," ?");
	if(strcmp(uri_name,"/")) uri_name++;
	
	return uri_name;
}
