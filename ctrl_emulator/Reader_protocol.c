#include <formatio.h>
#include <rs232.h>
#include <utility.h>
#include <ansi_c.h>
#include <userint.h>
#include "main_UI.h"
#include "global.h"
#include "Reader_protocol.h"
#include "tx_leakage_control.h"
#include "misc_util.h"


unsigned char RF_freq;
unsigned char RF_conf;

unsigned short int Auto_RepeatCycle = 10;

unsigned char check_msg_flag = -1;

int ItemTableRepeat_flag = 0;

//extern unsigned char RFIC_Reg_Ptr;

MagNPhaseParam MagNPhase =
{
	4,	//avg_cnt
	3,	//mv_avg_cnt
	0,	//abs_RSSI
	0,	//raw_RSSI
	0,	//max_indicator
	
	0,	//mv_avg_result
	0,	//log2_RSSI
	0,	//D_RSSI
	0,	//atan_out
	0,	//cal_log10_RSSI
	
	15, //rx_loss.   14dB coupler. 1db margin
	28, //fronted_gain. LNA dependent
	0, 	//vga_gain
	0	//cal_input_power
};


extern MsgFormat cmd, rsp;
extern NtsTableFormat nts;


extern int panelRFIC;
extern int panelTable; 
extern int panelAGC;  
extern int panelLBT; 

extern char str[];

extern unsigned char Demo_operation_state_flag;

extern int g_hCirBmp ;
extern int g_hTriBmp ;
extern int g_hAxeBmp ;

extern int RFRegCtrlModeSpi;

extern void SetRFRegMapColor(void);
extern unsigned char RFIC_Val_ctrl(unsigned char address, unsigned char data, unsigned char write_enable);


void send_msg(void)
{
	unsigned short int temp16;
	unsigned char temp8;
	unsigned char msg_buffer[MAX_PAYLOAD_LENGTH+6];
	unsigned char msg_cnt =0;
	int hours, minutes, seconds;   
	
	GetSystemTime(&hours, &minutes, &seconds);

	//Sending message to reader
	msg_buffer[msg_cnt++] = msg_preable;
	msg_buffer[msg_cnt++] = cmd.type;
	msg_buffer[msg_cnt++] = cmd.code;
	msg_buffer[msg_cnt++] = ((cmd.payload_length>>8)&0xff);
	msg_buffer[msg_cnt++] = ((cmd.payload_length&0xff));
	
	temp16	=	cmd.payload_length;
	
	while(temp16)
	{
		msg_buffer[msg_cnt++] = cmd.payload[temp16-1];
		temp16--;
	}
	
	msg_buffer[msg_cnt++] = msg_end_mask; 
	
	while (GetOutQLen(ComPort));
	
	ComWrt (ComPort, msg_buffer, msg_cnt);
	
	//while (GetOutQLen(ComPort));
	
	
	//Reporting history
	sprintf(str, "CMD(%02d:%02d:%02d):    ",hours,minutes,seconds);
	sprintf(str,"%s %02X", str, msg_preable);
	sprintf(str,"%s %02X", str, cmd.type);
	sprintf(str,"%s %02X", str, cmd.code);
	sprintf(str,"%s %04X", str, cmd.payload_length);

	temp16	=	cmd.payload_length;
	while(temp16)
	{
		sprintf(str,"%s %02X", str, cmd.payload[temp16-1]);
		temp16--;

	}
	sprintf(str,"%s %02X\n", str, msg_end_mask);

	SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_CMD_HISTORY, str);
}

