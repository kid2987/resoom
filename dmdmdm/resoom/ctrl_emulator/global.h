//==============================================================================
//
// Title:       global.h
// Purpose:     A short description of the interface.
//
// Created on:  2007-10-05 at ¿ÀÀü 10:42:04 by user.
// Copyright:   samsung. All Rights Reserved.
//
//==============================================================================

#ifndef __global_H__
#define __global_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants
#define COMPORT			1
#define BAUDRATE		115200
#define PARITY			0
#define DATABITS		8
#define STOPBITS		1
#define TIMEOUT			0.02
#define INPUTQSIZE		512
#define OUTPUTQSIZE		512		
		
#define MAX_PAYLOAD_LENGTH 1024*32 
		
#define TRUE 1
#define FALSE 0
//==============================================================================
// Types
typedef struct
{
	unsigned char type;
	unsigned char code;
	unsigned short int payload_length;
	unsigned char payload[MAX_PAYLOAD_LENGTH];

}MsgFormat;

typedef struct
{
	unsigned int number;
	unsigned int PC;
	char UII[1024];
	unsigned int count;
	double atime; //last access time
	double ptime; //passed time
	unsigned char stats;

}NtsTableFormat;

typedef enum
{
	TABLE_NUMBER = 1,
	TABLE_PC,
	TABLE_UII,
	TABLE_COUNT,
	TABLE_ATIME,
	TABLE_PTIME,
	TABLE_STATS,
	TABLE_STATS_IMAGE
}TableRow;

typedef enum
{
	BATCH_TYPE = 1,
	BATCH_CODE,
	BATCH_PAYLOAD_LENGTH,
	BATCH_PAYLOAD,
	BATCH_DESCRIPTION
}TableBatchName;

typedef enum
{
	AXE = 0,
	TRI = 1,
	CIR = 2
}TableStats;

///////////////////////////////////////////////////////////
typedef enum
{
	TAG_BANK_RESERVED =0,
	TAG_BANK_UII,
	TAG_BANK_TID,
	TAG_BANK_USER
}TagBank;

typedef enum
{
	UNDEFINED_CODE = 0,
	READER_POWER_CONTROL = 0x1,		// 0x01
	READER_CONNECTION_CONTROL,		// 0x02
	GET_READER_INFORMATION,			// 0x03
	GET_SIGNAL_STRENGTH,				// 0x04
	SET_SIGNAL_STRENGTH,				// 0x05
	GET_REGION,						// 0x06
	SET_REGION,						// 0x07
	RESET_READER,						// 0x08
	GET_TYPE_B_AI_PARAM,				// 0x09
	SET_TYPE_B_AI_PARAM,				// 0x0A
	GET_TYPE_C_AI_SELECT_PARAM,		// 0x0B
	SET_TYPE_C_AI_SELECT_PARAM,		// 0x0C
	GET_TYPE_C_AI_INVENTORY_PARAM,	// 0x0D
	SET_TYPE_C_AI_INVENTORY_PARAM,	// 0x0E
	GET_TYPE_C_AI_QUERY_PARAM,		// 0x0F
	SET_TYPE_C_AI_QUERY_PARAM,		// 0x10
	GET_AUTOMATIC_READ_PARAM,		// 0x11
	SET_AUTOMATIC_READ_PARAM,		// 0x12

	
	READ_TYPE_B_TID = 0x21,			// 0x21
	READ_TYPE_C_UII_BLOCK,			// 0x22
	READ_TYPE_B_USER_DATA,			// 0x23
	READ_TYPE_C_USER_DATA,			// 0x24
	READ_ENTIRE_TYPEB_TAG,			// 0x25
	READ_ENTIRE_TYPEC_TAG,			// 0x26
	START_AUTOMATIC_READ,			// 0x27
	STOP_AUTOMATIC_READ,				// 0x28

	WRITE_TYPE_C_UII_BLOCK = 0x41,	// 0x41
	WRITE_TYPE_B_USER_DATA,			// 0x42
	WRITE_TYPE_C_USER_DATA,			// 0x43
	WRITE_ENTIRE_TYPE_B_TAG,			// 0x44
	WRITE_ENTIRE_TYPE_C_TAG,			// 0x45
	WRITE_TYPE_C_WORD = 0x50,
	
	
	KILL_TYPE_C_TAG = 0x61,				// 0x61

	LOCK_TYPE_B_TAG = 0x81,			// 0x81
	LOCK_TYPE_C_TAG,					// 0x82

	//GET_LAST_RESULT = 0xA1,			// 0xA1
	//START_TEST_MODE,					// 0xA2
	//STOP_TEST_MODE,					// 0xA3
	//START_RECEIVE_TEST,				// 0xA4
	//STOP_RECEIVE_TEST,					// 0xA5
	
	READER_LBT = 0xC1,	//RSSI measure for LBT with power/RF control
	
	
	TLC_AUTO_LEAKAGE_MEASURE = 0xE1,
	TLC_ESTIMATION_ROUTIN,
	TLC_TRACKING,
	TLC_SWEEP_SEARCH1,
	TLC_SWEEP_SEARCH2,
	TLC_CALCULATE_NOISE_LEVEL,
	
	MISC_POWER_CONTRL = 0xE7,
	MISC_BLOCK_INITI,
	MISC_SET_BB_REG,
	MISC_SET_TLC_BLOCK = 0xEA,
	MISC_SET_RFIC_REG,
	
		
} code_field;

/*
typedef struct
{
	unsigned char	avg_cnt;	//default 4
	unsigned char	mv_avg_cnt;	//default 2**3
	unsigned char	abs_RSSI;
	unsigned char	raw_RSSI;
	unsigned char	max_indicator;
	unsigned short	mv_avg_result;
	unsigned char	log2_RSSI;
	unsigned short	D_RSSI;
	unsigned short	atan_out;
}MagNPhaseParam;
*/

typedef struct
{
	unsigned char	avg_cnt;	//default 4
	unsigned char	mv_avg_cnt;	//default 2**3
	unsigned char	abs_RSSI;
	unsigned char	raw_RSSI;
	unsigned char	max_indicator;
	
	unsigned short	mv_avg_result;
	unsigned char	log2_RSSI;
	unsigned short	D_RSSI;
	unsigned short	atan_out;
	int		cal_log10_RSSI;
	
	int		rx_loss;	//unsigned. positive
	int		fronted_gain;	//positive
	int		vga_gain;	//positive
	int		cal_input_power;	//signed
}MagNPhaseParam;

//==============================================================================
// External variables
extern unsigned char msg_preable;  //Msg preamble
extern unsigned char msg_end_mask;	//Msg end mask

// RS config
extern int ComPort;
extern int BaudRate;
extern int Parity;
extern int DataBits;
extern int StopBits;
extern double TimeOut;
extern int InputQSize;
extern int OutputQSize;

extern int panelMain, menuW1, rsCP, panelLM, panelVGASWP, panelVPS1SWP, panelVPS2SWP;

extern int leakage_magnitude, leakage_phase, LM_noise_level;
extern unsigned char vga, vps1, vps2;
extern int VGA_sweep_flag;
extern int VPS1_sweep_flag;
extern int VPS2_sweep_flag;
extern int Receive_TLC_info;

//==============================================================================
// Global functions
void CVICALLBACK Check_msg_event (int COMPort, int eventMask, void *callbackData);
int Check_msg(void);
void send_msg(void);


		
#ifdef __cplusplus
    }
#endif

#endif  /* ndef __global_H__ */
