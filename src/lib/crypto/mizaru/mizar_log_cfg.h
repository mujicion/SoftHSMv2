/***************************************************
 * Introduction: Write logs and profile parsing
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/

#ifndef _MIZAR_LOG_CFG_H_
#define _MIZAR_LOG_CFG_H_

#include "mizar_basetype.h"
#include <stdio.h>

#define LOG_TYPE_NONE  0
#define LOG_TYPE_ERROR 1
#define LOG_TYPE_WARN  2
#define LOG_TYPE_INFO  3
#define LOG_TYPE_DATA 4
#define LOG_TYPE_DEBUG 5

#define MAX_FILEPATH_LEN 256

typedef struct 
{
	mizar_uint8 nLevel;
	mizar_uint8 nFlag;
	mizar_uint8 nType;
	mizar_uint32 nFileSize;
	mizar_char szLogPath[128];
	mizar_char szLogFileName[128];
	mizar_char ip[128];
	mizar_uint16 nPort;
} TMizarLogCfg;

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************
Desc: Save the format string log

Input parameters:
	nLevel - Log level[0-NONE; 1-ERROR; 2-WARN; 3-INFO; 4-DEBUG]
	szFormat - The log info

Output parameters:
	none

Return value: 0
**********************************************************************************/
mizar_uint32 MizarSysLog(mizar_uint8 nLevel, const mizar_char* szFormat, ...);

/**********************************************************************************
Desc: Output log file, BCD log print

Input parameters:
	nLevel - Log level[0-NONE; 1-ERROR; 2-WARN; 3-INFO; 4-DEBUG]
	pBinLog - The log data
	nBinLogLen - The length of the data
	szShowBuf - Print the info before the hex data

Output parameters:
	none

Return value: 0
**********************************************************************************/
mizar_uint32 MizarHexLog(mizar_uint8 nLevel, mizar_uint8* pBinLog, mizar_int32 nBinLogLen, mizar_char* szShowBuf);

/**********************************************************************************
Desc: Read the configuration file to specify the property values

Input parameters:
	fp - The file operate pointer
	szSection - The Section name
	szSubSection - The sub section name (the item name)

Output parameters:
	szItemValue - The result of the config item

Return value: = 0 - found; else - not found
**********************************************************************************/
mizar_int32 MizarGetItemValue(
	FILE* fp, const mizar_char* szSection, const mizar_char* szSubSection, mizar_char* szItemValue);

/**********************************************************************************
Desc: Get item value from list, such as "111|222|333|"

Input parameters:
	szLine - The data list string, such as "111|222|333|"
	nPos - The pos the field need to get
	szSep - The seperate byte such as '|'

Output parameters:
	szDes - The value to be get

Return value: = 0 - succeed; else - error code
**********************************************************************************/
mizar_int32 MizarGetItem(mizar_char* szLine, mizar_char* szDes, mizar_int32 nPos, mizar_char szSep);

/**********************************************************************************
Desc: Sets the log output level externally

Input parameters:
	nLevel - Log level[0-NONE; 1-ERROR; 2-WARN; 3-INFO; 4-DEBUG]

Output parameters:
	none

Return value: 0
**********************************************************************************/
mizar_uint32 MizarSetLogLevel(mizar_uint8 nLevel);

/**********************************************************************************
Desc: Sets the log output flag externally

Input parameters:
	nFlag - Print log on terminal or not. 1-print; 0-do not print

Output parameters:
	none

Return value: none
**********************************************************************************/
mizar_uint32 MizarSetLogPrint(mizar_uint8 nFlag);

/**********************************************************************************
Desc: Init log

Input parameters:
	pLogCfg: log config 
		nLevel - Log level[1-ERROR; 2-WARN; 3-INFO; 4-DEBUG]
		nFlag - Print log on terminal or not. 1-print; 0-do not print
		nType - 0-file and print; 1-UDP only; 2-file only
		nFileSize - Log file size limit(KByte). loop to save log if exceed limit.
		szLogPath - Log path to be stored
		szLogFileName - Log file name to be save log
		ip - Udp log server ip
		nPort - Upd log server port

Output parameters:
	none

Return value: = 0 - succeed; else - error code
**********************************************************************************/
mizar_int32 MizarInitLog(TMizarLogCfg* pLogCfg);

/**********************************************************************************
Desc: Print Hex data on terminal only

Input parameters:
	data - The bin data to be print
	len - Length of the data
	szInfo - Print the desc info before the data

Output parameters:
	none

Return value: none
**********************************************************************************/
mizar_uint32 MizarPrintHex(mizar_uint8* data, mizar_uint32 len, mizar_char* szInfo);

/**********************************************************************************
Desc: Save the format string log

Input parameters:
	nTabLevel - add tab level: [0-4]
	nLevel - Log level[0-NONE; 1-ERROR; 2-WARN; 3-INFO; 4-DEBUG]
	szFormat - The log info

Output parameters:
	none

Return value: 0
**********************************************************************************/
mizar_uint32 MizarSysLogFormat(mizar_uint8 nTabLevel, mizar_uint8 nLevel, const mizar_char* szFormat, ...);

/**********************************************************************************
Desc: Output log file, BCD log print

Input parameters:
	nTabLevel - add tab level: [0-4]
	nLevel - Log level[0-NONE; 1-ERROR; 2-WARN; 3-INFO; 4-DEBUG]
	pBinLog - The log data
	nBinLogLen - The length of the data
	szShowBuf - Print the info before the hex data

Output parameters:
	none

Return value: 0
**********************************************************************************/
mizar_uint32 MizarHexLogFormat(mizar_uint8 nTabLevel, mizar_uint8 nLevel, mizar_uint8* pBinLog, mizar_int32 nBinLogLen, mizar_char* szShowBuf);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version	Date			Author		Note
 * @ -------------------------------------------------------------------------
 * @ 1.0		2022-02-10	zhangjianlin	create
 * @ 1.1		2022-06-10	jianglu			0001080: modify return void type
 * @ 1.2		2022-06-13	jianglu			0001087: MizarInitLog/MizarSysLogFormat/MizarHexLogFormat
 * @ 1.3		2022-06-14	jianglu			0001115: add LOG_TYPE_DATA
 * @ 1.4		2023-02-07	hejiazhen		0001708: add LOG_TYPE 2-file only
 * @
 */
