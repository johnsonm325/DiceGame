/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Header file for Game class
***************************************************************************************************/

#ifndef GAME_H
#define GAME_H
#include "LoadedDie.h"

class Game
{
private:
	int numOfSides,		// Holds the number of side for the dice
		numOfRounds,	// Holds the number of rounds
		roundNum,		// Holds the round number
		diceOneScore,	// Holds the roll score for player 1 for each round
		diceTwoScore,	// Holds the roll score for player 2 for each round
		playerOneScore,	// Holds the game score for player 1
		playerTwoScore;	// Holds the game score for player 2
	string typeOfDieP1,	// Holds the type of die for player 1
		   typeOfDieP2; // Holds the type of die for player 2

public:
	Game();
	InputValid inputVal2;
	void menu();
	void setRounds();
	void rollDice(Dice*, Dice*);
	Dice* makeDie(int, string, int);
	void determineWinner();
	void displayDice(Dice*, Dice*);
	void deallocateMem(Dice*, Dice*);

};
#endif
