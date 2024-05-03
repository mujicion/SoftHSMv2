/***************************************************
 * Introduction: mizar ext data define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/
#ifndef _MIZAR_EXT_DATA_H_
#define _MIZAR_EXT_DATA_H_

#include "mizar_basetype.h"

#define EXT_FLASH_OFFSET 140000

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: Read data from extended FLASH storage space

Input parameters:
    nOffset - Extends the space offset, starting at 0
    nDatalen - Length of data to read

Output parameters:
    szOutData - Returned data

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarReadExtData(mizar_uint32 nOffset, mizar_uint32 nDatalen, mizar_uint8* szOutData);

/**********************************************************************************
Desc: Write data to the extended FLASH storage space

Input parameters:
    nOffset - Extends the space offset, starting at 0
    nDatalen - Length of data to be written
    szData - Data to be written

Output parameters:
    none

Return value: 0 - Succeeded, Others - Error Code
**********************************************************************************/
mizar_uint32 MizarWriteExtData(mizar_uint32 nOffset, mizar_uint32 nDatalen, mizar_uint8* szData);

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