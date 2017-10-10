/******************************************************************************
Author:        Uday S. Trivedi 


Description:   This CPP file contains the functions for the Ant class. 
The Ant class handles all aspects of tracking the ant's movement, it's 
current position, and what turns it needs to make, etc.

Please see each function below for more details.
******************************************************************************/

#include <iostream>
#include "Ant.hpp"
#include "Board.hpp"
#include "IntErrorCheck.hpp"
#include <cstdlib>//for random number generation
#include <ctime>//for automatic feeding to srand

using std::cout;
using std::endl;


/******************************************************************************
[Method Name]:	Ant constructor

[Description]:	This function will initialize the private variables within
the ant class.

[Arguments]:	
1. startRowIDIn - the ID of the starting Row

2. startColIDIn - the ID of the starting Col

[ArgRestrict]:	n/a

[Return]:      n/a
******************************************************************************/
Ant::Ant(int startRowIdIn, int startColIdIn, char startDirectionIN)
{
	startRowID = startRowIdIn;
	startColID = startColIdIn;
	startDirection = startDirectionIN;
	
	orientation = startDirectionIN;
	turn = 'R';
	currentRow = startRowIdIn-1;
	currentCol = startColIdIn-1;

	blockBefore = 'W';
	blockAfter = 'W';
	blockCurrent = 'W';
}


/******************************************************************************
[Method Name]:	initialize

[Description]:	This function will reinitialize the ant before the play option
is chosen in the main menu - just for safety incase any of the private variable
settings were changed during user setting updates.  Also, another example is
everytime the program runs, the steps need to be reset, etc.  This is why
this function is needed in addition to the constructor initialization.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      n/a
******************************************************************************/
void Ant::initialize()
{
	//startRowID = startRowIdIn;
	//startColID = startColIdIn;
	startDirection = getStartDirection();

	orientation = getStartDirection();
	
	turn = 'R';
	currentRow = startRowID;
	currentCol = startColID;

	blockBefore = 'W';
	blockAfter = 'W';
	blockCurrent = 'W';

	return;
}


/******************************************************************************
[Method Name]:	setRandStartPos

[Description]:	This function handles all aspects of assigning a random
start position to the ant.  It will automatically adjust random values to
fall within the bounds of the user-specified board size.

[Arguments]:
1. The current board object
2. A 2D array of pointers to pointers

[ArgRestrict]:	n/a

[Return]:      n/a
******************************************************************************/
void Ant::setRandStartPos(Board boardIN, char **boardArray)
{
	//Please, text book pages 132-136 were referred to for this section
	cout << "[NOW GENERATING A RANDOM ANT START POSITION...]" << endl << endl;

	int rowsUser = boardIN.getRows(); //total rows specified by user
	int colsUser = boardIN.getCols(); //total cols specified by user
	
	//but we want the maximum value of row, to be the max of the array
	//ID.  Row if the user specifies 11 rows, that really means the array
	//has a max of 10 because array goes from 0-10.  Therefore, we take
	//the values of rowsUser and colsUser and subtract one to create our max

	int rowsUserMax = rowsUser - 1;
	int colsUserMax = colsUser - 1;
	
	//And ofcourse, the minimum value is zero (index) for rows and cols
	//from an array perspective
	int rowsUserMin = 0;
	int colsUserMin = 0;

	unsigned seed; //random number generator seed

	//***RANDOM ROW GENERATION***
				   
	//Now we generate a random row between 0 and the maximum array ID
	//for the current board size
	seed = time(0);
	srand(seed);
	
	//initialize a random value for the row ID
	int rowsRand = 0; 
	
	//Taken from Pg. 136 textbook
	rowsRand = rand() % (rowsUserMax - rowsUserMin + 1) + rowsUserMin;
	cout << "Random Row ID is now generated" << endl;

	//***RANDOM COLUMN GENERATION***
	//we do the same as we did above for rows, except for columns


	//No need to generate a new seed, we did that above for rows

	//initialize a random value for the col ID
	int colsRand = 0; 

	//Textbook pg. 136
	colsRand = rand() % (colsUserMax - colsUserMin + 1) + colsUserMin;
	cout << "Random Column ID is now generated" << endl;

	//now we have our assigned values for row and column ID, we set it
	//to the official program default for the ant, and also show it on the
	//board for the user.

	//to write these values into the program we first set them equal to the
	//startRowID and startColID variables
	startRowID = rowsRand;
	startColID = colsRand;

	//but the program is designed that the Current Row and Current Column
	//are separate (but important) variables and must also be initialized 
	//to the above variables.  
	
	//We now set currentRow and currentCol class variables also equal to start
	//column and rowID class variables
	currentRow = startRowID;
	currentCol = startColID;

	//print the board with the ant on it and update the user
	cout << "Your ant is now assigned starting row ID: " << startRowID << endl;
	cout << "Your ant is now assigned starting col ID: " << startColID << endl;

	boardArray[startRowID][startColID] = '@';

	cout << endl << "Now printing the updated board below with your ant:" <<
		endl;

	boardIN.printBoard(boardArray);

	return;

}


