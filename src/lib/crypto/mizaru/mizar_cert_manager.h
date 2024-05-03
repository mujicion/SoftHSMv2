/***************************************************
 * Introduction: mizar cert manager define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/
#ifndef _MIZAR_CERT_MANAGER_H_
#define _MIZAR_CERT_MANAGER_H_

#include "mizar_basetype.h"

#define MAX_CERT_NUM 30

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: Import certificate

Input parameters:
    nCertIndex - Index of the certificate[0~29]
    nKeyIndex - Corresponding key index[0~0xFF]. If there is no corresponding private key, the value is 0xFF
    nCertType - Certificate type:
					0:PKI-SM2;
					1:PKI-ECC;
					2:PKI-RSA;
					3:CAR-SM2;
					4:CAR-ECC;
					5:CAR-RSA
    nLen - The length of the certificate: PKI[0~2000]; CAR[0~392]
    szCert - Certificate data

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarImportCert(
    mizar_uint32 nCertIndex, mizar_uint32 nKeyIndex, mizar_uint32 nCertType, mizar_uint32 nLen, mizar_uint8* szCert);

/**********************************************************************************
Desc: Delete the certificate

Input parameters:
    nCertIndex - Index of the certificate[0~29]
    nCertType - Certificate type:
					0:PKI-SM2;
					1:PKI-ECC;
					2:PKI-RSA;
					3:IC-SM2;
					4:IC-ECC;
					5:IC-RSA

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDeleteCert(mizar_uint32 nCertIndex, mizar_uint32 nCertType);

/**********************************************************************************
Desc: Read the certificate

Input parameters:
    nCertIndex - Index of the certificate
    nCertType - Certificate type:
	0:PKI-SM2;
	1:PKI-ECC;
	2:PKI-RSA;
	3:IC-SM2;
	4:IC-ECC;
	5:IC-RSA

Output parameters:
    pKeyIndex - Corresponding key pair index
    pCertLen - The length of the certificate
    szCert - certificate data

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetCert(mizar_uint32 nCertIndex, mizar_uint32 nCertType, mizar_uint32* pKeyIndex,
    mizar_uint32* pCertLen, mizar_uint8* szCert);

/**********************************************************************************
Desc: Obtaining certificate List

Input parameters:
    none

Output parameters:
    pListlen - Length of certificate list information
    szList - Certificate list, each certificate format is as follows:
	 INDEX(1B)+KEY_INDEX(1B)+CERT_TYPE(1B)

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetCertList(mizar_uint32* pListlen, mizar_uint8* szList);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version      Date              Author               Note
 * @ -------------------------------------------------------------------------
 * @ 1.0          2022-02-18        yuhongbao            create
 * @
 */