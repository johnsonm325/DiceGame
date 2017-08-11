/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Header file for derived LoadedDie class
***************************************************************************************************/

#ifndef LOADEDDIE_H
#define LOADEDDIE_H

#include "Dice.h"

class LoadedDie : public Dice
{
private:
	int sides,
		rollNum;

public:
	LoadedDie();
	LoadedDie(int);
	~LoadedDie();
	int roll();
	int getSides();
	int biasedRoll();
};
#endif