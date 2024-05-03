/***************************************************
 * Introduction: Aerolink api declaration
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/

#ifndef _MIZAR_AERO_LINK_H_
#define _MIZAR_AERO_LINK_H_

#include "mizar_basetype.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	ECDSA_NISTP256_WITH_SHA256 = 0,
	ECIES_NISTP256 = 1,
	ECDSA_SM2_WITH_SM3 = 0xE0,
	ECIES_SM2_WITH_SM3 = 0xE1,
	ECDSA_BRAINPOOLP256_WITH_SHA256 = 0xF0,
	ECIES_BRAINPOOLP256 = 0xF1
} PKAlgorithm;

typedef enum {
	ACAS_SUCCESS = 0x00,
	ACAS_ERR_ERR_UNSUPPORTED_CRYPTO_ALGORITHM,
	ACAS_ERR_ERR_BUFLEN,
	ACAS_ERR_ERR_CRYPTO_INTERNAL
} AerolinkCryptoApiStatus;

typedef struct {
	size_t len;
	PKAlgorithm alg;
	// 65 bytes, 04||x||y
	mizar_uint8* blob;
} ECPubKey;

typedef struct {
	size_t len;
	PKAlgorithm alg;
	mizar_uint8* blob;
} ECPrivKey;

/**********************************************************************************
Desc: Key pairs are generated and stored

Input parameters:
    nPrivkey - Private Key Index: [0-299]
    alg - Algorithm: 0-ECDSA_SM2_WITH_SM3

Output parameters:
    pubkey - Public key, fixed length 65 bytes, format: 04|| x|| y

Return value: = 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_keygen_with_index(PKAlgorithm alg, ECPubKey* pubkey, mizar_uint32 nPrivkey);

/**********************************************************************************
Desc: Perform OPS initialization of the internal private key

Input parameters:
    none

Output parameters:
    szImplName - HSM module name, MizarU HSM
    pMaxSlots - The number of stored certificates and keys, 500

Return value: = 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_initialize_privkey_ops_with_index(mizar_char const** szImplName, mizar_uint32* pMaxSlots);

/**********************************************************************************
Desc: ECC internal private key OPS completed

Input parameters:
    none

Output parameters:
    none

Return value: = 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_finalize_privkey_ops_with_index(void);

/**********************************************************************************
Desc: The signature data is verified using the EC key and the calculation result is returned 

Input parameters:
    eckey - Verify the public key
    pDgst - Data to be verified
    nDgstLen - The length to be verified
    pSig - Signature data   0x00||r||s   : EPK_X_COORDINATE_ONLY
    nSigLen - The length of the signature data

Output parameters:
    none

Return value: = 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_ecdsa_verify(
    ECPubKey const* eckey, mizar_uint8 const* pDgst, size_t nDgstLen, mizar_uint8 const* pSig, size_t nSigLen);

/**********************************************************************************
Desc: The data is signed with an EC key and the calculation results are returned

Input parameters:
    eckey - Sign the private key
    pDgst - Data to be signed
    nDgstLen - The length of the data to be signed

Output parameters:
    pSig - Signature data
    pSigLen - The length of the signature data

Return value: = 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_ecdsa_sign(
    ECPrivKey const* eckey, mizar_uint8 const* pDgst, size_t nDgstLen, mizar_uint8* pSig, size_t* pSigLen);

/**********************************************************************************
Desc: Sign with the ECC-ECDSA internal private key

Input parameters:
    nEckey - Private key index, value range [0-299]
    pDgst - Data to be signed
    nDgstLen - The length of the data to be signed

Output parameters:
    pSig - Signature data
    pSigLen - The length of the signature data

Return value: = 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_ecdsa_sign_with_index(
    mizar_uint32 nEckey, mizar_uint8 const* pDgst, size_t nDgstLen, mizar_uint8* pSig, size_t* pSigLen);

/**********************************************************************************
Desc: Use the ECQV refactoring algorithm for public key refactoring

Input parameters:
    pAScalar - 32-byte large number
    nALen - AScalar length
    B - Raw public key, in format 32 bytes X || 32 bytes Y
    C - 64-byte dot, format 32 bytes X || 32 bytes Y

Output parameters:
    R - Refactored public key, 32 bytes X || 32 bytes Y

Return value: >= 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_point_multiply_add(
    mizar_uint8 const* pAScalar, size_t nALen, ECPubKey const* B, ECPubKey const* C, ECPubKey* R);

/**********************************************************************************
Desc: The internal private key is derived and stored

Input parameters:
    seedPrivKey - The private key index to be derived, with a value range of [0-299]
    f - Calculate the factors
    fLen - Calculate the factor f length
    e - Calculate the factors
    eLen - Calculate the factor e length
    r - Calculate the factors
    rLen - Calculate the factor r length
    newKey - The private key index to be stored, with a value range of [0-299]

Output parameters:
    newKeyX - The public key X component
    newKeyY - The public key Y component
    coordinateLen - The length of the child chaincode

Return value: = 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_derive_private_key_with_index(mizar_uint32 seedPrivKey, mizar_uint8 const* f, size_t fLen,
    mizar_uint8 const* e, size_t eLen, mizar_uint8 const* r, size_t rLen, mizar_uint32 newKey, mizar_uint8* newKeyX,
    mizar_uint8* newKeyY, size_t* coordinateLen);

/**********************************************************************************
Desc: Internal private key decryption

Input parameters:
    ecPrivKey - Private key index, value range [0-299]
    kdp - If the algorithm is ECC curvature, the value is valid, is the
	    P1 parameter in the 1609 specification,and is fixed in length 32 bytes;
	    If the algorithm is SM2 and the value is invalid,set the value to NULL
    kdpLen - kdp length
    ephPubKey - Temporary public key
    ephLen - The length of the temporary public key
    encrData - Ciphertext data, SM2 algorithm format is C1|| C2|| C3;ECC algorithm
	    format is V|| C|| T,where V is the public key in compressed format
    encrLen - Ciphertext data length, the algorithm is ECC curvature, and kdp is
	    not equal to 0,the ciphertext data length range is [1-1024], the
	    algorithm is SM2, the ciphertext data length range is [1-32]ciphertext
	    data, and the SM2 algorithm format is C1|| C2|| C3;ECC algorithm format
	    is V|| C|| T, where V is thepublic key in compressed format
    tagLen - Authentication label length
    tag - Authentication label

Output parameters:
    pMsg - Decrypted plaintext data

Return value: = 0 - succeed; else - error code
**********************************************************************************/
AerolinkCryptoApiStatus ecc_ecies_decrypt_with_index(mizar_uint32 ecPrivKey, mizar_uint8 const* kdp, size_t kdpLen,
    mizar_uint8 const* ephPubKey, size_t ephLen, mizar_uint8 const* encrData, size_t encrLen, mizar_uint8 const* tag,
    size_t tagLen, mizar_uint8* pMsg);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author		Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-01-08	chenzhao		create
 * @ 1.1		2022-04-08	lvyanzhen	Modify the comment
 * @ 1.2		2022-06-07	linzongfang	0001037: Change define for aero api
 * @
 */
