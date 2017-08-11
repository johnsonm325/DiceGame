/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Class header for Input Validation class
***************************************************************************************************/

#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <string>

using std::string;

class InputValid
{
private:
	string input = "";	// Initializes variable to empty string
	int    counter,		// Creates variable to use for counting
		   tries;		// Creates variable to hold number of tries

public:
	InputValid();
	string isString();
	int isPosInteger();
};
#endif