/******************************************************************************
[Method Name]:	setStartPos

[Description]:	This function will handle all aspects of helping the user
manually set the ant's starting position.

[Arguments]:
1. A board object
2. A 2D array of pointers to pointers

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::setStartPos(Board boardIN, char **boardArray)
{
	cout << "[PLEASE SET YOUR ANT STARTING POSITION]" << endl <<endl;
	
	int rows = boardIN.getRows();
	int cols = boardIN.getCols();
	boardIN.printBoard(boardArray);

	//int rowID = 0; //desired rowID by user
	//int colID = 0; //desired colID by user

	cout << "Please Enter A Numerical Vertical Row ID" << endl
		<< "Between The Range Of 0 and " << rows-1 << ": ";
		startRowID = intSetAntPosRowErrCheck(rows-1);//set starting Row ID


		cout << endl << "Please Choose A Horizontal Column ID" << endl
			<< "Between The Range of 0 and " << cols-1 << ": ";
		startColID = intSetAntPosColErrCheck(cols-1);//set starting Col ID

		//now set current row and col equal to start row and col ID
		currentRow = startRowID;
		currentCol = startColID;

		//system("ClS");
		system("clear");
		boardArray[startRowID][startColID] = '@';
		
		cout << "[CHANGES SAVED: ANT STARTING POSITION]" << endl << endl;
		boardIN.printBoard(boardArray);
		cout << "[YOUR ANT START POSITION SETTINGS ARE STORED AND SHOWN ABOVE]"
			<< endl << endl;
		cout << "Current Row ID Setting: " << startRowID << endl <<
			"Current Column ID Setting: " << startColID << endl << endl;




		return;

}


/******************************************************************************
[Method Name]:	setCurrent Step

[Description]:	This function will set the current step of the ant. This is 
essentially a way of updating the ant's curent step.

[Arguments]:
1. An integer value of the current step in.

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::setCurrentStep(int currentStepIn)
{
	currentStep = currentStepIn;
	return;
}


/******************************************************************************
[Method Name]:	getCurrentStep

[Description]:	This function will return the value of the ant's current
step.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      Integer value of the ant's current step
******************************************************************************/
int Ant::getCurrentStep()
{
	return currentStep;
}


/******************************************************************************
[Method Name]:setStartRowColID

[Description]:	This function will set the starting row and column Column IDs

[Arguments]:
1. integer value of the rowID 
2. integer value of the colID

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::setStartRowColID(int rowIdIn, int colIdIn)
{
	startRowID = rowIdIn;
	startColID = colIdIn;
	return;
}


/******************************************************************************
[Method Name]:	getStartRow ID

[Description]:	This function will return the value of the starting row ID

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      Integer value of the ant's starting row ID
******************************************************************************/
int Ant::getStartRowID()
{
	return startRowID;
}


/******************************************************************************
[Method Name]:	getStartCol ID

[Description]:	This function will return the value of the starting col ID

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      Integer value of the ant's starting col ID
******************************************************************************/
int Ant::getStartColID()
{
	return startColID;
}


/******************************************************************************
[Method Name]:	getStartDirection

[Description]:	This function will return the value of the starting 
direction of the ant.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      character value of the ant's starting direction.
******************************************************************************/
char Ant::getStartDirection()
{
	return startDirection;
}


/******************************************************************************
[Method Name]:	setOreintation

[Description]:	This function will set the ant's orientaiton.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::setOrientation(char orientationIN)
{
	orientation = orientationIN;
	return;
}


/******************************************************************************
[Method Name]:	getOrientation

[Description]:	This function will return the value of the ant's orientation

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      char value of the ant's orientation
******************************************************************************/
char Ant::getOrientation()
{
	return orientation;
}


