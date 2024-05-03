/***************************************************
 * Introduction: mizar chip manager define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/

#ifndef _MIZAR_CHIP_MANAGER_H_
#define _MIZAR_CHIP_MANAGER_H_

#include "mizar_basetype.h"

#define SDK_VERSION "mizaru_api_V1.1.4"

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: set the SPI | I2C | SDIO communication equipment types, if this method is not
	  called, the default using SPI

Input parameters:
	nType - Device type:
		0 - SPI;
		1 - I2C;
		2 - SDIO;
		3 - Socket;

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarSetDeviceType(mizar_uint32 nType);

/**********************************************************************************
Desc: Set the path to read the SDK configuration file m2000.ini.
	  If this function is not called, then the m2000.ini is read
	  from the current directory.
	  This function needs to be called before MizarSdkInit is valid

Input parameters:
	szPath - Path to the m2000.ini file, for example: /user/myapp

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarSetCfgPath(mizar_char* szPath);

/**********************************************************************************
Desc: SDK initialization, set chip reset after automatic
	 verification PIN function

Input parameters:
	nAutoVerifyPinFlag - Automatic PIN check switch after reset:
		 0 - no automatic PIN check;
		 1 - Automatic PIN checking
	szPin - PIN Plaintext The value is a string of characters ranging : [4, 16].
	If nAutoVerifyPinFlag is 0, the value is invalid

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarSdkInit(mizar_uint32 nAutoVerifyPinFlag, mizar_char* szPin);

/**********************************************************************************
Desc: Clear the semaphore and shared memory used by the SDK.
	  This interface is called to clean up when the system stops
	  all processes that call chips after deadlock occurs.
	  The kernel shares resources for soft reset

Input parameters:
	none

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDeleteShareObject(void);

/**********************************************************************************
Desc: Low power mode switching

Input parameters:
	nFlag - Switch flag:
	   0 - Switch to low power mode to reduce operating frequency
	   1 - Switch to normal mode and restore the working frequency

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarLowPower(mizar_uint8 nFlag);

/**********************************************************************************
Desc: Obtain the SDK version number

Input parameters:
	none

Output parameters:
	szVersion - SDK version number

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetSdkVersion(mizar_char* szVersion);

/**********************************************************************************
Desc: Obtain the chip key pair public key and chip number,
	 extend the chip number, and customize the chip number

Input parameters:
	none

Output parameters:
	ucKeyX - Chip public key X component, fixed length 32 bytes
	ucKeyY - Chip public key Y component, fixed length 32 bytes
	ucChipCode - Chip number, constant length 12 bytes
	ucExtChipCode - Extension chip number, fixed length 16 bytes
	ucCustomChipCode - Custom chip number, [0-64] bytes
	pnCustomChipCodeLen - User-defined chip ID length. The value ranges: [0, 64]

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetSiliconKeyExt(mizar_uint8* ucKeyX, mizar_uint8* ucKeyY, mizar_uint8* ucChipCode,
    mizar_uint8* ucExtChipCode, mizar_uint8* ucCustomChipCode, mizar_uint8* pnCustomChipCodeLen);

/**********************************************************************************
Desc: Obtain the chip key pair public key and chip number

Input parameters:
	none

Output parameters:
	ucKeyX - Chip public key X component, fixed length 32 bytes
	ucKeyY - Chip public key Y component, fixed length 32 bytes
	ucChipCode - Chip number, constant length 12 bytes

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetSiliconKey(mizar_uint8* ucKeyX, mizar_uint8* ucKeyY, mizar_uint8* ucChipCode);

/**********************************************************************************
Desc: The custom chip number (such as the six business) chip number into the
	 chip customization OTP area, can only be written once

Input parameters:
	ucCustomChipCode - Custom chip number
	nCustomChipCodeLen - Custom chip number length

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarSetCustomChipCode(mizar_uint8* ucCustomChipCode, mizar_uint32 nCustomChipCodeLen);

/**********************************************************************************
Desc: Update 1-3 authentication key (protected with KMC)

Input parameters:
	nLevel - Auth-key indicates the authentication level 1-3
	ucMkey - New Auth-key ciphertext, protected by current KMC encryption
	ucMac - Use the current KMC to calculate the MAC for level and MKEY
	ucCV - New auth-key KEY verification value

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarUpdateAuthKeyByKMC(mizar_uint32 nLevel, mizar_uint8* ucMkey, mizar_uint8* ucMac, mizar_uint8* ucCV);

/**********************************************************************************
Desc: Update the chip master key KMC

Input parameters:
	ucMkey - New KMC ciphertext, protected by current KMC encryption
	ucMac - Compute the MAC using the current KMC against the MKEY
	ucCV - New KMC key verification value

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarUpdateKMC(mizar_uint8* ucMkey, mizar_uint8* ucMac, mizar_uint8* ucCV);

/**********************************************************************************
Desc: Querying chip Status

Input parameters:
	none

Output parameters:
	pState - Chip status code
	szVersion - Chip firmware version number

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetState(mizar_uint32* pState, mizar_char* szVersion);

/**********************************************************************************
Desc: Destroy the key and all FLASH data on the chip

Input parameters:
	none

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarDestroy(void);

/**********************************************************************************
Desc: Modify the execute permission code configuration of all CMD commands

Input parameters:
	ucInsAuthCodeList - Instruction permission code list, 256 bytes
	ucSign - Use the manufacturer's instructions permissions list private key
	 signature, 64 bytes,
	 format: R || S (using MFG_KEY private key signature)

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarUpdateConfig(mizar_uint8* ucInsAuthCodeList, mizar_uint8* ucSign);

/**********************************************************************************
Desc: Chip personalization

Input parameters:
	ucIcvFlag - ICV flag, 4 bytes
	ucHbk - SecureBoot signature check public key sm3-hash, 32 bytes
	ucOemFlag - OEM Flag, 4 bytes
	ucChipId - Chip unique ID, 12 bytes
	ucMfgPk - Vendor public key, 64 bytes
	ucFlashEncKey - Secure FLASH encryption key component, 16 bytes
	ucFlashMacKey - The security FLASH verification key component, 16 bytes
	ucGeneralPurpose - Set the clock source, main frequency, and firmware size, 4 bytes

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarChipPerso(mizar_uint8* ucHbk, mizar_uint8* ucChipId, mizar_uint8* ucMfgPk, mizar_uint8* ucFlashEncKey,
    mizar_uint8* ucFlashMacKey, mizar_uint8* ucGeneralPurpose);

/**********************************************************************************
Desc: Update authentication keys 1-3

Input parameters:
	nLevel - Auth-key indicates the authentication level 1-3
	nKeylen - The ciphertext length of the key
	ucAuthKey - Key cipher
	ucSIG - Sign with MFG_KEY private key
	ucCV - Authentication key verification value

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarUpdateAuthKey(
    mizar_uint32 nLevel, mizar_uint32 nKeylen, mizar_uint8* ucAuthKey, mizar_uint8* ucSIG, mizar_uint8* ucCV);

/**********************************************************************************
Desc: After the chip is powered on or is abnormal, you can reset the chip

Input parameters:
	none

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarChipReset(void);

/**********************************************************************************
Desc: When the chip enters the deep sleep, wake up the chip to make it enter
	  the normal working state

Input parameters:
	none

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarChipWakeup(void);

/**********************************************************************************
Desc: Get external authentication random number

Input parameters:
	none

Output parameters:
	ucRandom - Random number, fixed length of 16 bytes

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarGetExtRnd(mizar_uint8* ucRandom);

/**********************************************************************************
Desc: Perform external authentication

Input parameters:
	nLevel - External authentication level: 1-3
	ucCipher - The external authentication key is used to encrypt the cipher
	   text for random numbers. The fixed length is 16 bytes

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarExtAuth(mizar_uint32 nLevel, mizar_uint8* ucCipher);

/**********************************************************************************
Desc: Cancel the permission of external authentication

Input parameters:
	none

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarExtUnAuth(void);

/**********************************************************************************
Desc: Verify PIN

Input parameters:
	nPINLen - PIN of length, the value ranges from 4 to 16
	szPin - PIN, the length of PIN ciphertext is [4-16] bytes,
	encrypted with the all-0 key SM4

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarVerifyPin(mizar_char* szPin);

/**********************************************************************************
Desc: Change PIN

Input parameters:
	szOldPin - Old PIN plaintext string, length is [4-16]
	szNewPin - New PIN plaintext string, length is [4-16]

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarChangePin(mizar_char* szOldPin, mizar_char* szNewPin);

/**********************************************************************************
Desc: Reset PIN

Input parameters:
	ucMkey - Use KMC to encrypt new PIN ciphertext, fixed length 16 bytes
	ucMac - Use KMC to calculate the MAC value of mkey, fixed length 8 bytes

Output parameters:
	none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarResetPin(mizar_uint8* ucMkey, mizar_uint8* ucMac);

/**********************************************************************************
Desc: Read the configuration file

Input parameters:
	szLogName - Log file name to be save log

Output parameters:
	none

Return value: 0 - succeed; else - error code
**********************************************************************************/
mizar_int32 MizarReadConfig(mizar_char* szLogName);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author			Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-02-10		yuhongbao		create
 * @ 1.2		2022-08-04		yuhongbao		0001272: remove MizarMaintain()
 * @ 1.3		2022-09-06		linzongfang		0001390: Change ver: V1.1.1
 * @ 1.4		2022-11-29		hejiazhen		0001568: Change ver: V1.1.2
 * @ 1.5		2023-01-31		hejiazhen		0001684: Change ver: V1.1.3
 * @ 1.6		2023-02-07		hejiazhen		0001708: Change ver: V1.1.4
 */
