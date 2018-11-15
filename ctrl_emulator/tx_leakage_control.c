#include <formatio.h>
#include <utility.h>
#include <ansi_c.h>
#include <userint.h>
//#include <utility.h>
//#include <formatio.h>
//#include <ansi_c.h>
//#include <userint.h>
//#include "main_UI.h"
#include "global.h"
#include "tx_leakage_control.h"
			 
extern int panelMain, menuW1, rsCP, panelLM, panelVGASWP, panelVPS1SWP, panelVPS2SWP;
extern int plot_handle_vga_arm_mag, plot_handle_vps1_arm_mag, plot_handle_vps2_arm_mag;
extern int plot_handle_vga_I_mag, plot_handle_vps1_I_mag, plot_handle_vps2_I_mag;
extern int plot_handle_vga_Q_mag, plot_handle_vps1_Q_mag, plot_handle_vps2_Q_mag;
extern int plot_handle_vga_com_mag, plot_handle_vps1_com_mag, plot_handle_vps2_com_mag;
extern int plot_handle_vga_arm_phase, plot_handle_vps1_arm_phase, plot_handle_vps2_arm_phase; 

extern MsgFormat cmd, rsp;

extern unsigned char msg_end_mask;	//Msg end mask

//extern unsigned char rsp.type;	//Rx Msg type
//extern unsigned char rsp.code;	//Response code
//extern unsigned short int rsp.payload_length;	//Response payload length
//extern unsigned char rsp.payload[];	//Response payload

int leakage_magnitude, leakage_phase, LM_noise_level;
unsigned char vga, vps1, vps2;
int VGA_sweep_flag =0;
int VPS1_sweep_flag =0;
int VPS2_sweep_flag =0;
int Receive_TLC_info =0;

double control_x[256];
double arm_magnitude_swp[256]={0};
double arm_phase_swp[256]={0};
double com_phase_swp[256]={0};
double com_magnitude_swp[256]={0};
double I_magnitude_swp[256]={0};
double Q_magnitude_swp[256]={0};

int vga_sweep_cnt =0;
int vps1_sweep_cnt =0;
int vps2_sweep_cnt =0;

int dB_scale_on =0;

double DA_power_value[16] = {-50,-6.3,-3.23, -1.09, -0.2, 0, 0, 4.16, 0, -5.23, -2.19, 2.02, 0, 3.36, 3.93, 4.5};

double BB_gain_offset = 0x2F+6;


