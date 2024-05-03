/***************************************************
 * Introduction: mizar msg define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/

#ifndef _MSGMANAGER_H_
#define _MSGMANAGER_H_

#include "mizar_basetype.h"
#include "mizar_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LEN_OF_CRC_LEN	     2
#define MSG_HEAD_DATA_OFFSET 4
#define MSG_HEAD_DATA_LEN    4
#define MAX_BODY_LEN	     2040
#define MAX_SDIO_BODY_LEN    8184

#define GPIO_CHECK_COUNT 100
#define MAX_MSG_LEN	 2048
#define MAX_SDIO_MSG_LEN 8192

#define MSG_HEAD_LEN	    8
#define LEN_OF_MSG_LEN	    2
#define CHECK_READY_TIMEOUT 5
#define MSG_LEN1	    168
#define MIN_MSG_LEN	    6
#define INS_OFFSET	    4
#define MAX_SRV_MSG_LEN	    MAX_MSG_LEN + 6
#define PROXY_RESET_TIME    3000

#define DEVICE_TYPE_SPI	 0
#define DEVICE_TYPE_I2C	 1
#define DEVICE_TYPE_SDIO 2
#define DEVICE_TYPE_SOCK 3

#define DEFAUILT_LOOP_COUNT 800
#define SDIO_SPEED	    8000000
#define DEFAUILT_SPI_SPEED  1000000
#define INS_NUM		    256

#define KEY_SEM_STAT	    20486832
#define KEY_SEM_STAT_SPI0   KEY_SEM_STAT + 0
#define KEY_SEM_STAT_SPI1   KEY_SEM_STAT + 129
#define KEY_SEM_STAT_TRANS  KEY_SEM_STAT + 257
#define KEY_SEM_STAT_RESET  KEY_SEM_STAT + 1236
#define KEY_SEM_STAT_WAKEUP KEY_SEM_STAT + 1286
#define KEY_SEM_STAT_I2C    KEY_SEM_STAT + 1352
#define KEY_SEM_STAT_SDIO   KEY_SEM_STAT + 1632

#define KEY_SHM_STAT	20488912
#define KEY_SHM_PKCACHE 20258614

typedef struct MESSAGE_STRUCT {
	mizar_uint16 len;
	mizar_uint16 crc16;
	mizar_uint8 ins;
	mizar_uint8 p1;
	mizar_uint8 p2;
	mizar_uint8 retcode;
	mizar_uint8 body[MAX_SDIO_MSG_LEN];
} TMizarMsg;

// proxy msg id
#define MSG_ID_BIZ	 0
#define MSG_ID_RESET	 1
#define MSG_ID_TRANSLOCK 2
#define MSG_ID_HEARTBEAT 3

typedef struct SRV_MSG_STRUCT {
	mizar_uint16 len;
	mizar_uint8 id;
	mizar_uint8 p1;
	mizar_uint8 p2;
	mizar_uint8 ret;
	mizar_uint8 body[MAX_MSG_LEN];
} TMizarSrvMsg;

/**********************************************************************************
Desc: Init Reset GPIO

Input:
    none
Output:
    none

Return: 0 - succeed; else - error code
**********************************************************************************/
mizar_uint32 MizarInitResetGpio(void);

/**********************************************************************************
Desc: Init Read GPIO

Input:
    pGpio - the gpio device to be inited.
Output:
    none

Return: 0- succeed; else - error code
**********************************************************************************/
mizar_uint32 MizarInitReadGpio(TGpio* pGpio);

/**********************************************************************************
Desc: Initialize all channels

Input:
    none
Output:
    none

Return: 0- succeed; else - error code
**********************************************************************************/
mizar_uint32 MizarInitDevice(void);

/**********************************************************************************
Desc: Wait for check gpio, until the value equas expected value or timeout.

Input:
    mode: 0-query mode; 1-interrupt mode.
    nQueryCount: query times when mode==0
    pGpio: GPIO device handle
    time: timeout time(ms)
    nExpectValue: expected gpio value

Output:
    none

return: 0-time out and not expect; -1 -failed; 1-expected
**********************************************************************************/
mizar_int32 MizarCheckGpioStateIsExpected(
    mizar_int32 mode, mizar_int32 nQueryCount, TGpio* pGpio, mizar_int32 time, mizar_int32 nExpectValue);

