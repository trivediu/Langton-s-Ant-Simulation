/******************************************************************************
Author:        Uday S. Trivedi 

Description:   This CPP file contains the functions for performing
error checks on INT type variable (integers).

IMPORTANT NOTE: This entire file is a work in progress.

******************************************************************************/
#include <iostream>
#include <string>
#include "IntErrorCheck.hpp"
#include <sstream>

using std::flush;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::stringstream;
//using std::getline;
//using std::numeric_limits;
//using std::streamsize;

//**********************************
//resources used for writing this code and researching 
//stackoverflow.com/questions/18567483/c-checking-for-an-integer
//stackoverflow.com/questions/16934183/integer-validation-for-input
//www.cplusplus.com/forum/beginner/76374/
//TA office hours.
//www.quora.com/How-do-I-convert-a-string-into-an-integer-in-C++
////www.youtube.com/watch?v=LM6EDIKS5Pk


/******************************************************************************
[Method Name]:	intErrorCheck

[Description]:	This function performs a generic error check to make sure the
user input is indeed an integer INT.

[Arguments]:
[ArgRestrict]:

[Return]:      Upon success, an integer is returned.
******************************************************************************/
int intErrorCheck()
{
	int userInt = 0;
	string userString;

	while (true)
	{
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, userString);
		stringstream ss(userString);

		if (ss >> userInt && !(ss >> userString))
		{
			return userInt;
		}

		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		intErrorMesg1();
	}

}

/******************************************************************************
[Method Name]:	intErrorMesg1

[Description]:	This function outputs a generic error message prompting the 
				user for a correct integer input.

[Arguments]:
[ArgRestrict]:

[Return]:      void
******************************************************************************/
void intErrorMesg1()
{
	cerr << "Error! Please enter an integer: ";
	return;
}


/******************************************************************************
[Method Name]:	menuErrorMesg1

[Description]:	This function couts a generic error message for the menu.

[Arguments]:
[ArgRestrict]:

[Return]:      Void
******************************************************************************/
void menuErrorMesg1()
{
	cerr << "Error! Please enter a numerical value from 1 through 8: ";
	return;
}


/******************************************************************************
[Method Name]:	menuErrCheck

[Description]:	This function performs an error check on user input for the 
menu.  Essentially input must be an integer ranging from 1 through 8.

[Arguments]:
[ArgRestrict]:

[Return]:      Upon success, an integer is returned.
******************************************************************************/
int intMenuErrCheck()
{
	int userInt = 0;
	string userString;

	while (true)
	{
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, userString);
		stringstream ss(userString);

		if (ss >> userInt && !(ss >> userString))
		{
			if (userInt == 1 || userInt == 2 || userInt == 3 ||
				userInt == 4 || userInt == 5 || userInt == 6 ||
				userInt == 7 || userInt == 8)
			{
				cout << endl;
				return userInt;
			}
			
		}

		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuErrorMesg1();
	}

}


/******************************************************************************
[Method Name]:	intRowsErrorCheck

[Description]:	This function performs a generic error check to make sure the
user input is within the min and max range specified for rows which is min 5
and max 26.

[Arguments]:
[ArgRestrict]:

[Return]:      Upon success, an integer is returned.
******************************************************************************/
int intRowsErrCheck()
{
	int userInt = 0;
	string userString;

	while (true)
	{
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, userString);
		stringstream ss(userString);

		if (ss >> userInt && !(ss >> userString))
		{
			if (userInt > 5 && userInt < 27)
			{
				return userInt;
			}
		}

		cin.clear();
		boardErrorMesg2();
	}

}


/******************************************************************************
[Method Name]:	intColsErrorCheck

[Description]:	This function performs a generic error check to make sure the
user input is within the min and max range specified for cols which is min 5
and max 26. This function was originally kept separate from the rows error
check function (even though they have the same range) incase different range
values are to be specified for columns in the future.

[Arguments]:
[ArgRestrict]:

[Return]:      Upon success, an integer is returned.
******************************************************************************/
int intColsErrCheck()
{
	int userInt = 0;
	string userString;

	while (true)
	{
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, userString);
		stringstream ss(userString);

		if (ss >> userInt && !(ss >> userString))
		{
			if (userInt > 5 && userInt < 27)
			{
				return userInt;
			}
		}

		cin.clear();
		boardErrorMesg1();
	}

}


