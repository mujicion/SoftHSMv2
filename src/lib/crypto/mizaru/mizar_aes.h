/***************************************************
  * Copyright 2002-2016 The OpenSSL Project Authors. All Rights Reserved.
  *
  * Licensed under the OpenSSL license (the "License").  You may not use
  * this file except in compliance with the License.  You can obtain a copy
  * in the file LICENSE in the source distribution or at
  * https://www.openssl.org/source/license.html

  * rijndael-alg-fst.c
  *
  * @version 3.0 (December 2000)
  *
  * Optimised ANSI C code for the Rijndael cipher (now AES)
  *
  * @author Vincent Rijmen
  * @author Antoon Bosselaers
  * @author Paulo Barreto
  *
  * This code is hereby placed in the public domain.
  *
  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ***************************************************/

#ifndef _MIZAR_AES_H_
#define _MIZAR_AES_H_

#include "mizar_basetype.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

# ifdef AES_LONG
typedef unsigned long u32;
# else
typedef unsigned int u32;
# endif
typedef unsigned short u16;
typedef unsigned char u8;

# if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_AMD64) || defined(_M_X64))
#  define SWAP(x) (_lrotl(x, 8) & 0x00ff00ff | _lrotr(x, 8) & 0xff00ff00)
#  define GETU32(p) SWAP(*((u32 *)(p)))
#  define PUTU32(ct, st) { *((u32 *)(ct)) = SWAP((st)); }
# else
#  define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ ((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
#  define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
# endif

/*
 * Because array size can't be a const in C, the following two are macros.
 * Both sizes are in bytes.
 */
#define AES_MAXNR      14
#define AES_BLOCK_SIZE 16


/* This should be a hidden type, but EVP requires that the size be known */
struct mizar_aes_key_st {
#ifdef AES_LONG
    unsigned long rd_key[4 * (AES_MAXNR + 1)];
#else
    unsigned int rd_key[4 * (AES_MAXNR + 1)];
#endif
    int rounds;
};

typedef struct mizar_aes_key_st MIZAR_AES_KEY;

#define AES_ENCRYPT 1
#define AES_DECRYPT 0

/***************************************************
 Desc: AES ECB mode calculate

 Input parameters:
    pData - input data for calculate
    nDataLen - bytes of input data
    pKey - input key data
    nKeyLen - bytes of key data, should be 16/24/32
    nMode - calculate flag:0-encrypt, 1-decrypt

 Output parameters:
    pOut - output calculate result

 Return value: 0 - Succeeded, -1 failures
 ***************************************************/
mizar_int32 MizarAESEcbCalcSoft(const mizar_uint8* pData, mizar_uint8* pOut, const mizar_uint32 nDataLen,
    const mizar_uint8* pKey, const mizar_uint32 nKeyLen, const mizar_uint32 nMode);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version    Date                Author              Note
 * @ -------------------------------------------------------------------------
 * @ 1.0        2022-3-4            wujialin            create
 * @
 */
