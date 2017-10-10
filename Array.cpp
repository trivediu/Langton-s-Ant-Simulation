/******************************************************************************
Author:        Uday S. Trivedi 

Description:   This is the CPP file for handling all array aspects.  See all 
functions below to understand more.
******************************************************************************/
#include "Array.hpp"


/******************************************************************************
[Method Name]:	createArray

[Description]:	This function will create a 2D array of pointers to pointers

[Arguments]:	1. rows - the number of rows required

				2. cols - the number of cols required

[ArgRestrict]:	n/a


[Return]:      character (char) 2D array of pointers to pointers.
******************************************************************************/
char **createArray(int rows, int cols)
{
	//Dynamically allocate an array of pointers to pointers
	char **boardArray = new char*[rows];
	for (int index = 0; index < rows; index++)
	{
		boardArray[index] = new char[cols];
	}

	//Step 2: Set all values of the array to white spaces
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			boardArray[i][j] = ' ';
		}
	}

	return boardArray;
}


/******************************************************************************
[Method Name]:	deleteArray

[Description]:	This function will delete a 2D array of pointers to pointers
by deallocating memory and setting the 2D array equal to "nullptr"

[Arguments]:	
1. The 2D array

2. rows - the number of rows required

3. cols - the number of cols required

[ArgRestrict]:	1. 2D array must be received as ** pointer to pointer.


[Return]:      void
******************************************************************************/
void deleteArray(char **boardArray, int rows, int cols)
{
	for (int index = 0; index < rows; index++)
	{
		delete[] boardArray[index];
	}

	delete[] boardArray;
	boardArray = nullptr;
}









//Jay Swaminarayan