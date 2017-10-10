/******************************************************************************
Author:        Uday S. Trivedi 

Description:   This is the CPP file for Board.  Board.cpp implements
the functions originally prototyped in the Board.hpp file.

The Board class handles all aspects of creating the board, customizing 
it for the user, and printing the board. Please see the below functions
for more details on functionality.
******************************************************************************/
#include <iostream>
#include "Board.hpp"
#include "IntErrorCheck.hpp"
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;


/******************************************************************************
[Method Name]:	Board constructor

[Description]:	This function will initialize the private variables within
the board class.

[Arguments]:	1. rowsCols - the number of rows which also equals the number
					of columns.

				2. stepsIn - the number of steps for which the program will
					default to.

[ArgRestrict]:	1. rowsCols is always a single integer and must obviously
					be within the range of 5-26.

				2. stepsIn - must be an integer value between 1-3000.

[Return]:      n/a 
******************************************************************************/
Board::Board(int rowsCols, int stepsIn)
{
	rows = rowsCols;
	cols = rowsCols;
	steps = stepsIn;
}


/******************************************************************************
[Method Name]:	setBoardDim

[Description]:	This function will help the user set the board dimensions.

[Arguments]:	n/a

[ArgRestrict]:	n/a

[Return]:       n/a
******************************************************************************/
void Board::setBoardDim()
{

	cout << "[YOU HAVE SELECTED: SET BOARD DIMENSIONS]" << endl;
	cout << endl << "Rows are currently set to: " << rows << endl;
	cout << "Columns are currently set to: " << cols << endl;

	cout << endl << "Enter Number of rows desired (minimum 6, maximum 26): ";
	rows = intRowsErrCheck();
	cout << "Rows settings are now updated" << endl;

	cout << endl;
	cout <<"Enter Number of columns Desired (minimum 6, maximum 26): ";
	cols = intColsErrCheck();

	cout << endl;
	cout << "Board dimensions have been updated as follows:" << endl;
	cout << "Rows: " << rows << endl;
	cout << "Columns: " << cols << endl << endl;

	return;
}


/******************************************************************************
[Method Name]:	printBoard

[Description]:	This function will take care of all aspects in printing the
board to the console screen - whether it is while the user is setting the ant
position, or even running the Langton Ant sequence - this is the function that
will handle all printing aspects.

[Arguments]:	1. boardArray - the 2D array representing the board

[ArgRestrict]:	1. boardArray - must be a pointer to a pointer 2D array

[Return]:      void
******************************************************************************/
void Board::printBoard(char **boardArray)
{
	for (int i = 0; i < rows; i++)
	{
		printRowID(i);

		//Now a nested for loop to print out columns
		for (int j = 0; j < cols; j++)
		{

			cout << boardArray[i][j] << "  ";
			printColID(i,j);
			
		}
		
		cout << endl;
	}//main for loop

	cout << endl << endl;
}


/******************************************************************************
[Method Name]:	printRowID

[Description]:	This function will handle all aspects of printing the 
rowID. This function is called from within the printBoard() function above.

[Arguments]:	1. i - the current value of the for loop that is passed from
the function printBoard above.

[ArgRestrict]:	1. i must be an integer value.

[Return]:      void
******************************************************************************/
void Board::printRowID(int i)
{
	/*This statement just helps allign the single -digit numerical
	IDs for rows*/
	if (i < 10)
	{
		cout << " " << i  << " ";
	}


	/*This statement prints out numerical row IDs greater than
	or equal to 10*/
	else if (i >= 10)
	{
		cout << i  << " ";
	}
	return;
}