/**********************************************************************************
Desc: Sends data to the specified SPI channel.

Input:
    nSPISn: The device number.
    pSndMsg: send message
    nLen: send message length
Output:
    none

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarSendDataSn(mizar_int32 nSPISn, mizar_uint8* pSndMsg, mizar_uint32 nLen);

/**********************************************************************************
Desc: Recv data from the specified SPI channel.

Input:
    nSPISn: The device number.
    pResMsg: recv message
    nLen:recv message length
Output:
    none

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarRecvDataSn(mizar_int32 nSPISn, mizar_uint8* pResMsg, mizar_uint32 nLen);

/**********************************************************************************
Desc: send and recv msg from the specified SPI channel.

Input:
    nSPISn: The device number
    pSndMsg: send message
    pResMsg: recv message

Output:
    none

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarSendAndRecvDataSn(mizar_int32 nSPISn, mizar_uint8* pSndMsg, mizar_uint8* pResMsg);

/**********************************************************************************
Desc: send and recv msg.

Input:
    pSndMsg: send message structure
    pResMsg: recv message structure

Output:
    none

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarSendRecv(TMizarMsg* pSndMsg, TMizarMsg* pResMsg);

/**********************************************************************************
Desc: send and recv msg by the specified SPI channel.

Input:
    nSPISn: The device number
    pSndMsg: send message structure
    pResMsg: recv message structure

Output:
    none

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarSendRecvSn(mizar_int32 nSPISn, TMizarMsg* pSndMsg, TMizarMsg* pResMsg);

/**********************************************************************************
Desc: Gets the return code in the message.

Input:
    pMsg: message structure

Output:
    none

return: retcode
**********************************************************************************/
mizar_uint8 MizarGetMizarMsgRetCode(TMizarMsg* pMsg);

/**********************************************************************************
Desc: Message channel semaphore lock.

Input:
    nSn: The message channel sequence number

Output:
    none

return: 0
**********************************************************************************/
mizar_uint32 MizarDevLock(mizar_uint32 nSn);

/**********************************************************************************
Desc: Message channel semaphore unlock.

Input:
    nSn: The message channel sequence number

Output:
    none

return: 0
**********************************************************************************/
mizar_uint32 MizarDevUnlock(mizar_uint32 nSn);

/**********************************************************************************
Desc: Send and receive chip data through the Socket channel.

Input:
    pSndMsg: send message structure

Output:
    pResMsg: recv message structure

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarSendAndRecvChipDataSocket(mizar_uint8* pSndMsg, mizar_uint8* pResMsg);

/**********************************************************************************
Desc: Send and receive chip data to the chip proxy.

Input:
    pSndMsg: send message structure
    ms: Wait for response time
Output:
    pResMsg: recv message structure

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarSendAndRecvProxyDataSocket(mizar_uint8* pSndMsg, mizar_uint8* pResMsg, mizar_int32 ms);

/**********************************************************************************
Desc: Sends a chip reset message to the proxy service via Socket.

Input:
    nMode: The type of transaction,0 - Update global PIN, 1 - Reset
    nFlag: Whether a pin is required ,0-need pin 1-not need
    szPin: pin,when nMode = 0 is valid
Output:
    none

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarProxyMsgReset(mizar_int32 nMode, mizar_int32 nFlag, mizar_char* szPin);

/**********************************************************************************
Desc: Verify the PIN after the chip resets.

Input:
    nSPISn: The message channel sequence number
Output:
    none

return: 0 - Success; other error codes
**********************************************************************************/
mizar_uint32 MizarVerifyPinForReset(mizar_int32 nSPISn);

/**********************************************************************************
Desc: Init WakeUp GPIO

Input:
    none
Output:
    none

Return: 0- succeed; else - error code
**********************************************************************************/
mizar_uint32 MizarInitWakeUpGpio(void);

/**********************************************************************************
Desc: Init all semaphores value in every system process

Input parameters:
	none

Output parameters:
	none

Return value: 0 - Succeeded, -1 - Error Code
**********************************************************************************/
mizar_uint32 MizarInitSem(void);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author		Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-01-04	jianglu		create
 * @ 1.1		2022-04-26	chenzhao		modify MAX_MSG_LEN define
 * @ 1.2		2022-06-10	jianglu		0001080: modify return void type
 */
