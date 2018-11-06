#include <utility.h>
#include <ansi_c.h>
//==============================================================================
//
// Title:       command_batch.c
// Purpose:     A short description of the implementation.
//
// Created on:  2008-06-24 at ¿ÀÈÄ 4:14:16 by samsung.
// Copyright:   samsung. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "command_batch.h"
#include <userint.h>
#include "main_UI.h"
#include "misc_util.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
static char command_patch_file[MAX_PATHNAME_LEN];
static int image_size=0;
//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions


int CVICALLBACK Panel_batch (int panel, int event, void *callbackData,
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


void CVICALLBACK Batch_menu (int menuBar, int menuItem, void *callbackData,int panel)
{
	FILE *fptr;
	char line_buffer[500],  returned_line_buffer[500];
	char *com_start_str, *com_end_str, *com_comment_str;
	unsigned int com_str_length;
	unsigned char com_hex[512] = {0};
	unsigned int com_hex_length;
	int row_num;
	
	switch(menuItem)
	{
		case COM_BATCH_FILE_LOADBATCH:
			//select command patch file
		    if (FileSelectPopup ("", "*.txt", "*.txt", "Select command patch file", VAL_OK_BUTTON, 0, 1, 1, 0, command_patch_file) != 1)
				break;
			GetFileSize (command_patch_file,&image_size);
			fptr = fopen (command_patch_file, "r");
			
			while (fgets (line_buffer, 500, fptr) != NULL)
			{
				unsigned char type, code;
				unsigned short int payload_length;
				char payload[512*4] = {NULL};
				char *description;
				int i;
			
				//conversion
				com_start_str = strstr (line_buffer,"BB");
				com_end_str = strstr (line_buffer,"7E");
				com_str_length =  com_end_str-com_start_str + 2;
				com_hex_length = misc_str2hex_varlength(com_start_str, com_hex, com_str_length);
				com_comment_str = com_end_str+2;
				
				//mapping to table
				type = com_hex[1];
				code = com_hex[2];
				payload_length = com_hex[3]<<8|com_hex[4];
				for (i=0;i<payload_length;i++)
					sprintf(payload,"%s %02X", payload, com_hex[5+i]);
				description = com_comment_str;
			}
			
			
			break;
		case COM_BATCH_FILE_OPENBATCH:
			
			break;
	}
}

int CVICALLBACK Com_batch (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	unsigned char type, code;
	unsigned short int payload_length;
	char payload[512*4] = {NULL};
				
	switch (event)
	{
		case EVENT_TABLE_ROW_COL_LABEL_CLICK:
			//printf("eventData1 --> %d, eventData2 --> %d \r\n", eventData1, eventData2);
			if(eventData1)
			{
				GetTableCellVal (panel, control, MakePoint(BATCH_TYPE, eventData1), &cmd.type);
				GetTableCellVal (panel, control, MakePoint(BATCH_CODE, eventData1), &cmd.code);
				GetTableCellVal (panel, control, MakePoint(BATCH_PAYLOAD_LENGTH, eventData1), &cmd.payload_length);
				GetTableCellVal (panel, control, MakePoint(BATCH_PAYLOAD, eventData1), payload);
				misc_str2hex_invers(payload, cmd.payload);
				send_msg();
			}
			break;
	}
	return 0;
}
