#include <cviauto.h>
#include <userint.h>
#include "msdxm.h"
#include "excel2000.h"
#include <formatio.h>
#include <rs232.h>
#include <utility.h>
#include <ansi_c.h>
#include "main_UI.h"
#include "global.h"
#include "tx_leakage_control.h"
#include "Reader_protocol.h"
#include "command_batch.h"
//#include "toolbox.h"
#include "misc_util.h"


// RS config
int ComPort 	= COMPORT;
int BaudRate	= BAUDRATE;
int Parity		= PARITY;
int DataBits	= DATABITS;
int StopBits	= STOPBITS;
double TimeOut	= TIMEOUT;
int InputQSize	= INPUTQSIZE;
int OutputQSize	= OUTPUTQSIZE;

//Handles
int panelMain, menuW1, rsCP, panelLM, panelVGASWP, panelVPS1SWP, panelVPS2SWP;
int panelRFIC, panelWT;
int panelDemo;
int panelTable;
int panelLBT;
int panelBatch;
//int panelRFReg;
int panelSPICtrl, panelSPIMonitor;
int panelAGC;
int plot_handle_vga_arm_mag, plot_handle_vps1_arm_mag, plot_handle_vps2_arm_mag;
int plot_handle_vga_I_mag, plot_handle_vps1_I_mag, plot_handle_vps2_I_mag;
int plot_handle_vga_Q_mag, plot_handle_vps1_Q_mag, plot_handle_vps2_Q_mag;
int plot_handle_vga_com_mag, plot_handle_vps1_com_mag, plot_handle_vps2_com_mag;
int plot_handle_vga_arm_phase, plot_handle_vps1_arm_phase, plot_handle_vps2_arm_phase;

static CAObjHandle mediaHandle;

int g_hCirBmp = 0;
int g_hTriBmp = 0;
int g_hAxeBmp = 0;


char str[1000];

//Message protocol variables
unsigned char msg_preable;  //Msg preamble
unsigned char msg_end_mask;	//Msg end mask

MsgFormat cmd, rsp;
NtsTableFormat nts;



extern unsigned char vga, vps1, vps2;
extern int leakage_magnitude, leakage_phase, LM_noise_level;
extern int VGA_sweep_flag;
extern int VPS1_sweep_flag;
extern int VPS2_sweep_flag;
extern int Receive_TLC_info;

extern double arm_phase_swp[];
extern double com_phase_swp[];

void InitialRS(int ComPort,int BaudRate, int Parity, int DataBits, int StopBits, double TimeOut,int InputQSize, int OutputQSize);

extern void VGA_sweep_search(void);
extern void VPS1_sweep_search(void);
extern void VPS2_sweep_search(void);



extern unsigned int PARALLEL_ADDRESS;
extern unsigned char SPI_CLK_PIN;
extern unsigned char SPI_SEN_PIN;
extern unsigned char SPI_SOUT_PIN;
extern unsigned char SPI_SIN_PIN;
extern unsigned int SPI_SPEED;

int delete_old_item_flag;

int RFRegCtrlModeSpi	= 0; 
//unsigned char RFIC_Reg_Ptr =0;


void Init_panel(void)
{
	double value;
	
	//Load protocol variable from GUI default value
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PREAMBLE, &msg_preable);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_TYPE, &cmd.type);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_CODE, &cmd.code);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, &cmd.payload_length);
	//cmd.payload_length[1]=(unsigned char)((temp16>>8)&0x0f);
	//cmd.payload_length[0]=(unsigned char)(temp16&0x0f);
	
	
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD35, &cmd.payload[35]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD34, &cmd.payload[34]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD33, &cmd.payload[33]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD32, &cmd.payload[32]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD31, &cmd.payload[31]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD30, &cmd.payload[30]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD29, &cmd.payload[29]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD28, &cmd.payload[28]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD27, &cmd.payload[27]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD26, &cmd.payload[26]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD25, &cmd.payload[25]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD24, &cmd.payload[24]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD23, &cmd.payload[23]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD22, &cmd.payload[22]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD21, &cmd.payload[21]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD20, &cmd.payload[20]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD19, &cmd.payload[19]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD18, &cmd.payload[18]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD17, &cmd.payload[17]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD16, &cmd.payload[16]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD15, &cmd.payload[15]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD14, &cmd.payload[14]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD13, &cmd.payload[13]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD12, &cmd.payload[12]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD11, &cmd.payload[11]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD10, &cmd.payload[10]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD9, &cmd.payload[9]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD8, &cmd.payload[8]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD7, &cmd.payload[7]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD6, &cmd.payload[6]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD5, &cmd.payload[5]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD4, &cmd.payload[4]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD3, &cmd.payload[3]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD2, &cmd.payload[2]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, &cmd.payload[1]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, &cmd.payload[0]);
	GetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_ENDMASK, &msg_end_mask);
	
	///
	
}


void KDTmp_NoErrorProc(void)
/// LabWindows/CVI에서 불필요한 에러메시지 방지(2005.12.21, 극동테크)
/// A non-debuggable thread is trying to suspend execution at address 00000001.... 에러메시지 방지
/// 또, Windows2000, MS Office 환경에서 종료시 생기는 문제를 해결하기 위해...
{
    int panel_Tmp;

    panel_Tmp = NewPanel (0, "", 0, 0, 0, 0);
    DisplayPanel (panel_Tmp);
    HidePanel (panel_Tmp);
    DiscardPanel (panel_Tmp);
}

void Init_variables(void)
{
	nts.number=0;	//ToDo: 없애고 패널에서 읽어오기 
}

