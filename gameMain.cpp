/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Main function for Dice War game
***************************************************************************************************/

#include "Game.h"

int main()
{

	Menu menu1;
	while (menu1.getChoice() != 2)
	{
		menu1.displayMenu();
		menu1.setChoice();

		// Exits the program
		if (menu1.getChoice() == 2)
		{
			return 0;
		}

		Game game1;
	}
}