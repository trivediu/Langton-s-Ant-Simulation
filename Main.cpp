/******************************************************************************
Program Name:  Langton's Ant - Main.cpp File
Author:        Uday S. Trivedi 

Description:   [What The Program Does]

This is the "int main" file for Program 1.  This file will implement the other
functions and classes included with this program. This program replicates
Langton's Ant on a default white board.  

[How to Run the Program - Quick Description]
Execute the program as normal.  Then follow the on-screen
menu and instructions.

[How to Run the Program - Detailed Description]
Simply run this program and follow the instructions in the menu - which will 
allow the user to set various aspects of the program.  If the user decides 
not to set any settings, then the program will use it's default settings 
(which are listed in the menu).  At anytime, the user can press option [5] 
to view current user settings.  The ant will always start in an eastward 
direction and if it hits the edge of the board, it will wrap around the board. 
Important! Please note: Step 1 is the starting position of the ant.

******************************************************************************/
#include <iostream>
#include "Menu.hpp"


int main()
{
	//memory leak check for visual studio - please disregard
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	executeMenu();
	return 0;
}









//Jay Swaminarayan