unsigned short calc_crc_bits(unsigned short crc16, unsigned char byte, unsigned char bit_length)
{
	unsigned short result;
	unsigned char xor1,xor2,xor3;
	int i;
	unsigned char abit;
		
	for(i=bit_length-1;i>=0;i--)
	{
		abit = (byte>>i)&0x01;
		
		result = crc16 << 1;
		xor1 = ((crc16 >> 15) ^ abit) & 0x1;
		xor2 = ((crc16 >> 4) ^ xor1) & 0x1;
		xor3 = ((crc16 >> 11) ^ xor1) & 0x1;
		
		result = result & (~0x1021);
		result |= xor1 | (xor2<<5) | (xor3<<12);
		
		crc16 = result; 
	}	
	return result;
}


static const unsigned short crcTable [256] = 
{
	0x0000,0x1021,0x2042,0x3063,0x4084,0x50A5,0x60C6,0x70E7,
	0x8108,0x9129,0xA14A,0xB16B,0xC18C,0xD1AD,0xE1CE,0xF1EF,
	0x1231,0x0210,0x3273,0x2252,0x52B5,0x4294,0x72F7,0x62D6,
	0x9339,0x8318,0xB37B,0xA35A,0xD3BD,0xC39C,0xF3FF,0xE3DE,
	0x2462,0x3443,0x0420,0x1401,0x64E6,0x74C7,0x44A4,0x5485,
	0xA56A,0xB54B,0x8528,0x9509,0xE5EE,0xF5CF,0xC5AC,0xD58D,
	0x3653,0x2672,0x1611,0x0630,0x76D7,0x66F6,0x5695,0x46B4,
	0xB75B,0xA77A,0x9719,0x8738,0xF7DF,0xE7FE,0xD79D,0xC7BC,
	0x48C4,0x58E5,0x6886,0x78A7,0x0840,0x1861,0x2802,0x3823,
	0xC9CC,0xD9ED,0xE98E,0xF9AF,0x8948,0x9969,0xA90A,0xB92B,
	0x5AF5,0x4AD4,0x7AB7,0x6A96,0x1A71,0x0A50,0x3A33,0x2A12,
	0xDBFD,0xCBDC,0xFBBF,0xEB9E,0x9B79,0x8B58,0xBB3B,0xAB1A,
	0x6CA6,0x7C87,0x4CE4,0x5CC5,0x2C22,0x3C03,0x0C60,0x1C41,
	0xEDAE,0xFD8F,0xCDEC,0xDDCD,0xAD2A,0xBD0B,0x8D68,0x9D49,
	0x7E97,0x6EB6,0x5ED5,0x4EF4,0x3E13,0x2E32,0x1E51,0x0E70,
	0xFF9F,0xEFBE,0xDFDD,0xCFFC,0xBF1B,0xAF3A,0x9F59,0x8F78,
	0x9188,0x81A9,0xB1CA,0xA1EB,0xD10C,0xC12D,0xF14E,0xE16F,
	0x1080,0x00A1,0x30C2,0x20E3,0x5004,0x4025,0x7046,0x6067,
	0x83B9,0x9398,0xA3FB,0xB3DA,0xC33D,0xD31C,0xE37F,0xF35E,
	0x02B1,0x1290,0x22F3,0x32D2,0x4235,0x5214,0x6277,0x7256,
	0xB5EA,0xA5CB,0x95A8,0x8589,0xF56E,0xE54F,0xD52C,0xC50D,
	0x34E2,0x24C3,0x14A0,0x0481,0x7466,0x6447,0x5424,0x4405,
	0xA7DB,0xB7FA,0x8799,0x97B8,0xE75F,0xF77E,0xC71D,0xD73C,
	0x26D3,0x36F2,0x0691,0x16B0,0x6657,0x7676,0x4615,0x5634,
	0xD94C,0xC96D,0xF90E,0xE92F,0x99C8,0x89E9,0xB98A,0xA9AB,
	0x5844,0x4865,0x7806,0x6827,0x18C0,0x08E1,0x3882,0x28A3,
	0xCB7D,0xDB5C,0xEB3F,0xFB1E,0x8BF9,0x9BD8,0xABBB,0xBB9A,
	0x4A75,0x5A54,0x6A37,0x7A16,0x0AF1,0x1AD0,0x2AB3,0x3A92,
	0xFD2E,0xED0F,0xDD6C,0xCD4D,0xBDAA,0xAD8B,0x9DE8,0x8DC9,
	0x7C26,0x6C07,0x5C64,0x4C45,0x3CA2,0x2C83,0x1CE0,0x0CC1,
	0xEF1F,0xFF3E,0xCF5D,0xDF7C,0xAF9B,0xBFBA,0x8FD9,0x9FF8,
	0x6E17,0x7E36,0x4E55,0x5E74,0x2E93,0x3EB2,0x0ED1,0x1EF0
};


unsigned short CrcByte (unsigned short remainderCom, unsigned char message) 
{ 
  int byte ;

  byte = (remainderCom >> 8) ^ message ;
  remainderCom = crcTable[byte] ^ (remainderCom << 8);
  return remainderCom ;
}

unsigned char calc_crc5_bits(unsigned char crc5, unsigned char byte, unsigned char bit_length)
{
	unsigned char result;
	unsigned char xor1, xor2;
	int i;
	unsigned char abit;
	
	
	for(i=bit_length-1;i>=0;i--)
	{
		abit = (byte>>i)&0x01;
	
		xor1 = (crc5>>4) ^ abit;
		xor2 = (crc5>>2) ^ xor1;
		
		result = (crc5>>3) & 0x1;
		result <<= 1;
		
		result |= xor2 & 0x1;
		result <<= 1;
		
		result |= (crc5>>1) & 0x1;	
		result <<= 1;
		
		result |= (crc5) & 0x1;
		result <<= 1;
		
		result |= xor1 & 0x1;

		crc5 = result;
	}
	
	return result;	
}


