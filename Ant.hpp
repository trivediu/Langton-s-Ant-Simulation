/******************************************************************************
Author:        Uday S. Trivedi 

Description:   This header file contains the function
prototypes for the Ant class. The Ant class handles
all aspects of tracking the ant's movement, it's current position, 
and what turns it needs to make, etc.

For full details on what each function does, input argument,
restrictions, and returns please refer to the
Ant.cpp file.

******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Board.hpp"

class Ant
{
private:
	//The current step the ant is on
	int currentStep;

	//The starting row ID of the ant as specified by end user
	int startRowID;

	//The starting column ID of the ant as specified by the end user
	int startColID;

	//the ant's starting direction (same as orientation below)
	//but it just represents what the default direction is set too
	char startDirection;

	//the ant's orientation (north, south, east, west) denoted by
	//'N', 'S', 'E', 'W'
	char orientation;

	//the direction the ant will turn which is either left or right
	//denoted by char values 'L' or 'R'
	char turn;

	//the current row the ant is on (different from start row)
	//also when initilizaed it will match startRow -1 (to match with)
	//array indexing - see constructor fxn in cpp file
	int currentRow;

	//the current column the ant is on (different from start column)
	//also when initilizaed it will match startCol - 1 (to match with)
	//array indexing - see constructor fxn in cpp file
	int currentCol;

	//color of the square before the ant stepped on it
	//holds values of only 'W' or 'B'
	char blockBefore;

	//color of the square after the ant leaves it
	//(holds values of only 'W' or 'B')
	char blockAfter;

	//same as above, except current block only holds 'W' or 'B'
	//values
	char blockCurrent;


public:
	//constructor will take a default starting rowID and colID
	//starting orientation, starting turn
	Ant(int, int, char);

	void initialize();

	void setRandStartPos(Board, char **);
	void setStartPos(Board, char **);
	
	void setCurrentStep(int);
	int getCurrentStep();
	
	void setStartRowColID(int, int);
	int getStartRowID();
	int getStartColID();
	char getStartDirection();
	
	void setCurrentRow(int);
	int getCurrentRow();
	void setCurrentCol(int);
	int getCurrentCol();


	void setOrientation(char);
	char getOrientation();

	//turn NIU yet
	void setTurn(char);
	char getTurn();

	//blocks before NIU yet
	char getBlockBefore();
	void setBlockBefore(char);
	
	
	//blocks after NIU yet
	char getBlockAfter();
	void setBlockAfter(char);

	//this is NIU yet
	void setBlockCurrent(char);
	
	//we have to pass in the array to get the current block color
	//because this fxn will scan the current color of the array
	char getBlockCurrent(char **);

	

	//******************************
	//Main "game" ant movement functions

	//start ant - essentially start the movement and the game
	void startAnt(char**, Board);
	void checkWrapNorth(char **);
};

#endif









//Jay Swaminarayan

