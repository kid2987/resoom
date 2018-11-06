#ifndef __READER_PROTOCOL_H
#define __READER_PROTOCOL_H

//#include <userint.h>
//#include "main_UI.h"
//#include "tx_leakage_control.h"


typedef enum
{
	READER_4_1_1 = 0xA1,
	READER_4_1_2,
	READER_4_1_3,
	READER_4_1_4,
	READER_4_1_5,
	READER_4_1_6,
	READER_4_1_7,
	READER_4_1_8,
	READER_4_1_9,
	READER_4_1_10,
	READER_4_1_11,
	READER_4_1_12,
	READER_4_1_13,
	READER_4_1_14,
	READER_4_1_15,
	READER_4_1_16,
	READER_4_1_17,
	READER_4_1_18,
	READER_4_1_19,
	READER_4_1_20,
	READER_4_1_21,
	READER_TEST_MODEM,  //B6
	READER_BER_TEST,	//B7
	READER_ext_1 = 0xB8,
	READER_DAC_TEST,		//B9
	READER_DAC_TEST2,		//BA
	READER_ext_2,
} conf_test_item;

//Miller parameter
#define MILLER_1	0	//FM0
#define FM0			0
#define MILLER_2	1	//Miller subcarrier M=2
#define MILLER_4	2	//Miller subcarrier M=4
#define MILLER_8	3	//Miller subcarrier M=8
#define BITCELL		4	//BITCELL for C

void SendAutoReadCmd(void)  ;

extern void send_msg(void);
extern int Check_msg(void);
extern void Init_panel(void);


#endif
