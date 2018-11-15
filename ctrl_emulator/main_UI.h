/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL_MAIN                       1       /* callback function: Panel_main */
#define  PANEL_MAIN_RING_TAG_READ         2       /* control type: ring, callback function: Msg_config */
#define  PANEL_MAIN_RING_READER_CONTROL   3       /* control type: ring, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_LENGTH    4       /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_CODE      5       /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_TYPE      6       /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_ENDMASK   7       /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD0  8       /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD1  9       /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD2  10      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD3  11      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD4  12      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD5  13      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD6  14      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD7  15      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD24 16      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD25 17      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD26 18      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD27 19      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD28 20      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD29 21      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD30 22      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD35 23      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD34 24      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD33 25      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD32 26      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD31 27      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD16 28      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD17 29      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD18 30      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD19 31      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD20 32      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD21 33      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD22 34      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD23 35      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD8  36      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD9  37      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD10 38      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD11 39      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD12 40      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD13 41      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD14 42      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PAYLOAD15 43      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_NUMERIC_MSG_PREAMBLE  44      /* control type: numeric, callback function: Msg_config */
#define  PANEL_MAIN_TEXTBOX_RSP_HISTORY   45      /* control type: textBox, callback function: Clear_history */
#define  PANEL_MAIN_TEXTBOX_STATUS        46      /* control type: textBox, callback function: (none) */
#define  PANEL_MAIN_TEXTBOX_CMD_HISTORY   47      /* control type: textBox, callback function: (none) */
#define  PANEL_MAIN_COMMANDBUTTON_SEND    48      /* control type: command, callback function: SEND_MSG */
#define  PANEL_MAIN_COMMANDBUTTON_RSP_CL  49      /* control type: command, callback function: Clear_history */
#define  PANEL_MAIN_COMMANDBUTTON_CMD_CL  50      /* control type: command, callback function: Clear_history */
#define  PANEL_MAIN_DECORATION            51      /* control type: deco, callback function: (none) */
#define  PANEL_MAIN_DECORATION_2          52      /* control type: deco, callback function: (none) */
#define  PANEL_MAIN_DECORATION_3          53      /* control type: deco, callback function: (none) */
#define  PANEL_MAIN_DECORATION_4          54      /* control type: deco, callback function: (none) */
#define  PANEL_MAIN_PICTURE               55      /* control type: picture, callback function: (none) */
#define  PANEL_MAIN_PICTURE_2             56      /* control type: picture, callback function: (none) */

#define  PANEL_RFIC                       2       /* callback function: Panel_pd */
#define  PANEL_RFIC_TABLE_RF_REGMAP       2       /* control type: table, callback function: RF_RegMap_Table */
#define  PANEL_RFIC_NUMERIC_MSG_DATA      3       /* control type: numeric, callback function: RFIC_reg_control */
#define  PANEL_RFIC_NUMERIC_MSG_ADDRESS   4       /* control type: numeric, callback function: RFIC_reg_control */
#define  PANEL_RFIC_DECORATION            5       /* control type: deco, callback function: (none) */
#define  PANEL_RFIC_COMMANDBUTTON_WRITE   6       /* control type: command, callback function: RFIC_reg_control */
#define  PANEL_RFIC_COMMANDBUTTON_READ    7       /* control type: command, callback function: RFIC_reg_control */

#define  PANEL_SPI                        3       /* callback function: Panel_SPI_Ctrl */
#define  PANEL_SPI_NUMERIC_PORT           2       /* control type: numeric, callback function: SPI_Control */
#define  PANEL_SPI_NUMERIC_SPEED          3       /* control type: numeric, callback function: SPI_Control */
#define  PANEL_SPI_RING_INP               4       /* control type: ring, callback function: SPI_Control */
#define  PANEL_SPI_RING_OUTP              5       /* control type: ring, callback function: SPI_Control */
#define  PANEL_SPI_RING_ENABLEP           6       /* control type: ring, callback function: SPI_Control */
#define  PANEL_SPI_RING_CLKP              7       /* control type: ring, callback function: SPI_Control */