/******************************************************************************
[Method Name]:	setTurn

[Description]:	Set's the ant's current turn

[Arguments]:
1. Char value of the turn

[ArgRestrict]:	1. Char value must be either 'L' or 'R'

[Return]:      void
******************************************************************************/
void Ant::setTurn(char turnIN)
{
	turn = turnIN;
	return;
}
/******************************************************************************
[Method Name]:	getTurn

[Description]:	This function will return the value of the ant's turn

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      Char value of 'L' or 'R'
******************************************************************************/
char Ant::getTurn()
{
	return turn;
}


/******************************************************************************
[Method Name]:	setCurrentRowID

[Description]:	This function will set the ant's current Row ID

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::setCurrentRow(int rowIN)
{
	currentRow = rowIN;
	return;
}


/******************************************************************************
[Method Name]:	getCurrentRow

[Description]:	This function will return the value of the ant's current row
[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      Integer value of the ant's current row
******************************************************************************/
int Ant::getCurrentRow()
{
	return currentRow;
}


/******************************************************************************
[Method Name]:	setCurrentCol

[Description]:	This function will set and update the current ID of the 
column the ant is on.

[Arguments]:
1. column In (integer)

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::setCurrentCol(int colIN)
{
	currentCol = colIN;
	return;
}


/******************************************************************************
[Method Name]:	getCurrentCol

[Description]:	This function will return the value of the current
column the ant is on.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      Integer value of the ant's current column
******************************************************************************/
int Ant::getCurrentCol()
{
	return currentCol;
}

/******************************************************************************
[Method Name]:	getBlockBefore

[Description]:	returns the block the ant was on before.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      char value of the block
******************************************************************************/
char Ant::getBlockBefore()
{
	return blockBefore;
}

/******************************************************************************
[Method Name]:	getStartCol ID

[Description]:	This function will return the value of the block after the
ant leaves

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      Char value of the block
******************************************************************************/
char Ant::getBlockAfter()
{
	return blockAfter;
}

/******************************************************************************
[Method Name]:	setBlockBefore

[Description]:	This function will set the value of the ant's block that it
was on beforehand.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      n/a
******************************************************************************/
void Ant::setBlockBefore(char blockBeforeIn)
{
	blockBefore = blockBeforeIn;
	return;
}