int main (int argc, char *argv[])
{
	int i;
	
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	
	CA_InitActiveXThreadStyleForCurrentThread (0, COINIT_APARTMENTTHREADED);  
	
	if ((panelMain = LoadPanel (0, "main_UI.uir", PANEL_MAIN)) < 0)
		return -1;
	if ((menuW1 = LoadMenuBar (panelMain, "main_UI.uir", W1_MENU))<0)
		return -1;
	if ((rsCP = LoadPanel (0, "main_UI.uir", RS232)) < 0)
		return -1;
	if ((panelSPICtrl = LoadPanel (0, "main_UI.uir", PANEL_SPI)) < 0)
		return -1;
	if ((panelSPIMonitor = LoadPanel (0, "main_UI.uir", PANEL_SPIM)) < 0)
		return -1;

	GetBitmapFromFile ("Cir.ico", &g_hCirBmp);
	GetBitmapFromFile ("Tri.ico", &g_hTriBmp);
	GetBitmapFromFile ("Axe.ico", &g_hAxeBmp);
	
	Init_panel();
	Init_variables();
	
	InitialRS(ComPort,BaudRate, Parity, DataBits, StopBits, TimeOut,InputQSize, OutputQSize);
	
	DisplayPanel (panelMain);
	//DisplayPanel (panelTable); 
	
	RunUserInterface ();
	
	// LabWindows/CVI에서 불필요한 에러메시지 방지
    KDTmp_NoErrorProc();
	
	
	//DiscardPanel (panelBatch); 
	//DiscardPanel (panelLBT);
	//DiscardPanel (panelTable);
	//DiscardPanel (panelDemo);
	//DiscardPanel (rsCP);
	//DiscardPanel (panelLM);
	//DiscardPanel (panelVGASWP);
	//DiscardPanel (panelVPS1SWP);
	//DiscardPanel (panelRFIC);
	//DiscardPanel (panelWT);
	DiscardPanel (panelMain);
	
	CloseCom(ComPort);
	
	CloseCVIRTE ();
	
	return 0;
}

int CVICALLBACK Panel_main (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
		}
	return 0;
}


int CVICALLBACK SEND_MSG (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
	if(event == EVENT_COMMIT)
	{
		Init_panel();
		send_msg();
	}
	return 0;
}



int CVICALLBACK Clear_history (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	if (event == EVENT_COMMIT)
	{
		//printf("controlled\n");
		if (control == PANEL_MAIN_COMMANDBUTTON_CMD_CL)
			ResetTextBox (panelMain, PANEL_MAIN_TEXTBOX_CMD_HISTORY, "\0");
		if (control == PANEL_MAIN_COMMANDBUTTON_RSP_CL)
			ResetTextBox (panelMain, PANEL_MAIN_TEXTBOX_RSP_HISTORY, "\0");
	}
	return 0;
}

static char image_file[MAX_PATHNAME_LEN];
static unsigned char image_buff[32*1024];
static int image_size=0;
unsigned char comp_data[104];
unsigned char check_data[104] = {
0x48,0x00,0x9f,0xe5,0x00,0x10,0xa0,0xe3,0xb0,0x10,
0xc0,0xe1,0x40,0x00,0x9f,0xe5,0x40,0x10,0x9f,0xe5,
0x40,0x20,0x9f,0xe5,0x40,0x30,0x9f,0xe5,0x01,0x40,
0xd2,0xe4,0xb0,0x50,0xd1,0xe1,0x85,0x5e,0xa0,0xe1,
0xa5,0x5f,0xa0,0xe1,0x01,0x00,0x55,0xe3,0xfa,0xff,
0xff,0x1a,0x00,0x40,0xc0,0xe5,0x03,0x00,0x52,0xe1,
0xf6,0xff,0xff,0x1a,0x1c,0x00,0x9f,0xe5,0x02,0x10,
0xa0,0xe3,0xb0,0x10,0xc0,0xe1,0xfe,0xff,0xff,0xea,
0x10,0x00,0x20,0x06,0xdc,0x00,0x30,0x06,0xda,0x00,
0x30,0x06,0x00,0x00,0x00,0x00,0x68,0x00,0x00,0x00,
0x0c,0x00,0x60,0x06
};

int check_uart_data(void)
{
	int index;

	DisableBreakOnLibraryErrors ();

	for (index=0;index<104;index++)
	{
		comp_data[index] = ComRdByte(ComPort);
		if(check_data[index] == comp_data[index])
		{
			;
		}
		else
		{
			return -1; //error
		}
	}
	
	return 0; //success
}

