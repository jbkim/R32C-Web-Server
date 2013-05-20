;***********************************************************************;
;
;  C COMPILER for R32C/100
;  Copyright(C) 2005. Renesas Technology Corp.
;  and Renesas Solutions Corp., All rights reserved.
;
;  ncrt0.a30 : startup program
;
;  This program is applicable when using the basic I/O library
;
;  $Date: 2007/03/22 02:16:01 $
;  $Revision: 1.13 $
;
;***********************************************************************;
;-----------------------------------------------------------------------;
;
; 	Arrangement of section
;
;-----------------------------------------------------------------------;
;-----------------------------------------------------------------------;
; NEAR RAM SECTIONS                                                     ;
;-----------------------------------------------------------------------;
	.section	data_SB8, data
	.org		00000400H
data_SB8_top:
	.section	bss_SB8,	data, align
bss_SB8_top:
	.section	data_NEAR,	data, align
data_NEAR_top:
	.section	bss_NEAR,	data, align
bss_NEAR_top:
	.section	data_MON1,	data, align
data_MON1_top:
	.section	bss_MON1,	data, align
bss_MON1_top:
	.section	data_MON2,	data, align
data_MON2_top:
	.section	bss_MON2,	data, align
bss_MON2_top:
	.section	data_MON3,	data, align
data_MON3_top:
	.section	bss_MON3,	data, align
bss_MON3_top:
	.section	data_MON4,	data, align
data_MON4_top:
	.section	bss_MON4,	data, align
bss_MON4_top:

;-----------------------------------------------------------------------;
; STACK SECTION                                                         ;
;-----------------------------------------------------------------------;
	.section	stack, data, align
	.blkb		STACKSIZE
	.align
stack_top:
	.blkb		ISTACKSIZE
	.align
istack_top:

;-----------------------------------------------------------------------;
; HEAP SECTION                                                          ;
;-----------------------------------------------------------------------;
	.section	heap, data, align
heap_top:
	.blkb		HEAPSIZE

;-----------------------------------------------------------------------;
; SB RELATIVE RAM SECTIONS                                              ;
;-----------------------------------------------------------------------;
;	.section	data_SB8, data
;	.org		00008000H
;data_SB8_top:
;	.section	bss_SB8,	data, align
;bss_SB8_top:
;	.section	data_SB16,	data, align
;data_SB16_top:
;	.section	bss_SB16,	data, align
;bss_SB16_top:

;-----------------------------------------------------------------------;
; FAR RAM SECTIONS                                                      ;
;-----------------------------------------------------------------------;
	.section	data_FAR, data, align
data_FAR_top:
	.section	bss_FAR, data, align
bss_FAR_top:

;-----------------------------------------------------------------------;
; EXTENDED RAM SECTIONS                                                 ;
;-----------------------------------------------------------------------;
	.section	data_EXT, data
	.org		00800000H
data_EXT_top:
	.section	bss_EXT, data, align
bss_EXT_top:

;-----------------------------------------------------------------------;
; EXTENDED ROM SECTIONS                                                 ;
;-----------------------------------------------------------------------;
	.section	data_EXT_INIT, romdata
	.org		0FF000000H 
data_EXT_INIT_top:
	.section	rom_EXT, romdata, align
rom_EXT_top:
	.section	program_EXT, code, align

;-----------------------------------------------------------------------;
; FAR ROM SECTIONS                                                      ;
;-----------------------------------------------------------------------;
	.section	rom_FAR, romdata
	.org		0FFFC1000H;0FFF81000H MRE
rom_FAR_top:

;-----------------------------------------------------------------------;
; INITIAL DATA SECTIONS                                                 ;
;-----------------------------------------------------------------------;
	.section	data_NEAR_INIT,	romdata
	.org		0FFFD1000H ;0FFFF0000H ;-mre anpassung
data_NEAR_INIT_top:
	.section	data_MON1_INIT,	romdata, align
data_MON1_INIT_top:
	.section	data_MON2_INIT,	romdata, align
