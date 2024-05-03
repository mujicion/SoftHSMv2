/***************************************************
 * Introduction: mizar v2xfota define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/
#ifndef _MIZAR_V2XFOTA_H_
#define _MIZAR_V2XFOTA_H_

#include "mizar_basetype.h"

#define V2X_CERT_MAX_LEN 254
#define MAX_CACER_NUM	 30
#define V2X_ECERT_NUM	 300
#define V2X_MAX_IDA_LEN	 32

#define V2X_CACERT_TYPE 1 
#define V2X_RCERT_TYPE 2


#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: Generate a vehicle certificate request

Input parameters:
    nEcuType - ecu type, 1 byte
    szVIN - Vehicle identification number, 17 bytes
     szSN - Gateway device serial number, 16 bytes
     nAlg - Algorithm identification, 3 bytes

Output parameters:
    szPK - Gateway public key, 64 bytes
    szSig - self-signed, 64 bytes

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarGenReq(mizar_uint8 nEcuType, mizar_uint8* szVIN, mizar_uint8* szSN, mizar_uint8* nAlg,
    mizar_uint8* szPK, mizar_uint8* szSig);

/**********************************************************************************
Desc: Generate and save a session key

Input parameters:
      nAlg - 1 - International; 2 - National Secret
      M1 - Shared Key, fixed length 32 bytes
      r1 - Client random number, fixed length 32 bytes
      r2 - Server random number, fixed length 32 bytes

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarGenSessKey(mizar_uint8 nAlg, mizar_uint8* M1, mizar_uint8* R1, mizar_uint8* R2);

/**********************************************************************************
Desc: Verify the certificate

Input parameters:
    szCert - Certificate
     nLen - Certificate length

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarVerifyCert(mizar_uint32 nLen, mizar_uint8* szCert);

/********************************************************************************
Desc: Import the V2X CA certificate

Input parameters:
    nIndex - Certificate Index[0-29]
    nType - Certificate Type: 1-CA szCert; 2-ROOT szCert
    nLen - Certificate length[1-254]
    szCert - Certificate data

Output parameters:
    none

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xImportCaCert(mizar_uint32 nIndex, mizar_uint32 nType, mizar_uint32 nLen, mizar_uint8* szCert);

/********************************************************************************
Desc: Export the V2X CA certificate

Input parameters:
    nIndex - Certificate Index[0-29]

Output parameters:
    nType - Certificate Type: 1-CA szCert; 2-ROOT szCert
    nLen - Certificate length[1-254]
    szCert - Certificate data

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xExportCaCert(mizar_uint32 nIndex, mizar_uint32* nType, mizar_uint32* nLen, mizar_uint8* szCert);

/********************************************************************************
Desc: Delete the V2X CA certificate

Input parameters:
    nIndex - Certificate Index[0-29]

Output parameters:
    none

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xDeleteCaCert(mizar_uint32 nIndex);

/********************************************************************************
Desc:The V2X endpoint certificate key pair is generated, and the key pair is stored internally

Input parameters:
    nIndex - Certificate Index[0-299]
    nAlg - algorithm: 0-SM2; 1-nistP256; 2-brainpoolP256r1

Output parameters:
    szX - Public key X, fixed length 32 bytes
    szY - Public key Y, fixed length 32 bytes

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertGenKeyIndex(mizar_uint32 nIndex, mizar_uint8 nAlg, mizar_uint8* szX, mizar_uint8* szY);

/********************************************************************************
Desc: Import the V2X endpoint certificate

Input parameters:
    nIndex - Certificate Index[0-299]
    nLen - Certificate length[1-254]
    szCert - Certificate data

Output parameters:
    none

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xImportECert(mizar_uint32 nIndex, mizar_uint32 nLen, mizar_uint8* szCert);

/********************************************************************************
Desc: Import v2X endpoint certificate and key pairs

Input parameters:
    nIndex - Certificate Index[0-299]
    nLen - Certificate length[0-254]
    szCert - Certificate data
    nAlg - algorithm: 0-SM2; 1-nistP256; 2-brainpoolP256r1
    szKey - The certificate corresponds to the key pair, with a fixed length of 96 bytes, and the format is X|| Y|| SK

Output parameters:
    none

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xImportECertKey(
    mizar_uint32 nIndex, mizar_uint32 nLen, mizar_uint8* szCert, mizar_uint8 nAlg, mizar_uint8* szKey);

/********************************************************************************
Desc: Export the V2X endpoint certificate

Input parameters:
    nIndex - Certificate Index[0-299]

Output parameters:
    nLen - Certificate length[1-254]
    szCert - Certificate data

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xExportECert(mizar_uint32 nIndex, mizar_uint32* nLen, mizar_uint8* szCert);

/********************************************************************************
Desc: Delete the V2X endpoint certificate

Input parameters:
    nIndex - Certificate Index[0-299]

Output parameters:
    none

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xDeleteECert(mizar_uint32 nIndex);

/********************************************************************************
Desc: Sign with the terminal private key

Input parameters:
    nIndex - Certificate Index[0-299]
    szHash - Hash data to be signed, fixed at 32 bytes

Output parameters:
    szR - Signature R, fixed length 32 bytes
    szS - Signature S, fixed length 32 bytes

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertSignIndex(mizar_uint32 nIndex, mizar_uint8* szHash, mizar_uint8* szR, mizar_uint8* szS);

/********************************************************************************
Desc:The SM2 algorithm is signed with the terminal private key, and the SM3-E hash is performed first

Input parameters:
    nIndex - Certificate Index[0-299]
    nLen - The length of the data to be signed
    szData - Data to be signed
    szX - The public key X that participates in the signature
    szY - The public key Y that participates in the signature

Output parameters:
    szR - Signature R, fixed length 32 bytes
    szS - Signature S, fixed length 32 bytes

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertSM2SignIndexWithIDA(mizar_uint32 nIndex, mizar_uint32 nLen, mizar_uint8* szData,
    mizar_uint8* szX, mizar_uint8* szY, mizar_uint8* szR, mizar_uint8* szS);

/********************************************************************************
Desc:The ECC algorithm is signed with the terminal private key, and the SHA256 hash is performed first

Input parameters:
    nIndex - Certificate Index[0-299]
    nLen - Data length
    szData - Data to be signed

Output parameters:
    szR - Signature R, fixed length 32 bytes
    szS - Signature S, fixed length 32 bytes

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertECCSignIndex(
    mizar_uint32 nIndex, mizar_uint32 nLen, mizar_uint8* szData, mizar_uint8* szR, mizar_uint8* szS);

/*******************************************************************************
Desc: V2X-Endpoint certificates are decrypted using the internal private key SM2
      private key

Input parameters:
    nIndex - Certificate key index[0-299]
    nDatalen - length of data to be calculated[97-158]
    szData - Data to be calculated

Output parameters:
    nOutlen - Output data length
    szOutData - Output data

Return value: 0 - Success; other error codes

*******************************************************************************/
mizar_uint32 MizarV2xECertSM2SkDecIndex(
    mizar_uint32 nIndex, mizar_uint32 nDatalen, mizar_uint8* szData, mizar_uint32* nOutlen, mizar_uint8* szOutData);