int Download_image_CMC(void)
{
	int i;
	int index;
	int retry_flag = 1;
	int	retry_num = 0;
	int size;
	int temp;
	////////////////////////////////////////////
	//////////// download mini image ///////////
	
	//disable receive timer
	//SetCtrlAttribute (panelMain, PANEL_MAIN_TIMER_RSP, ATTR_ENABLED, 0);

	
    //select image file
    if (FileSelectPopup ("", "*.bin", "*.bin", "Select Mini Boot Image",
						 VAL_OK_BUTTON, 0, 1, 1, 0, image_file) != 1)
		return -1;
	
	GetFileSize (image_file,&image_size);
	//read mini boot image file
	
	FileToArray (image_file, image_buff, VAL_UNSIGNED_CHAR, image_size, 1,
				 VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_BINARY);
	
	FlushOutQ (ComPort);
	FlushInQ (ComPort);
	

	//Delay(0.5);
	
	while(retry_flag)
	{
		for (i=0;i<1;i++)
		{
			// reset
			ComWrtByte(ComPort,0x55);
			ComWrtByte(ComPort,0x00);
			ComWrtByte(ComPort,0x01);
			//Delay(0.5);
		}
		Delay(0.5);
		//send start of download (mini boot)
		ComWrtByte(ComPort,0x70);

		//Delay(1);
		FlushInQ (ComPort);
		
		
		
		size = image_size;
	
		index = 0;
		//send start address
		ComWrtByte(ComPort,0x0a);
		ComWrtByte(ComPort,0x00);
		ComWrtByte(ComPort,0x00);
	
		//send 32 bit at a time
		while((size>>2) != 0)
		{
			ComWrtByte(ComPort, 0x50);
			ComWrtByte(ComPort, image_buff[index+3]);
			ComWrtByte(ComPort, image_buff[index+2]);
			ComWrtByte(ComPort, image_buff[index+1]);
			ComWrtByte(ComPort, image_buff[index]);
		
			size -= 4;
			index += 4;
		}
	
		switch(size)
	    {
	        case 1:
	        	ComWrtByte(ComPort,0x50);
	            ComWrtByte(ComPort,0x00);
	            ComWrtByte(ComPort,0x00);
	            ComWrtByte(ComPort,0x00);
	            ComWrtByte(ComPort,image_buff[index]);
	            break;
	        case 2:
	        	ComWrtByte(ComPort,0x50);
	            ComWrtByte(ComPort,0x00);
	            ComWrtByte(ComPort,0x00);
	            ComWrtByte(ComPort,image_buff[index+1]);
	            ComWrtByte(ComPort,image_buff[index]);
	            break;
	        case 3:
	        	ComWrtByte(ComPort,0x50);
	            ComWrtByte(ComPort,0x00);
	            ComWrtByte(ComPort,image_buff[index+2]);
	            ComWrtByte(ComPort,image_buff[index+1]);
	            ComWrtByte(ComPort,image_buff[index]);
	            break;
	    }
	    
	    ComWrtByte(ComPort,0x55);
	    ComWrtByte(ComPort,0x00);
	    ComWrtByte(ComPort,0x00);
    
	    
	    //bank change & reset
		ComWrtByte(ComPort,0x55);
		ComWrtByte(ComPort,0x00);
		ComWrtByte(ComPort,0x03);
		
		retry_flag = 0;
		
		
		Delay(0.5);
		for(i=0;i<104;i++)
			comp_data[i] =0;
		
		if(GetInQLen(ComPort))
		{
			if(check_uart_data()==-1)
				retry_flag = 1;
		}
		else
			retry_flag = 1;
			
		//Delay(1);
		
		sprintf(str,"Retry number = %d \r\n", retry_num);
		sprintf(str,"%s Press reset & wait a monent \r\n", str);
		SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
	
		if(retry_flag)
		//if (0)
		{
			ComWrtByte(ComPort,0x00);
			ComWrtByte(ComPort,0x00);
		
			// retain reset status and bank change
			ComWrtByte(ComPort,0x55);
			ComWrtByte(ComPort,0x00);
			ComWrtByte(ComPort,0x02);

			// retain reset status and bank change
			ComWrtByte(ComPort,0x55);
			ComWrtByte(ComPort,0x00);
			ComWrtByte(ComPort,0x02);
		
			// reset
			ComWrtByte(ComPort,0x55);
			ComWrtByte(ComPort,0x00);
			ComWrtByte(ComPort,0x01);

			retry_num++;
			//printf("retry_num = %d \r\n", retry_num);

			Delay(2);
		} //end of if(retry_flag)
		
		//if(retry_num > 100)
		//	return -1;
		
	} // end of while(retry_flag)
	sprintf(str,"Mini_boot downloaded.................... \r\n");
	SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
	
	for(i=0; i<32*1024; i++)
		image_buff[i] = 0;

	//////////////////////////////////////////
	////////// download real image ///////////
	
	//ComWrtByte(ComPort,0x00);
	//ComWrtByte(ComPort,0x00);
	
	//select image file
    if (FileSelectPopup ("", "*.bin", "*.bin", "Select Real Boot Image",
						 VAL_OK_BUTTON, 0, 0, 1, 0, image_file) != 1)
		return -1;

	GetFileSize (image_file,&image_size);
	//read mini boot image file
	
	FileToArray (image_file, image_buff, VAL_UNSIGNED_CHAR, image_size, 1,
				 VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_BINARY);
	
	size = image_size;
	index =0;
	
	
	FlushOutQ (ComPort);
	FlushInQ (ComPort);
	
	sprintf(str,"Start real image downloading. \r\n");
	SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
	

	//set start address
	ComWrtByte(ComPort,0x0a);
	ComWrtByte(ComPort,0x00);
	ComWrtByte(ComPort,0x00);
	
	//send 32 bit at a time
	while((size>>2) != 0)
	{
		if (GetOutQLen(ComPort)>10)
		{
			if (temp !=  index*100/image_size+1)
			{
				temp =  index*100/image_size+1;
				sprintf(str,"%d %% downloaded\r\n", index*100/image_size+1);
				SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
			}
			while (GetOutQLen(ComPort));
		}
		
		
		ComWrtByte(ComPort, 0x50);
		ComWrtByte(ComPort, image_buff[index+3]);
		ComWrtByte(ComPort, image_buff[index+2]);
		ComWrtByte(ComPort, image_buff[index+1]);
		ComWrtByte(ComPort, image_buff[index]);
	
		size -= 4;
		index += 4;
	}

	switch(size)
    {
        case 1:
        	ComWrtByte(ComPort,0x50);
            ComWrtByte(ComPort,0x00);
            ComWrtByte(ComPort,0x00);
            ComWrtByte(ComPort,0x00);
            ComWrtByte(ComPort,image_buff[index]);
            break;
        case 2:
        	ComWrtByte(ComPort,0x50);
            ComWrtByte(ComPort,0x00);
            ComWrtByte(ComPort,0x00);
            ComWrtByte(ComPort,image_buff[index+1]);
            ComWrtByte(ComPort,image_buff[index]);
            break;
        case 3:
        	ComWrtByte(ComPort,0x50);
            ComWrtByte(ComPort,0x00);
            ComWrtByte(ComPort,image_buff[index+2]);
            ComWrtByte(ComPort,image_buff[index+1]);
            ComWrtByte(ComPort,image_buff[index]);
            break;
    }
				   
    for(i=0;i<1;i++)
    {
	    //bank change & reset
	    ComWrtByte(ComPort,0x55);
	    ComWrtByte(ComPort,0x00);
	    ComWrtByte(ComPort,0x00);
	    
	    Delay(0.1);
    
	    //bank change & reset
	    ComWrtByte(ComPort,0x55);
	    ComWrtByte(ComPort,0x00);
	    ComWrtByte(ComPort,0x00);
	    
	    Delay(0.1);
    
    
	    //bank change & reset
		ComWrtByte(ComPort,0x55);
		ComWrtByte(ComPort,0x00);
		ComWrtByte(ComPort,0x03);
		
		Delay(0.1);
    }
    
    while (GetOutQLen(ComPort));
    sprintf(str,"Real image downloaded. \r\n");
	SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
	
	//enable receive timer
	//SetCtrlAttribute (panelMain, PANEL_MAIN_TIMER_RSP, ATTR_ENABLED, 1);

	return 0;

}