///////////////////////////// Update dialog from rsp /////////////////////////////
void UpDateDialogFromRsp(void)
{
	/*
	unsigned short temp16a, temp16b; 

	//if ((rsp.type ==0x01)&&((rsp.code >= 0xE1) && (rsp.code <= 0xFF)))
	if (rsp.type ==0x01)
	{
		switch (rsp.code)
		{
			case 0xE1:	//Auto-leakage measure
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_MSG_LM_ERROR, rsp.payload[6]);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VAR_I, rsp.payload[5]);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VAR_Q, rsp.payload[4]);
				leakage_magnitude = (rsp.payload[3]<<8)|(rsp.payload[2]);
				leakage_phase = (rsp.payload[1]<<8)|(rsp.payload[0]);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_MSG_LM_MAG, leakage_magnitude);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_MSG_PHASE, (double)(leakage_phase/100));
				if((VGA_sweep_flag==1)||(VPS1_sweep_flag==1)||(VPS2_sweep_flag==1)) Receive_TLC_info = 1;
				break;
			case 0xE2:	////Estimation routin
				vga = rsp.payload[2];
				vps1 = rsp.payload[1];
				vps2 = rsp.payload[0];
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VGACONTRL, vga);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VPS1, vps1);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VPS2, vps2);
				break;
			case 0xE3:	//Tracking
				break;
			case 0xE4:	//sweep search
			case 0xE5:
				vga = rsp.payload[2];
				vps1 = rsp.payload[1];
				vps2 = rsp.payload[0];
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VGACONTRL, vga);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VGAPOWER, 0xFF);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VPS1, vps1);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VPS2, vps2);
	
				Fmt (str, "%f%s", ((double)vga)*2.8/255,"[V]");
				SetCtrlVal (panelLM, PANEL_LM_TEXTMSG_VGACTRL, str);
				Fmt (str, "%f%s", ((double)vps1)*2.8/255,"[V]");
				SetCtrlVal (panelLM, PANEL_LM_TEXTMSG_VPS1CTRL, str);
				Fmt (str, "%f%s", ((double)vps2)*2.8/255,"[V]");
				SetCtrlVal (panelLM, PANEL_LM_TEXTMSG_VPS2CTRL, str);
				break;
	        
			case 0xE6:	//calculate noise level
				LM_noise_level = (rsp.payload[1]<<8)|(rsp.payload[0]);
				SetCtrlVal (panelLM, PANEL_LM_NUMERIC_NOISE_LEVEL, LM_noise_level); 
				break;
			case 0xEB:	//RFIC control
				//if(rsp.payload[0] != 0xFF)
				if(rsp.payload_length ==2)
				{
					SetCtrlVal (panelRFIC, PANEL_RFIC_NUMERIC_MSG_DATA, rsp.payload[0]);
					//SetCtrlVal (panelRFIC, PANEL_RFIC_NUMERIC_MSG_DATA, rsp.payload[0]);
					SetTableCellVal (panelRFIC, PANEL_RFIC_TABLE_RF_REGMAP, MakePoint(2, rsp.payload[1]+1), rsp.payload[0]);
					//RFIC_Reg_Ptr = rsp.payload[1];
					SetRFRegMapColor();
				}
				break;
			case 0xF0:	//one byte control
				if(rsp.payload[2] == 0x0B)	//AGC control
				{
					if(rsp.payload[1] == 0x02)	//read gain
					{
						;
					}
				}
				break;
			case READER_LBT:
				//if(rsp.payload_length == 8)
				{
					MagNPhase.atan_out = (rsp.payload[1]<<8)|rsp.payload[0];
					MagNPhase.log2_RSSI = rsp.payload[2];
					MagNPhase.mv_avg_result = (rsp.payload[4]<<8)|rsp.payload[3];
					MagNPhase.max_indicator = rsp.payload[5];
					MagNPhase.raw_RSSI = rsp.payload[6];
					MagNPhase.abs_RSSI = rsp.payload[7];
					MagNPhase.cal_log10_RSSI = (rsp.payload[8] < 128)? (rsp.payload[8]) : (0xFF - rsp.payload[8] + 1);
					MagNPhase.rx_loss = rsp.payload[9];
					MagNPhase.fronted_gain = rsp.payload[10];
					MagNPhase.vga_gain	= rsp.payload[11];
					MagNPhase.cal_input_power = (rsp.payload[12] < 128) ? (rsp.payload[12]) : (0xFF - rsp.payload[12] + 1);;
					
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_ATAN_OUT, ((double)MagNPhase.atan_out)/16384*180/3.141592);  //  /16384*180/pi
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_LOG2_RSSI, MagNPhase.log2_RSSI);
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_MV_AVG_RESULT, MagNPhase.mv_avg_result);
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_MAX_INDICATOR, MagNPhase.max_indicator);
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_RAW_RSSI, MagNPhase.raw_RSSI);
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_ABS_RSSI, MagNPhase.abs_RSSI);
					
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_ABS_RSSI, MagNPhase.abs_RSSI);
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_ABS_RSSI, MagNPhase.abs_RSSI);
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_ABS_RSSI, MagNPhase.abs_RSSI);
					SetCtrlVal(panelLBT, PANEL_LBT_NUMERIC_ABS_RSSI, MagNPhase.abs_RSSI);
				}
				break;
			
		}//end (rsp.code)
	}
	*/
}