/*******************************************************************************
Desc: V2X - Verify the legitimacy of an externally entered key pair

Input parameters:
    nAlg - algorithm: 0-SM2; 1-nistP256; 2-brainpoolP256r1
    szSK - Private key plaintext
    szX - Public key X, fixed length 32 bytes
    szY - Public key Y, fixed length 32 bytes

Output parameters:
    none

Return value: 0 - Success; other error codes

*******************************************************************************/
mizar_uint32 MizarV2xVerifyKeyPair(mizar_uint8 nAlg, mizar_uint8* szSK, mizar_uint8* szX, mizar_uint8* szY);

/*******************************************************************************
Desc: V2X - Verify the legitimacy of internal private and external public keys

Input parameters:
    nIndex - Certificate Index[0-299]
    szX - Public key X, fixed length 32 bytes
    szY - Public key Y, fixed length 32 bytes

Output parameters:
    none

Return value: 0 - Success; other error codes

*******************************************************************************/
mizar_uint32 MizarV2xVerifyKeyPairIndex(mizar_uint32 nIndex, mizar_uint8* szX, mizar_uint8* szY);

/*******************************************************************************
Desc: SM2 point multiplication and point addition: R=a*B+C
    ECQV's public key refactoring algorithm

Input parameters:
     nAlg - 0-SM2; 1-nistP256; 2-brainpoolP256r1
     a - 32-byte large number
     szPKB - 64 bytes of point X || Y
     szPKC - 64 bytes of dot X || Y

Output parameters:
    szPKR - 64 bytes of dot: X|| Y

Return value: 0 - Success; other error codes

*******************************************************************************/
mizar_uint32 MizarV2xPointMulAdd(
    mizar_uint8 nAlg, mizar_uint8* a, mizar_uint8* szPKB, mizar_uint8* szPKC, mizar_uint8* szPKR);