void CVICALLBACK W1_menu (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	switch(menuItem)
	{
		case W1_MENU_FILE_CMCDOWNLOAD:
			break;
		case W1_MENU_FILE_S3CDOWNLOAD:
			break;
		case W1_MENU_FILE_S3CDOWNLOAD1:
			break;
		case W1_MENU_CONFIG_RS232:
			DisplayPanel (rsCP);
			SetCtrlVal (rsCP, RS232_RING_COMPORT, ComPort);
			SetCtrlVal (rsCP, RS232_RINGSLIDE_BAUDRATE, BaudRate);
			SetCtrlVal (rsCP, RS232_RINGSLIDE_PARITY, Parity);
			SetCtrlVal (rsCP, RS232_RINGSLIDE_DATABITS, DataBits);
			SetCtrlVal (rsCP, RS232_RINGSLIDE_STOPBIT, StopBits);
			break;
		case W1_MENU_CONFIG_TXLEAKAGE:
			DisplayPanel (panelLM);
			break;
		case W1_MENU_CONFIG_RFIC_CONTROL:
			DisplayPanel (panelRFIC);
			//DisplayPanel(panelSPIMonitor);
			break;
		case W1_MENU_DEBUG_TYPECWRITE:
			DisplayPanel (panelWT);
			break;
		case W1_MENU_DEBUG_COMBATCH:
			DisplayPanel (panelBatch);
			break;
		case W1_MENU_DEBUG_LBT:
			DisplayPanel (panelLBT);
			break;
		case W1_MENU_DEBUG_AGC:
			DisplayPanel (panelAGC);
			break;
		case W1_MENU_VIEW_TLCDEMO1:
			DisplayPanel (panelDemo);
			break;
		case W1_MENU_VIEW_ITEM_TLB:
			DisplayPanel (panelTable);
			break;
		
	}
}

int CVICALLBACK TestMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	if(event == EVENT_COMMIT)
	{
		
		// clear receive buffer
		//rsp.code=0; rsp.payload_length=0;rsp.payload[0]=0;
		
		//Send Test mode
		ComWrtByte (ComPort,msg_preable);
		ComWrtByte (ComPort,0x00);
		ComWrtByte (ComPort,0xA2);
		ComWrtByte (ComPort,0x00); 
		ComWrtByte (ComPort,0x00);
		ComWrtByte (ComPort,msg_end_mask);
		
		sprintf(str,"Entered test mode \r\n");
		SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_CMD_HISTORY, str);
		
		//Send Modem_test
		ComWrtByte (ComPort,msg_preable);
		ComWrtByte (ComPort,0x03);
		ComWrtByte (ComPort,0xB0);
		ComWrtByte (ComPort,0x00); 
		ComWrtByte (ComPort,0x00);
		ComWrtByte (ComPort,msg_end_mask);
		
		sprintf(str,"Entered Modem_test \r\n");
		SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_CMD_HISTORY, str);

	}
	return 0;
}

#define RF_POWER	0
#define CHANNELIZATION	1
#define CHANNEL_BW	2
#define POWER_ONOFF_ENVELOP	3
#define HOPPING_ENVELOP 4
#define ASK_MOD_DEPTH	5
#define ASK_RF_ENVELOP	6
#define SPECTRUM_MASK	7
#define SSB_SPECIFICATION	8
#define ASK_RECEIVING	9
#define PSK RECEIVING	10
#define HOPPING_SPECIFICATION	11
#define LBT_HOPPING	12
#define READER_PREAMBLE	13
#define READER_T2	14
#define READER_T3_T4	15
#define READER_T1	16

