#include <userint.h>
#include "main_UI.h"
#include <utility.h>
#include <ansi_c.h>
//==============================================================================
//
// Title:       misc_util.c
// Purpose:     A short description of the implementation.
//
// Created on:  2008-06-25 at ¿ÀÀü 11:05:10 by samsung.
// Copyright:   samsung. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "misc_util.h"
#include "global.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions


unsigned int misc_log2(unsigned int x)
{
	int i;
	unsigned int xx=0;
	for (i=15;i>=0;i--)
	{
		if(x>>i) break;
		
	}
	
	if(i)
		xx = x + (1<<(i-1));
	else
		xx = x;
	
	for (i=15;i>=0;i--)
	{
		if(xx>>i) break;
		
	}
	
	return (unsigned int)(i);
	
}

unsigned short str2hex(char *string, unsigned char *full_byte)
{
	unsigned short i, target_str_length, byte_cnt;
	unsigned char half_byte;

	target_str_length =  strlen(string);
	
	for(i=0;i<target_str_length;i++)
	{
		if(isxdigit(string[i]))
		{
			if(isdigit(string[i]) )
				half_byte = (string[i])-'0';
			else
				half_byte = toupper(string[i])-'A'+10;
			
			if(byte_cnt%2) //È¦¼ö
				full_byte[byte_cnt/2] = (full_byte[byte_cnt/2]<<4)|half_byte;
			else
				full_byte[byte_cnt/2] = half_byte;
			
			byte_cnt++;
		}
	}
	
	return byte_cnt/2;

}

unsigned int misc_str2hex(unsigned char *str, unsigned char *full_byte)
{
	unsigned int target_str_length, byte_cnt, i;
	unsigned char half_byte;
	
	target_str_length =  strlen(str);
	byte_cnt = 0;
	
	for(i=0;i<target_str_length;i++)
	{
		
		if(isxdigit(str[i]))
		{
			if(isdigit(str[i]) )
				half_byte = (str[i])-'0';
			else
				half_byte = toupper(str[i])-'A'+10;
			
			if(byte_cnt%2) //È¦¼ö
				full_byte[byte_cnt/2] = (full_byte[byte_cnt/2]<<4)|half_byte;
			else
				full_byte[byte_cnt>>1] = half_byte;
			
			byte_cnt++;
		}
		else if((str[i] == 'x')||(str[i] == 'X'))
		{
			if (byte_cnt)	byte_cnt--;
		}
	}
	
	return byte_cnt>>1;
}


unsigned int misc_str2hex_invers(unsigned char *str, unsigned char *full_byte)
{
	unsigned int target_str_length, byte_cnt, i;
	unsigned char half_byte;
	unsigned char temp[512]={0};
	
	target_str_length =  strlen(str);
	byte_cnt = 0;
	
	for(i=0;i<target_str_length;i++)
	{
		
		if(isxdigit(str[i]))
		{
			if(isdigit(str[i]) )
				half_byte = (str[i])-'0';
			else
				half_byte = toupper(str[i])-'A'+10;
			
			if(byte_cnt%2) //È¦¼ö
				temp[byte_cnt/2] = (temp[byte_cnt/2]<<4)|half_byte;
			else
				temp[byte_cnt>>1] = half_byte;
			
			byte_cnt++;
		}
		else if((str[i] == 'x')||(str[i] == 'X'))
		{
			if (byte_cnt)	byte_cnt--;
		}
	}
	
	for(i=byte_cnt>>1;i>0;i--)
		full_byte[i-1] = temp[(byte_cnt>>1) -i ];
	
	
	return byte_cnt>>1;
}

unsigned int misc_str2hex_varlength(unsigned char *str, unsigned char *full_byte, unsigned int target_str_length)
{
	unsigned int byte_cnt, i;
	unsigned char half_byte;
	
	byte_cnt = 0;
	
	for(i=0;i<target_str_length;i++)
	{
		
		if(isxdigit(str[i]))
		{
			if(isdigit(str[i]) )
				half_byte = (str[i])-'0';
			else
				half_byte = toupper(str[i])-'A'+10;
			
			if(byte_cnt%2) //È¦¼ö
				full_byte[byte_cnt/2] = (full_byte[byte_cnt/2]<<4)|half_byte;
			else
				full_byte[byte_cnt>>1] = half_byte;
			
			byte_cnt++;
		}
		else if((str[i] == 'x')||(str[i] == 'X'))
		{
			if (byte_cnt)	byte_cnt--;
		}
	}
	
	return byte_cnt>>1;
}


#define ToggleBit8(__Data, __position)	((__Data)^(1<<(__position))) 

//////////////////////////////////////////////////////////////////////////////////
//#define PARALLEL_ADDRESS	0x378
unsigned int PARALLEL_ADDRESS	= 0x378;
//#define SPI_CLK_PIN			2
unsigned char SPI_CLK_PIN	=	2;
//#define SPI_SEN_PIN			3
unsigned char SPI_SEN_PIN	=	3;
//#define SPI_SOUT_PIN		4
unsigned char SPI_SOUT_PIN	=	4;
//#define SPI_SIN_PIN		5
unsigned char SPI_SIN_PIN	=	4;
//#define SPI_SPEED		100
unsigned int SPI_SPEED	=	100;