/*******************************************************************************
Desc: V2X - Internal Private Key Refactoring, New Private Key Overwrites Initial
      Private Key and Public Key, and Records,Status as Refactored

Input parameters:
     nIndex - The private key index to be refactored
     e - 32 bytes in large e
     r - 32 bytes in larger r
     pQu - 64 bytes of the reconstructed public key X|| Y (for validation)

Output parameters:
    none

Return value: 0 - Success; other error codes

*******************************************************************************/
mizar_uint32 MizarV2xSkEcqvIndex(mizar_uint32 nIndex, mizar_uint8* e, mizar_uint8* r, mizar_uint8* pQu);

/*******************************************************************************
Desc: V2X - External private key refactoring

Input parameters:
    nAlg - algorithm: 0-SM2; 1-nistP256; 2-brainpoolP256r1
     e - 32 bytes in large e
     r - 32 bytes in larger r
     szSK - Private key plaintext to be refactored, 32 bytes

Output parameters:
    szNewSk - Refactored private key plaintext, 32 bytes

Return value: 0 - Success; other error codes

*******************************************************************************/
mizar_uint32 MizarV2xSkEcqv(mizar_uint8 nAlg, mizar_uint8* e, mizar_uint8* r, mizar_uint8* szSK, mizar_uint8* szNewSk);

/*******************************************************************************
Desc: V2X - Get Key-to-Public Key

Input parameters:
    nIndex - Key pair index[0-299]

Output parameters:
    szX - Public key X, 32 bytes
    szY - Public key Y, 32 bytes

Return value: 0 - Success; other error codes

*******************************************************************************/
mizar_uint32 MizarV2xGetPK(mizar_uint32 nIndex, mizar_uint8* szX, mizar_uint8* szY);

