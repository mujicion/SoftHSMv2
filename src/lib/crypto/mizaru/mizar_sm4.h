/***************************************************
 * Introduction: mizar sm4 define
 *
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 ***************************************************/

#ifndef _MIZAR_SM4_H_
#define _MIZAR_SM4_H_

#include "mizar_basetype.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SM4_ENCRYPT 1
#define SM4_DECRYPT 0

#define MAX_CALC_LEN 2048
#define MAX_BUFF_LEN MAX_CALC_LEN + 16

typedef struct {
	mizar_int32 mode;
	mizar_ulong sk[32];
} sm4_context;

/**********************************************************************************
Desc:SM4-ECB encryption and decryption algorithm

Input parameters:
    szInData: data to be calculated
    nLength:Length operates on the length of the data, which must be an integer multiple of 16
    szKey:Key Arithmetic key, fixed length 16 bytes
    nEncFlag encryption and decryption identification: 1-encrypted; 0 - Decrypt

Output parameters:
    szOutData: evaluates the result

Return value: 0 - Succeeded, other failures
**********************************************************************************/
mizar_uint32 MizarSM4EcbCalcSoft(mizar_uint8* szInData, mizar_uint8* szOutData, const mizar_uint32 nLength,
    mizar_uint8* szKey, const mizar_int32 nEncFlag);

/**********************************************************************************
Desc: SM4-CBC encryption and decryption algorithm

Input parameters:
    szIV: Initialization vector
    szInData: data to be calculated
    nLength:Length operates on the length of the data, which must be an integer multiple of 16
    szKey: Arithmetic key, fixed length 16 bytes
    nEncFlag: encryption and decryption identification: 1-encrypted; 0 - Decrypt

Output parameters:
    szOutData: evaluates the result

Return value: 0 - Succeeded, other failures
**********************************************************************************/
mizar_uint32 MizarSM4CbcCalcSoft(mizar_uint8* szIV, mizar_uint8* szInData, mizar_uint8* szOutData,
    const mizar_uint32 nLength, mizar_uint8* szKey, const mizar_int32 nEncFlag);

/**********************************************************************************
Desc: SM4-CBC-MAC algorithm

Input parameters:
    szIV: Initialization vector
    szInData: data to be calculated
    nLength: calculates the length of the data
    szKey: Arithmetic key, fixed length 16 bytes

Output parameters:
    szMac: calculation result

Note:
	szInData will be padding to 16x len, so in should be allocate space len: real datalen + 16 bytes

Return value: 0 - Succeeded, other failures
**********************************************************************************/
mizar_uint32 MizarSM4MacCbcSoft(
    mizar_uint8* szIV, mizar_uint8* szKey, mizar_uint8* szInData, const mizar_uint32 nLength, mizar_uint8 szMac[16]);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author	Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-02-11	jianglu	create
 * @ 1.1		2022-04-13	jianglu	add Note to MizarSM4MacCbcSoft
 */