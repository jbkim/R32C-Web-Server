/*********************************************
Project : M16C65 mit OLED C028 v. CHI MEI 
          OLED Definitionen
          8-Bit Connection
Version : 0.1 Status: ready
Date    : 25.04.2008

Author  : P.Dörwald / GLYN GmbH & Co. KG

Releases: 	V0.1
			
Info    :   			
  		
*********************************************/
#define uch      unsigned char
#define uin      unsigned int
#define ulo      unsigned long int
#define corr     7
#define corr2    1


void Index_out(unsigned char wert);
void Parameter_out(unsigned int wert);
void Pixel_out(uch r, uch g, uch b);
void init_S6E63D6_240X320_8Bit_80Mode(void);
void OLED_RECT(uch HSA, uch HEA, uin VSA, uin VEA, uch r, uch g, uch b);
void OLED_FRAME(uch HEA, uch HSA, uch VEA, uch VSA);
void Draw_ASCII_down(uch font, uin xpo, uin ypo, uch red_bg, uch green_bg, uch blue_bg, uch red_text, uch green_text, uch blue_text, char sign);
void Draw_ASCII_left(uch font, uin xpo, uin ypo, uch red_bg, uch green_bg, uch blue_bg, uch red_text, uch green_text, uch blue_text, char sign);
void Draw_ASCII_right(uch font, uin xpo, uin ypo, uch red_bg, uch green_bg, uch blue_bg, uch red_text, uch green_text, uch blue_text, char sign);
void printstring_h(uch font, uch red_b, uch green_b, uch blue_b, uch red_t, uch green_t, uch blue_t, uin x, uin y, char  *string);
void printstring_l(uch font, uch red_b, uch green_b, uch blue_b, uch red_t, uch green_t, uch blue_t, uin x, uin y, char  *string);
void printstring_r(uch font, uch red_b, uch green_b, uch blue_b, uch red_t, uch green_t, uch blue_t, uin x, uin y, char  *string);
void printnum_h(uch font, uch red_b, uch green_b, uch blue_b, uch red_t, uch green_t, uch blue_t, uin x, uin y,unsigned long int num);

void picture(uch HSA, uch HEA, uin VSA, uin VEA, uin  *tile);
void clearscreen(void);
void scroll(uin SSA, uin SEA, uin SST);

/*
// Defines für OLED
#define DB_IN    pd2 = 0x00
#define DB_OUT   pd2 = 0xFF
#define DB       p2
#define NCS_H    p1_7 = 1
#define NCS_L    p1_7 = 0
#define NRESET_L p0_2 = 0
#define NRESET_H p0_2 = 1
#define RS       p1_5
#define WRB      p1_6
#define RDB      p0_3
#define Init     pd1 = 0xE0; pd0 = 0x0C; pd8_2=1;

#define Power	p8_2

#define win1x   320
#define win1y   240
*/

// Defines f?r OLED
#define DB_IN    pd2 = 0x00
#define DB_OUT   pd2 = 0xFF
#define DB       p2
#define NCS_H    p1_7 = 1
#define NCS_L    p1_7 = 0
#define NRESET_L p7_6=1
#define NRESET_H p7_6=1
#define RS       p1_5
#define WRB      p1_6
#define RDB      p7_5
#define Init     pd1 = 0xE0; pd7 = 0x60; pd8_2=1;

#define Power	p8_2

#define win1x   320
#define win1y   240


