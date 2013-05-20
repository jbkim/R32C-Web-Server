/*********************************************
Project : M16C65 mit OLED C028 v. CHI MEI 
          OLED Driver and Library
          8-Bit Connection
Version : 1.0 Status: ready
Date    : 09.05.2008

Author  : M. Reinschmidt / GLYN GmbH & Co. KG
          P. Dörwald     / GLYN GmbH & Co. KG
		  
Releases: V1.1
			
Info    : V1.1 Anpassung der Initialisierungsroutine - Power Supply  			
  		
*********************************************/
#include "sfr111.h"

#include "OLED28.h"
#include "CourierNew10.h"
#include "FranklinGothicHeavy18.h"


/*********************************************************************
*    Koordinatengitter (rote Ecke rechts oben)                       *
*                                                                    *
*    0 ------------------------------------> 239 (x)                 *
*    |                                                               *
*    |                                                               *
*    |                                                               *
*    |                                                               *    
*    |                                                               *
*    |                                                               *
*   \/                                                               *
*   319 (y)                                                          *
*                                                                    *
*   Ausrichtung Text und Bilder:                                     *                                                                    
*   dir=0   \/                                                       *
*   dir=1  <---                                                      *
*   dir=2  --->                                                      *
**********************************************************************/
#define dir      1     // 0=senkrecht,  1=nach links,  2= nach rechts


/**************************************************************
***  Operating Instruction  ***********************************
**************************************************************/

void Index_out(unsigned char wert)
{
DB_OUT;

DB=wert; 
RDB=1;
RS=0;
NCS_L;
WRB=0;
WRB=1;
NCS_H;
}

/**************************************************************
***  Display Datenausgabe   ***********************************
**************************************************************/

void Parameter_out(unsigned int wert)
{
DB_OUT;
RDB=1;
DB=wert>>8; 

RS=1;
NCS_L;	
WRB=0;	
WRB=1;		//Daten übernehmen
NCS_H;	

//Niederwertiges Byte
DB=wert;  
NCS_L;	
WRB=0;	
WRB=1;		//Daten übernehmen 
NCS_H;	

}
/**************************************************************
***  Display Pixelausgabe   ***********************************
**************************************************************/

void Pixel_out(uch r, uch g, uch b)
{
DB_OUT;
RDB=1;
DB=r<<2;  
RS=1;
NCS_L;
WRB=0;
WRB=1;
NCS_H;

DB=g<<2;
NCS_L;
WRB=0;
WRB=1;
NCS_H;

DB=b<<2;
NCS_L;
WRB=0;
WRB=1;
NCS_H;

}

/**************************************************************
***  Initialisierung des OLED Displays   **********************
**************************************************************/

void init_S6E63D6_240X320_8Bit_80Mode(void)
{
 unsigned long i;
 
 Init;

 WRB=1;
 RDB=1;
 NCS_H;
 NRESET_L;
 NRESET_H;
 
 Index_out(0x24);
 Index_out(0x02);
 Parameter_out(0x0000);
 
 Index_out(0x03);
 Parameter_out(0x4120);    // 262k colour mode (3Bytes))  SS=1 0x4031
 
 Index_out(0x10);
 Parameter_out(0x0000);
 Index_out(0x05); // display on
 Parameter_out(0x0001);
 Index_out(0x22); 
 clearscreen();
 Power=1; // switch -NCP5810- power supply on for display 
}

/**************************************************************
***  Rahmen festlegen und mit Farbe füllen  *******************
**************************************************************/

void OLED_RECT(uch HSA, uch HEA, uin VSA, uin VEA, uch r, uch g, uch b)
{
   unsigned long i;

   ulo x;
   /*** Set Window address ***/
   Index_out(0x35);							  //Startpunkt VSA
   Parameter_out(VSA);						  

   Index_out(0x36);							  //Startpunkt VEA
   Parameter_out(VEA);						  

   Index_out(0x37);							  //Startpunkt VSA
   Parameter_out((int)((int)HSA<<8) | (int)HEA);	//HSA/HEA - hier y
//     	  for(i=0;i<0x500;i++) _asm("\tNOP");
 
   /*** Start address set ***/
   Index_out(0x20);							  
   Parameter_out(HSA);
   Index_out(0x21);							  
   Parameter_out(VSA);
		   
   /*** Index write ***/
   Index_out(0x22);
//   	  for(i=0;i<0x500;i++) _asm("\tNOP");
   for(x=0;x<((ulo)VEA-(ulo)VSA+1)*(ulo)(HEA-HSA+1);x++)
   {
     Pixel_out(r, g, b);
   
   } 
    Index_out(0x00); 
}
 