/******************************************************************************
[Method Name]:	printColID

[Description]:	This function will handle all aspects of printing the
colID. This function is called from within the printBoard() function above.

[Arguments]:	1. i - the current value of the for loop that is passed from
the function printBoard above.

				2. j - the current value of the inner for loop that is passed
from the function printBoard above.

[ArgRestrict]:	1. i must be an integer value.
				2. j must be an integer value

[Return]:      void
******************************************************************************/
void Board::printColID(int i, int j)
{
	//if we are on the last row, then cout (on a new line endl) 
	//the bottom horizontal axis ID numbers
	
	if (i+1 == rows && j+1 == cols)
	{//if statement bracket
		
		cout << endl;
		
		if (rows<10)
		{
			cout << "  ";
		}

		else if (rows > 9)
		{
			cout << "  ";
		}
		
		for (int index = 0; index<cols; index++)
		{//first for loop bracket
			if (index < 10)
			{
				cout << " " << index << " ";
			}

			else if (index > 9)
			{
				cout << "" << index << " ";
			}

		}//first for loop bracket
		
		 
		 /*
		//80 Column Width Test to print 80 characters in console
		cout << endl;
		for (int testX = 0; testX < 81; testX++)
		{
			cout << '*';
		}
		*/

	}//main if statement bracket
}//end function


 /******************************************************************************
 [Method Name]:	setSteps

 [Description]:	This function will handle all aspects of setting the total
 steps for the ant.

 [Arguments]:	n/a

 [ArgRestrict]:	n/a

 [Return]:      void
 ******************************************************************************/
void Board::setSteps()
{
	cout << "[YOU HAVE SELECTED: SET TOTAL NUMBER OF STEPS]" << endl;
	cout << endl << "Steps are currently set to: " << steps << endl;

	cout << endl << "Enter Number of steps desired (min 1, max 3000): ";
	steps = intStepsErrCheck();
	cout << endl << "Total number of steps have now been updated to: " <<
		steps << endl << endl;
	return;
}


/******************************************************************************
[Method Name]:	getUserSettings

[Description]:	This function will handle all aspects of printing the
user settings to the console screen.

[Arguments]:	1. startRowIDIn - the ID of the row the ant will start on
		
				2. startColIDIn - the ID of the col the ant will start on

				3. startDirection - not really applicable but was put in
					for future flexibility. Right now plain cout statement
					that will always state "East".

[ArgRestrict]:	all variables should be within range by functions passing them

[Return]:      void
******************************************************************************/
void Board::getUserSettings(int startRowIDIn, int startColIDIn, 
	char startDirection)
{
	
	
	cout << "Board Rows: " << rows  << endl;
	cout << "Board Columns: " << cols <<  endl;
	cout << "Total Steps: " << steps << endl;
	cout << "Ant's Starting Coordinates (Row, Col): " << startRowIDIn
		<< "," << startColIDIn << endl;
	cout << "Ant's Starting Orientation: East" << endl;
	
	/* //no time to implement below code, but possibly for future use
	if (startDirection == 'N')
	{
		cout << "Ant's Starting Direction: North" << endl;
	}

	else if (startDirection == 'S')
	{
		cout << "Ant's Starting Direction: South" << endl;
	}

	else if (startDirection == 'E')
	{
		cout << "Ant's Starting Direction: East" << endl;
	}

	else if (startDirection == 'W')
	{
		cout << "Ant's Starting Direction: West" << endl;
	} */


	cout << endl << endl;
	return;
}


/******************************************************************************
[Method Name]:	getRows

[Description]:	This function will return the rows private variable

[Arguments]:	n/a
[ArgRestrict]:	n/a

[Return]:      Integer value of the total rows on the board.
******************************************************************************/
int Board::getRows()
{
	return rows;
}


/******************************************************************************
[Method Name]:	getCols

[Description]:	This function will return the cols private variable

[Arguments]:	n/a
[ArgRestrict]:	n/a

[Return]:      Integer value of the total columns on the board.
******************************************************************************/
int Board::getCols()
{
	return cols;
}


/******************************************************************************
[Method Name]:	getSteps

[Description]:	This function will return the steps private variable

[Arguments]:	n/a
[ArgRestrict]:	n/a

[Return]:      Integer value of the total steps the ant will take.
******************************************************************************/
int Board::getSteps()
{
	return steps;
}









//Jay Swaminarayan


