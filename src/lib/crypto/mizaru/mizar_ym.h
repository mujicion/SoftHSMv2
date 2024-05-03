/***************************************************
 * Introduction: mizar YM cryptography define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/
#ifndef _MIZAR_YM_H_
#define _MIZAR_YM_H_

#include "mizar_basetype.h"
#include "mizar_errcode.h"

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: Random number generation

Input parameters:
    nLen - Length of random number to generate
    flag - Mode: 0 - slow high quality random number;
	 1 - Fast random number

Output parameters:
    ucRND - The random number

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGenRnd(mizar_uint32 flag, mizar_uint32 nLen, mizar_uint8* ucRND);

/**********************************************************************************
Desc: ECC signature, using external key

Input parameters:
    nGroup - Elliptic curvature ID
    nKeyLen - The private key length
    ucKey - The private key
    nHashFlag - Hash flag : 0- not hash;
		1- Hash first and sign later
    nDataLen - Length of data to be signed
    ucData - Data to be signed

Output parameters:
    nRlen - Public key R Length
    ucR - Public key R
    nSlen - Length of public key S
    ucS - Public key S

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarEccSign(mizar_uint32 nGroup, mizar_uint32 nHashFlag, mizar_uint32 nKeyLen, mizar_uint8* ucKey,
    mizar_uint32 nDataLen, mizar_uint8* ucData, mizar_uint32* nRlen, mizar_uint8* ucR, mizar_uint32* nSlen,
    mizar_uint8* ucS);

/**********************************************************************************
Desc:  ECC signature, using internal key

Input parameters:
    nKeyIndex - Key pair index
    nHashFlag - Hash flag: 0 - do not hash;
	       1 - hash first and then sign
    nDataLen - The length of the data to be signed
    ucData - Data to be signed

Output parameters:
    nRlen - Signature R length
    ucR - Signature R
    nSlen - Signature S length
    ucS - Signature S

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarEccSignIndex(mizar_uint32 nKeyIndex, mizar_uint32 nHashFlag, mizar_uint32 nDataLen,
    mizar_uint8* ucData, mizar_uint32* nRlen, mizar_uint8* ucR, mizar_uint32* nSlen, mizar_uint8* ucS);

/**********************************************************************************
Desc:  ECC Signature Verification

Input parameters:
    nGroup - Ellipse curvature ID
    nXlen - Public key X length
    ucX - Public key X
    nYlen - Public key Y length
    ucY - Public key Y
    nRlen - Signature R length
    ucR - Signature R
    nSlen - Signature S length
    ucS - Signature S
    nHashFlag - Hash flag: 0 - do not hash;
	       1 - verify signature after hashing
    nDataLen - Length of signature data to be verified
    ucData - Signature data to be verified

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarEccVerify(mizar_uint32 nGroup, mizar_uint32 nHashFlag, mizar_uint32 nXlen, mizar_uint8* ucX,
    mizar_uint32 nYlen, mizar_uint8* ucY, mizar_uint32 nRlen, mizar_uint8* ucR, mizar_uint32 nSlen, mizar_uint8* ucS,
    mizar_uint32 nDataLen, mizar_uint8* ucData);

/**********************************************************************************
Desc:  ECC public key encryption

Input parameters:
    nGroup - Ellipse curvature ID
    nXlen -  Public key X length
    ucX -  Public key X
    nYlen -  Public key Y length
    ucY -  Public key Y
    nInLen - The length of the data to be calculated
    ucInData - Data to be calculated

Output parameters:
    pOutLen - Output data length
    ucOutData - Output Data

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarEccPkEnc(mizar_uint32 nGroup, mizar_uint32 nXlen, mizar_uint8* ucX, mizar_uint32 nYlen,
    mizar_uint8* ucY, mizar_uint32 nInLen, mizar_uint8* ucInData, mizar_uint32* pOutLen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: ECC private key decryption, using external private key

Input parameters:
    nGroup - Ellipse curvature ID
    nKeylen - Private key length
    ucKey - Private key
    nInLen - The length of the data to be calculated
    ucInData - Data to be calculated

Output parameters:
    pOutLen - Output data length
    ucOutData - Output Data

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarEccSkDec(mizar_uint32 nGroup, mizar_uint32 nKeylen, mizar_uint8* ucKey, mizar_uint32 nInLen,
    mizar_uint8* ucInData, mizar_uint32* pOutLen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: ECC private key decryption, using internal private key

Input parameters:
    nKeyIndex - Key pair index
    nInLen - The length of the data to be calculated
    ucInData - Data to be calculated

Output parameters:
    nOutLen - Output data length
    ucOutData - Output Data

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarEccSkDecIndex(
    mizar_uint32 nKeyIndex, mizar_uint32 nInLen, mizar_uint8* ucInData, mizar_uint32* nOutLen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: ECC key agreement, using external private key

Input parameters:
    nKeylen - The length of the key to be generated
    nGroup - Ellipse curvature ID
    nSKeylen - Private key length
    ucSkey - Private key
    nRXlen - Remote public key X length
    ucRX - Remote public key X
    nRYlen - Remote public key Y length
    ucRY - Remote public key Y

Output parameters:
    ucOutKey - Output shared key

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarEccComputeKey(mizar_uint32 nKeylen, mizar_uint32 nGroup, mizar_uint32 nSKeylen, mizar_uint8* ucSkey,
    mizar_uint32 nRXlen, mizar_uint8* ucRX, mizar_uint32 nRYlen, mizar_uint8* ucRY, mizar_uint8* ucOutKey);

/**********************************************************************************
Desc: ECC key agreement, using internal private key

Input parameters:
    nIndex - key pair index
    nKeylen - The length of the key to be generated
    nRXlen - Remote public key X length
    ucRX - Remote public key X
    nRYlen - Remote public key Y length
    ucRY - Remote public key Y

Output parameters:
    ucOutKey - Output shared key

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarEccComputeKeyIndex(mizar_uint32 nIndex, mizar_uint32 nKeylen, mizar_uint32 nRXlen, mizar_uint8* ucRX,
    mizar_uint32 nRYlen, mizar_uint8* ucRY, mizar_uint8* ucOutKey);

/**********************************************************************************
Desc: RSA private key encryption, using external private key

Input parameters:
    nDatalen - The length of the data to be calculated, the value must be equal to
	   the number of bytes of the modulo length of the private key
    ucData - Data to be calculated
    nSKlen - Private key length
    ucSK - Private key

Output parameters:
    nOutlen - Operation result length
    ucOutData -  Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarRsaSkEnc(mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32 nSKlen, mizar_uint8* ucSK,
    mizar_uint32* nOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: RSA private key encryption, using internal private key

Input parameters:
    nKeyIndex - Key pair index
    nDatalen - The length of the data to be calculated, the value must be equal to
	   the number of bytes of the modulo length of the private key
    ucData - Data to be calculated

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarRsaSkEncIndex(
    mizar_uint32 nKeyIndex, mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: RSA public key decryption

Input parameters:
    nNlen - The length of the N component of the public key
    ucN - Public key N component
    nElen - Length of public key E component
    ucE - public key E component
    nDatalen - The length of the data to be calculated, the value must be equal to
	   the number of bytes of the modulo length of the public key
    ucData - Data to be calculated

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarRsaPkDec(mizar_uint32 nNlen, mizar_uint8* ucN, mizar_uint32 nElen, mizar_uint8* ucE,
    mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: RSA public key encryption

Input parameters:
    nNlen - The length of the N component of the public key
    ucN - Public key N component
    nElen - Length of public key E component
    ucE - Public key E component
    nDatalen - The length of the data to be calculated, the value must be equal to
	   the number of bytes of the modulo length of the public key
    ucData - Data to be calculated

Output parameters:
    nOutlen - Operation result length
    ucOutData -  Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarRsaPkEnc(mizar_uint32 nNlen, mizar_uint8* ucN, mizar_uint32 nElen, mizar_uint8* ucE,
    mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32* nOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: RSA private key decryption, using external private key

Input parameters:
    nSKlen - Private key length
    ucSK - Private key
    nDatalen - The length of the data to be calculated, the value must be equal to
	   the number of bytes of the modulo length of the public key
    ucData - Data to be calculated

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarRsaSkDec(mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32 nSKlen, mizar_uint8* ucSK,
    mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: RSA private key decryption, using internal private key

Input parameters:
    nKeyIndex - Key pair index
    nDatalen - The length of the data to be calculated, the value must be equal to
	   the number of bytes of the modulo length of the public key
    ucData - Data to be calculated

Output parameters:
    nOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarRsaSkDecIndex(
    mizar_uint32 nKeyIndex, mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32* nOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: AES encryption and decryption ECB mode

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    nDatalen - The length of the data to be calculated
    ucData - Data to be calculated
    nKeylen - Key length
    ucKey - Operation key

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarAesEcb(mizar_uint32 nMode, mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32 nKeylen,
    mizar_uint8* ucKey, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: AES encryption and decryption in ECB mode, using internal key

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    nDatalen - The length of the data to be calculated
    ucData - Data to be calculated
    nKeyIndex - Operation key index

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarAesEcbIndex(mizar_uint32 nMode, mizar_uint32 nKeyIndex, mizar_uint32 nDatalen, mizar_uint8* ucData,
    mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: AES encryption and decryption CBC mode

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    ucIV - Initialization vector
    nDatalen - The length of the data to be calculated
    ucData - Data to be calculated
    nKeylen - Key length
    ucKey - Operation key

Output parameters:
    pOutlen - Operation result length
    ucOutData -  Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarAesCbc(mizar_uint32 nMode, mizar_uint8* ucIV, mizar_uint32 nDatalen, mizar_uint8* ucData,
    mizar_uint32 nKeylen, mizar_uint8* ucKey, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: AES encryption and decryption in CBC mode, using the internal key

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    ucIV - Initialization vector
    nDatalen - The length of the data to be calculated
    ucData - Data to be calculated
    nKeyIndex - Operation key index

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarAesCbcIndex(mizar_uint32 nMode, mizar_uint8* ucIV, mizar_uint32 nKeyIndex, mizar_uint32 nDatalen,
    mizar_uint8* ucData, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: DES encryption and decryption ECB mode

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    nDatalen - The length of the data to be calculated
    ucData - Data to be calculated
    nKeylen - Key length
    ucKey - Operation key

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDesEcb(mizar_uint32 nMode, mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32 nKeylen,
    mizar_uint8* ucKey, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: DES encryption and decryption ECB mode, using internal key

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    nDatalen - The length of the data to be calculated
    ucData - Data to be calculated
    nKeyIndex - Operation key index

Output parameters:
    nOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDesEcbIndex(mizar_uint32 nMode, mizar_uint32 nKeyIndex, mizar_uint32 nDatalen, mizar_uint8* ucData,
    mizar_uint32* nOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: DES encryption and decryption CBC mode

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    ucIV - Initialization vector
    nDatalen - The length of the data to be calculated
    ucData - Data to be calculated
    nKeylen - Key length
    ucKey - Operation key

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDesCbc(mizar_uint32 nMode, mizar_uint8* ucIV, mizar_uint32 nDatalen, mizar_uint8* ucData,
    mizar_uint32 nKeylen, mizar_uint8* ucKey, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: DES encryption and decryption in CBC mode, using the internal key

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    ucIV - Initialization vector
    nDatalen - The length of the data to be calculated
    ucData - Data to be calculated
    nKeyIndex - Operation key index

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDesCbcIndex(mizar_uint32 nMode, mizar_uint8* ucIV, mizar_uint32 nKeyIndex, mizar_uint32 nDatalen,
    mizar_uint8* ucData, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

/**********************************************************************************
Desc: SHA hash initialization Init

Input parameters:
    nAlg - Algorithm parameters:
	1-SHA1; 2-SHA224; 3-SHA256; 4-SHA384 (reserved); 5-SHA512 (reserved)

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarShaInit(mizar_uint32 nAlg);

/**********************************************************************************
Desc: SHA HashUpdate

Input parameters:
    nAlg - Algorithm parameters:
	1-SHA1; 2-SHA224; 3-SHA256; 4-SHA384 (reserved); 5-SHA512 (reserved)
    nDatalen - Data length, if multiple updates, except for the last update,
	   the length is not limited.
	   The length of other update data must be an integer multiple of 64
    ucData - Operation data

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarShaUpdate(mizar_uint32 nAlg, mizar_uint32 nDatalen, mizar_uint8* ucData);

/**********************************************************************************
Desc: SHA Hash Final

Input parameters:
    nAlg - Algorithm parameters:
	1-SHA1; 2-SHA224; 3-SHA256; 4-SHA384 (reserved); 5-SHA512 (reserved)

Output parameters:
    nHashlen - Hash result length
    ucHash - Hash result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarShaFinal(mizar_uint32 nAlg, mizar_uint32* nHashlen, mizar_uint8* ucHash);

/**********************************************************************************
Desc: SHA hash operation

Input parameters:
    nAlg - Algorithm parameters:
	1-SHA1; 2-SHA224; 3-SHA256; 4-SHA384 (reserved); 5-SHA512 (reserved)
    nDatalen - Data length
    ucData - Operation data

Output parameters:
    nHashlen - Hash result length
    ucHash - hash result

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarSHA(
    mizar_uint32 nAlg, mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32* nHashlen, mizar_uint8* ucHash);

/********************************************************************************
Desc: AES encryption and decryption CCM mode, external key (soft algorithm)

Input parameters:
    nMode - Operation mode: 0-encryption; 1-decryption
    ucKey - Operation key
    nKeyLen - Key length, 16/24/32
    ucNonce - Initialization vector data, fixed length 12 bytes
    nDatalen - Data length to be calculated:
	    if nMode = 0 data length [1-1024]
	    if nMode = 1 data length [17-1040]
    ucData - Data to be calculated,
	if nMode = 1, data format: ciphertext||label (16 bytes)

Output parameters:
    pOutlen - Operation result length
    ucOutData - Operation result,
	if nMode = 0, data format: ciphertext||label (16 bytes)

Return value: 0 - Succeeded, Others - Error Code
********************************************************************************/
mizar_uint32 MizarAesCcm(mizar_uint32 nMode, mizar_uint8* ucKey, mizar_uint32 nKeyLen, mizar_uint8* ucNonce,
    mizar_uint32 nDatalen, mizar_uint8* ucData, mizar_uint32* pOutlen, mizar_uint8* ucOutData);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author		Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-02-22	yuhongbao	create
 * @
 */