/***************************************************
 * Introduction: mizar errcode define
 *
 * Copyright (C) 2017, 2022, Thinktech, Inc.
 ***************************************************/

#ifndef _MIZAR_ERRCODE_H_
#define _MIZAR_ERRCODE_H_

#define SUCCESS		0x00
#define ERR_MSG_CRC	0x02
#define ERR_ACCESS_DENY 0x03

#define ERR_CALC	  0x08
#define ERR_SM3_FAIL	  0xB0
#define ERR_CFG		  0xE0
#define ERR_PARAMETER	  0xE1
#define ERR_CMD_SEND	  0xE2
#define ERR_CMD_TIMEOUT	  0xE3
#define ERR_COMM	  0xE4
#define ERR_MSG_CHECK	  0xE5
#define ERR_MSG_BODY_LEN  0xE6
#define ERR_OPENDEV	  0xE7
#define ERR_SPI_IOCTL	  0xE8
#define ERR_I2C_FAULT	  0xE9
#define ERR_MSG_LEN	  0xEA
#define ERR_RSA_LEN	  0xEB
#define ERR_GPIO_OPER	  0xEC
#define ERR_DATA_LEN	  0xED
#define ERR_SEM_FAIL	  0xEF
#define ERR_SPI_SN	  0xF0
#define ERR_KEY_LEN	  0xF1
#define ERR_UNCOMPRESS_PK 0xF2
#define ERR_NOT_SUPPORT	  0xF3
#define ERR_SET_DEV	  0xF4
#define ERR_SYSTEM	  0xF5
#define ERR_CHIP_BUSY	  0xF6
#define ERR_CONNECT_AGENT 0xF7
#define ERR_FULL_POLL	  0xF8
#define ERR_MSG_FORMAT	  0xF9
#define ERR_MSG		  0xFA
#define ERR_SOKT_CONNECT  0xFB
#define ERR_SOKT_BUSY	  0xFC
#define ERR_PIN_LEN	  0xFD

#endif
/**
 * @ Revision History
 * @ -------------------------------------------------------------------------
 * @ Version      Date              Author          Note
 * @ -------------------------------------------------------------------------
 * @ 1.0          2021-12-31        jianglu         create
 * @
 */