///////////////////////////// Update dialog from notification ///////////////////////////// 

void UpDateDialogFromNts(void)
{
	unsigned short temp16a, temp16b;
	Point return_point;
	int i;
	double temp_double; 
	int row_num;
	int val;
	
	if (rsp.type ==0x02) 
	{
		
		//SetCtrlAttribute (panelTable, PANEL_TBL_TIMER_TBL_REFRESH, ATTR_ENABLED, 0);  //disable timed-refresh timer

		
		switch(rsp.code)
		{
			case 0x21:	//auto-read Type B UID
			case 0x22:	//auto-read Type C UII
				
				nts.PC = ((((unsigned short)rsp.payload[rsp.payload_length-1])<<8)|((unsigned short)rsp.payload[rsp.payload_length-2]));
		
				sprintf (nts.UII, "0x");
				for(i=rsp.payload_length-3;i>=0;i--)
				{
					sprintf (nts.UII, "%s %02X ", nts.UII, rsp.payload[i]);
				}
				
				
				
				if(rsp.payload_length != 0)
				{
				
					if(row_num != 0) //table이 있을때
					{

						if(return_point.y ==0)
						{
							nts.number++;   //ToDo: 없애고 패널에서 읽어오기
							nts.count = 1;
						}
						else
						{

							 ;
						}	
					
				
					}
					else //table이 없을때 
					{
						nts.number++;   //ToDo: 없애고 패널에서 읽어오기
						nts.count = 1;
					}
				
				}
				break;
			
			case 0x27:  //auto-read end.
			 	if(ItemTableRepeat_flag)
				{
					SendAutoReadCmd();

				}
				
				break;
			
		}
		//GetCtrlVal(panelTable,PANEL_TBL_CHECKBOX_TIME_REFRESH, &val);
		//SetCtrlAttribute (panelTable, PANEL_TBL_TIMER_TBL_REFRESH, ATTR_ENABLED, val);  //disable timed-refresh timer	
	}
	
}

void CVICALLBACK Check_msg_event (int COMPort, int eventMask, void *callbackData)
{
	unsigned short temp16a, temp16b; 
	

	if (eventMask & LWRS_RXFLAG)
	//while (eventMask & LWRS_RXFLAG)
	{
		//if(Check_msg()==0)	//success
		//{
			
		//}//end if (eventMask & LWRS_RXFLAG)
		
		check_msg_flag =  Check_msg();
		
		//하나씩 밀리는 버그 해결
		
		if (GetInQLen(ComPort))
			check_msg_flag =  Check_msg();
		
	}

}