/******************************************************************************
[Method Name]:	setBlockAfter

[Description]:	This function will set the value of the block after the
ant leaves.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::setBlockAfter(char blockAfterIn)
{
	blockAfter = blockAfterIn;
	return;
}

/******************************************************************************
[Method Name]:	setBlockCurrent

[Description]:	This function will set the value of the current block
the ant is on.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::setBlockCurrent(char blockCurrentIn)
{
	blockCurrent = blockCurrentIn;
	return;
}

/******************************************************************************
[Method Name]:	getBlockCurrent

[Description]:	This function will return the value of the current block
color the ant is on.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      Char value of black or white 'B' or 'W'
******************************************************************************/
char Ant::getBlockCurrent(char **arrayIN)
{
	if (arrayIN[getCurrentRow()][getCurrentCol()] == ' ')
	{
		blockCurrent = 'W';
		//return blockCurrent;
	}

	else if (arrayIN[getCurrentRow()][getCurrentCol()] == '#')
	{
		blockCurrent = 'B';
		//return blockCurrent;
	}
	
	return blockCurrent;
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

/******************************************************************************
[Method Name]:	startAnt

[Description]:	This function will handle all aspects of the ant's movement,
updating that movmenet, etc. This is the heart of the ant class.

[Arguments]:
1. 2D array of pointers to pointers
2. The current board object

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::startAnt(char** array2d, Board board)
{
	
	int currentStepAnt = 1;
	
	//set the blockCurrent value equal to the value 
	//of the "get current block function" which actually
	//returns the value of the next block the ant will move to.
	//This value was calculated in the above if statements.
	//Basically, before this function is executed blockCurrent
	//is actually still set to the same value as the block the ant
	//@ is on.  This is why it is needed
	setBlockCurrent(getBlockCurrent(array2d));


	//print the current step
	array2d[getCurrentRow()][getCurrentCol()] = '@';
	cout << "CURRENT STEP NUMBER: "
		<< currentStepAnt << endl;
	board.printBoard(array2d);

	//maybe start a for loop here....and enclose if statements
	for (int i=0; i<board.getSteps()-1; i++)//test for loop
	{//test for loop bracket


	//NORTH FACING ANT UPDATES
	if (getOrientation()=='N')
	{
		if (blockCurrent == 'W')
		{
			
			//change current array space to black as it is white
			array2d[getCurrentRow()][getCurrentCol()] = '#';
			
			//turn a north facing ant 90 degrees to the right
			//now it is facing east. Update orientation accordingly
			setOrientation('E');

			//the row will stay the same because a north facing ant
			//will simply move to the right from a white square
			setCurrentRow(getCurrentRow());

			//however a north facing ant will move "up" one column
			//e.g. move to the right from a white square
			
			//wrap around check in below if statement
			if (getCurrentCol() + 1 >= board.getCols())
			{
				setCurrentCol(0);
			}
			//execute normal move if no wrap around needed
			else if (getCurrentCol() + 1 < board.getCols())
			{
				setCurrentCol(getCurrentCol() + 1);
			}

			
		}
		
		else if (blockCurrent == 'B')
		{
			
			//change curent array space to white as it is black
			array2d[getCurrentRow()][getCurrentCol()] = ' ';
			
			//turn a north facing ant 90 degrees to the left
			//now it is facing west. Update orientation accordingly
			setOrientation('W');

			//the row will stay the same because a north facing ant
			//will simply move to the left from a black square
			setCurrentRow(getCurrentRow());

			//however a north facing ant will move "down" one column
			//e.g. move to the left from a black square
			
			//setCurrentCol(getCurrentCol() - 1);

			//wrap around check in below if statement
			if (getCurrentCol() - 1 < 0)
			{
				setCurrentCol(board.getCols()-1);
			}
			//execute normal move if no wrap around needed
			else if (getCurrentCol() - 1 >= 0)
			{
				setCurrentCol(getCurrentCol() - 1);
			}
		}
		
	}//end else if bracket for north facing ant

	 //SOUTH FACING ANT UPDATES
	else if(getOrientation() == 'S')
	{
		if (blockCurrent == 'W')
		{
			
			//change current array space to black as it is white
			array2d[getCurrentRow()][getCurrentCol()] = '#';
			
			//turn a south facing ant 90 degrees to the right,
			//now it is facing west. Update orientation accordingly
			setOrientation('W');

			//the row will stay the same because a south facing ant
			//will simply move to the right from a white square
			setCurrentRow(getCurrentRow());

			//however a south facing ant will move "down" one column
			//e.g. move to the left from a white square
			
			//setCurrentCol(getCurrentCol() - 1);

			//wrap around check in below if statement
			if (getCurrentCol() - 1 < 0)
			{
				setCurrentCol(board.getCols() - 1);
			}
			//execute normal move if no wrap around needed
			else if (getCurrentCol() - 1 >= 0)
			{
				setCurrentCol(getCurrentCol() - 1);
			}
		}
		
		else if (blockCurrent == 'B')
		{
			
			//change curent array space to white as it is black

			array2d[getCurrentRow()][getCurrentCol()] = ' ';
			//turn a south facing ant 90 degrees to the left,
			//now it is facing east. Update orientation accordingly
			setOrientation('E');

			//the row will stay the same because a south facing ant
			//will simply move to the left from a black square
			setCurrentRow(getCurrentRow());

			//however a south facing ant will move "up" one column
			//e.g. move to the right from a black square
			
			//setCurrentCol(getCurrentCol() + 1);

			//wrap around check in below if statement
			if (getCurrentCol() + 1 >= board.getCols())
			{
				setCurrentCol(0);
			}
			//execute normal move if no wrap around needed
			else if (getCurrentCol() + 1 < board.getCols())
			{
				setCurrentCol(getCurrentCol() + 1);
			}
		}
					
	}//end else-if bracket for south facing ant

	//EAST FACING ANT UPDATES
	else if (getOrientation() == 'E')
	{
		if (blockCurrent == 'W')
		{

			//change current array space to black as it is white
			array2d[getCurrentRow()][getCurrentCol()] = '#';

			//turn aN EAST facing ant 90 degrees to the right,
			//from a white square now it is facing south. 
			//Update orientation accordingly
			setOrientation('S');

			//the row will move "up" one because an east facing ant
			//will simply move down one square (which increases row value)
			
			//setCurrentRow(getCurrentRow()+1);

			//wrap around check in below if statement
			if (getCurrentRow() + 1 >= board.getRows())
			{
				setCurrentRow(0);
			}
			//execute normal move if no wrap around needed
			else if (getCurrentRow() + 1 < board.getRows())
			{
				setCurrentRow(getCurrentRow() + 1);
			}

			//however an east facing ant will turn south but still stay on 
			//the same column
			setCurrentCol(getCurrentCol());
		}

		else if (blockCurrent == 'B')
		{

			//change curent array space to white as it is black

			array2d[getCurrentRow()][getCurrentCol()] = ' ';
			
			//turn aN EAST facing ant 90 degrees to the left,
			//from a black square now it is facing north. 
			//Update orientation accordingly
			setOrientation('N');

			//the row will move "down" one because an east facing ant
			//will simply move up one square (which decreases row value)
			
			//setCurrentRow(getCurrentRow()-1);

			//wrap around check in below if statement
			if (getCurrentRow() - 1 < 0)
			{
				setCurrentRow(board.getRows() - 1);
			}
			//execute normal move if no wrap around needed
			else if (getCurrentRow() - 1 >= 0)
			{
				setCurrentRow(getCurrentRow() - 1);
			}



			//however an east facing ant will turn north but still stay on 
			//the same column
			setCurrentCol(getCurrentCol());
		}
		//update step #				
	}//end else-if bracket for EAST facing ant

	 //WEST FACING ANT UPDATES
	else if (getOrientation() == 'W')
	{
		if (blockCurrent == 'W')
		{

			//change current array space to black as it is white
			array2d[getCurrentRow()][getCurrentCol()] = '#';

			//turn a West facing ant 90 degrees to the right,
			//from a white square now it is facing north. 
			//Update orientation accordingly
			setOrientation('N');

			//the row will move "down" one because a west facing ant
			//will turn right (north) from a white and simply move up 
			//one square (which decreases row value)
			
			//setCurrentRow(getCurrentRow() - 1);
			
			//wrap around check in below if statement
			if (getCurrentRow() - 1 < 0)
			{
				setCurrentRow(board.getRows() - 1);
			}
			//execute normal move if no wrap around needed
			else if (getCurrentRow() - 1 >= 0)
			{
				setCurrentRow(getCurrentRow() - 1);
			}

			//however a west facing ant will turn right (north)
			//but still stay on the same column
			setCurrentCol(getCurrentCol());


		}

		else if (blockCurrent == 'B')
		{

			//change curent array space to white as it is black

			array2d[getCurrentRow()][getCurrentCol()] = ' ';

			//turn a West facing ant 90 degrees to the left,
			//from a black square now it is facing south. 
			//Update orientation accordingly
			setOrientation('S');

			//the row will move "up" one because a west facing ant
			//will turn south and simply move down  one square 
			//(which increases row value)
			
			//setCurrentRow(getCurrentRow() + 1);
			
			//wrap around check in below if statement
			if (getCurrentRow() + 1 >= board.getRows())
			{
				setCurrentRow(0);
			}
			//execute normal move if no wrap around needed
			else if (getCurrentRow() + 1 < board.getRows())
			{
				setCurrentRow(getCurrentRow() + 1);
			}

			//however a west facing ant will turn south but still stay on 
			//the same column
			setCurrentCol(getCurrentCol());
		}
		//update step #				
	}//end else-if bracket for WEST facing ant


	//set the blockCurrent value equal to the value 
	//of the "get current block function" which actually
	//returns the value of the next block the ant will move to.
	//This value was calculated in the above if statements.
	//Basically, before this function is executed blockCurrent
	//is actually still set to the same value as the block the ant
	//@ is on.  This is why it is needed
	setBlockCurrent(getBlockCurrent(array2d));

	//cout << "Array value of next block coming up in below chart"
	//	<< blockCurrent << endl;
	
	
	array2d[getCurrentRow()][getCurrentCol()] = '@';
	
	currentStepAnt += 1;
	cout << "CURRENT STEP NUMBER: "
		<< currentStepAnt << endl;
	board.printBoard(array2d);
	//cout << "Orientation of ant: " << getOrientation() << endl;


	}//temp test for loop closing bracket

	//checkWrapNorth(boardArray);
	
	return;
}

/******************************************************************************
[Method Name]:	checkWrapNorth

[Description]:	Checks whether the ant should wrap the board. Just for
testing purposes to cout a statement.

[Arguments]:
n/a

[ArgRestrict]:	n/a

[Return]:      void
******************************************************************************/
void Ant::checkWrapNorth(char ** boardArray)
{
	//Situation 1: Ant on very left side of board (column index ==0)
	//Case1: Ant is facing north and turns left

	if (orientation == 'N' && turn == 'L' && getCurrentCol() == 0)
	{
		cout << "North Orientation and left turn" << endl;
	}
	return;
}









//Jay Swaminarayan