/********************************************************************************
Desc: Use terminal derived private key signatures to sign the input HASH directly
     The chip executes Private szKey = a + exp + c internally, and then signs with
     the derived private key

Input parameters:
    nIndex - Certificate Index[0-299]
    szHash - Data hash to be signed
    exp - derived factor, fixed length 32 bytes
    c - The private key factor returned by the server, with a fixed length of 32 bytes

Output parameters:
    szR - Signature R, fixed length 32 bytes
    szS - Signature S, fixed length 32 bytes

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertSignIndexExp(
    mizar_uint32 nIndex, mizar_uint8* szHash, mizar_uint8* exp, mizar_uint8* c, mizar_uint8* szR, mizar_uint8* szS);

/********************************************************************************
Desc:The SM2 algorithm is signed with a terminal derived private key, and the SM3-E
    hash is performed first,The chip executes Private szKey = a + exp + c internally,
    and then signs with the derived private key

Input parameters:
    nIndex - Certificate Index[0-299]
    nLen - The length of the data to be signed
    szData - Data to be signed
    szX - The public key X that participates in the signature
    szY - The public key Y that participates in the signature
    exp - derived factor, fixed length 32 bytes
    c - The private key factor returned by the server, with a fixed length of 32 bytes

Output parameters:
    szR - Signature R, fixed length 32 bytes
    szS - Signature S, fixed length 32 bytes

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertSM2SignIndexExpWithIDA(mizar_uint32 nIndex, mizar_uint32 nLen, mizar_uint8* szData,
    mizar_uint8* szX, mizar_uint8* szY, mizar_uint8* exp, mizar_uint8* c, mizar_uint8* szR, mizar_uint8* szS);

/********************************************************************************
Desc: ECQV reconstructs the public key and then verifies the signature

Input parameters:
     nAlg - 0-SM2; 1-nistP256; 2-brainpoolP256r1
     a - 32-byte large number
     szPKB - 64 bytes of point X || Y
     szPKC - 64 bytes of dot X || Y
     szR - 32-byte signature R
     szS - 32-byte signature S
     szHash - 32 bytes of hash data

Output parameters:
    none

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xPkEcqvVerify(mizar_uint8 nAlg, mizar_uint8* a, mizar_uint8* szPKB, mizar_uint8* szPKC,
    mizar_uint8* szR, mizar_uint8* szS, mizar_uint8* szHash);

/********************************************************************************
Desc: After the internal private key is derived, a new key pair is generated and stored in the new index
      Derived calculation formula: k_new = (k_seed + f)* e + r

Input parameters:
     nIndex1 - The index of the private key to be derived
     nIndex2 - The index of the private key to be stored
     f - Calculates the factor f
     e - Calculates the factor e
     r -- Calculates the factor r

Output parameters:
     szX - 32 bytes after deriving the public key X
     szY - 32 bytes after derivation of the public key Y

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertSkDeriveIndex(mizar_uint32 nIndex1, mizar_uint32 nIndex2, mizar_uint8* f, mizar_uint8* e,
    mizar_uint8* r, mizar_uint8* szX, mizar_uint8* szY);

/********************************************************************************
Desc: V2X signature verification, using a compressed public key, supports IDA hashing

Input parameters:
    nAlg - algorithm ID: 0-SM2; 1-nistP256; 2-brainpoolP256r1
    nszPKType - Public key type: 0 - Compressed public key (public key length 33 bytes,
		     format: ODD_FLAG|| X)
	      1 - Uncompressed public key (public key length 64 bytes, format X|| Y)
    szPK - public key (according to nszPKType, the public key format is different)
    szR - Signature R
    szS - Signature S
    nHashFlag - Hash flags: 0 - does none hash; 1 - hash first and then verifies signature
    nIDALen - The length of the IDA [0-32], if 0, indicates that no IDA is involved in HASH
    szIDA - IDA data
    nDataLen - The length of the signature data to be verified
    szData - Signature data to be verified

Output parameters:
    none

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xVerify(mizar_uint32 nHashFlag, mizar_uint32 nAlg, mizar_uint32 nszPKType, mizar_uint8* szPK,
    mizar_uint8* szR, mizar_uint8* szS, mizar_uint32 nIDALen, mizar_uint8* szIDA, mizar_uint32 nDataLen,
    mizar_uint8* szData);

/********************************************************************************
Desc: V2X-SM2 signature verification with support for custom IDA hashing

Input parameters:
    szPK - public key (public key length 64 bytes, format X|| Y)
    szR - Signature R
    szS - Signature S
    nIDALen - The length of the IDA [0-32], if 0, indicates that no IDA is involved in HASH
    szIDA - IDA data
    nDataLen - The length of the signature data to be verified
    szData - Signature data to be verified

Output parameters:
    none

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xVerifyWithCustomIDA(mizar_uint8* szPK, mizar_uint8* szR, mizar_uint8* szS, mizar_uint32 nIDALen,
    mizar_uint8* szIDA, mizar_uint32 nDataLen, mizar_uint8* szData);

/********************************************************************************
Desc: After the internal private key is derived, a new key pair is generated, and
    the new private key is used to decrypt the data Derived calculation formula:
    k_new = (k_seed + f)* e + r

Input parameters:
    nAlg - algorithm ID: 0-SM2;1-nistP256; 2-brainpoolP256r1
    nIndex - The private key index to be derived
    f - Calculates the factor f
    e - Calculates the factor e
    r - Calculates the factor r
    kdp - If the key pair algorithm is ECC curvature, the value is valid, is the P1
	parameter in the 1609 specification, and is fixed in length 32 bytes If
	the key pair algorithm is SM2, the value is invalid and must be set to NULL
    szData - Ciphertext data in THE FORMAT OF THE SM2 algorithm C1|| C2|| C3 The
	ECCalgorithm format is V|| C|| T,where V is the public key in compressed
	format, with a fixed length of 33 bytes
    nLen -Ciphertext data length

Output parameters:
     nOutlen - Output data length
     szOut - Decrypted plaintext data

Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertSkDeriveAndDecrypt(mizar_uint32 nAlg, mizar_uint32 nIndex, mizar_uint8* f, mizar_uint8* e,
    mizar_uint8* r, mizar_uint8* kdp, mizar_uint8* szData, mizar_uint32 nLen, mizar_uint32* nOutlen,
    mizar_uint8* szOut);

/**********************************************************************************
Desc: ECIES public key cryptography

Input parameters:
    nAlg - algorithm ID: 1-nistP256; 2-brainpoolP256r1 [Reserved]
    nszPKType - Public key type: 0 - Compressed public key (public key length 33 bytes, format: ODD_FLAG|| X)
	      1 - Uncompressed public key (public key length 64 bytes, format X|| Y)
    szPK - public key (according to nszPKType, the public key format is different)
    kdp - is the P1 parameter in the 1609 specification, fixed length 32 bytes
    nDatalen - length of data to be calculated[1-32]
    szData - Data to be calculated

Output parameters:
    nOutlen - Output data length, input plaintext length +49
    szOutData - Output data, data format V|| C|| T
	  V is a temporary public key in compressed format, with a fixed length of 33 bytes
	  C is ciphertext data, and the length is equal to the length of the input plaintext
	  T is the check digit, fixed length 16 bytes

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarV2xEciesPkEnc(mizar_uint32 nAlg, mizar_uint32 nszPKType, mizar_uint8* szPK, mizar_uint8* kdp,
    mizar_uint32 nDatalen, mizar_uint8* szData, mizar_uint32* nOutlen, mizar_uint8* szOutData);

/**********************************************************************************
Desc: V2x bulk verification signatures

Input parameters:
    nAlg - algorithm ID: 0-SM2;1-nistP256;2-brainpoolP256r1
    nTransNum - The maximum number of data blocks to be checked is 8 blocks
    szData - Blocks to be signed, up to 8 blocks, format: public key X|| The public key Y || Sign R || Sign the S ||
	szHash
    nLen - The length of the data to be checked, the value is fixed to 160

Output parameters:
    Result - Desc 8 bytes: 1 - Check passed; 0 - Check failed

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarV2xBatchVerify(
    mizar_uint32 nAlg, mizar_uint32 nTransNum, mizar_uint8* szData, mizar_uint32 nLen, mizar_uint8* Result);

/**********************************************************************************
Desc: Decompress the compressed public key

Input parameters:
    nAlg - algorithm ID: 0-SM2;1-nistP256;2-brainpoolP256r1
    nUseCacheFlag - Whether to use cache flags
    szCompressed - Compresses public key data in the form of ODD_FLAG|| X
    nLen - Compresses the length of the public key, which is fixed at 33 bytes

Output parameters:
    szPK - The unzipped public key in the format X|| Y

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarV2xUncompressPK(
    mizar_uint32 nAlg, mizar_uint32 nUseCacheFlag, mizar_uint8* szCompressed, mizar_uint32 nLen, mizar_uint8* szPK);

/**********************************************************************************
Desc: Decompress the compressed public key

Input parameters:
    nAlg - algorithm ID: 0-SM2;1-nistP256;2-brainpoolP256r1
    nTransNum - The maximum number of data blocks to be checked is 8 blocks
    szData - Blocks to be signed, up to 8 blocks, format: public key X|| The public key Y || Sign R || Sign the S ||
    szHash
    nLen - The length of the data to be checked, the value is fixed to 129

Output parameters:
    szPK - The unzipped public key in the format X|| Y

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarV2xCompressedPKBatchVerify(
    mizar_uint32 nAlg, mizar_uint32 nTransNum, mizar_uint8* szData, mizar_uint32 nLen, mizar_uint8* Result);


/**********************************************************************************
Desc: Endpoint private key decryption

Input parameters:
    nAlg - algorithm ID: 0-SM2;1-nistP256;2-brainpoolP256r1[reserved]
    nIndex - Certificate Index[0-299]
    kdp - is the P1 parameter in the 1609 specification, fixed length 32 bytes,
      If the algorithm is SM2 and the value is invalid, you can set the value to
      NULL
    szData - The SM2 algorithm format is C1|| C2|| C3;ECC algorithm format is V|| C|| T,
	where V is the public key in compressed format
    nLen - The algorithm is ECC curvature, and kdp is not equal to 0, and the ciphertext
    data length value range is [82-1881], and the algorithm is SM2

Output parameters:
    none

Return value: 0 - Success; other error codes

**********************************************************************************/
mizar_uint32 MizarV2xECertSkDecryptIndex(mizar_uint32 nAlg, mizar_uint32 nIndex, mizar_uint8* kdp, mizar_uint8* szData,
    mizar_uint32 nLen, mizar_uint32* pOutLen, mizar_uint8* szOutData);

/********************************************************************************
Abstract:The SM2 algorithm is signed with the terminal private key, and the SM3-E hash is performed first, and the custom IDA is supported

Input parameters:
	index Certificate Index[0-299]
	The length of the nIDALen IDA [0-32], if 0, indicates that no IDA is involved in HASH
	szIDA IDA data
	len The length of the data to be signed
	data Data to be signed
	x The public key X that participates in the signature
	y Participates in the signature of the public key Y
	
Output parameters:
	r Signature R, fixed length 32 bytes
	s Signature S, fixed length 32 bytes
	
Return value: 0 - Success; other error codes

********************************************************************************/
mizar_uint32 MizarV2xECertSM2SignIndexWithCustomIDA(mizar_uint32 index, mizar_uint32 nIDALen, mizar_uint8* szIDA,
	mizar_uint32 len, mizar_uint8* data, mizar_uint8 *x, mizar_uint8* y, mizar_uint8 *r, mizar_uint8* s);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author	Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-02-23	jianglu	create
 * @ 1.1		2022-05-17	jianglu	add function MizarV2xECertSM2SignIndexWithCustomIDA
 * @ 1.2		2022-06-07	jianglu	0001017/0001018: Change function define
 */
