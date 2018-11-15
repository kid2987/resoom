//==============================================================================
//
// Title:       misc_util.h
// Purpose:     A short description of the interface.
//
// Created on:  2008-06-25 at ¿ÀÀü 11:05:10 by samsung.
// Copyright:   samsung. All Rights Reserved.
//
//==============================================================================

#ifndef __misc_util_H__
#define __misc_util_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants
#define ToggleBit8(__Data, __position)	((__Data)^(1<<(__position)))  
//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions
unsigned int misc_log2(unsigned int x);
unsigned int misc_str2hex(unsigned char *str, unsigned char *full_byte);
unsigned short str2hex(char *string, unsigned char *full_byte);		
unsigned int misc_str2hex_varlength(unsigned char *str, unsigned char *full_byte, unsigned int target_str_length);
unsigned int misc_str2hex_invers(unsigned char *str, unsigned char *full_byte);
unsigned long PushSPI(unsigned long SPI_DATA) ;
void write_rfic_reg(unsigned char address, unsigned char data);
unsigned char read_rfic_reg(unsigned char address);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __misc_util_H__ */