/*
int CVICALLBACK Leakage_control (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int temp;
	unsigned char temp8;
	char str[100];
	
	if (event == EVENT_COMMIT)
	{
		cmd.type = 0x00;	//command
		
		switch(control)
		{
			case PANEL_LM_COMMANDBUTTON_MEASURE:
				cmd.code = 0xE1;	//Auto-leakage measure
				cmd.payload_length = 0x00;	//payload length
				break;
			case PANEL_LM_COMMANDBUTTON_ESTIMAT:
				cmd.code = 0xE2;	//Estimation routin
				cmd.payload_length = 0x04;	//payload length
				cmd.payload[3]=(leakage_magnitude>>8)&0xFF;
				cmd.payload[2]=(leakage_magnitude)&0xFF;
				cmd.payload[1]=(leakage_phase>>8)&0xFF;
				cmd.payload[0]=(leakage_phase)&0xFF;
				break;
			case PANEL_LM_COMMANDBUTTON_TRACK:
				cmd.code = 0xE3;	//Tracking
				cmd.payload_length = 0x00;	//payload length
				break;
			case PANEL_LM_COMMANDBUTTON_SWP_SCH:
				cmd.code = 0xE4;	//sweep search
				cmd.payload_length = 0x02;	//payload length
				cmd.payload[1] = 0xF0-0x90; //5 //mod depth
				cmd.payload[0] = 0x00;//0x21; //bb gain
				break;
			case PANEL_LM_COMMANDBUTTON_SWP_SC2:
				cmd.code = 0xE5;	//sweep search 2        
				cmd.payload_length = 0x02;	//payload length
				cmd.payload[1] = 0xF0-0x90; //5 //mod depth
				cmd.payload[0] = 0x00;//0x21; //bb gain
				break;
			case PANEL_LM_COMMANDBUTTON_NOISE:
				cmd.code = 0xE6;	// calculate noise level
				cmd.payload_length = 0x00;	//payload length
				break;
			case PANEL_LM_TOGGLEBUTTON_ADC:
				cmd.code = 0xE7;	// ADC, DAC. RF power control
				cmd.payload_length = 0x02;
				cmd.payload[1] = 0x00;   //ADC
				GetCtrlVal (panel, control, &temp);
				if(temp == 1)
					cmd.payload[0] = 0xFF;
				else
					cmd.payload[0] = 0x00;
					
				break;
			case PANEL_LM_TOGGLEBUTTON_DAC:
				cmd.code = 0xE7;	// ADC, DAC. RF power control
				cmd.payload_length = 0x02;
				cmd.payload[1] = 0x01;   //DAC
				GetCtrlVal (panel, control, &temp);
				if(temp == 1)
					cmd.payload[0] = 0xFF;
				else
					cmd.payload[0] = 0x00;
					
				break;
				
			case PANEL_LM_TOGGLEBUTTON_RF:
				cmd.code = 0xE7;	// ADC, DAC. RF power control
				cmd.payload_length = 0x02;
				cmd.payload[1] = 0x02;   //RF
				GetCtrlVal (panel, control, &temp);
				if(temp == 1)
					cmd.payload[0] = 0xFF;
				else
					cmd.payload[0] = 0x00;
				
				break;
			
			case PANEL_LM_TOGGLEBUTTON_RFIC:
				cmd.code = 0xE7;	// ADC, DAC. RF power control
				cmd.payload_length = 0x02;
				cmd.payload[1] = 0x03;   //RFIC
				GetCtrlVal (panel, control, &temp);
				if(temp == 1)
					cmd.payload[0] = 0xFF;
				else
					cmd.payload[0] = 0x00;
				
				break;
			case PANEL_LM_TOGGLEBUTTON_PA:
				cmd.code = 0xE7;	// ADC, DAC. RF power control
				cmd.payload_length = 0x02;
				cmd.payload[1] = 0x04;   //PA
				GetCtrlVal (panel, control, &temp);
				if(temp == 1)
					cmd.payload[0] = 0xFF;
				else
					cmd.payload[0] = 0x00;
				
				break;
			case PANEL_LM_TOGGLEBUTTON_LNAPOWER:
				cmd.code = 0xE7;	// ADC, DAC. RF power control
				cmd.payload_length = 0x02;
				cmd.payload[1] = 0x05;   //LNA on/off
				GetCtrlVal (panel, control, &temp);
				if(temp == 1)
				{
					cmd.payload[0] = 0xFF;
					Fmt (str, "%d%s", 10,"[dB]");
					SetCtrlVal (panel, PANEL_LM_TEXTMSG_LNACTRL, str);
				}
				else
				{
					cmd.payload[0] = 0x00;
					Fmt (str, "%d%s", -5,"[dB]");
					SetCtrlVal (panel, PANEL_LM_TEXTMSG_LNACTRL, str);
				}
				break;
				
			
			
			case PANEL_LM_COMMANDBUTTON_BBMINIT:	
				cmd.code = 0xE8;	//init
				cmd.payload_length = 0x01;	//payload length
				cmd.payload[0] = 0x00;		//bbm init
				break;
				
			case PANEL_LM_COMMANDBUTTON_RFICINT:	
				cmd.code = 0xE8;	//init
				cmd.payload_length = 0x01;	//payload length
				cmd.payload[0] = 0x01;		//RFIC init
				break;
				
			case PANEL_LM_COMMANDBUTTON_GEN2INT:	
				cmd.code = 0xE8;	//init
				cmd.payload_length = 0x01;	//payload length
				cmd.payload[0] = 0x02;		//Gen2 init
				break;
				
			case PANEL_LM_COMMANDBUTTON_TYPEBIN:	
				cmd.code = 0xE8;	//init
				cmd.payload_length = 0x01;	//payload length
				cmd.payload[0] = 0x03;		//Type B init
				break;
			
			case PANEL_LM_COMMANDBUTTON_IICINIT:
				cmd.code = 0xE8;	//init
				cmd.payload_length = 0x01;	//payload length
				cmd.payload[0] = 0x04;		//IIC
				break;
			
				
			case PANEL_LM_NUMERIC_SCALER_HIGH:
				cmd.code = 0xE9;	//BBM reg setup
				cmd.payload_length = 0x02;	//payload length
				cmd.payload[1] = 0x00; //HIGH
				GetCtrlVal (panel, control, &temp8);
				cmd.payload[0] = temp8;
				break;
			
			case PANEL_LM_NUMERIC_SCALER_LOW:
				cmd.code = 0xE9;	//BBM reg setup
				cmd.payload_length = 0x02;	//payload length
				cmd.payload[1] = 0x01; //LOW
				GetCtrlVal (panel, control, &temp8);
				cmd.payload[0] = temp8;
				break;
			
			case PANEL_LM_NUMERIC_BB_GAIN:
				cmd.code = 0xE9;	//BBM reg setup
				cmd.payload_length = 0x02;	//payload length
				cmd.payload[1] = 0x02; //BB gain
				GetCtrlVal (panel, control, &temp8);
				cmd.payload[0] = temp8;
				Fmt (str, "%d%s", (temp8)+6,"[dB]");
				SetCtrlVal (panel, PANEL_LM_TEXTMSG_BBGAINCTRL, str);
				BB_gain_offset = temp8+6;
				break;
				
			case PANEL_LM_RING_DAGAIN:
				cmd.code = 0xE9;	//reg setup
				cmd.payload_length = 0x02;	//payload length
				cmd.payload[1] = 0x03; //DA gain
				GetCtrlVal (panel, control, &temp8);
				cmd.payload[0] = temp8;
				Fmt (str, "%s%f%s","Totol power = ",( DA_power_value[temp8] )+26,"[dBm]");
				SetCtrlVal (panel, PANEL_LM_TEXTMSG_TOTALPOWER, str);
				break;
				
			case PANEL_LM_NUMERIC_VGACONTRL:
				cmd.code = 0xEA;	//exteranl TLC block
				cmd.payload_length = 0x02;
				cmd.payload[1] = 00;	//VGA gain
				GetCtrlVal (panel, control, &temp8);
				cmd.payload[0] = temp8;
				Fmt (str, "%f%s", ((double)temp8)*2.8/255,"[V]");
				SetCtrlVal (panel, PANEL_LM_TEXTMSG_VGACTRL, str);
				break;
			
			case PANEL_LM_NUMERIC_VGAPOWER:
				cmd.code = 0xEA;	//exteranl TLC block
				cmd.payload_length = 0x02;
				cmd.payload[1] = 01;	//VGA power
				GetCtrlVal (panel, control, &temp8);
				cmd.payload[0] = temp8;
				break;
			case PANEL_LM_NUMERIC_VPS1:
				cmd.code = 0xEA;	//exteranl TLC block
				cmd.payload_length = 0x02;
				cmd.payload[1] = 02;	//VPS1
				GetCtrlVal (panel, control, &temp8);
				cmd.payload[0] = temp8;
				Fmt (str, "%f%s", ((double)temp8)*2.8/255,"[V]");
				SetCtrlVal (panel, PANEL_LM_TEXTMSG_VPS1CTRL, str);
				break;
			case PANEL_LM_NUMERIC_VPS2:
				cmd.code = 0xEA;	//exteranl TLC block
				cmd.payload_length = 0x02;
				cmd.payload[1] = 03;	//VPS2
				GetCtrlVal (panel, control, &temp8);
				cmd.payload[0] = temp8;
				Fmt (str, "%f%s", ((double)temp8)*2.8/255,"[V]");
				SetCtrlVal (panel, PANEL_LM_TEXTMSG_VPS2CTRL, str);
				break;
		}
		send_msg();
	}
	return 0;
}
*/
int CVICALLBACK Panel_LeakageControl (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			HidePanel (panelLM);
			//QuitUserInterface (0);
			break;
		}
	return 0;
}