/******************************************************************************
[Method Name]:	intStepsErrCheck

[Description]:	This function performs a generic error check to make sure the
user input is within the min and max range specified for the number of ant
steps.

[Arguments]:
[ArgRestrict]:

[Return]:      Upon success, an integer is returned.
******************************************************************************/
int intStepsErrCheck()
{
	int userInt = 0;
	string userString;

	while (true)
	{
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, userString);
		stringstream ss(userString);

		if (ss >> userInt && !(ss >> userString))
		{
			if (userInt > 0 && userInt < 3001)
			{
				return userInt;
			}
		}

		cin.clear();
		cerr << endl << "Error - Please Try Again!" << endl;
		cerr << "Enter a numerical value in the range of 1 through 3000: ";
	}

}


/******************************************************************************
[Method Name]:	boardErrorMesg1

[Description]:	This function outputs the basic error message if the user
inputs an integer outside of the max and min range of column and row size
integers.

[Arguments]:
[ArgRestrict]:

[Return]:      void
******************************************************************************/
void boardErrorMesg1()
{
	cerr << endl << "Error - Please Try Again!" << endl;
	cerr << "Enter a numerical value in the range of 6 to 26: ";
	return;
}


/******************************************************************************
[Method Name]:	intRowsErrorCheck

[Description]:	This function performs a generic error check to make sure the
user input is within the min and max range specified for rows which is min 5
and max 26. Again, this is the same as the above function, but it is kept 
incase the program expands in the future and requires different ranges for
the rows and columns instead of it being the same range.

[Arguments]:
[ArgRestrict]:

[Return]:      void
******************************************************************************/
void boardErrorMesg2()
{
	cerr << endl << "Error - Please Try Again!" << endl;
	cerr << "Enter a numerical value in the range of 6 to 26: ";
	return;
}


/******************************************************************************
[Method Name]:	intSetAntPosRowErrCheck

[Description]:	This function automatically adjusts it's error input bounds
to the user specified board size of rows.  Then when the user
goes to manually set the ant position, if the user specifies a range outside
of the board's row bounds, this function will automatically calculate errors.
Essentially this is a flexible function that adjusts to board size.

[Arguments]:  (Arg 1) rows - the number of rows in the current board 
[ArgRestrict]: (Arg 1) rows must be of integer value

[Return]:      Upon success, an integer is returned.
******************************************************************************/
int intSetAntPosRowErrCheck(int rows)
{
	int userInt = 0;
	string userString;

	while (true)
	{
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, userString);
		stringstream ss(userString);

		if (ss >> userInt && !(ss >> userString))
		{
			if (userInt >= 0 && userInt <= rows)
			{
				return userInt;
			}
		}

		cin.clear();
		cerr << endl << "Error - Please Try Again!" << endl;
		cerr << "Enter a numerical value in the range of 0 through " << rows 
			<< ": ";
	}
}


/******************************************************************************
[Method Name]:	intSetAntPosColsErrCheck

[Description]:	This function automatically adjusts it's error input bounds
to the user specified board size of columns.  Then when the user
goes to manually set the ant position, if the user specifies a range outside
of the board's column bounds, this function will automatically calculate errors.
Essentially this is a flexible function that adjusts to board size.

[Arguments]:  (Arg 1) cols - the number of columns in the current board
[ArgRestrict]: (Arg 1) rows must be of integer value

[Return]:      Upon success, an integer is returned.
******************************************************************************/
int intSetAntPosColErrCheck(int cols)
{
	int userInt = 0;
	string userString;

	while (true)
	{
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, userString);
		stringstream ss(userString);

		if (ss >> userInt && !(ss >> userString))
		{
			if (userInt >= 0 && userInt <= cols)
			{
				return userInt;
			}
		}

		cin.clear();
		cerr << endl << "Error - Please Try Again!" << endl;
		cerr << "Enter a numerical value in the range of 0 through " << cols 
			<< ": ";
	}
}









//Jay Swaminarayan