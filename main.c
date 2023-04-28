/*
 * finalProject.c
 *
 * Created: 4/24/2023 1:34:00 PM
 * Author : Xinyi Yuan
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL	// 16 MHz clock speed
#endif

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include "KS0108.h"
#include "Tahoma11x13.h"
#include "Tekton_Pro_Ext27x28.h"

int USERID = 0;
const char txt1[] PROGMEM = "Big";
const char txt2[] PROGMEM = "Small";

void setUp();
//void led();
//bool check(int grid[7][6], int count, int locRow, int locCol);
//bool checkValid(int grid[7][6], int colSel);


/*ISR(PCINT8_vect) {
	led();
}
*/



int main()
{	
	setUp();
	while(1) {
		//led();
		//setUp();
	}
	return 0;
	
}


void setUp() {
	//cli();
	//DDRD = 0b00001100;					// port D, 2 and 3 are now output
	//DDRC |= 0x01;
	//PCICR |= 0x02;						// turn on port C
	//PCMSK1 |= 0x01;						// PCINT18
	
	//sei();								// enable interrupts
	
	// setup
	GLCD_Setup();
	GLCD_Clear();
	
	// Inverted mode
	GLCD_InvertMode();
	
	// Print text # 1
	GLCD_SetFont(Tekton_Pro_Ext27x28, 27, 28, GLCD_Merge);
	GLCD_GotoXY(42, 1);
	GLCD_PrintString_P(txt1);
	
	//Print text #2
	GLCD_SetFont(Tahoma11x13, 11, 13, GLCD_Merge);
	GLCD_GotoXY(48, 30);
	GLCD_PrintString_P(txt2);
	
	// Draw outline
	GLCD_DrawRoundRectangle(1, 1, 126, 62, 5, GLCD_Black);
	
	// Render screen
	GLCD_Render();
	
	while (1 == 1);

}


/* This function is called when one user finished his/her turn, 
	and then turn on the led of the other user, which indicates 
	that user's turn. */
/*
void led() {
	unsigned char tmp;
	if (USERID == 0) {
		tmp = PORTD;					// Get PORTD
		tmp = tmp | 0b00000100;			// Set bit 2
		PORTD = tmp;					// Update PORTD
		_delay_ms(500.0);
		
		tmp = PORTD;
		tmp = tmp & ~(0b000000100);
		PORTD = tmp;
		USERID = 1;
		_delay_ms(500.0);
		return;
	}
	else {
		tmp = PORTD;
		tmp = tmp | 0b00001000;
		PORTD = tmp;				
		_delay_ms(500.0);
		
		tmp = PORTD;
		tmp = tmp & ~(0b00001000);
		PORTD = tmp;
		USERID = 0;
		_delay_ms(500.0);
	}

}
*/

/*	
	row
	0 | 0 0 0 0 0 0
	1 | 0 0 0 0 0 0
	2 | 0 0 0 0 0 0
	3 | 0 0 0 0 0 0
	4 | 0 0 0 0 0 0
	5 | 0 0 0 0 0 0 
	6 | 0 0 0 0 0 0 
		_ _ _ _ _ _
 	col 0 1 2 3 4 5
	
	if user 1 select column 0, grid[6][0] should be assigned to 1
	if user 2 select column 2, grid[6][1] should be assigned to 2
*/


/* Check if there exists connected 4 checkers in the grid, locRow is which row user places at,
	locCol is which column user places at. Return true if exist a winner, false otherwise.  */
/*
bool check(int grid[7][6], int count, int locRow, int locCol) {
	// if less than 8 moves, there's no winner
	if (count <= 7) {
		return false;
	}
	
	// check horizontally
	int value = grid[locRow][locCol];
	int counter = 0;
	for (int i = 0; i < locCol; ++ i) {
		if (counter >= 4) {
			return true;
		}
		if (grid[locRow][i] == value) {
			counter = counter + 1;
		}
		else {
			counter = 0;
		}
	}
	
	
	// check column
	counter = 0;
	for (int i = 0; i < locRow; ++ i) {
		if (counter >= 4) {
			return true;
		}
		if (grid[i][locCol] == value) {
			counter = counter + 1;
		}
		else {
			counter = 0;
		}
	}
	
	
	// check diagonal
	
	// top left to bottom right
	counter = 0;
	int startRow = locRow;
	int startCol = locCol;
	// find starting point
	while (startRow != 0 && startCol != 0) {
		startRow = startRow - 1;
		startCol = startCol - 1;
	}
	while (startRow != 7 && startCol != 6) {
		if (counter >= 4) {
			return true;
		}
		if (grid[startRow][startCol] == value) {
			counter = counter + 1;
		}
		else {
			counter = 0;
		}
		startRow = startRow + 1;
		startCol = startCol + 1;
	}
	
	
	// top right to bottom left
	counter = 0;
	startRow = locRow;
	startCol = locCol;
	while (startRow != 0 && startCol != 5) {
		startRow = startRow - 1;
		startCol = startCol + 1;
	}
	while (startRow != 7 && startCol != -1) {
		if (counter >= 4) {
			return true;
		}
		if (grid[startRow][startCol] == value) {
			counter = counter + 1;
		}
		else {
			counter = 0;
		}
		startRow = startRow - 1;
		startCol = startCol - 1;
	}
	
	return false;
}
*/

/* check if user is selecting a valid column, which means that column is not full */
/*
bool checkValid(int grid[7][6], int colSel){
	if (grid[0][colSel] == 0) {
		return true;
	}
	return false;
}
*/