/*
int CVICALLBACK TLC_sweep_search (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int i;

	switch (event)
		{
		case EVENT_COMMIT:
			for(i=0;i<256;i++)
			{
				control_x[i]=(double)i/255*2.8;
			}
			switch(control)
			{
				case PANEL_LM_COMMANDBUTTON_VGASWP:
					DisplayPanel (panelVGASWP);
					VGA_sweep_flag = 1;
					break;
					
				case PANEL_LM_COMMANDBUTTON_VPS1SWP:
					DisplayPanel (panelVPS1SWP);
					VPS1_sweep_flag = 1;
					break;
				case PANEL_LM_COMMANDBUTTON_VPS2SWP:
					DisplayPanel (panelVPS2SWP);
					VPS2_sweep_flag = 1;
					break;
						
			}
			break;
		}
	return 0;
}
*/
/*
void VGA_sweep_search(void)
{
	int temp16;
	unsigned char temp8;
	float temp_float;
	char str[100];
	
	if((vga_sweep_cnt==0)&&(Receive_TLC_info ==0))
	{
		//1. DAC control
		cmd.type = 0x00;
		cmd.code = 0xEA;	//exteranl TLC block
		cmd.payload_length = 0x02;
		cmd.payload[1] = 00;	//VGA gain
		SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VGACONTRL, vga_sweep_cnt);
		cmd.payload[0] = vga_sweep_cnt;
		Fmt (str, "%f%s", ((double)vga_sweep_cnt)*2.8/255,"[V]");
		SetCtrlVal (panelLM, PANEL_LM_TEXTMSG_VGACTRL, str);
		send_msg();
		
		Delay(0.03);
		
		//2. measure command
		cmd.type = 0x00;
		cmd.code = 0xE1;	//Auto-leakage measure
		cmd.payload_length = 0x00;	//payload length
		send_msg();
		
		
		vga_sweep_cnt++;
	
	}
	
	else if((vga_sweep_cnt!=0)&&(Receive_TLC_info ==1))
	{
		GetCtrlVal (panelLM, PANEL_LM_NUMERIC_MSG_LM_MAG, &temp16);
		if(temp16 == 0) temp16=1;
		
		if(dB_scale_on)
			arm_magnitude_swp[vga_sweep_cnt-1] = 20*log10((double)temp16/128) + BB_gain_offset;
		else
			arm_magnitude_swp[vga_sweep_cnt-1] = temp16;
		//arm_magnitude_swp[vga_sweep_cnt-1] = 10*log10(temp16*temp16/(0.9*0.9));
		
		
		GetCtrlVal (panelLM, PANEL_LM_NUMERIC_VAR_I, &temp8);
		if (temp8 ==0) temp8 = 1;
		
		if(dB_scale_on)
			I_magnitude_swp[vga_sweep_cnt-1] = 20*log10((double)temp8/128) + BB_gain_offset;
		else 
			I_magnitude_swp[vga_sweep_cnt-1] = temp8;
			
		GetCtrlVal (panelLM, PANEL_LM_NUMERIC_VAR_Q, &temp8);
		if (temp8 ==0) temp8 = 1;
		
		
		if(dB_scale_on)
			Q_magnitude_swp[vga_sweep_cnt-1] = 20*log10((double)temp8/128) + BB_gain_offset;
		else
			Q_magnitude_swp[vga_sweep_cnt-1] = temp8;
		
		com_magnitude_swp[vga_sweep_cnt-1] = sqrt(I_magnitude_swp[vga_sweep_cnt-1]*I_magnitude_swp[vga_sweep_cnt-1]+Q_magnitude_swp[vga_sweep_cnt-1]*Q_magnitude_swp[vga_sweep_cnt-1]);
		
		if(dB_scale_on)
			com_magnitude_swp[vga_sweep_cnt-1] = 20*log10((double)com_magnitude_swp[vga_sweep_cnt-1]/128) + BB_gain_offset;
		
		GetCtrlVal (panelLM, PANEL_LM_NUMERIC_MSG_PHASE, &temp_float);
		arm_phase_swp[vga_sweep_cnt-1] =  temp_float;
		
		if(vga_sweep_cnt%2 ==0)
		{
			Fmt (str, "%d%s", (int)((double)(vga_sweep_cnt-1)/255*100),"[%]");
			SetCtrlVal (panelVGASWP, PANEL_VGA_TEXTMSG_VGASWP, str);
		}
		
		if(vga_sweep_cnt == 256)
		{
			plot_handle_vga_arm_mag = PlotXY (panelVGASWP,
											  PANEL_VGA_GRAPH_VGA_SWEEP,
											  control_x, arm_magnitude_swp, 256,
											  VAL_DOUBLE, VAL_DOUBLE,
											  VAL_FAT_LINE, VAL_EMPTY_SQUARE,
											  VAL_SOLID, 1, VAL_RED);
	    	
			plot_handle_vga_I_mag = PlotXY (panelVGASWP,
											PANEL_VGA_GRAPH_VGA_SWEEP, control_x,
											I_magnitude_swp, 256, VAL_DOUBLE,
											VAL_DOUBLE, VAL_FAT_LINE,
											VAL_EMPTY_SQUARE, VAL_SOLID, 1,
											VAL_BLUE);
	    			
			plot_handle_vga_Q_mag = PlotXY (panelVGASWP,
											PANEL_VGA_GRAPH_VGA_SWEEP, control_x,
											Q_magnitude_swp, 256, VAL_DOUBLE,
											VAL_DOUBLE, VAL_FAT_LINE,
											VAL_EMPTY_SQUARE, VAL_SOLID, 1,
											VAL_GREEN);
	    			
			plot_handle_vga_com_mag = PlotXY (panelVGASWP,
											  PANEL_VGA_GRAPH_VGA_SWEEP,
											  control_x, com_magnitude_swp, 256,
											  VAL_DOUBLE, VAL_DOUBLE,
											  VAL_FAT_LINE, VAL_EMPTY_SQUARE,
											  VAL_SOLID, 1, VAL_DK_RED);
			
			plot_handle_vga_arm_phase = PlotXY (panelVGASWP,
											  PANEL_VGA_GRAPH_VGA_SWEEP2,
											  control_x, arm_phase_swp, 256,
											  VAL_DOUBLE, VAL_DOUBLE,
											  VAL_FAT_LINE, VAL_EMPTY_SQUARE,
											  VAL_SOLID, 1, VAL_RED);
	    	
	    	VGA_sweep_flag =0;
	    	vga_sweep_cnt =0;
	    	
	    	Fmt (str, "%d%s", 100,"[%]");
			SetCtrlVal (panelVGASWP, PANEL_VGA_TEXTMSG_VGASWP, str);
		}
		

		
		Receive_TLC_info = 0;
		
		
		if(vga_sweep_cnt<256)
		{
			//1. DAC control
			cmd.type = 0x00;
			cmd.code = 0xEA;	//exteranl TLC block
			cmd.payload_length = 0x02;
			cmd.payload[1] = 00;	//VGA gain
			SetCtrlVal (panelLM, PANEL_LM_NUMERIC_VGACONTRL, vga_sweep_cnt);
			cmd.payload[0] = vga_sweep_cnt;
			Fmt (str, "%f%s", ((double)vga_sweep_cnt)*2.8/255,"[V]");
			SetCtrlVal (panelLM, PANEL_LM_TEXTMSG_VGACTRL, str);
			send_msg();
			
			Delay(0.03);
			
			//2. measure command
			cmd.type = 0x00;
			cmd.code = 0xE1;	//Auto-leakage measure
			cmd.payload_length = 0x00;	//payload length
			send_msg();
			
			vga_sweep_cnt++;
			
		}
		
	}
}
*/

int temp_array[256]={0};

