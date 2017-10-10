/******************************************************************************
Author:        Uday S. Trivedi 

Description:   This is the CPP file for Menu.  Menu.cpp implements
the functions originally prototyped in the Menu.hpp file.

The purpose of this file is to assist in all aspects of
creating and executing the menu. There are several "helper" functions here
to help in other tasks of implementing the menu.  Please see below for details
on each function
******************************************************************************/
#include "Menu.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::flush;


/******************************************************************************
[Method Name]:	executeMenu

[Description]:	This function will execute the menu and get it running. The
menu will then provide 8 options to the user:
				
				Option 1: Set Board Dimensions
				Option 2: Set Total Number of Steps
				Option 3: Set Ant Starting Position
				Option 4: EXTRA CREDIT: Set Random Ant Start Position
				Option 5: View Current User Settings
				Option 6: Play - Start and Execute The Program
				Option 7: Help Documentation
				Option 8: Quit

[Arguments]:   n/a

[ArgRestrict]: n/a

[Return]:      Void.
******************************************************************************/
void executeMenu()
{
	//initialize a board from the board class;
	Board board(15, 10);

	//initiliaze an ant object
	Ant ant(5,5,'N');

	//initialize a 2d array
	char **boardArray=nullptr;

	//initialize an integer value that will drive which menu items are executed
	int menuChoice = 0;
	
	//Now execute the actual menu with above variable initializations done
	while (menuChoice != -20)
	{
		//Choice 0 (choice 0 not available to user on front end console)
		/*Display the menu in the console and prompt the user for an error-
		checked integer input that is only a menu item number*/
		if (menuChoice == 0)
		{
			printMenu();
			menuChoice = intMenuErrCheck();
			//cin.ignore();
			//cin.get();
		}

		//Choice 1
		/*Set the dimensions of the board*/
		else if (menuChoice == 1)
		{
			clearScreen();
			board.setBoardDim();
			
			//prompt user to press enter to return to menu
			menuChoice = promptEnterMenu();
			clearScreen();
			
		}

		/*Choice 2*/
		/*Set the total number of steps*/
		else if (menuChoice == 2)
		{
			clearScreen();
			board.setSteps();

			//prompt user to press enter to return to menu
			menuChoice = promptEnterMenu();
			clearScreen();
		}

		/*Choice 3*/
		/*Set Ant Starting Position*/
		else if (menuChoice == 3)
		{
			clearScreen();
			
			//generate an array temporarily, because after 
			//the play function (option 6) array was deleted automatically.
			boardArray = createArray(board.getRows(), board.getCols());
				
			//feed that array into the set start position function
			ant.setStartPos(board, boardArray);
				
			//prompt user to press enter to return back to menu
			menuChoice = promptEnterMenu();
				
			//free the memory
			deleteArray(boardArray, board.getRows(), board.getCols());
				
			//clear the screen
			clearScreen();
		}

		/*Choice 4 Extra Credit*/
		/*Set RANDOM Ant Starting Position*/
		else if (menuChoice == 4)
		{
			clearScreen();

			//generate an array temporarily, because after 
			//the play function (option 6) array was deleted automatically.
			boardArray = createArray(board.getRows(), board.getCols());

			//feed that array into the RAND set start position function
			ant.setRandStartPos(board, boardArray);

			//prompt user to press enter to return back to menu
			menuChoice = promptEnterMenu();

			//free the memory
			deleteArray(boardArray, board.getRows(), board.getCols());

			//clear the screen
			clearScreen();
		}

		//Choice 5
		/*View current user settings*/
		else if (menuChoice == 5)
		{
			clearScreen();
			
			board.getUserSettings(ant.getStartRowID(), ant.getStartColID(),
				ant.getStartDirection());
			
			//prompt user to press enter to return to menu
			menuChoice = promptEnterMenu();
			clearScreen();
		}

		//Choice 6
		/*Start and Execute The Program*/
		else if (menuChoice == 6)
		{
			clearScreen();
			//Set the current step value to zero (start again)
			ant.setCurrentStep(0);

			//Initialize a dynamic 2d array with values specified in
			//the Board class and object
			boardArray = createArray(board.getRows(), board.getCols());

			//initialize variables to settings specified in user settings
			//option [5] of the menu , just incase anything changed from
			//the last run
			ant.initialize();
			
			//Now "play" with the dynamic array passed.  Col and Row
			//information is already stored as private variables in the
			//board class
			ant.startAnt(boardArray, board);
			
			//prompt user to press enter to return to menu
			menuChoice = promptEnterMenu(); 
			//free the memory
			deleteArray(boardArray, board.getRows(), board.getCols());
			clearScreen();
		}

		//Choice 7
		/*Show help/about documentation*/
		else if (menuChoice == 7)
		{
			clearScreen();
			printMenuHelp();
			menuChoice = promptEnterMenu();
			clearScreen();
		}

		//Choice 8
		/*Quit the while loop return to int main*/
		else if (menuChoice == 8)
		{
			menuChoice = -20;
		}
	
	}

	return;
}


