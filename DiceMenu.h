/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Definitions of Input Validation functions
***************************************************************************************************/

#ifndef DICEMENU_H
#define DICEMENU_H

#include "inputValidation.h"
#include <string>

class Menu
{
	private:
		int		   choice;
		InputValid inputVal1;

	public:
		void displayMenu();
		void setChoice();
		int getChoice();

};
#endif