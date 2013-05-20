/*
*
@file		type.h
*
*/

#ifndef _TYPE_H_
#define _TYPE_H_

#define	MAX_SOCK_NUM		4	/**< Maxmium number of socket  */

#define __DEF_IINCHIP_DIRECT_MODE__ 1
#define __DEF_IINCHIP_INDIRECT_MODE__ 2
#define __DEF_IINCHIP_SPI_MODE__ 3

//#define __DEF_IINCHIP_BUS__ __DEF_IINCHIP_DIRECT_MODE__
//#define __DEF_IINCHIP_BUS__ __DEF_IINCHIP_INDIRECT_MODE__
#define __DEF_IINCHIP_BUS__ __DEF_IINCHIP_SPI_MODE__ /*Enable SPI_mode*/


/**
@brief	 __DEF_IINCHIP_MAP_xxx__ : define memory map for iinchip 
*/
#define __DEF_IINCHIP_MAP_BASE__ 0x8000
#if (__DEF_IINCHIP_BUS__ == __DEF_IINCHIP_DIRECT_MODE__)
 #define COMMON_BASE __DEF_IINCHIP_MAP_BASE__
#else
 #define COMMON_BASE 0x0000
#endif
#define __DEF_IINCHIP_MAP_TXBUF__ (COMMON_BASE + 0x4000) /* Internal Tx buffer address of the iinchip */
#define __DEF_IINCHIP_MAP_RXBUF__ (COMMON_BASE + 0x6000) /* Internal Rx buffer address of the iinchip */


   #ifdef __DEF_IINCHIP_INT__
      // iinchip use external interrupt 4
      #define IINCHIP_ISR_DISABLE()	(EIMSK &= ~(0x10))
      #define IINCHIP_ISR_ENABLE()	(EIMSK |= 0x10)
      #define IINCHIP_ISR_GET(X)		(X = EIMSK)
      #define IINCHIP_ISR_SET(X)		(EIMSK = X)
   #else
      #define IINCHIP_ISR_DISABLE()
      #define IINCHIP_ISR_ENABLE()	
      #define IINCHIP_ISR_GET(X)
      #define IINCHIP_ISR_SET(X)
   #endif



#ifndef NULL
#define NULL		((void *) 0)
#endif

typedef enum { false, true } bool;

/*
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif
*/

/**
 * The 8-bit signed data type.
 */
typedef char int8;
/**
 * The volatile 8-bit signed data type.
 */
typedef volatile char vint8;
/**
 * The 8-bit unsigned data type.
 */
typedef unsigned char uint8;
/**
 * The volatile 8-bit unsigned data type.
 */
typedef volatile unsigned char vuint8;

/**
 * The 16-bit signed data type.
 */
//typedef int int16;
typedef short int16;
/**
 * The volatile 16-bit signed data type.
 */
typedef volatile int vint16;
/**
 * The 16-bit unsigned data type.
 */
//typedef unsigned int uint16;
typedef unsigned short uint16;

/**
 * The volatile 16-bit unsigned data type.
 */
//typedef volatile unsigned int vuint16;
typedef volatile unsigned short vuint16;

/**
 * The 32-bit signed data type.
 */
typedef long int32;
/**
 * The volatile 32-bit signed data type.
 */
typedef volatile long vint32;
/**
 * The 32-bit unsigned data type.
 */
typedef unsigned long uint32;
/**
 * The volatile 32-bit unsigned data type.
 */
typedef volatile unsigned long vuint32;

/* bsd */
typedef uint8			u_char;		/**< 8-bit value */
typedef uint8 			SOCKET;
typedef uint16			u_short;	/**< 16-bit value */
typedef uint16			u_int;		/**< 16-bit value */
typedef uint32			u_long;		/**< 32-bit value */

typedef union _un_l2cval {
	u_long	lVal;
	u_char	cVal[4];
}un_l2cval;

typedef union _un_i2cval {
	u_int	iVal;
	u_char	cVal[2];
}un_i2cval;


#define MAX_BUF_SIZE		2048

#define TX_BUF	0x7400
#define RX_BUF	(TX_BUF+MAX_BUF_SIZE)


/*----------- Definitions of port control ------------*/
#define HI			(uint8)0x01		// Port "H"	
#define LOW			(uint8)0x00		// Port "L"
#define OUT			(uint8)0x01		// Port output setting	
#define IN			(uint8)0x00		// Port input setting

#define LED_ON			0
#define LED_OFF			1	
#define MAX_LCD_SIZE		16

#endif		/* _TYPE_H_ */