/**************************************************************
***  Rahmen festlegen  ****************************************
**************************************************************/

void OLED_FRAME(uch HSA, uch HEA, uch VSA, uch VEA)
 {
  unsigned long i;
  
  /*** Set Window address ***/
  Index_out(0x00);		//Startpunkt
  Index_out(0x21);		//festlegen
  Parameter_out(HSA);	//X0
  Parameter_out(VSA);	//Y0
//    	  for(i=0;i<0x500;i++) _asm("\tNOP");
 
  /*** Rahmen festlegen ***/
  Index_out(0x00);
  Index_out(0x23);		//0 <= VSA <= VEA <= maxy
  Parameter_out(VEA);	//Vertikal Ende
  Parameter_out(VSA);	//Vertikal Anfang
  
  Index_out(0x00);
  Index_out(0x24);		//0 <= HSA <= HEA <= maxx
  Parameter_out(HEA);	//Horizontal Ende
  Parameter_out(HSA);	//Horizontal Anfang
//  for(i=0;i<0x500;i++) _asm("\tNOP");
 }

/**************************************************************
***  Setzen eines ASCII-Zeichens an Cursorposition   **********
**************************************************************/
void Draw_ASCII_down(uch font, uin xpo, uin ypo, uch red_bg, uch green_bg, uch blue_bg, uch red_text, uch green_text, uch blue_text, char sign)
{
 uch hor,vert;
  uin xsize,ysize;
  
   if (font==1)
   {
   xsize=char_xsize_f;
   ysize=char_ysize_f;
   }
   if (font==2)
   {
   xsize=char_xsize_c;
   ysize=char_ysize_c;
   }
   
   

  /*** Set Window address ***/
   Index_out(0x35);							  //Startpunkt VSA
   Parameter_out(ypo);						  

   Index_out(0x36);							  
   Parameter_out(ypo+ysize-1);						  

   Index_out(0x37);							  //Startpunkt
   Parameter_out((int)((int)xpo<<8) | (int)(xpo+xsize-1));	//HSA/HEA 
   
   /*** Start address set ***/
   Index_out(0x20);							  
   Parameter_out(xpo);
   Index_out(0x21);							  
   Parameter_out(ypo);
   
   Index_out(0x03);
   Parameter_out(0x4130);
   
   /*** Index write ***/
   Index_out(0x22);
   
   if(sign>127|sign<32)sign=' ';      //uerwuenschte Zeichen abfangen
  
  if (font==1)
  {
   for(vert=0;vert<ysize;vert++)
   {
    for(hor=0;hor<xsize;hor++)
    {
     if((FranklinGothicHeavy18[sign-32][vert]>>(31-hor))&0x00000001)
     {
      Pixel_out(red_text, green_text,blue_text);
     }
     else
     {
      Pixel_out(red_bg, green_bg,blue_bg);
     }
    }
   }
  } 
  
  if (font==2)
  {
   for(vert=0;vert<ysize;vert++)
   {
    for(hor=0;hor<xsize;hor++)
    {
     if((CourierNew10[sign-32][vert]>>(31-hor))&0x00000001)
     {
      Pixel_out(red_text, green_text,blue_text);
     }
     else
     {
      Pixel_out(red_bg, green_bg,blue_bg);
     }
    }
   }
  }  

}