void InitialRS(int ComPort,int BaudRate, int Parity, int DataBits, int StopBits, double TimeOut,int InputQSize, int OutputQSize)
{
	char str[100];
	
	if (ComPort != 255)
	{
		if(OpenComConfig(ComPort, "", BaudRate, Parity, DataBits, StopBits, InputQSize, OutputQSize)==0)
		{
			/*  Turn off Hardware handshaking (loopback test will not function with it on) */
    		//SetCTSMode (ComPort, LWRS_HWHANDSHAKE_OFF);
			//SetXMode (ComPort, 1);
			
			/*  Make sure Serial buffers are empty */
    		FlushInQ (ComPort);
    		FlushOutQ (ComPort);
			
			//success
			Fmt (str, "%s%d%s", "\nRS Com" ,ComPort," open !");
			SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
			Fmt (str, "%s%d%s", "\n  BaudRate : " ,BaudRate," ");
			SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
			Fmt (str, "%s%d%s", "\n  Parity : " ,Parity," ");
			SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
			Fmt (str, "%s%d%s", "\n  DataBits : " ,DataBits," ");
			SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
			Fmt (str, "%s%d%s", "\n  Stop Bits : " ,StopBits," ");
			SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
			if(SetComTime(ComPort, TimeOut)==0)
			{
				Fmt (str, "%s%f%s", "\n  TimeOut :" ,TimeOut," sec");
				SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
			}
			
			InstallComCallback (ComPort, LWRS_RXFLAG, 0, (int)msg_preable, Check_msg_event, 0);		//for rx
			//InstallComCallback (ComPort, LWRS_TXEMPTY, 0, (int)msg_preable, Check_tx_fifo, 0);		//for rx
			
		}
		else
		{
			//Fale
			SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, "\nRS Initialization FALE!");
		}
	}
	if (ComPort==255)
	{
			Fmt (str, "%s%s", "\n\n Using a Virtual Port","\n");
			SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_STATUS, str);
	}
}

int CVICALLBACK Rs_Config (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	if (event==EVENT_COMMIT)
	{
		switch(control)
		{
			case RS232_BUTTON_CONFIGOK:
				GetCtrlVal (rsCP, RS232_RING_COMPORT, &ComPort);
				GetCtrlVal (rsCP, RS232_RINGSLIDE_BAUDRATE, &BaudRate);
				GetCtrlVal (rsCP, RS232_RINGSLIDE_PARITY, &Parity);
				GetCtrlVal (rsCP, RS232_RINGSLIDE_DATABITS, &DataBits);
				GetCtrlVal (rsCP, RS232_RINGSLIDE_STOPBIT, &StopBits);
				GetCtrlVal (rsCP, RS232_RING_TIMEOUT, &TimeOut);
				GetCtrlVal (rsCP, RS232_RING_INPUTQ, &InputQSize);
				GetCtrlVal (rsCP, RS232_RING_OUTPUTQ, &OutputQSize);
				InitialRS(ComPort,BaudRate, Parity, DataBits, StopBits, TimeOut,InputQSize, OutputQSize);
				HidePanel (rsCP);
				break;
			case RS232_BUTTON_CONFIGCANCEL:
				HidePanel (rsCP);
				break;
		}
	}
	return 0;
}



int CVICALLBACK Panel_pd (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			HidePanel (panel);
			break;
	}
	return 0;
}

