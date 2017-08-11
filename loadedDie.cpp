/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Definitions of Derived LoadedDie class functions
***************************************************************************************************/

#include "LoadedDie.h"


/*******************************************************************************************************
**									Default LoadedDie Constructor
**			Default constructor for Loaded Die object setting object to 0 sides and regular dice
*******************************************************************************************************/
LoadedDie::LoadedDie() : Dice(0)
{
	this->sides = 0;
}

/*******************************************************************************************************
**										LoadedDie Constructor
**				Constructor for Loaded Die object setting sides and type to parameters passed
*******************************************************************************************************/
LoadedDie::LoadedDie(int n) : Dice(n)
{
	this->sides = n;
}


/*******************************************************************************************************
**											LoadedDie destructor
**					Destructs object. This is a virtual destructor as called in header file
*******************************************************************************************************/
LoadedDie::~LoadedDie()
{

}


/*******************************************************************************************************
**											roll function
**									Calls the biasedRoll function
*******************************************************************************************************/
int LoadedDie::roll()
{
	return this->biasedRoll();
}


/*******************************************************************************************************
**											getSides function
**								Returns the number of sides of a Loaded Die object
*******************************************************************************************************/
int LoadedDie::getSides()
{
	return this->sides;
}


/*******************************************************************************************************
**										biasedRoll function
**		Rolls a random number between 1 and number of sides, but if that number is less than
**			half of the number of sides, then it continues to reroll and returns that number
*******************************************************************************************************/
int LoadedDie::biasedRoll()
{
	rollNum = rand() % sides + 1;
	while (rollNum < sides / 2)
	{
		rollNum = rand() % sides + 1;
	}
	return this->rollNum;
}
