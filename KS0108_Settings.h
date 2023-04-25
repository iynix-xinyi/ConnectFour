#ifndef KS0108_SETTINGS_H_INCLUDED
#define KS0108_SETTINGS_H_INCLUDED
/*
||
||  Filename:	 		KS0108_Settings.h
||  Title: 			    KS0108 Driver Settings
||  Author: 			Efthymios Koktsidis
||	Email:				efthymios.ks@gmail.com
||  Compiler:		 	AVR-GCC
||	Description:
||	Settings for the KS0108 driver. 
||
*/

//----- Configuration -------------//
//Chip Enable Pin
#define GLCD_Active_Low		0

//GLCD pins					PORT, PIN
#define GLCD_D0				B, 0
#define GLCD_D1				B, 1
#define GLCD_D2				B, 2
#define GLCD_D3				B, 3
#define GLCD_D4				B, 4
#define GLCD_D5				B, 5
#define GLCD_D6				B, 6
#define GLCD_D7				B, 7

#define GLCD_DI				C, 0
#define GLCD_RW				C, 1
#define GLCD_EN				C, 2
#define GLCD_CS1			C, 3
#define GLCD_CS2			C, 4
#define GLCD_RST			C, 5
//---------------------------------//
#endif