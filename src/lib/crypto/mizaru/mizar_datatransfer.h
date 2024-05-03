/***************************************************
 * Introduction: Mizar data transfer define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/

#ifndef _MIZAR_DATA_TRANSFER_H_
#define _MIZAR_DATA_TRANSFER_H_

#include "mizar_basetype.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	mizar_uint16 dlen;
	mizar_uint16 plen;
	mizar_uint16 qlen;
	mizar_uint16 dplen;
	mizar_uint16 dqlen;
	mizar_uint16 qplen;
	mizar_uint16 nlen;
	mizar_uint16 elen;
	mizar_uint8* d;
	mizar_uint8* p;
	mizar_uint8* q;
	mizar_uint8* dp;
	mizar_uint8* dq;
	mizar_uint8* qp;
	mizar_uint8* n;
	mizar_uint8* e;
} TRSA;

/**********************************************************************************
 Desc: Convert the ASCII string to HEX data

 Input parameters:
     szAscBuf - ASCII string
     nConvLen - the length of the string.
     nType - 0-add 0 behind the string, if string len is odd number. "5A4" --> 0x5A, 0x40
			 1-add 0 before the string, if string len is odd number. "5A4" --> 0x05, 0xA4

 Output parameters:
     ucBcdBuf: HEX data

 Return value:
	 succeed - 0
	 falied - -1
**********************************************************************************/
mizar_int32 MizarAsc2bcd(
    mizar_uint8* ucBcdBuf, const mizar_char* szAscBuf, const mizar_uint32 nConvLen, const mizar_uint8 nType);

/**********************************************************************************
 Desc: Convert the HEX data to string

 Input parameters:
    ucBcdBuf - HEX data
    nConvLen - ucBcdBuf len
    nType - 0-not need append
			1-append the last char. if len is odd number.       0x5A, 0x4 --> 5A40

 Output parameters:
	szAscBuf - String data

 Return value:
	 succeed - 0
	 falied - -1
**********************************************************************************/
mizar_int32 MizarBcd2asc(
    mizar_char* szAscBuf, const mizar_uint8* ucBcdBuf, const mizar_uint32 nConvLen, const mizar_uint8 nType);

/**********************************************************************************
 Desc: Reverse the data in 4 bytes(int) for SPI 32 bits.

 Input parameters:
    pnSrc - source buffer
    nLen - data len by int type

 Output parameters:
    pnDst - destination buf

 Return value:
	 succeed - 0
	 falied - -1
**********************************************************************************/
mizar_int32 MizarSwapU32Buf(mizar_uint32* pnDst, const mizar_uint32* pnSrc, const mizar_uint32 nLen);

/**********************************************************************************
 Desc: put short data to buffer

 Input parameters:
    uSrc - source short data

 Output parameters:
    szDst - destination buffer

 Return value:
	succeed - 0
	falied - -1
**********************************************************************************/
mizar_int32 MizarPutShort(mizar_uint8* szDst, const mizar_uint32 uSrc);

/**********************************************************************************
 Desc: put integer data to buffer

 Input parameters:
    uSrc - source integer data

 Output parameters:
    szDst - destination buffer

 Return value:
	succeed- 0
	falied - -1
**********************************************************************************/
mizar_int32 MizarPutInt32(mizar_uint8* szDst, const mizar_uint32 uSrc);

/**********************************************************************************
 Desc: get short data from buffer

 Input parameters:
    szSrc - source buffer

 Output parameters:
    NULL

 Return value:
	succeed - the value of short data
	falied - 0
**********************************************************************************/
mizar_uint16 MizarGetShort(const mizar_uint8* szSrc);

/**********************************************************************************
 Desc: get int data from buffer

 Input parameters:
    szSrc - source buffer

 Output parameters:
    NULL

 Return value:
	succeed - the value of integer data
	falied - 0
**********************************************************************************/
mizar_uint32 MizarGetInt32(const mizar_uint8* szSrc);

/**********************************************************************************
 Desc: Trim the string, Delete spaces, newlines, tabs at both ends of the string

 Input parameters:
    pStr - the string to be trimed

 Output parameters:
    pStr - the string after trimed.

 Return value:
	0-success; 1-failed.
**********************************************************************************/
mizar_uint32 MizarTrim(mizar_char* pStr);

/**********************************************************************************
 Desc: Padding the data length to a multiple of 16 bytes

 Input parameters:
    in - the fill data
	pInLen - the pending data length
	force - Whether to force a padding id

 Output parameters:
    in - the filled data
	pInLen - the filled data length

 Return value:
	0-success; 1-failed.
**********************************************************************************/
mizar_uint32 MizarPaddingTo16(mizar_uint8* in, mizar_uint32* pInLen, mizar_uint8 force);

/**********************************************************************************
 Desc: Parse rsa key
 
 Input parameters:
	sk - rsa sk 

 Output parameters:
	rsa - rsa struct

 Return value:
	0-success; 1-failed.
**********************************************************************************/
mizar_uint8 MizarParseRsaKey(mizar_uint8* sk, TRSA* rsa);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version    Date		Author		Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-02-17	wujialin		create
 * @ 1.1		2022-02-17	wujialin		add fuction description & "extern 'C'"  declaration
 * @ 1.2		2022-02-18	wujialin		make functins' input parament to const
 * @ 1.3		2022-04-23	chenzhao		modify function comment
 * @ 1.4		2022-06-07	linzongfang	0001019: add MizarParseRsaKey
 * @ 1.5		2022-06-10	jianglu		0001080: modify return void type
 * @
 */
