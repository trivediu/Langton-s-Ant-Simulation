/******************************************************************************
Author:        Uday S. Trivedi (Summer 2017 - CS 162)

Description:   This header file contains the function
				prototypes for performing error check on INT type variable
				(integers).

				For full details on what each function does, input argument,
				restrictions, and returns please refer to the
				IntErrorCheck.cpp file.

				Please note this file is a work in progress.

******************************************************************************/
#ifndef INTERRORCHECK_HPP
#define INTERRORCHECK_HPP

int intErrorCheck();
int intMenuErrCheck();
int intRowsErrCheck();
int intColsErrCheck();
int intStepsErrCheck();

//error check integer value inputted is between 0 and total user-specified rows
int intSetAntPosRowErrCheck(int rows);
//Same as above except for columns
int intSetAntPosColErrCheck(int cols);

void intErrorMesg1();
void menuErrorMesg1();
void boardErrorMesg1();
void boardErrorMesg2();


#endif









//Jay Swaminarayan