void Draw_ASCII_left(uch font, uin xpo, uin ypo, uch red_bg, uch green_bg, uch blue_bg, uch red_text, uch green_text, uch blue_text, char sign)
{
 uch hor,vert;
  uin xsize,ysize;
  
   if (font==1)
   {
   xsize=char_xsize_f;
   ysize=char_ysize_f;
   }
   if (font==2)
   {
   xsize=char_xsize_c;
   ysize=char_ysize_c;
   }
   
   

  /*** Set Window address ***/
   Index_out(0x35);							  //Startpunkt VSA
   Parameter_out(ypo);						  

   Index_out(0x36);							  
   Parameter_out(ypo+xsize-1);						  

   Index_out(0x37);							  //Startpunkt
   Parameter_out((int)((int)xpo<<8) | (int)(xpo+ysize-1));	//HSA/HEA 
   
   /*** Start address set ***/
   Index_out(0x20);							  
   Parameter_out(xpo);
   Index_out(0x21);							  
   Parameter_out(ypo);
   
   Index_out(0x03);
   Parameter_out(0x4121);
   
   /*** Index write ***/
   Index_out(0x22);
   
   if(sign>127|sign<32)sign=' ';      //uerwuenschte Zeichen abfangen
  
  if (font==1)
  {
   for(vert=0;vert<ysize;vert++)
   {
    for(hor=0;hor<xsize;hor++)
    {
     if((FranklinGothicHeavy18[sign-32][vert]>>(31-hor))&0x00000001)
     {
      Pixel_out(red_text, green_text,blue_text);
     }
     else
     {
      Pixel_out(red_bg, green_bg,blue_bg);
     }
    }
   }
  } 
  
  if (font==2)
  {
   for(vert=0;vert<ysize;vert++)
   {
    for(hor=0;hor<xsize;hor++)
    {
     if((CourierNew10[sign-32][vert]>>(31-hor))&0x00000001)
     {
      Pixel_out(red_text, green_text,blue_text);
     }
     else
     {
      Pixel_out(red_bg, green_bg,blue_bg);
     }
    }
   }
  }  

}

void Draw_ASCII_right(uch font, uin xpo, uin ypo, uch red_bg, uch green_bg, uch blue_bg, uch red_text, uch green_text, uch blue_text, char sign)
{
 uch hor,vert;
  uin xsize,ysize;
  
   if (font==1)
   {
   xsize=char_xsize_f;
   ysize=char_ysize_f;
   }
   if (font==2)
   {
   xsize=char_xsize_c;
   ysize=char_ysize_c;
   }
   
   

  /*** Set Window address ***/
   Index_out(0x35);							  //Startpunkt VSA
   Parameter_out(ypo);						  

   Index_out(0x36);							  
   Parameter_out(ypo+xsize-1);						  

   Index_out(0x37);							  //Startpunkt
   Parameter_out((int)((int)xpo<<8) | (int)(xpo+ysize-1));	//HSA/HEA 
   
   /*** Start address set ***/
   Index_out(0x20);							  
   Parameter_out(xpo);
   Index_out(0x21);							  
   Parameter_out(ypo);
   
   Index_out(0x03);
   Parameter_out(0x4111);
   
   /*** Index write ***/
   Index_out(0x22);
   
   if(sign>127|sign<32)sign=' ';      //uerwuenschte Zeichen abfangen
  
  if (font==1)
  {
   for(vert=0;vert<ysize;vert++)
   {
    for(hor=0;hor<xsize;hor++)
    {
     if((FranklinGothicHeavy18[sign-32][vert]>>(31-hor))&0x00000001)
     {
      Pixel_out(red_text, green_text,blue_text);
     }
     else
     {
      Pixel_out(red_bg, green_bg,blue_bg);
     }
    }
   }
  } 
  
  if (font==2)
  {
   for(vert=0;vert<ysize;vert++)
   {
    for(hor=0;hor<xsize;hor++)
    {
     if((CourierNew10[sign-32][vert]>>(31-hor))&0x00000001)
     {
      Pixel_out(red_text, green_text,blue_text);
     }
     else
     {
      Pixel_out(red_bg, green_bg,blue_bg);
     }
    }
   }
  }  

}


/**************************************************************
***  Setzen eines horizontalen Strings an Cursorposition    ***
***************************************************************/

void printstring_h(uch font, uch red_b, uch green_b, uch blue_b, uch red_t, uch green_t, uch blue_t, uin x, uin y, char  *string)
{
while(*string != 0x00)
{
 if(font==1) //FranklinGothicHeavy18
 {
  Draw_ASCII_down(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, *string++);
  x+=char_xsize_f-corr;
 }
 if(font==2) //CourierNew10
 {
 Draw_ASCII_down(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, *string++);
  x+=char_xsize_c-corr2;
 } 
}
}

/***********************************************************************
***  Setzen eines vertikalen Strings nach links an Cursorposition    ***
************************************************************************/

