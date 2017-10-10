/******************************************************************************
Author:        Uday S. Trivedi

Description:   This header file contains the function
prototypes for the Board class. The Board class handles
all aspects of creating the board, customizing it for the user, and printing
the board.

For full details on what each function does, input argument,
restrictions, and returns please refer to the
Board.cpp file.

******************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include "Array.hpp"
//#include "Ant.hpp"

class Board
{
private:
	/*The total number of rows (vertical height) of the array
	this value will be one more than the rows specified by the user
	because the last row will hold IDs*/
	int rows; 

	/*The total number of columns (horizontal length) of the array*/
	int cols;

	/*This is the total number of steps*/
	int steps;



public:
	/*Constructor (rows/cols, steps, current step (should always
		equal zero), */
	Board(int,int);

	/*This fxn will set dimensions from user*/
	void setBoardDim();

	/*Prints the board*/
	void printBoard(char **);

	/*Set the number of steps*/
	void setSteps();

	/*Get the current user settings*/
	//as input it will take ant's start RowID and start Col ID
	void getUserSettings(int,int, char);

	/*get rows*/
	int getRows();

	/*get columns*/
	int getCols();

	/*print vertical IDs on the side of the board*/
	void printRowID(int);

	/*print horizontal column IDs at bottom of the board*/
	void printColID(int,int);

	/*get the total number of steps specified*/
	int getSteps();

	
};

#endif









//Jay Swaminarayan