data_MON2_INIT_top:
	.section	data_MON3_INIT,	romdata, align
data_MON3_INIT_top:
	.section	data_MON4_INIT,	romdata, align
data_MON4_INIT_top:
	.section	data_SB8_INIT,	romdata, align
data_SB8_INIT_top:
;	.section	data_SB16_INIT,	romdata, align
;data_SB16_INIT_top:
	.section	data_FAR_INIT,	romdata, align
data_FAR_INIT_top:

;-----------------------------------------------------------------------;
; SWITCH TABLE SECTIONS                                                 ;
;-----------------------------------------------------------------------;
	.section	switch_table, romdata, align

;-----------------------------------------------------------------------;
; CODE SECTIONS                                                         ;
;-----------------------------------------------------------------------;
	.section	program, code, align

	.section	interrupt, code, align

;-----------------------------------------------------------------------;
; NEAR ROM SECTIONS                                                     ;
;-----------------------------------------------------------------------;
;	.section	rom_NEAR, romdata
;	.org		0FFFF8000H
;rom_NEAR_top:

;-----------------------------------------------------------------------;
; VARIABLE VECTOR SECTION                                               ;
;-----------------------------------------------------------------------;
	.section	vector,	romdata
	.org	VECTOR_ADR
.if	1	
	.lword	dummy_int	; BRK               (software int 0)
	.lword	dummy_int	; reservation area  (software int 1)
	.lword	dummy_int	; uart5 trance/NACK (software int 2)
	.lword	dummy_int	; uart5 receive/ACK (software int 3)
	.lword	dummy_int	; uart6 trance/NACK (software int 4)
	.lword	dummy_int	; uart6 receive/ACK (software int 5)
	.lword	dummy_int	; uart5/uart6 bus collision (software int 6)
	.lword	dummy_int	; reservation area  (software int 7)
	.lword	dummy_int	; DMA0              (software int 8)
	.lword	dummy_int 	; DMA1              (software int 9)
	.lword	dummy_int 	; DMA2              (software int 10)
	.lword	dummy_int 	; DMA3              (software int 11)
	.lword	dummy_int	; TIMER A0          (software int 12)
	.lword	dummy_int	; TIMER A1          (software int 13)
	.lword	dummy_int	; TIMER A2          (software int 14)
	.lword	dummy_int	; TIMER A3          (software int 15)
	.lword	dummy_int	; TIMER A4          (software int 16)
	.lword	dummy_int	; uart0 trance/NACK (software int 17)
	.lword	dummy_int	; uart0 receive/ACK (software int 18)
	.lword	dummy_int	; uart1 trance/NACK (software int 19)
	.lword	dummy_int	; uart1 receive/ACK (software int 20)
	.lword	dummy_int	; TIMER B0          (software int 21)
	.lword	dummy_int	; TIMER B1          (software int 22)
	.lword	dummy_int	; TIMER B2          (software int 23)
	.lword	dummy_int	; TIMER B3          (software int 24)
	.lword	dummy_int	; TIMER B4          (software int 25)
	.lword	dummy_int	; INT5              (software int 26)
	.lword	dummy_int	; INT4              (software int 27)
	.lword	dummy_int	; INT3              (software int 28)
	.lword	dummy_int	; INT2              (software int 29)
	.lword	dummy_int	; INT1              (software int 30)
	.lword	dummy_int	; INT0              (software int 31)
	.lword	dummy_int	; TIMER B5          (software int 32)
	.lword	dummy_int	; uart2 trance/NACK (software int 33)
	.lword	dummy_int	; uart2 receive/ACK (software int 34)
	.lword	dummy_int	; uart3 trance/NACK (software int 35)
	.lword	dummy_int	; uart3 receive/ACK (software int 36)
	.lword	dummy_int	; uart4 trance/NACK (software int 37)
	.lword	dummy_int	; uart4 receive/ACK (software int 38)
	.lword	dummy_int	; uart2       bus collision (software int 39)
	.lword	dummy_int	; uart3/uart0 bus collision (software int 40)
	.lword	dummy_int	; uart4/uart1 bus collision (software int 41)
	.lword	dummy_int	; A-D Convert        (software int 42)
	.lword	dummy_int	; input key          (software int 43)
	.lword	dummy_int	; intelligent I/O  0 (software int 44)
	.lword	dummy_int	; intelligent I/O  1 (software int 45)
	.lword	dummy_int	; intelligent I/O  2 (software int 46)
	.lword	dummy_int	; intelligent I/O  3 (software int 47)
	.lword	dummy_int	; intelligent I/O  4 (software int 48)
	.lword	dummy_int	; intelligent I/O  5 (software int 49)
	.lword	dummy_int	; intelligent I/O  6 (software int 50)
	.lword	dummy_int	; intelligent I/O  7 (software int 51)
	.lword	dummy_int	; intelligent I/O  8 (software int 52)
	.lword	dummy_int	; intelligent I/O  9 (software int 53)
	.lword	dummy_int	; intelligent I/O 10 (software int 54)
	.lword	dummy_int	; intelligent I/O 11 (software int 55)
	.lword	dummy_int	; reservation area   (software int 56)
	.lword	dummy_int	; reservation area   (software int 57)
	.lword	dummy_int	; reservation area   (software int 58)
	.lword	dummy_int	; CAN1WU             (software int 59)
	.lword	dummy_int	; reservation area   (software int 60)
	.lword	dummy_int	; reservation area   (software int 61)
	.lword	dummy_int	; reservation area   (software int 62)
	.lword	dummy_int	; reservation area   (software int 63)
	.lword	dummy_int	; reservation area   (software int 64)
	.lword	dummy_int	; reservation area   (software int 65)
	.lword	dummy_int	; reservation area   (software int 66)
	.lword	dummy_int	; reservation area   (software int 67)
	.lword	dummy_int	; Audio interface 0  (software int 68)
	.lword	dummy_int	; Sound field processor (software int 69)
	.lword	dummy_int	; reservation area   (software int 70)
	.lword	dummy_int	; reservation area   (software int 71)
	.lword	dummy_int	; reservation area   (software int 72)
	.lword	dummy_int	; reservation area   (software int 73)
	.lword	dummy_int	; reservation area   (software int 74)
	.lword	dummy_int	; reservation area   (software int 75)
	.lword	dummy_int	; reservation area   (software int 76)
	.lword	dummy_int	; reservation area   (software int 77)
	.lword	dummy_int	; reservation area   (software int 78)
	.lword	dummy_int	; reservation area   (software int 79)
	.lword	dummy_int	; reservation area   (software int 80)
	.lword	dummy_int	; reservation area   (software int 81)
	.lword	dummy_int	; reservation area   (software int 82)
	.lword	dummy_int	; reservation area   (software int 83)
	.lword	dummy_int	; reservation area   (software int 84)
	.lword	dummy_int	; reservation area   (software int 85)
	.lword	dummy_int	; reservation area   (software int 86)
	.lword	dummy_int	; reservation area   (software int 87)
	.lword	dummy_int	; reservation area   (software int 88)
	.lword	dummy_int	; reservation area   (software int 89)
	.lword	dummy_int	; reservation area   (software int 90)
	.lword	dummy_int	; reservation area   (software int 91)
	.lword	dummy_int	; reservation area   (software int 92)
	.lword	dummy_int	; INT8               (software int 93)
	.lword	dummy_int	; INT7               (software int 94)
	.lword	dummy_int	; INT6               (software int 95)
	.lword	dummy_int	; CAN0 trance        (software int 96)
	.lword	dummy_int	; CAN0 receive       (software int 97)
	.lword	dummy_int	; CAN0 error         (software int 98)
	.lword	dummy_int	; CAN1 trance        (software int 99)
	.lword	dummy_int	; CAN1 receive       (software int 100)
	.lword	dummy_int	; CAN1 error         (software int 101)
	.lword	dummy_int	; reservation area   (software int 102)
	.lword	dummy_int	; reservation area   (software int 103)
	.lword	dummy_int	; reservation area   (software int 104)
	.lword	dummy_int	; reservation area   (software int 105)
	.lword	dummy_int	; reservation area   (software int 106)
	.lword	dummy_int	; reservation area   (software int 107)
	.lword	dummy_int	; reservation area   (software int 108)
	.lword	dummy_int	; reservation area   (software int 109)
	.lword	dummy_int	; reservation area   (software int 110)
	.lword	dummy_int	; reservation area   (software int 111)
	.lword	dummy_int	; reservation area   (software int 112)
	.lword	dummy_int	; reservation area   (software int 113)
	.lword	dummy_int	; reservation area   (software int 114)
	.lword	dummy_int	; reservation area   (software int 115)
	.lword	dummy_int	; reservation area   (software int 116)
	.lword	dummy_int	; reservation area   (software int 117)
	.lword	dummy_int	; reservation area   (software int 118)
	.lword	dummy_int	; reservation area   (software int 119)
	.lword	dummy_int	; reservation area   (software int 120)
	.lword	dummy_int	; reservation area   (software int 121)
	.lword	dummy_int	; reservation area   (software int 122)
	.lword	dummy_int	; reservation area   (software int 123)
	.lword	dummy_int	; uart7 trance       (software int 124)
	.lword	dummy_int	; uart7 receive      (software int 125)
	.lword	dummy_int	; uart8 trance       (software int 126)
	.lword	dummy_int	; uart8 receive      (software int 127)
	.lword	dummy_int	; software int 128
	.lword	dummy_int	; software int 129
	.lword	dummy_int	; software int 130
	.lword	dummy_int	; software int 131
	.lword	dummy_int	; software int 132
	.lword	dummy_int	; software int 133
	.lword	dummy_int	; software int 134
	.lword	dummy_int	; software int 135
	.lword	dummy_int	; software int 136
	.lword	dummy_int	; software int 137
	.lword	dummy_int	; software int 138
	.lword	dummy_int	; software int 139
	.lword	dummy_int	; software int 140
	.lword	dummy_int	; software int 141
	.lword	dummy_int	; software int 142
	.lword	dummy_int	; software int 143
	.lword	dummy_int	; software int 144
	.lword	dummy_int	; software int 145
	.lword	dummy_int	; software int 146
	.lword	dummy_int	; software int 147
	.lword	dummy_int	; software int 148
	.lword	dummy_int	; software int 149
	.lword	dummy_int	; software int 150
	.lword	dummy_int	; software int 151
	.lword	dummy_int	; software int 152
	.lword	dummy_int	; software int 153
	.lword	dummy_int	; software int 154
	.lword	dummy_int	; software int 155
	.lword	dummy_int	; software int 156
	.lword	dummy_int	; software int 157
	.lword	dummy_int	; software int 158
	.lword	dummy_int	; software int 159
	.lword	dummy_int	; software int 160
	.lword	dummy_int	; software int 161
	.lword	dummy_int	; software int 162
	.lword	dummy_int	; software int 163
	.lword	dummy_int	; software int 164
	.lword	dummy_int	; software int 165
	.lword	dummy_int	; software int 166
	.lword	dummy_int	; software int 167
	.lword	dummy_int	; software int 168
	.lword	dummy_int	; software int 169
	.lword	dummy_int	; software int 170
	.lword	dummy_int	; software int 171
	.lword	dummy_int	; software int 172
	.lword	dummy_int	; software int 173
	.lword	dummy_int	; software int 174
	.lword	dummy_int	; software int 175
	.lword	dummy_int	; software int 176
	.lword	dummy_int	; software int 177
	.lword	dummy_int	; software int 178
	.lword	dummy_int	; software int 179
	.lword	dummy_int	; software int 180
	.lword	dummy_int	; software int 181
	.lword	dummy_int	; software int 182
	.lword	dummy_int	; software int 183
	.lword	dummy_int	; software int 184
	.lword	dummy_int	; software int 185
	.lword	dummy_int	; software int 186
	.lword	dummy_int	; software int 187
	.lword	dummy_int	; software int 188
	.lword	dummy_int	; software int 189
	.lword	dummy_int	; software int 190
	.lword	dummy_int	; software int 191
	.lword	dummy_int	; software int 192
	.lword	dummy_int	; software int 193
	.lword	dummy_int	; software int 194
	.lword	dummy_int	; software int 195
	.lword	dummy_int	; software int 196
	.lword	dummy_int	; software int 197
	.lword	dummy_int	; software int 198
	.lword	dummy_int	; software int 199
	.lword	dummy_int	; software int 200
	.lword	dummy_int	; software int 201
	.lword	dummy_int	; software int 202
	.lword	dummy_int	; software int 203
	.lword	dummy_int	; software int 204
	.lword	dummy_int	; software int 205
	.lword	dummy_int	; software int 206
	.lword	dummy_int	; software int 207
	.lword	dummy_int	; software int 208
	.lword	dummy_int	; software int 209
	.lword	dummy_int	; software int 210
	.lword	dummy_int	; software int 211
	.lword	dummy_int	; software int 212
	.lword	dummy_int	; software int 213
	.lword	dummy_int	; software int 214
	.lword	dummy_int	; software int 215
	.lword	dummy_int	; software int 216
	.lword	dummy_int	; software int 217
	.lword	dummy_int	; software int 218
	.lword	dummy_int	; software int 219
	.lword	dummy_int	; software int 220
	.lword	dummy_int	; software int 221
	.lword	dummy_int	; software int 222
	.lword	dummy_int	; software int 223
	.lword	dummy_int	; software int 224
	.lword	dummy_int	; software int 225
	.lword	dummy_int	; software int 226
	.lword	dummy_int	; software int 227
	.lword	dummy_int	; software int 228
	.lword	dummy_int	; software int 229
	.lword	dummy_int	; software int 230
	.lword	dummy_int	; software int 231
	.lword	dummy_int	; software int 232
	.lword	dummy_int	; software int 233
	.lword	dummy_int	; software int 234
	.lword	dummy_int	; software int 235
	.lword	dummy_int	; software int 236
	.lword	dummy_int	; software int 237
	.lword	dummy_int	; software int 238
	.lword	dummy_int	; software int 239
	.lword	dummy_int	; software int 240
	.lword	dummy_int	; software int 241
	.lword	dummy_int	; software int 242
	.lword	dummy_int	; software int 243
	.lword	dummy_int	; software int 244
	.lword	dummy_int	; software int 245
	.lword	dummy_int	; software int 246
	.lword	dummy_int	; software int 247
	.lword	dummy_int	; software int 248
	.lword	dummy_int	; software int 249
	.lword	dummy_int	; software int 250
	.lword	dummy_int	; software int 251
	.lword	dummy_int	; software int 252
	.lword	dummy_int	; software int 253
	.lword	dummy_int	; software int 254
	.lword	dummy_int	; software int 255
.endif

;-----------------------------------------------------------------------;
; FIXED VECTOR SECTION                                                  ;
;-----------------------------------------------------------------------;
	.section	fvector, romdata
	.org		0FFFFFFDCH
UDI:		.lword		dummy_int
OVER_FLOW:	.lword		dummy_int
BRKI:		.lword		dummy_int
		.lword		0FFFFFFFFH
		.lword		0FFFFFFFFH
WDT:		.lword		dummy_int
		.lword		dummy_int
NMI:		.lword		dummy_int
RESET:		.lword		start

;-----------------------------------------------------------------------;
; ID code DEFINITION                                                    ;
;-----------------------------------------------------------------------;
; ID code check function
; .id "CodeChk"

;***********************************************************************;
;                                                                       ;
;       End of R32C/100 start up                                        ;
;                                                                       ;
;***********************************************************************;