int Check_msg(void)
{
	unsigned short temp16a, temp16b;
	unsigned char temp8;
	int return_val;
	int hours, minutes, seconds;   

	if (!GetInQLen(ComPort))
		return_val = -1;		//empty rs232
	else
	{
		DisableBreakOnLibraryErrors ();
		if(ComRdByte(ComPort) == msg_preable)
		{
			GetSystemTime(&hours, &minutes, &seconds);
			
			rsp.type = ComRdByte(ComPort);
			rsp.code = ComRdByte(ComPort);
			temp16a = ComRdByte(ComPort);
			temp16b = ComRdByte(ComPort);
			rsp.payload_length = ((temp16a<<8)&0xff)|(temp16b&0xff);
		
				
			temp16a	=	rsp.payload_length;
			while(temp16a)
			{
				rsp.payload[temp16a-1] = ComRdByte(ComPort);
				temp16a--;
			}
		
			if(ComRdByte(ComPort) == msg_end_mask)
			{
		
				//Report
				sprintf(str, "RSP(%02d:%02d:%02d):    ",hours,minutes,seconds);
				sprintf(str,"%s %02X", str, msg_preable);
				sprintf(str,"%s %02X", str, rsp.type);
				sprintf(str,"%s %02X", str, rsp.code);
				sprintf(str,"%s %04X", str, rsp.payload_length);
	
				temp16a	=	rsp.payload_length;
				while(temp16a)
				{
					sprintf(str,"%s %02X", str, rsp.payload[temp16a-1]);
					temp16a--;
				}
				sprintf(str,"%s %02X\n", str, msg_end_mask);
			
				SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_RSP_HISTORY, str);
				
				return_val = 0;	//success
				
				UpDateDialogFromRsp();
				UpDateDialogFromNts();
			}
			else
			{
				sprintf(str, "Info(%d:%d:%d)    : Wrong format\n",hours,minutes,seconds);
				SetCtrlVal (panelMain, PANEL_MAIN_TEXTBOX_RSP_HISTORY, str);
				
				return_val = -2; //no end_mask
				
			}
		}
		else
		{
			return_val = -3; //no preamble
		}
		
		DisableBreakOnLibraryErrors ();
	}
	
	return return_val;
	
}