//double temp_time1, temp_time2;

unsigned int PushSPI(unsigned int SPI_DATA)
{
	//MSB first
	
	int state = 29;	//29 state
	const unsigned int sclk = 0x05555554;
	const unsigned int sen  = 0x10000001;
	unsigned int sout = SPI_DATA<<1;
	unsigned int sin=0;
	
	unsigned char temp_in = 1;
	
	unsigned char DataArray[29], mask;//, LPTHistory[29];
	
	extern int panelSPIMonitor;
	
	int loaded;
	
	unsigned char temp8;
	
	loaded = CVILowLevelSupportDriverLoaded ();
	
	while(state--)
	{
		
		unsigned int delay_cnt = SPI_SPEED;
		unsigned int LPT_data;
		
		
		

		LPT_data 	= (((sclk>>state)&0x01)<<(SPI_CLK_PIN-1))
					| (((sen>>state)&0x01)<<(SPI_SEN_PIN-1))
					| (((sout>>(state>>1))&0x01)<<(SPI_SOUT_PIN-1));
					//| ((1)<<(SPI_SIN_PIN-1));
		
		outp(PARALLEL_ADDRESS,LPT_data>>1);
		
		//LPTHistory[28-state] = LPT_data; 
		
		if((state&1))
		{
			//temp_in = inp(PARALLEL_ADDRESS);
			//sin |= ((temp_in>>(SPI_SIN_PIN-1))<<(state>>1));
			
			temp_in = (inp(PARALLEL_ADDRESS+1)>>(SPI_SIN_PIN-1))&0x01;
			temp8 = inp(PARALLEL_ADDRESS+1);
			sin |= (temp_in<<(state>>1));
			
			//if (LPT_data != temp_in<<1)
			//	Delay(0.001);
		}
		
		
		
		//temp_time1 = Timer();
		
		while(delay_cnt--);
		//Delay(0.001);
		
		
		//temp_time2 = Timer();
		//while(delay_cnt--);
		
		
		/*
		DataArray[28-state]= (((sclk>>state)&0x01)<<(SPI_CLK_PIN-1))
							| (((sen>>state)&0x01)<<(SPI_SEN_PIN-1))
							| (((sout>>(state>>1))&0x01)<<(SPI_SOUT_PIN-1))
							| ((temp_in));
		*/
		DataArray[28-state]= (((sclk>>state)&0x01)<<(0))
							| (((sen>>state)&0x01)<<(1))
							| (((sout>>(state>>1))&0x01)<<(2))
							| ((temp_in)<<(3));

	}
	
	//UpdataLogicAnalyzer();

	ClearDigitalGraph (panelSPIMonitor, PANEL_SPIM_DIGGRAPH_SPIM);
	
	mask = 0xFF;
	
	PlotPackedDigitalLines (panelSPIMonitor, PANEL_SPIM_DIGGRAPH_SPIM, DataArray, 29, VAL_UNSIGNED_CHAR, &mask);
	
	if (SPI_SIN_PIN==7)	//GPIO10
		sin ^= 0xFF;
	
	return sin;
}

#define S3C4RU7

void write_rfic_reg(unsigned char address, unsigned char data)
{
	unsigned int val;
	#ifdef S3C4RU1
		val =  (0x00<<13) | (address <<9) | (data & 0x1FF);   // indicator 1, address 4bit, data 9bit
	#endif
	#ifdef S3C4RU7
		val =  (0x00<<12) | (address <<8) | (data);   // indicator 0, address 4bit, data 8bit
	#endif

	PushSPI(val);
}

unsigned char read_rfic_reg(unsigned char address)
{
	unsigned int val;
	
	#ifdef S3C4RU1
		val =  (0x01<<13) | (address <<9);   // address 5bit, read indicator 1bit, dumy 8bit
	#endif
	#ifdef S3C4RU7
		val =  (0x01<<12) | (address <<8);   // address 5bit, read indicator 1bit, dumy 8bit
	#endif

	return PushSPI(val)&0xFF;
}

int CVICALLBACK SPI_Control (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
	if (event == EVENT_COMMIT)
	{
		switch (control)
		{
			case PANEL_SPI_NUMERIC_PORT:
				GetCtrlVal (panel, PANEL_SPI_NUMERIC_PORT, &PARALLEL_ADDRESS);
				break;
			case PANEL_SPI_NUMERIC_SPEED:
				GetCtrlVal (panel, PANEL_SPI_NUMERIC_SPEED, &SPI_SPEED);
				break;
			case PANEL_SPI_RING_CLKP:
				GetCtrlVal (panel, PANEL_SPI_RING_CLKP, &SPI_CLK_PIN);
				break;
			case PANEL_SPI_RING_ENABLEP:
				GetCtrlVal (panel, PANEL_SPI_RING_ENABLEP, &SPI_SEN_PIN);
				break;
			case PANEL_SPI_RING_OUTP:
				GetCtrlVal (panel, PANEL_SPI_RING_OUTP, &SPI_SOUT_PIN);
				break;
			case PANEL_SPI_RING_INP:
				GetCtrlVal (panel, PANEL_SPI_RING_INP, &SPI_SIN_PIN);
				break;
		}
	}
	return 0;
}
