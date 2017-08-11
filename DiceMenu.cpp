/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Definitions of the menu class functions
***************************************************************************************************/

#include "DiceMenu.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/****************************************************************************************************
**                                         displayMenu
**                       Displays the menu of game options on the screen.
**                        I pulled this function idea from the textbook.
****************************************************************************************************/
void Menu::displayMenu()
{
	cout << "\n Dice War" << endl;
	cout << "1.  Play war" << endl;
	cout << "2.  Quit game" << endl;
	cout << endl;
}


/****************************************************************************************************
**                                          setChoice
**                              Sets the menu choice from the user
****************************************************************************************************/
void Menu::setChoice()
{
	cout << "Choose an option: " << endl;
	choice = inputVal1.isPosInteger();

	while (choice > 2 || choice < 1)
	{
		cout << "Choose an option: " << endl;
		choice = inputVal1.isPosInteger();
	}
}


/****************************************************************************************************
**                                          getChoice
**                       Gets the menu choice from the user and returns it
****************************************************************************************************/
int Menu::getChoice()
{
	return choice;
}