int CVICALLBACK Msg_config (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	if(event == EVENT_COMMIT)
	{
		//Set Msg CODE
		if(control == PANEL_MAIN_RING_READER_CONTROL)
		{
			GetCtrlVal (panelMain, control, &cmd.code);
			SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_CODE, cmd.code);
			SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_TYPE, 0x00);//msg type
			switch(cmd.code)
			{
				case READER_POWER_CONTROL: //Reader Power Control
					//default
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x01);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0xFF);//payload, 0xFF=>ON, 0x00==>OFF
					break;
				case READER_CONNECTION_CONTROL: //Reader Connection Control
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x01);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0xFF);//payload, 0xFF=>ON, 0x00==>OFF
					break;
				case GET_READER_INFORMATION: //Get Reader Information
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x01);//payload length
						//- 리더 모델명 : 0x00
						//- 리더의 S/N : 0x01
						//- 리더 제조사 : 0x02
						//- 리더의 주파수 : 0x03
						//- 리더가 지원하는 Tag 종류 : 0x04
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x00);
					break;
				case GET_SIGNAL_STRENGTH: //Get Signal Strength
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case SET_SIGNAL_STRENGTH: //Set Signal Strength 
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x01);//payload length
					//신호강도를 나타내는 0~100 사이의 값 (0x00~0x64)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x64);
					break;
				case GET_REGION: //Get Region
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case SET_REGION: //Set Region
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x01);//payload length
					//- 대한민국 : 0x01
					//- 미국 : 0x02 
					//- 유럽 : 0x04
					//- 일본 : 0x08
					//- 중국 : 0x10
					//- 실패한 경우 : 결과 Code - Cannot Get Region (0x07)
					//- 명령을 지원하지 않는 경우 : 결과 Code - Not Supported Command (0x17) 
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x01);
					break;
				case RESET_READER: //Reset Reader
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case GET_TYPE_B_AI_PARAM: //Get Type B A/I Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;	
				case SET_TYPE_B_AI_PARAM: //Set Type B A/I Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x03);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x0F); //address
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0xFF); //byte mask
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD2, 0x00); //Modulation index. 0x00==>18%
					break;
				case GET_TYPE_C_AI_SELECT_PARAM: //Get Type C A/I Select Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case SET_TYPE_C_AI_SELECT_PARAM: //Set Type C A/I Select Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x0B);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x00); //Mask0 (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x00); //Mask1
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD2, 0x00); //Mask2
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD3, 0x00); //Mask3
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD4, 0x00); //Trunc[1]/RFU[7]
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD5, 0x20); //mask length.bits
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD6, 0xFF); //Ptr0 (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD7, 0x00); //Ptr1
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD8, 0x00); //Ptr2
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD9, 0x00); //Ptr3
					break;
				case GET_TYPE_C_AI_INVENTORY_PARAM: //Get Type C A/I Inventory Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case SET_TYPE_C_AI_INVENTORY_PARAM: //Set Type C A/I Inventory Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x02);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x08); //Sel/Tr/Q
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x00); //S/IV/M
					break;
				case GET_TYPE_C_AI_QUERY_PARAM: // Get Type C A/I Query related Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case SET_TYPE_C_AI_QUERY_PARAM: //Set Type C A/I Inventory Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x02);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x40); //T/Q/UpDn
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x00); //DR/M/TR/Sel/S/T
					break;
				case GET_AUTOMATIC_READ_PARAM: // Get Automatic Read Parameters
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case SET_AUTOMATIC_READ_PARAM: //Set Automatic Read Parameters 
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x03);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x32); //Read Delay Time[ms]
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x32); //Read Cycle(LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD2, 0x00); //Read Cycle
					break;
				
			}
			
		}
		else if(control == PANEL_MAIN_RING_TAG_READ)
		{
			GetCtrlVal (panelMain, control, &cmd.code);
			SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_CODE, cmd.code);
			SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_TYPE, 0x00);//msg type
			switch(cmd.code)
			{
				case 0x21: // Read Type B UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case 0x22: // Read Type C UII Block
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
				case 0x23: // Read Type C UII Block
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x0C);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x08); //length (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x00); //length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD2, 0x00); //Start address (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD3, 0x00); //Start address
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD4, 0x01); //UID (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD5, 0x00); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD6, 0x00); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD7, 0x00); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD8, 0x00); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD9, 0x35); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD10, 0xE0); //UID
					break;
				case 0x24: // Read Type C User Data
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x10);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x0F); //length (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x00); //length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD2, 0x00); //Start address (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD3, 0x00); //Start address
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD4, 0x02); //UID (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD5, 0x00); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD6, 0x00); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD7, 0x00); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD8, 0x80); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD9, 0x5F); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD10, 0x62); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD11, 0xF4); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD12, 0x7B); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD13, 0x25); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD14, 0xF4); //UID
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD15, 0x30); //UID
					break;
				case 0x25: // Read Entire Type B Tag
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x02);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x0F); //length (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x00); //length
					break;
				case 0x26: // Read Entire Type C Tag
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x02);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x0E); //length (LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x00); //length
					break;
				case 0x27: // Start Automatic Read
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x03);//payload length
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD0, 0x10); //Repeat cycle(LSB)
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD1, 0x00); //Repeat cycle
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_PAYLOAD2, 0x22); //Code
					break;
				case 0x28: //  Stop Automatic Read
					SetCtrlVal (panelMain, PANEL_MAIN_NUMERIC_MSG_LENGTH, 0x00);//payload length
					break;
			}
			
		}

		//Set preamble
		else if(control == PANEL_MAIN_NUMERIC_MSG_PREAMBLE)
			GetCtrlVal (panelMain, control, &msg_preable);
		
		//Set Msg type
		else if(control == PANEL_MAIN_NUMERIC_MSG_TYPE)
			GetCtrlVal (panelMain, control, &cmd.type);
		
		//Set Msg code
		else if(control == PANEL_MAIN_NUMERIC_MSG_CODE)
			GetCtrlVal (panelMain, control, &cmd.code);
 		
 		//Set Payload length
		else if(control == PANEL_MAIN_NUMERIC_MSG_LENGTH)
			GetCtrlVal (panelMain, control, &cmd.payload_length);
		
		//Set Payload length
		else if(control == PANEL_MAIN_NUMERIC_MSG_ENDMASK)
			GetCtrlVal (panelMain, control, &msg_end_mask);
		
		
		//Set Payload values
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD35)
			GetCtrlVal (panelMain, control, &cmd.payload[35]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD34)
			GetCtrlVal (panelMain, control, &cmd.payload[34]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD33)
			GetCtrlVal (panelMain, control, &cmd.payload[33]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD32)
			GetCtrlVal (panelMain, control, &cmd.payload[32]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD31)
			GetCtrlVal (panelMain, control, &cmd.payload[31]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD30)
			GetCtrlVal (panelMain, control, &cmd.payload[30]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD29)
			GetCtrlVal (panelMain, control, &cmd.payload[29]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD28)
			GetCtrlVal (panelMain, control, &cmd.payload[28]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD27)
			GetCtrlVal (panelMain, control, &cmd.payload[27]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD26)
			GetCtrlVal (panelMain, control, &cmd.payload[26]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD25)
			GetCtrlVal (panelMain, control, &cmd.payload[25]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD24)
			GetCtrlVal (panelMain, control, &cmd.payload[24]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD23)
			GetCtrlVal (panelMain, control, &cmd.payload[23]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD22)
			GetCtrlVal (panelMain, control, &cmd.payload[22]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD21)
			GetCtrlVal (panelMain, control, &cmd.payload[21]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD20)
			GetCtrlVal (panelMain, control, &cmd.payload[20]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD19)
			GetCtrlVal (panelMain, control, &cmd.payload[19]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD18)
			GetCtrlVal (panelMain, control, &cmd.payload[18]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD17)
			GetCtrlVal (panelMain, control, &cmd.payload[17]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD16)
			GetCtrlVal (panelMain, control, &cmd.payload[16]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD15)
			GetCtrlVal (panelMain, control, &cmd.payload[15]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD14)
			GetCtrlVal (panelMain, control, &cmd.payload[14]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD13)
			GetCtrlVal (panelMain, control, &cmd.payload[13]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD12)
			GetCtrlVal (panelMain, control, &cmd.payload[12]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD11)
			GetCtrlVal (panelMain, control, &cmd.payload[11]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD10)
			GetCtrlVal (panelMain, control, &cmd.payload[10]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD9)
			GetCtrlVal (panelMain, control, &cmd.payload[9]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD8)
			GetCtrlVal (panelMain, control, &cmd.payload[8]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD7)
			GetCtrlVal (panelMain, control, &cmd.payload[7]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD6)
			GetCtrlVal (panelMain, control, &cmd.payload[6]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD5)
			GetCtrlVal (panelMain, control, &cmd.payload[5]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD4)
			GetCtrlVal (panelMain, control, &cmd.payload[4]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD3)
			GetCtrlVal (panelMain, control, &cmd.payload[3]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD2)
			GetCtrlVal (panelMain, control, &cmd.payload[2]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD1)
			GetCtrlVal (panelMain, control, &cmd.payload[1]);
		else if(control == PANEL_MAIN_NUMERIC_MSG_PAYLOAD0)
			GetCtrlVal (panelMain, control, &cmd.payload[0]);

	}
	return 0;
}


void SendAutoReadCmd(void)
{
	cmd.type = 0x00;
	cmd.code = 0x27;
	cmd.payload_length = 0x0003;
	cmd.payload[2]=0x22;
	cmd.payload[1]=0x00;	//repeat MSB
	cmd.payload[0]=0x30;	//repeat LSB
	send_msg();
}



