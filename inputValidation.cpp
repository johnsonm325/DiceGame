/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Definitions of Input Validation functions
***************************************************************************************************/

#include "inputValidation.h"
#include <iostream>
#include <string>

using std::stoi;
using std::string;
using std::cout;
using std::cin;
using std::endl;

/**************************************************************************************
**
**************************************************************************************/
InputValid::InputValid()
{
	string input = "";
}


/**************************************************************************************
**
**************************************************************************************/
int InputValid::isPosInteger()
{
	int testInt;	// Variable to hold an integer converted from a string
	tries = 0;		// Variable to hold the number of times a user has tried to enter
					// a value

	do
	{
		counter = 0;	// Increments is character is not a digit or is less than 0

		// If the user has tried to enter a positive integer more than once it prompts
		// a message
		if (tries > 0)
		{
			cout << "Please enter a positive integer" << endl;
			getline(cin, input);
		}

		// Captures line on first try
		else
		{
			getline(cin, input);
		}

		// Loops through the length of the string and
		for (size_t count = 0; count < input.length(); count++)
		{
			// If the character is not a digit
			if (!(isdigit(input[count])))
			{
				// It increments the count variable
				counter++;
			}
		}
		
		if (counter == 0)
		{
			// Stores an integer version of the string into testInt
			testInt = stoi(input);
			
			if (testInt < 0)
			{
				counter++;
			}
		}

		tries++;

	}while (counter > 0);
	
	return testInt;
}


/**************************************************************************************
**
**************************************************************************************/
string InputValid::isString()
{
	tries = 0;		// Variable to hold the number of times a user has tried to enter
					// a value

	do
	{
		counter = 0;	// Increments is character is not a digit or is less than 0

		// If the user has tried to enter a string more than once it prompts
		// a message
		if (tries > 0)
		{
			cout << "Please enter a string" << endl;
			getline(cin, input);
		}

		// Captures line on first try
		else
		{
			getline(cin, input);
		}

		// Loops through each character of string
		for (size_t count = 0; count < input.length(); count++)
		{
			// If the character is a digit
			if (isdigit(input[count]))
			{
				// Then it increments the counter
				counter++;
			}
		}

		// If none of the characters in the string were digits
		if (counter == 0)
		{
			// Loop through string and turn each character into lowercase
			for (size_t count = 0; count < input.length(); count++)
			{
				input[count] = tolower(input[count]);
			}
		}

		// Increment tries at end of loop if it fails so the next loop
		// will ask the user to enter a string
		tries++;

	} while (counter > 0);
	return input;
}