#define  PANEL_SPIM                       4       /* callback function: Panel_pd */
#define  PANEL_SPIM_DIGGRAPH_SPIM         2       /* control type: digitalGraph, callback function: (none) */

#define  RS232                            5       /* callback function: Panel_pd */
#define  RS232_RINGSLIDE_BAUDRATE         2       /* control type: slide, callback function: (none) */
#define  RS232_BUTTON_CONFIGCANCEL        3       /* control type: command, callback function: Rs_Config */
#define  RS232_BUTTON_CONFIGOK            4       /* control type: command, callback function: Rs_Config */
#define  RS232_RINGSLIDE_PARITY           5       /* control type: slide, callback function: (none) */
#define  RS232_RINGSLIDE_DATABITS         6       /* control type: slide, callback function: (none) */
#define  RS232_RINGSLIDE_STOPBIT          7       /* control type: slide, callback function: (none) */
#define  RS232_RING_OUTPUTQ               8       /* control type: numeric, callback function: (none) */
#define  RS232_RING_COMPORT               9       /* control type: numeric, callback function: (none) */
#define  RS232_RING_INPUTQ                10      /* control type: numeric, callback function: (none) */
#define  RS232_RING_TIMEOUT               11      /* control type: numeric, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  COM_BATCH                        1
#define  COM_BATCH_FILE                   2
#define  COM_BATCH_FILE_LOADBATCH         3       /* callback function: Batch_menu */
#define  COM_BATCH_FILE_OPENBATCH         4       /* callback function: Batch_menu */

#define  RFIC_CTRL                        2
#define  RFIC_CTRL_FILE                   2
#define  RFIC_CTRL_FILE_OPEN_MAP          3       /* callback function: RFIC_Ctrl_menu */
#define  RFIC_CTRL_OPTION                 4
#define  RFIC_CTRL_OPTION_SPI_ENALBE      5       /* callback function: RFIC_Ctrl_menu */
#define  RFIC_CTRL_OPTION_SEPARATOR       6
#define  RFIC_CTRL_OPTION_SPI_CTRL        7       /* callback function: RFIC_Ctrl_menu */
#define  RFIC_CTRL_OPTION_SPI_MONITOR     8       /* callback function: RFIC_Ctrl_menu */

#define  W1_MENU                          3
#define  W1_MENU_FILE                     2
#define  W1_MENU_FILE_CMCDOWNLOAD         3       /* callback function: W1_menu */
#define  W1_MENU_FILE_S3CDOWNLOAD         4       /* callback function: W1_menu */
#define  W1_MENU_FILE_S3CDOWNLOAD1        5       /* callback function: W1_menu */
#define  W1_MENU_CONFIG                   6
#define  W1_MENU_CONFIG_RS232             7       /* callback function: W1_menu */
#define  W1_MENU_CONFIG_TXLEAKAGE         8       /* callback function: W1_menu */
#define  W1_MENU_CONFIG_RFIC_CONTROL      9       /* callback function: W1_menu */
#define  W1_MENU_DEBUG                    10
#define  W1_MENU_DEBUG_TYPECWRITE         11      /* callback function: W1_menu */
#define  W1_MENU_DEBUG_COMBATCH           12      /* callback function: W1_menu */
#define  W1_MENU_DEBUG_LBT                13      /* callback function: W1_menu */
#define  W1_MENU_DEBUG_AGC                14      /* callback function: W1_menu */
#define  W1_MENU_VIEW                     15
#define  W1_MENU_VIEW_TLCDEMO1            16      /* callback function: W1_menu */
#define  W1_MENU_VIEW_ITEM_TLB            17      /* callback function: W1_menu */


     /* Callback Prototypes: */

void CVICALLBACK Batch_menu(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK Clear_history(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Msg_config(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Panel_main(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Panel_pd(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Panel_SPI_Ctrl(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RF_RegMap_Table(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK RFIC_Ctrl_menu(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK RFIC_reg_control(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Rs_Config(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SEND_MSG(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SPI_Control(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK W1_menu(int menubar, int menuItem, void *callbackData, int panel);


#ifdef __cplusplus
    }
#endif
