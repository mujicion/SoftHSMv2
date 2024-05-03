/***************************************************
 * Introduction: mizar memoryopt define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/

#ifndef _MIZAR_MEMORYOPT_H_
#define _MIZAR_MEMORYOPT_H_

#include "mizar_basetype.h"

#define MEM_CMP_EQUAL	0
#define MEM_CMP_UNEQUAL 1

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc:
	Sets buffers to a specified character.

Input:
    c - character to set
    count - number of characters

Output:
    dst - pointer of destination

Return:
	0
**********************************************************************************/
mizar_uint32 MizarMemset(void* dst, const mizar_uint8 ch, mizar_uint32 count);

/**********************************************************************************
Desc:
	Copies characters between buffers.

Input:
    src - pointer of source
    count - number of characters to copy

Output:
    dst - pointer of destination

Return:
	0
**********************************************************************************/
mizar_uint32 MizarMemcpy(void* dst, const void* src, mizar_uint32 count);

/**********************************************************************************
Desc:
	Compare characters in two buffers.

Input:
    dest - first buffer
    src - second buffer
    count - number of characters to compare

Output:
    none

Return:
	0 - buf1 equals buf2
	1 - buf1 not equals buf2
**********************************************************************************/
mizar_uint32 MizarMemcmp(const void* dst1, const void* dst2, mizar_uint32 count);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author		Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-03-03	jianglu		create
 * @ 1.1		2022-04-20	jianglu		update MizarMemset/MizarMemcpy/MizarMemcmp/MizarGetSysOrderType
 * @ 1.2		2022-06-10	jianglu		0001080: modify return void type
 * @
 */