/******************************************************************************
[Method Name]: promptEnterMenu

[Description]: This function will simply prompt the user to press the [enter]
key to return back to the menu.

[Arguments]:   n/a

[ArgRestrict]: n/a

[Return]:      Integer [int] value of 0.  This automatically sets the menu
choice back to zero and thus defaults to the first option - displaying the
menu when we come back inside the executeMenu function.
******************************************************************************/
int promptEnterMenu()
{
	cout << "Press the [Enter] Key To Return Back to the Menu";
	//cin.ignore(INT_MAX, '\n');
	//cin.ignore();
	cin.get();
	return 0;
}


/******************************************************************************
[Method Name]: clearScreen

[Description]: This function will clear the console display.

[Arguments]:   n/a

[ArgRestrict]: n/a

[Return]:      Void.
******************************************************************************/
void clearScreen()
{
	cout << flush;
	//system("CLS");
	system("clear");
}


/******************************************************************************
[Method Name]: printMenu

[Description]: This function will simply print the menu options in the console.
This function is simply a series of COUT statements.

[Arguments]:   n/a

[ArgRestrict]: n/a

[Return]:      Void.
******************************************************************************/
void printMenu()
{
	cout << "Please Enter the Number of the Menu Item" <<
		" You Wish to Choose:" << endl << endl;

	cout << "[1] Set Board Dimensions (Default: 15x15 board)" << endl;
	cout << "[2] Set Total Number of Steps (Default: 10 Steps)" << endl;
	cout << "[3] Set Ant Starting Position (Default Start: 5,5)"
		<< endl;
	cout << "[4] EXTRA CREDIT: Set Random Ant Starting Position" << endl;
	cout << "[5] View Current User Settings" << endl;
	cout << "[6] [>>PLAY] Start and Execute the Program" << endl;
	cout << "[7] Help Documentation" << endl;
	cout << "[8] Quit" << endl;
	cout << endl << endl;
	cout << "Enter Your Choice Here: ";

	return;
}


/******************************************************************************
[Method Name]: printMenuHelp()

[Description]: A simple functions that couts some information about this
program to assist the end-user.

[Arguments]:   n/a

[ArgRestrict]: n/a

[Return]:      Void.
******************************************************************************/
void printMenuHelp()
{
	cout << "About this program:" << endl;
	cout << "Written by Uday Trivedi, CS 162 Project 1" << endl;
	cout << "Langton's Ant" << endl << endl;

	cout << "This program replicates Langton's Ant.  The board default is all"
		<< endl << "white spaces.  If the user does not specify their own settings"
		<< endl << "then the default values shown in the main menu will be used."
		<< endl << "The user can manually assign a starting position for the ant,"
		<< endl << "or the user can choose to randomly assign a starting position"
		<< endl << "for the ant."  
		<<endl << endl << "The starting cardinal direction orientation"
		<< endl << "for the ant is East.  The ant will make it's first step"
		<< endl << "in an eastward direction.At the moment the eastward start" 
		<< endl << "direction cannot be modified.  However, it can easily be"
		<< endl << "added in the future to have such functionality."
		<< endl <<  endl << 
		"Another important aspect of this program is how the ant will"
		<< endl << "behave on the board's edge.  In this program the ant will"
		<< endl << "wrap around to the opposite side of the board when it hits"
		<< endl << "an edge."
		<<endl << endl <<"Also, please note that step 1 is always the starting" 
		<< endl << "position of the ant. The next move will always be step 2. " 
		<< endl << endl << endl;

	return;
}









//Jay Swaminarayan