int CVICALLBACK Panel_SPI_Ctrl (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			HidePanel (panel);
			break;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////


//----------------------------------------------------------------------------
// ReportWordAutomationError
//----------------------------------------------------------------------------
static void ReportAppAutomationError (HRESULT hr)
{
    char errorBuf[256];
    
    if (hr < 0) {
        CA_GetAutomationErrorString (hr, errorBuf, sizeof (errorBuf));
        MessagePopup ("Error:  Microsoft Excel Automation", errorBuf);
    }
    return;
}
//----------------------------------------------------------------------------
// ClearObjHandle
//----------------------------------------------------------------------------
HRESULT ClearObjHandle(CAObjHandle *objHandle)
{
    HRESULT error = 0;
    if ((objHandle) && (*objHandle))
    {
        error = CA_DiscardObjHandle (*objHandle);
        *objHandle = 0;
    }
    return error;    
}   

int ReadRFICMapFromExcel(char *RegMapFileName)
{
	int result =0;
	int error =0;
	int ExcelWorkbooksHandle =0;
	int ExcelWorkbookHandle =0;
	int ExcelAppHandle =0;
	int ExcelSheetsHandle =0;
	int ExcelWorksheetHandle=0;
	int ExcelRangeHandle =0;
	ExcelObj_Range ExcelSingleCellRangeHandle = 0;
	
	static ERRORINFO ErrorInfo;
	static VARIANT MyCellRangeV;
	static VARIANT MyVariant, MyVariantColor; 
	static LPDISPATCH MyDispatch; 
	VARIANT *vArray = NULL;
	unsigned dim1Size, dim2Size; 
	
	ExcelObj_Sheets test_val;
	
	int i,j;
	double d;
	
	
	// Launch App
    // Connect to existing application if available
    SetWaitCursor (1);
	error = Excel_ActiveApp (NULL, 1, LOCALE_NEUTRAL, 0, &ExcelAppHandle);
	if (error<0)
	{
	    // Launch new App
        SetWaitCursor (1);
        error = Excel_NewApp (NULL, 1, LOCALE_NEUTRAL, 0, &ExcelAppHandle);
        SetWaitCursor (0);
		if (error<0) 
                goto Error;
	}
    SetWaitCursor (0);
	
	// Make App Visible
	error = Excel_SetProperty (ExcelAppHandle, NULL, Excel_AppVisible, CAVT_BOOL, VTRUE);
    if (error<0) 
		goto Error;
	
	MakeApplicationActive ();
	
	// Get Workbooks    
    error = Excel_GetProperty (ExcelAppHandle, NULL, Excel_AppWorkbooks, CAVT_OBJHANDLE, &ExcelWorkbooksHandle);
	if (error < 0) 
		goto Error;
	
	
	// Open existing Workbook
	//error = Excel_ActiveWorkbook (NULL, 1, LOCALE_NEUTRAL, 0, &ExcelWorkbookHandle);
	//Excel_WorkbookSave (ExcelAppHandle, NULL);


    error = Excel_WorkbooksOpen (ExcelWorkbooksHandle, NULL, RegMapFileName, CA_DEFAULT_VAL,
                             CA_DEFAULT_VAL, CA_DEFAULT_VAL,
                             CA_DEFAULT_VAL, CA_DEFAULT_VAL,
                             CA_DEFAULT_VAL, CA_DEFAULT_VAL,
                             CA_DEFAULT_VAL, CA_DEFAULT_VAL,
                             CA_DEFAULT_VAL, CA_DEFAULT_VAL,
                             CA_DEFAULT_VAL, &ExcelWorkbookHandle);


	
	
		
	if (error < 0) 
		goto Error;
	



	// Get Active Workbook Sheets 
	error = Excel_GetProperty (ExcelAppHandle, NULL, Excel_AppSheets, CAVT_OBJHANDLE, &ExcelSheetsHandle);
	if (error < 0) 
		goto Error;

	
	//test
	//error = Excel_GetProperty (ExcelSheetsHandle, NULL, Excel_AppWorksheets, CAVT_OBJHANDLE,&test_val);
	//MessagePopup ("Select Sheet", "Conform the sheet item for load");
	
	// Get Second Sheet 
	error = Excel_SheetsItem (ExcelSheetsHandle, NULL, CA_VariantInt(2), &ExcelWorksheetHandle);
	//error = Excel_GetProperty (ExcelSheetsHandle, NULL, Excel_AppWorksheets, CAVT_OBJHANDLE, &ExcelWorksheetHandle);
	if (error < 0) 
		goto Error;
	
	
	// Make First Sheet Active - should already be active
	error = Excel_WorksheetActivate (ExcelWorksheetHandle, NULL);
	if (error < 0) 
		goto Error;
	
	//error = Excel_WorksheetPrintPreview (ExcelWorksheetHandle, NULL, CA_DEFAULT_VAL);
	//if (error < 0) goto Error; 
	
	// Open new Range for Worksheet
    error = CA_VariantSetCString (&MyCellRangeV, "E4:L19");
    error = Excel_WorksheetRange (ExcelWorksheetHandle, NULL, MyCellRangeV, CA_DEFAULT_VAL, &ExcelRangeHandle);
    CA_VariantClear(&MyCellRangeV);
    if (error<0) 
		goto Error;
	
	// Make range Active    
    error = Excel_RangeActivate (ExcelRangeHandle, &ErrorInfo, NULL);
    if (error<0) 
		goto Error;
	
	
	//----------------------------------------------------------------
    // 1) Get each cell value in Range one at a time using an offset 
    //    from the range's top left cell
    //----------------------------------------------------------------
	//#define ROW_START	
	#define ROW_END			16
	//#define COLUMNS_START
	#define COLUMNS_END		8
	
	
  
	
	
	
	//----------------------------------------------------------------
    // 2) Get Range as a SAFEARRAY inside a VARIANT
    //----------------------------------------------------------------
    error = Excel_GetProperty (ExcelRangeHandle, &ErrorInfo, Excel_RangeValue2, CAVT_VARIANT, &MyVariant);
    if (error<0) goto Error;
    
    // Get 2D Array of values from SAFEARRAY in Variant
    error = CA_VariantGet2DArray (&MyVariant, CAVT_VARIANT, &vArray, &dim1Size, &dim2Size);
    if (error<0) goto Error;
    
    // Loop on SAFEARRAY of VARIANTs
    //printf("Get all data at once:\n");
    for (i = 0; i < dim1Size; i++)
    {
        //printf("    ");
        for (j = 0; j < dim2Size; j++)
        {
			char ContentsBuffer[100] = "   ";
			
            // Use CA_Get2DArrayElement macro to get VARIANT array element
            MyVariant = CA_Get2DArrayElement(vArray, dim1Size, dim2Size, i, j, VARIANT);
            if (!(CA_VariantHasCString(&MyVariant) || CA_VariantHasNull (&MyVariant)|| CA_VariantIsEmpty (&MyVariant)))
            {
                MessagePopup("Warning", "Values returned were not of type String.");
                goto Error;
            }    
            
            // Get value
            //error = CA_VariantGetDouble (&MyVariant, &d);
			if(CA_VariantHasCString(&MyVariant))
				error = CA_VariantGetCStringBuf (&MyVariant, ContentsBuffer, 100);
			
			
            if (error<0) goto Error;
        
            // Clear VARAINT element in array
            CA_VariantClear(&MyVariant);

            //printf("%s ", ContentsBuffer);
			SetTableCellVal (panelRFIC, PANEL_RFIC_TABLE_RF_REGMAP, MakePoint (j+3,i+1), ContentsBuffer);
        }
        //printf("\n");
    }    
    //printf("\n");
	
	
	
	
	
	//////////////////////////////////////
	ClearObjHandle (&ExcelRangeHandle);
    ClearObjHandle (&ExcelWorksheetHandle);
    ClearObjHandle (&ExcelSheetsHandle);
    
    if (ExcelWorkbookHandle) 
    {
        // Close workbook without saving
        //error = Excel_WorkbookClose (ExcelWorkbookHandle, NULL, CA_VariantBool (VFALSE), CA_DEFAULT_VAL, CA_VariantBool (VFALSE));
        //if (error < 0)
        //    goto Error;
        
        ClearObjHandle (&ExcelWorkbookHandle);
    }
    
    ClearObjHandle (&ExcelWorkbooksHandle);
        
    if (ExcelAppHandle)
    {   
        //if (excelLaunched) 
        {
            // Quit the Application
            //error = Excel_AppQuit (ExcelAppHandle, &ErrorInfo);
            //if (error < 0) goto Error;
        }
        
        ClearObjHandle (&ExcelAppHandle);
    } 
    
    return 0;   
Error:    
    if (error < 0)
        ReportAppAutomationError (error);
        
    return error;  
 
	
//	return result;
}





void CVICALLBACK RFIC_Ctrl_menu (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	char RegMapFileName[MAX_PATHNAME_LEN]; 

	switch(menuItem)
	{
		case RFIC_CTRL_FILE_OPEN_MAP:
			//select map file
		    if (FileSelectPopup ("", "*.xls", "*.xls", "Select RFIC Reg Map",
								 VAL_OK_BUTTON, 0, 0, 1, 0, RegMapFileName) == 1)
			{
				ReadRFICMapFromExcel(RegMapFileName);
			}
			
			break;
		case RFIC_CTRL_OPTION_SPI_CTRL:
			DisplayPanel(panelSPICtrl);
			SetCtrlVal (panelSPICtrl, PANEL_SPI_NUMERIC_PORT, PARALLEL_ADDRESS);
			SetCtrlVal (panelSPICtrl, PANEL_SPI_NUMERIC_SPEED, SPI_SPEED);
			SetCtrlVal (panelSPICtrl, PANEL_SPI_RING_CLKP, SPI_CLK_PIN);
			SetCtrlVal (panelSPICtrl, PANEL_SPI_RING_ENABLEP, SPI_SEN_PIN);
			SetCtrlVal (panelSPICtrl, PANEL_SPI_RING_OUTP, SPI_SOUT_PIN);
			SetCtrlVal (panelSPICtrl, PANEL_SPI_RING_INP, SPI_SIN_PIN);
			break;
		
		case RFIC_CTRL_OPTION_SPI_ENALBE:
			RFRegCtrlModeSpi ^= 1;
			SetMenuBarAttribute (menuBar, menuItem, ATTR_CHECKED, RFRegCtrlModeSpi);
			SetMenuBarAttribute (menuBar, RFIC_CTRL_OPTION_SPI_CTRL, ATTR_DIMMED, RFRegCtrlModeSpi^1);
			SetMenuBarAttribute (menuBar, RFIC_CTRL_OPTION_SPI_MONITOR, ATTR_DIMMED, RFRegCtrlModeSpi^1);
			break;
		case RFIC_CTRL_OPTION_SPI_MONITOR:
			DisplayPanel(panelSPIMonitor);
			break;
	}
}

void SetRFRegMapColor(void)
{
	int i,j;
	unsigned char Data;
	
	for(j=0;j<16;j++)
	{
		GetTableCellVal (panelRFIC, PANEL_RFIC_TABLE_RF_REGMAP, MakePoint (2, j+1), &Data); 
		for(i=0;i<8;i++)
		{
			//Rect MakeRect (int top, int left, int height, int width);
			SetTableCellRangeAttribute (panelRFIC, PANEL_RFIC_TABLE_RF_REGMAP, MakeRect(j+1, i+3, 1, 1), ATTR_TEXT_BGCOLOR, (Data>>(7-i))&0x01 ? 0xD0D0D0L : 0xFFFFFFL);
		}
	}
	
}

unsigned char RFIC_Val_ctrl(unsigned char address, unsigned char data, unsigned char write_enable)
{

	//RFIC_Reg_Ptr = address;
	
	if(RFRegCtrlModeSpi)
	{
		if (write_enable)
		{
			write_rfic_reg(address, data);
		}
		else
		{
			data = read_rfic_reg(address);
		}
	}
	else
	{
		cmd.type = 0x00;
		cmd.code = 0xEB;	  //RFIC control
		cmd.payload_length = 0x03;	//payload length
		
		cmd.payload[2] = write_enable&0x01;
		cmd.payload[1] = address;
		cmd.payload[0] = data;		//data
		
		send_msg();
	}
	return data;
}

int CVICALLBACK RF_RegMap_Table (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
	Point cell = {0,0};
	unsigned char Data; 
	unsigned char Address;
	//GetActiveTableCell (panel, control, cell);
	//printf("                Point.x --> %d, Point.y --> %d \r\n", cell[0].x, cell[0].y); 
	//printf("test");
	
	switch (event)
	{
		//case EVENT_COMMIT:
		//case EVENT_TABLE_ROW_COL_LABEL_CLICK:
		case EVENT_KEYPRESS:
			if ( eventData1 == 32 )  // SPACE
			{
				//printf("eventData1 --> %d, eventData2 --> %d \r\n", eventData1, eventData2);
				//int GetActiveTableCell (int panelHandle, int controlID, Point *cell);
				//GetActiveTableCell (panel, control, &cell);
				//printf("                Point.x --> %d, Point.y --> %d \r\n", cell.x, cell.y);
				
				GetActiveTableCell (panel, control, &cell);
				if (cell.x >2)
				{
					
					GetTableCellVal (panel, control, MakePoint (1, cell.y), &Address);
					GetTableCellVal (panel, control, MakePoint (2, cell.y), &Data); 
					Data = ToggleBit8(Data, 8-(cell.x-2));
					SetTableCellVal (panel, control, MakePoint(2, cell.y), Data);
					SetRFRegMapColor();
					RFIC_Val_ctrl(Address, Data, 1);
				}
				
				//SetTableCellRangeAttribute (panel, control, VAL_TABLE_ROW_RANGE(rowIndex), ATTR_TEXT_BGCOLOR, 0xD0D0D0L);
				
				
			}
			break;

		case EVENT_VAL_CHANGED://EVENT_COMMIT:
			//GetActiveTableCell (panel, control, &cell);
			//if ( (cell.x ==2)&& (cell.y<=16) )
			if( (eventData2 ==2)&& (eventData1<=16) )
			{
				GetTableCellVal (panel, control, MakePoint (1, eventData1), &Address);
				GetTableCellVal (panel, control, MakePoint (2, eventData1), &Data); 
				
				SetRFRegMapColor();
				RFIC_Val_ctrl(Address, Data, 1);
			}
			break;
			
	}
	return 0;
}
