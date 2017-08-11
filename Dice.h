/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Header file for Dice class
***************************************************************************************************/

#ifndef DICE_H
#define DICE_H

#include "DiceMenu.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Dice
{
private:
	int sides,
		rollNum;

public:
	Dice();
	Dice(int);
	virtual ~Dice();
	virtual int roll();
	int getSides();

};
#endif