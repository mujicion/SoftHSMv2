/***************************************************
 * Introduction: mizar key manager define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/

#ifndef _MIZAR_KEY_MANAGER_H_
#define _MIZAR_KEY_MANAGER_H_

#include "mizar_basetype.h"

// basic symm key number
#define MAX_SYMM_NUM 128
#define MAX_SM2_NUM  10
#define MAX_ECC_NUM  10
// basic symm key and session key
#define MAX_SYMM_KEY_NUM 160

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: Generates a symmetric key, which is stored internally

Input parameters:
    nAlg - Algorithm of key importing: 0-ALL; 1-DES; 2-AES; 3-SM4
    nKeyIndex - Index number of the key store
    nLock - Whether the key is locked(Don't Modify): 0-no lock; 1-lock
    nKeylen - Key length
    szMac - Check value, MAC value calculated using KMC for key information, 4 bytes

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGenSymmKey(
    mizar_uint32 nAlg, mizar_uint32 nKeyIndex, mizar_uint32 nLock, mizar_uint32 nKeylen, mizar_uint8* szMac);

/**********************************************************************************
Desc: Importing a Symmetric key

Input parameters:
    nAlg -  Algorithm of importing a Symmetric key: 0-ALL; 1-DES; 2-AES; 3-SM4
    nKeyIndex - Index number of the key store
    nLock - Whether the key is locked(Don't Modify): 0-no lock; 1-lock
    nKeylen - Key length
    szKey - Use KMC encryption key plaintext
	(Plaintext: 2 bytes + plaintext key + 8000 complement,
	    no mandatory complement)
    szMac - Check value, MAC value calculated using KMC for key information, 4 bytes

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarImportSymmKey(mizar_uint32 nAlg, mizar_uint32 nKeyIndex, mizar_uint32 nLock, mizar_uint32 nKeyLen,
    mizar_uint8* szKey, mizar_uint8* szMac);

/**********************************************************************************
Desc: Exporting a Symmetric key

Input parameters:
    nKeyIndex - Index number of the key store
    nKekIndex - Protected key index

Output parameters:
    pAlg - Algorithm: 0-ALL; 1-DES; 2-AES; 3-SM4
    pKeylen - Key length
    szKey - Use the exported key to encrypt the plaintext
    (Plaintext: 2 bytes + plaintext key + 8000 complement,
	    no mandatory complement)
    szCV - The key check value, 3 bytes

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarExportSymmKey(mizar_uint32 nKeyIndex, mizar_uint32 nKekIndex, mizar_uint32* pAlg,
    mizar_uint32* pKeyLen, mizar_uint8* szKey, mizar_uint8* szCV);

/**********************************************************************************
Desc: Deleting a Symmetric key

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDeleteSymmKey(mizar_uint32 nKeyIndex);

/**********************************************************************************
Desc: Query symmetric key properties

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    nAlg - Algorithm: 0-ALL; 1-DES; 2-AES; 3-SM4
    nKeylen - Key length
    nLock - Key lock identifier
    szCV - The key check value, 3 bytes

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarQuerySymmKey(
    mizar_uint32 nKeyIndex, mizar_uint32* nKeyLen, mizar_uint32* nAlg, mizar_uint32* nLock, mizar_uint8* szCV);

/**********************************************************************************
Desc: An SM2 key pair is generated and exported

Input parameters:
    none

Output parameters:
    szX - Public key X, fixed length 32 bytes
    szY - Public key Y, fixed length 32 bytes
    szSK - Private key, 32 bytes in length

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGenSM2Key(mizar_uint8* szX, mizar_uint8* szY, mizar_uint8* szSK);

/**********************************************************************************
Desc: Generates an SM2 key pair, which is stored internally

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    szX - Public key X, fixed length 32 bytes
    szY - Public key Y, fixed length 32 bytes

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGenSM2KeyIndex(mizar_uint32 nKeyIndex, mizar_uint8* szX, mizar_uint8* szY);

/**********************************************************************************
Desc: Import an SM2 key pair

Input parameters:
    nKeyIndex - Index number of the key store
    nKeylen - Private key ciphertext length
    szKey - Private key ciphertext, using KMC encryption key plaintext
       (Plaintext: 2 bytes in length + key plaintext +8000 bits of complement)
    nXlen - X component length of the public key
    szX - Public key X component
    nYlen - The Y-component length of the public key
    szY - Public key Y component
    szMac - Mac of the key information using KMC

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarImportSM2Key(mizar_uint32 nKeyIndex, mizar_uint32 nKeyLen, mizar_uint8* szKey, mizar_uint32 nXlen,
    mizar_uint8* szX, mizar_uint32 nYlen, mizar_uint8* szY, mizar_uint8* szMac);

/**********************************************************************************
Desc: Export the SM2 key pair

Input parameters:
    nKeyIndex - Index number of the key store
    nKekIndex - Protected key index

Output parameters:
    pKeylen - Private key ciphertext length
    szKey - Private key ciphertext.
	Use the exported key to encrypt the plaintext key
	(Plaintext :2 bytes long + plaintext key +8000 complement,
	no mandatory complement)
    pXlen - X component length of the public key
    szX - Public key X component
    pYlen - The Y-component length of the public key
    szY - Public key Y component

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarExportSM2Key(mizar_uint32 nKeyIndex, mizar_uint32 nKekIndex, mizar_uint32* pXlen, mizar_uint8* szX,
    mizar_uint32* pYlen, mizar_uint8* szY, mizar_uint32* pKeyLen, mizar_uint8* szKey);

/**********************************************************************************
Desc: Delete an SM2 key pair

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDeleteSM2Key(mizar_uint32 nKeyIndex);

/**********************************************************************************
Desc: Query the SM2 key pair and read the public key

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    pXlen - X component length of the public key
    szX - Public key X component
    pYlen - The Y-component length of the public key
    szY - Public key Y component

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarQuerySM2Key(
    mizar_uint32 nKeyIndex, mizar_uint32* pXlen, mizar_uint8* szX, mizar_uint32* pYlen, mizar_uint8* szY);

/**********************************************************************************
Desc: An ECC key pair is generated and exported

Input parameters:
    nGroup - Elliptic curvature ID

Output parameters:
    pKeyLen - The private key length
    szKey - The private key
    pXlen - Public key X Length
    szX - Public key X
    pYlen - Public key Y Length
    szY - Public key Y

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGenEccKey(mizar_uint32 nGroup, mizar_uint32* pKeyLen, mizar_uint8* szKey, mizar_uint32* pXlen,
    mizar_uint8* szX, mizar_uint32* pYlen, mizar_uint8* szY);

/**********************************************************************************
Desc: ECC key pairs are generated and stored internally

Input parameters:
    nGroup - Elliptic curvature ID
    nKeyIndex - Index number of the key store

Output parameters:
    pXlen - X component length of the public key
    szX - Public key X component
    pYlen - The Y-component length of the public key
    szY - Public key Y component

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGenEccKeyIndex(mizar_uint32 nKeyIndex, mizar_uint32 nGroup, mizar_uint32* pXlen, mizar_uint8* szX,
    mizar_uint32* pYlen, mizar_uint8* szY);

/**********************************************************************************
Desc: Import an ECC key pair

Input parameters:
    nGroupID - Elliptic curvature : 415-256bit
    nKeyIndex - Index number of the key store
    nKeylen - Private key ciphertext length
    szKey - Private key ciphertext, using KMC encryption key plaintext
      (Plaintext :2 bytes long + plaintext key +8000 complement,
      no mandatory complement)
    nXlen - X component length of the public key
    szX - Public key X component
    nYlen - The Y-component length of the public key
    szY - Public key Y component
    szMac - Use KMC to verify the key information, 4 bytes

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarImportEccKey(mizar_uint32 nGroupID, mizar_uint32 nKeyIndex, mizar_uint32 nKeyLen, mizar_uint8* szKey,
    mizar_uint32 nXlen, mizar_uint8* szX, mizar_uint32 nYlen, mizar_uint8* szY, mizar_uint8* szMac);

/**********************************************************************************
Desc: Export the ECC key pair

Input parameters:
    nKeyIndex - Index number of the key store
    nKekIndex - Protected key index

Output parameters:
    nGroupID - Elliptic curvature : 415-256bit
    pKeylen - Private key ciphertext length
    szKey - Private key ciphertext. Use the exported key to encrypt the plaintext key
      (Plaintext :2 bytes long + plaintext key +8000 complement,
      no mandatory complement)
    pXlen - X component length of the public key
    szX - Public key X component
    pYlen - The Y-component length of the public key
    szY - Public key Y component

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarExportEccKey(mizar_uint32 nKeyIndex, mizar_uint32 nKekIndex, mizar_uint32* nGroupID,
    mizar_uint32* pXlen, mizar_uint8* szX, mizar_uint32* pYlen, mizar_uint8* szY, mizar_uint32* pKeyLen,
    mizar_uint8* szKey);

/**********************************************************************************
Desc: Deletes an ECC key pair

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDeleteEccKey(mizar_uint32 nKeyIndex);

/**********************************************************************************
Desc: Querying ECC key pairs and reading public keys

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    nGroupID - Elliptic curvature : 415-256bit
    nXlen - X component length of the public key
    szX - Public key X component
    nYlen - The Y-component length of the public key
    szY - Public key Y component

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarQueryEccKey(mizar_uint32 nKeyIndex, mizar_uint32* nGroupID, mizar_uint32* nXlen, mizar_uint8* szX,
    mizar_uint32* nYlen, mizar_uint8* szY);

/**********************************************************************************
Desc: An RSA key pair is generated and exported

Input parameters:
    nModlen - Length: 512-2048
    nElen - Exponent Length
    szE - Exponent

Output parameters:
    nKPLen - Structure length of the key pair
    szKP - The key pair structure encodes data

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGenRsaKey(
    mizar_uint32 nModlen, mizar_uint32 nElen, mizar_uint8* szE, mizar_uint32* nKPLen, mizar_uint8* szKP);

/**********************************************************************************
Desc: Generates an RSA key pair, which is stored internally

Input parameters:
    nKeyIndex - Index number of the key store
    nModlen - Length: 512-2048
    nElen - Exponent Length
    szE - Exponent

Output parameters:
    pNlen - The N-component length of the public key
    szN - The N-component of the public key

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGenRsaKeyIndex(mizar_uint32 nKeyIndex, mizar_uint32 nModlen, mizar_uint32 nElen, mizar_uint8* szE,
    mizar_uint32* pNlen, mizar_uint8* szN);

/**********************************************************************************
Desc: Importing an RSA key pair

Input parameters:
    nKeyIndex - Index number of the key store
    nKeylen - Private key ciphertext length
    szKey - Private key ciphertext, using KMC encryption key plaintext
	(Plaintext :2 bytes long + plaintext key +8000 complement,
	no mandatory complement)
    szMac - Verify the key information using KMC

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarImportRsaKey(mizar_uint32 nKeyIndex, mizar_uint32 nKeyLen, mizar_uint8* szKey, mizar_uint8* szMac);

/**********************************************************************************
Desc: Export an RSA key pair

Input parameters:
    nKeyIndex - Index number of the key store
    nKekIndex - Protected key index

Output parameters:
    nKeylen - Private key ciphertext length
    szKey - Private key ciphertext.
	Use the exported key to encrypt the plaintext key
	(Plaintext :2 bytes long + plaintext key +8000 complement,
	no mandatory complement)

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarExportRsaKey(
    mizar_uint32 nKeyIndex, mizar_uint32 nKekIndex, mizar_uint32* nKeyLen, mizar_uint8* szKey);

/**********************************************************************************
Desc: Deleting an RSA key pair

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDeleteRsaKey(mizar_uint32 nKeyIndex);

/**********************************************************************************
Desc: Querying an RSA key pair and reading the public key

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    pNlen - The N-component length of the public key
    szN - The N-component of the public key
    pElen - The E-component length of the public key
    szE - The E-component of the public key

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarQueryRsaKey(
    mizar_uint32 nKeyIndex, mizar_uint32* pNlen, mizar_uint8* szN, mizar_uint32* pElen, mizar_uint8* szE);

/**********************************************************************************
Desc: Gets the symmetric key list

Input parameters:
    none

Output parameters:
    pListlen - Length of key list information
    szList - Key list, each key in the following format:
	 INDEX(1B)+ALG(1B)+LEN(1B)+CV(3B)

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetSymmKeyList(mizar_uint32* pListlen, mizar_uint8* szList);

/**********************************************************************************
Desc: Gets the SM2 key list

Input parameters:
    none

Output parameters:
    pListlen - Length of key list information
    szList - Key list, each key in the following format:
	INDEX(1B)+SKLEN(1B)

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetSM2KeyList(mizar_uint32* pListlen, mizar_uint8* szList);

/**********************************************************************************
Desc: Gets the ECC key list

Input parameters:
    none

Output parameters:
    pListlen - Length of key list information
    szList - Key list, each key in the following format:
	INDEX(1B)+SKLEN(1B)

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetEccKeyList(mizar_uint32* pListlen, mizar_uint8* szList);

/**********************************************************************************
Desc: Gets the RSA key list

Input parameters:
    none

Output parameters:
	pListlen - Length of key list information
    szList - Key list, each key in the following format:
	INDEX(1B)

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetRsaKeyList(mizar_uint32* pListlen, mizar_uint8* szList);

/**********************************************************************************
Desc: Importing a session key

Input parameters:
    nAlg - Key import algorithm: 0-ALL; 1-DES; 2-AES; 3-SM4
    nKeyIndex - Index number of the key store
    nCalcIndex - Index of the key involved in the operation.
	 0xFF indicates that no key is involved in the operation
    nKeylen - Key length
    szKey - Key

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarImportSessKey(
    mizar_uint32 nAlg, mizar_uint32 nKeyIndex, mizar_uint32 nCalcIndex, mizar_uint32 nKeyLen, mizar_uint8* szKey);

/**********************************************************************************
Desc: Exporting session Keys

Input parameters:
    nKeyIndex - Index number of the key store

Output parameters:
    nAlg - Key export algorithm: 0-ALL; 1-DES; 2-AES; 3-SM4
    nKeylen - Key length
    szKey - Key

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarExportSessKey(mizar_uint32 nKeyIndex, mizar_uint32* nAlg, mizar_uint32* nKeyLen, mizar_uint8* szKey);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version      Date              Author               Note
 * @ -------------------------------------------------------------------------
 * @ 1.0          2022-02-15        yuhongbao            create
 * @
 */
