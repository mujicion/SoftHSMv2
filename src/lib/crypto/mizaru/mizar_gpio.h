/***************************************************
 * Introduction: mizar GPIO define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/
#ifndef _MIZAR_GPIO_H_
#define _MIZAR_GPIO_H_

#include "mizar_basetype.h"

#define GPIO_TIMEOUT  0
#define GPIO_EXCEPTED 1

#define GPIO_SUCCESS	 0
#define GPIO_ERRCODE	 -1
#define GPIO_IN		 0x80
#define GPIO_OUT	 0x40
#define MAX_FILEPATH_LEN 256

typedef struct {
	mizar_int32 pin;
	mizar_int32 value;
	mizar_uint8 flags;
	mizar_int32 fd;
} TGpio;

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: Generate a GPIO file

Input parameters:
    TGpio - GPIO handle to be operated

Output parameters:
    none

Return value: 0 - Succeeded, -1 - Error Code
**********************************************************************************/
mizar_int32 MizarGpioExport(TGpio* pGpio);

/**********************************************************************************
Desc: Set the direction of GPIO operation, read or write

Input parameters:
    TGpio - GPIO handle to be operated

Output parameters:
    none

Return value: 0 - Succeeded, -1 - Error Code
**********************************************************************************/
mizar_int32 MizarGpioDirection(TGpio* pGpio);

/**********************************************************************************
Desc: Read THE GPIO status value

Input parameters:
    TGpio - GPIO handle to be operated

Output parameters:
    none

Return value: GPIO State [0 | 1]
**********************************************************************************/
mizar_int32 MizarGpioRead(TGpio* pGpio);

/**********************************************************************************
Desc: Output the GPIO specified value

Input parameters:
    TGpio - GPIO handle to be operated
    nValue - GPIO level value to be output

Output parameters:
    none

Return value: 0 - Succeeded, -1 - Error Code
**********************************************************************************/
mizar_int32 MizarGpioWrite(TGpio* pGpio, mizar_int32 nValue);

/**********************************************************************************
Desc: Delete the GPIO file

Input parameters:
    TGpio - GPIO handle to be operated

Output parameters:
    none

Return value: 0 - Succeeded, -1 - Error Code
**********************************************************************************/
mizar_int32 MizarGpioUnexport(TGpio* pGpio);

/**********************************************************************************
Desc: Open the GPIO file and store the handle to the context pointer

Input parameters:
    TGpio - GPIO handle to be operated

Output parameters:
    none

Return value: 0 - Succeeded, -1 - Error Code
**********************************************************************************/
mizar_int32 MizarGpioOpen(TGpio* pGpio);

/**********************************************************************************
Desc: Close the GPIO handle

Input parameters:
    TGpio - GPIO handle to be operated

Output parameters:
    none

Return value: 0 - Succeeded, -1 - Error Code
**********************************************************************************/
mizar_int32 MizarGpioClose(TGpio* pGpio);

/**********************************************************************************
Desc: Listens for GPIO status using Interrupt Mode

Input parameters:
    TGpio - Information about GPIO handle to be listened on
    nMs - Timeout duration, in ms
    nCheckValue - Expected GPIO value

Output parameters:
    none

Return value:
	    0 - Timed out, unexpected result
	    1 - GPIO is expected
**********************************************************************************/
mizar_int32 MizarGpioMonitor(TGpio* pGpio, mizar_int32 nMs, mizar_int32 nCheckValue);

/**********************************************************************************
Desc: Set the GPIO interrupt monitor to
      rise edge, fall edge, and monitor all three scenarios simultaneously

Input parameters:
    TGpio - GPIO handle to be operated

Output parameters:
    none

Return value: 0 - Succeeded, -1 - Error Code
**********************************************************************************/
mizar_int32 MizarGpioEdge(TGpio* pGpio);

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