void printstring_l(uch font, uch red_b, uch green_b, uch blue_b, uch red_t, uch green_t, uch blue_t, uin x, uin y, char  *string)
{
while(*string != 0x00)
{
 if(font==1) //FranklinGothicHeavy18
 {
  Draw_ASCII_left(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, *string++);
  y+=char_xsize_f-corr;
 }
 if(font==2) //CourierNew10
 {
 Draw_ASCII_left(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, *string++);
  y+=char_xsize_c-corr2;
 } 
}
}

/***********************************************************************
***  Setzen eines vertikalen Strings nach links an Cursorposition    ***
************************************************************************/

void printstring_r(uch font, uch red_b, uch green_b, uch blue_b, uch red_t, uch green_t, uch blue_t, uin x, uin y, char  *string)
{
while(*string != 0x00)
{
 if(font==1) //FranklinGothicHeavy18
 {
  Draw_ASCII_right(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, *string++);
  y-=char_xsize_f-corr;
 }
 if(font==2) //CourierNew10
 {
 Draw_ASCII_right(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, *string++);
  y-=char_xsize_c-corr2;
 } 
}
}

void printnum_h(uch font, uch red_b, uch green_b, uch blue_b, uch red_t, uch green_t, uch blue_t, uin x, uin y,unsigned long int num)
{
unsigned long int i;
unsigned long int dummy;
char Zeichen;

for(i = 1; i <= num; i= i*10){};
i = i/10;
for( ; i>2; )
	{
	 dummy = num;
	 dummy = dummy /i;
	 Zeichen = dummy + 0x30;
	 if(font==1) //FranklinGothicHeavy18
 {
  Draw_ASCII_down(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, Zeichen);
  x+=char_xsize_f-corr;
 }
 if(font==2) //CourierNew10
 {
 Draw_ASCII_down(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, Zeichen);
  x+=char_xsize_c-corr2;
 } 

	 num = num - (dummy * i);
	 i = i/10;  
	};
Zeichen = num + 0x30;
if(font==1) //FranklinGothicHeavy18
 {
  Draw_ASCII_down(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, Zeichen);
  x+=char_xsize_f-corr;
 }
 if(font==2) //CourierNew10
 {
 Draw_ASCII_down(font, x, y, red_b, green_b, blue_b, red_t, green_t, blue_t, Zeichen);
  x+=char_xsize_c-corr2;
 } 

}


void picture(uch HSA, uch HEA, uin VSA, uin VEA, uin  *tile)
{
  ulo x;

    /*** Set Window address ***/
   Index_out(0x35);							  //Startpunkt VSA
   Parameter_out(VSA);						  

   Index_out(0x36);							  //Startpunkt VEA
   Parameter_out(VEA);						  

   Index_out(0x37);							  //Startpunkt VSA
   Parameter_out((int)((int)HSA<<8) | (int)HEA);	//HSA/HEA - hier y
   
   /*** Start address set ***/
   Index_out(0x20);							  
   Parameter_out(HSA);
   Index_out(0x21);							  
   Parameter_out(VSA);
   
   Index_out(0x03);
   #if dir==0
   Parameter_out(0x4130);
   #endif
   
   #if dir==1
   Parameter_out(0x4121);
   #endif
   
   #if dir==2
   Parameter_out(0x4111);
   #endif
   
   			   
   /*** Index write ***/
   Index_out(0x22);
   
   for(x=0;x<((ulo)VEA-(ulo)VSA+1)*(ulo)(HEA-HSA+1);x++)
   {
     Pixel_out((uin)*tile>>9, (uin)*tile>>4,(uin)*tile<<1);
//     Pixel_out((uin)*tile>>7, (uin)*tile>>2,(uin)*tile<<3);
     *tile++;
   
   } 
    Index_out(0x00); 
    Index_out(0x03);
    Parameter_out(0x4120);    // Defaulteinstellung
}   

void clearscreen(void)
{
OLED_RECT(0, 240, 0, 320, 0x00,0x00,0x00);
}

/*************** Scrolling ****************/
void scroll(uin SSA, uin SEA, uin SST)
{
 Index_out(0x30);							  
 Parameter_out(SSA);
 
 Index_out(0x31);							  
 Parameter_out(SEA);
 
 Index_out(0x32);							  
 Parameter_out(SST);

}

