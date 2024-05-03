/***************************************************
 * Introduction: mizar gm define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/
#ifndef _MIZAR_GM_H_
#define _MIZAR_GM_H_

#include "mizar_basetype.h"
#include "mizar_key_manager.h"

#define MAX_DATA_LEN	 2000
#define MAX_SDIO_SM4_LEN 8160
#define MAX_SM4_LEN	 2016

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: SM2 signature, using an external key

Input parameters:
    szSK - private key
    nHashFlag - hash flags: 0 - no hash; 1 - hash before signing
    nDataLen - The length of the nDataLen data to be signed
    szData - data to be signed

Output parameters:
    szR - public key R
    szS - public key S

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2Sign(mizar_uint8* szSK, mizar_uint32 nHashFlag, mizar_uint32 nDataLen, mizar_uint8* szData,
    mizar_uint8* szR, mizar_uint8* szS);

/**********************************************************************************
Desc: SM2 signature, using an internal key

Input parameters:
    nKeyIndex - key pair index
    nHashFlag - hash flags: 0 - no hash; 1 - hash before signing
    nDataLen - The length of the nDataLen data to be signed
    szData - data to be signed

Output parameters:
    szR - public key R
    szS - public key S

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2SignIndex(mizar_uint32 nKeyIndex, mizar_uint32 nHashFlag, mizar_uint32 nDataLen,
    mizar_uint8* szData, mizar_uint8* szR, mizar_uint8* szS);

/**********************************************************************************
Desc: SM2 signature verification

Input parameters:
    szX - public key X
    szY - public key Y
    szR - signature R
    szS - signature S
    nHashFlag - hash flags: 0 - no hash; 1 - hash before verifying the signature
    nDataLen - The length of the signature data to be verified
    szData - signature data to be verified

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2Verify(mizar_uint32 nHashFlag, mizar_uint8* szX, mizar_uint8* szY, mizar_uint8* szR,
    mizar_uint8* szS, mizar_uint32 nDataLen, mizar_uint8* szData);

/**********************************************************************************
Desc: SM2 public key cryptography

Input parameters:
    szX - public key X
    szY - public key Y
    nDataLen - The length of the data to be evaluated
    szData - data to be calculated

Output parameters:
    pOutLen - output data length
    szOutData - output data

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2PkEnc(mizar_uint8* szX, mizar_uint8* szY, mizar_uint32 nDataLen, mizar_uint8* szData,
    mizar_uint32* pOutLen, mizar_uint8* szOutData);

/**********************************************************************************
Desc: The SM2 private key is decrypted using the external private key

Input parameters:
    szSK - private key
    nDataLen - The length of the data to be evaluated
    szData - data to be calculated

Output parameters:
    pOutLen - output data length
    szOutData - output data

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2SkDec(
    mizar_uint8* szSK, mizar_uint32 nDataLen, mizar_uint8* szData, mizar_uint32* pOutLen, mizar_uint8* szOutData);

/**********************************************************************************
Desc: The SM2 private key is decrypted using the internal private key

Input parameters:
    nKeyIndex - key pair index
    nDatalen - The length of the data to be evaluated
    szData - data to be calculated

Output parameters:
    pOutLen - output data length
    szOutData - output data

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2SkDecIndex(
    mizar_uint32 nKeyIndex, mizar_uint32 nDatalen, mizar_uint8* szData, mizar_uint32* pOutLen, mizar_uint8* szOutData);

/**********************************************************************************
Desc: Set the calculated IDA value when setting sm2 signature verification
    If the function is not called, then the default IDA default is
    {0x43, 0x68, 0x69, 0x6E, 0x61}["China"]

Input parameters:
    nUidLen - UID length[1-32]
    szUid - The value of IDA, in hexadecimal format

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSetSM2Uid(mizar_uint32 nUidLen, mizar_uint8* szUid);

/**********************************************************************************
Desc: Get IDA data stored in the SDK

Input parameters:
    none

Output parameters:
    pUidLen - UID length[1-32]
    szUid - The value of IDA, in hexadecimal format

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarGetSM2Uid(mizar_uint32* pUidLen, mizar_uint8* szUid);

/**********************************************************************************
Desc: SM2 signature, using an external key, data first using SM3-E to perform
      HASH IDA = "China"

Input parameters:
    szSK - private key
    nDataLen - The length of
	       the nDataLen data to be signed
    szData - data to be signed
    szX - public key X
    szY - public key Y

Output parameters:
    szR - signature R
    szS - signature S

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2SignWithIDA(mizar_uint8* szSK, mizar_uint32 nDataLen, mizar_uint8* szData, mizar_uint8* szX,
    mizar_uint8* szY, mizar_uint8* szR, mizar_uint8* szS);

/**********************************************************************************
Desc: SM2 signature, internal key, data first using SM3-E to perform HASH
	IDA = "China"
Input parameters:
    nKeyIndex key pair index
    The length of the nDataLen data to be signed
    szData data to be signed
    szX public key X
    szY public key Y
Output parameters:
    szR signature R
    szS signature S

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2SignIndexWithIDA(mizar_uint32 nKeyIndex, mizar_uint32 nDataLen, mizar_uint8* szData,
    mizar_uint8* szX, mizar_uint8* szY, mizar_uint8* szR, mizar_uint8* szS);

/**********************************************************************************
Desc: SM2 signature verification, data first perform SM3-E hash
    IDA = "China"
Input parameters:
    szX - public key X
    szY - public key Y
    szR - signature R
    szS - signature S
    nDataLen - The length of the signature data to be verified
    szData - signature data to be verified

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM2VerifyWithIDA(
    mizar_uint8* szX, mizar_uint8* szY, mizar_uint8* szR, mizar_uint8* szS, mizar_uint32 nDataLen, mizar_uint8* szData);

/**********************************************************************************
Desc: SM4 encryption and decryption ECB mode

Input parameters:
    nMode - operation mode: 0- encrypted; 1 - decrypted
    nDataLen - The length of the data to be evaluated
    szData - data to be calculated
    szKey - calculates the key

Output parameters:
    nOutLen - The length of the nOutlen operation result
    szOutData - operation result

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM4Ecb(mizar_uint32 nMode, mizar_uint8* szKey, mizar_uint32 nDataLen, mizar_uint8* szData,
    mizar_uint32* pOutLen, mizar_uint8* szOutData);

/**********************************************************************************
Desc:SM4 encryption and decryption ECB mode, using internal key

Input parameters:
    nMode - operation mode: 0- encrypted; 1 - decrypted
    nDatalen - The length of the data to be evaluated
    szData - data to be calculated
    nKeyIndex - operates the key index

Output parameters:
    pOutLen - The length of the nOutlen operation result
    szOutData - operation result

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM4EcbIndex(mizar_uint32 nMode, mizar_uint32 nKeyIndex, mizar_uint32 nDataLen, mizar_uint8* szData,
    mizar_uint32* pOutLen, mizar_uint8* szOutData);

/**********************************************************************************
Desc:SM4 encryption and decryption CBC/OFB/CTR mode

Input parameters:
    nMode - operation mode: 0- encrypted; 1 - decrypted
    nAlg - Operation method: 0-CBC; 1-OFB; 2-CTR
    szIV - initialization vector
    nDatalen - The length of the data to be evaluated
    szData - data to be calculated
    szKey - calculates the key

Output parameters:
    pOutLen - The length of the nOutlen operation result
    szOutData - operation result

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM4Modes(mizar_uint32 nMode, mizar_uint32 nAlg, mizar_uint8* szIV, mizar_uint8* szKey,
    mizar_uint32 nDataLen, mizar_uint8* szData, mizar_uint32* pOutLen, mizar_uint8* szOutData);

/**********************************************************************************
Desc:SM4 encrypts and decrypts CBC/OFB/CTR mode, using an internal key

Input parameters:
    nMode - operation mode: 0- encrypted; 1 - decrypted
    nAlg - Operation method: 0-CBC; 1-OFB; 2-CTR
    szIV - initialization vector
    nDatalen - The length of the data to be evaluated
    szData - data to be calculated
    nKeyIndex - operates the key index

Output parameters:
    pOutLen - The length of the nOutlen operation result
    szOutData - operation result

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM4ModesIndex(mizar_uint32 nMode, mizar_uint32 nAlg, mizar_uint8* szIV, mizar_uint32 nKeyIndex,
    mizar_uint32 nDataLen, mizar_uint8* szData, mizar_uint32* pOutLen, mizar_uint8* szOutData);

/********************************************************************************
Desc: SM4 Encryption and Decryption CCM Mode, External Key (Soft Algorithm)

Input parameters:
    nMode - operation mode: 0- encrypted; 1 - decrypted
    nIVLen - IV length[7-13]
    szIV - initializes vector data
    nDatalen - data length to be calculated:
	    if nMode = 0 data length [1-1024]
	    If nMode = 1 data length [17-1040]
    szData - data to be computed, if nMode = 1, data format:
	    ciphertext || Label (16 bytes)
    szKey - arithmetic key, fixed length 16 bytes

Output parameters:
    pOutLen - The length of the pnOutlen operation result
    szOutData - operation result if nMode = 0, data format: ciphertext || Label
(16 bytes)

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarSM4CcmSoft(mizar_uint32 nMode, mizar_uint8* szKey, mizar_uint32 nIVLen, mizar_uint8* szIV,
    mizar_uint32 nDataLen, mizar_uint8* szData, mizar_uint32* pOutLen, mizar_uint8* szOutData);

/**********************************************************************************
Desc: SM3 hash initialization Init

Input parameters:
    none

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM3Init(void);

/**********************************************************************************
Desc: SM3 Hash Update

Input parameters:
    nDatalen - data length, if multiple updates, except for the last update
length is unlimited Other update data must be an integer multiple of 64 szData -
calculates the data

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM3Update(mizar_uint32 nDataLen, mizar_uint8* szData);

/**********************************************************************************
Desc: SM3 hash Final

Input parameters:
    none

Output parameters:
    szHash - hash result, fixed length 32 bytes

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM3Final(mizar_uint8* szHash);

/**********************************************************************************
Desc: SM3 hash

Input parameters:
    nDatalen data length
    szData calculates the data

Output parameters:
    szHash hash result, fixed length 32 bytes

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM3(mizar_uint32 nDatalen, mizar_uint8* szData, mizar_uint8* szHash);

/**********************************************************************************
Desc: Zu Chongzhi's algorithm is encrypted and decrypted

Input parameters:
    szCount - frame sequence numberCOUNT, 4 bytes of fixed-length data, default
is 0 nBearer - The bearer layer identifies BEARER nDirection - The direction
transmit direction identifies DIRECTION: 0 - upstream; 1 - downstream, which can
default to 0 nDatalen - The length of the data to be evaluated szData - data to
be calculated szKey - calculates the key

Output parameters:
    szOutData - operation result

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarZucEnc(mizar_uint8* szCount, mizar_uint8 nBearer, mizar_uint8 nDirection, mizar_uint32 nDataLen,
    mizar_uint8* szData, mizar_uint8* szKey, mizar_uint8* szOutData);

/**********************************************************************************
Desc: Zu Chongzhi's algorithm encrypts and decrypts, using an internal key

Input parameters:
    szCount - frame sequence numberCOUNT, 4 bytes of fixed-length data, default
is 0 nBearer - The bearer layer identifies BEARER nDirection - The direction
transmit direction identifies DIRECTION: 0 - upstream; 1 - downstream, which can
default to 0 nDatalen - The length of the data to be evaluated szData - data to
be calculated nIndex - operates the key index

Output parameters:
    szOutData - operation result

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarZucEncIndex(mizar_uint8* szCount, mizar_uint8 nBearer, mizar_uint8 nDirection, mizar_uint32 nDataLen,
    mizar_uint8* szData, mizar_uint8 nIndex, mizar_uint8* szOutData);

/**********************************************************************************
Desc: Zu Chongzhi's algorithm MAC calculation

Input parameters:
    szCount - frame sequence numberCOUNT, 4 bytes of fixed-length data, default
is 0 nBearer - The bearer layer identifies BEARER nDirection - The direction
transmit direction identifies DIRECTION: 0 - upstream; 1 - downstream, which can
default to 0 nDatalen - The length of the data to be evaluated szData - data to
be calculated szKey - calculates the key

Output parameters:
    szMac - operation result, 4 bytes

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarZucMac(mizar_uint8* szCount, mizar_uint8 nBearer, mizar_uint8 nDirection, mizar_uint32 nDatalen,
    mizar_uint8* szData, mizar_uint8* szKey, mizar_uint8* szMac);

/**********************************************************************************
Desc: Zu Chongzhi's algorithm is calculated on the MAC, using an internal key

Input parameters:
    szCount - frame sequence numberCOUNT, 4 bytes of fixed-length data, default
is 0 nBearer - The bearer layer identifies BEARER nDirection - The direction
transmit direction identifies DIRECTION: 0 - upstream; 1 - downstream, which can
default to 0 nDatalen - The length of the data to be evaluated szData - data to
be calculated nIndex - operates the key index

Output parameters:
    szMac - operation result, 4 bytes

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarZucMacIndex(mizar_uint8* szCount, mizar_uint8 nBearer, mizar_uint8 nDirection, mizar_uint32 nDataLen,
    mizar_uint8* szData, mizar_uint8 nIndex, mizar_uint8* szMac);

/**********************************************************************************
Desc: MAC initialization Init

Input parameters:
    nMacType - MAC Type: 0-CBCMAC; 1-CMAC; 2-HMAC
    nAlg - algorithm: 0-AES/SHA256; 1-SM4/SM3
    nKeyMode - 0 - use internal key; 1 - Use an external key
    nIndex - valid when using internal key, internal key index [0-143]
    szIV - Initializes the vector, which is valid when calculating CBCMAC
    nKeyLen - Valid when using an external key, the key length
    szKey - The key value that is valid when using an external key

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarMacInit(mizar_uint8 nMacType, mizar_uint8 nAlg, mizar_uint8 nKeyMode, mizar_uint8 nIndex,
    mizar_uint8* szIV, mizar_uint8 nKeyLen, mizar_uint8* szKey);

/**********************************************************************************
Desc: MAC data Update

Input parameters:
    nDatalen - data length[1-248]
    szData - calculates the data

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarMacUpdate(mizar_uint32 nDatalen, mizar_uint8* szData);

/**********************************************************************************
Desc: MAC Final

Input parameters:
    nAlg - algorithm parameters: 1-SHA1; 2-SHA224; 3-SHA256;
	   4-SHA384(reserved); 5-SHA512 (Reserved)

Output parameters:
    nMacLen - MAC result length
    szMac calculates result data

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarMacFinal(mizar_uint32* nMacLen, mizar_uint8* szMac);

/**********************************************************************************
Desc: MAC operation, using an external key

Input parameters:
    nMacType - MAC Type: 0-CBCMAC; 1-CMAC; 2-HMAC
    nAlg - algorithm: 0-AES/SHA256; 1-SM4/SM3
    nKeyLen - Valid when using an external key, the key length
    szKey - The key value that is valid when using an external key
    nDataLen - data length [1-230]
    szData - calculates the data

Output parameters:
    nMacLen - MAC result length
    szMac - calculates result data

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarMac(mizar_uint8 nMacType, mizar_uint8 nAlg, mizar_uint8 nKeyLen, mizar_uint8* szKey,
    mizar_uint32 nDataLen, mizar_uint8* szData, mizar_uint32* nMacLen, mizar_uint8* szMac);

/**********************************************************************************
Desc: MAC operation, using an internal key

Input parameters:
    nMacType - MAC Type: 0-CBCMAC; 1-CMAC; 2-HMAC
    nAlg - algorithm: 0-AES/SHA256; 1-SM4/SM3
    nIndex - The operation key index
    nDataLen - data length [1-230]
    szData - calculates the data

Output parameters:
    nMacLen - MAC result length
    szMac - calculates result data

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarMacIndex(mizar_uint8 nMacType, mizar_uint8 nAlg, mizar_uint8 nIndex, mizar_uint32 nDataLen,
    mizar_uint8* szData, mizar_uint32* nMacLen, mizar_uint8* szMac);

/**********************************************************************************
Desc: SM4 encryption and decryption CBC mode

Input parameters:
    nMode - operation mode: 0- encrypted; 1 - decrypted
    nDataLen - The length of the data to be evaluated
    szData - data to be calculated
    szKey - calculates the key
    szIV - initialization vector

Output parameters:
    nOutLen - The length of the nOutlen operation result
    szOutData - operation result

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM4Cbc(mizar_uint32 nMode, mizar_uint8* szKey, mizar_uint8* szIV, mizar_uint32 nDatalen,
    mizar_uint8* szData, mizar_uint32* nOutlen, mizar_uint8* szOutData);

/**********************************************************************************
Desc: SM4 encryption and decryption CBC mode ,using internal key

Input parameters:
    nMode - operation mode: 0- encrypted; 1 - decrypted
    nDataLen - The length of the data to be evaluated
    szData - data to be calculated
    nKeyIndex - the index of key
    szIV - initialization vector

Output parameters:
    nOutLen - The length of the nOutlen operation result
    szOutData - operation result

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarSM4CbcIndex(mizar_uint32 nMode, mizar_uint32 nKeyIndex, mizar_uint8* szIV, mizar_uint32 nDatalen,
    mizar_uint8* szData, mizar_uint32* nOutlen, mizar_uint8* szOutData);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author	Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-01-11	jianglu	create
 * @ 1.1		2022-05-07	jianglu	add sm4 cbc interface
 * @
 */
