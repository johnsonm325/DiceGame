/***************************************************************************************************
** Author: Michael Johnson
** Date: 7/16/2017
** Description: Definitions of Game class functions
***************************************************************************************************/

#include "Game.h"

/*******************************************************************************************************
**									Game class Constructor
**				Constructor for game class that calls the menu function
*******************************************************************************************************/
Game::Game()
{
	menu();
}


/******************************************************************************************************
**										menu function
**		This function starts the game and accpets most of the input from the user to set up the game
*******************************************************************************************************/
void Game::menu()
{
	// Gets user input for sides of die
	cout << "How many sides will dice 1 have?" << endl;
	cout << "Choose a number between 4 and 100" << endl;
	
	// Input validation class checks for positive integer and returns the integer if positive
	numOfSides = inputVal2.isPosInteger();
	
	// Runs as long as the user inputs a number outside of the range
	while (numOfSides < 4 || numOfSides > 100)
	{
		cout << "Choose a number between 4 and 100" << endl;
		numOfSides = inputVal2.isPosInteger();
	}
	
	// Gets user input for type of die
	cout << "For a loaded die, type 'loaded', for a regular die, type 'regular.'" << endl;
	
	// Input validation class checks for string and returns the lowercase string if a string
	typeOfDieP1 = inputVal2.isString();
	
	// Runs as long as the user inputs a string that is not regular or loaded
	while (typeOfDieP1 != "regular" && typeOfDieP1 != "loaded")
	{
		cout << "Enter either 'loaded' or 'regular'" << endl;
		typeOfDieP1 = inputVal2.isString();
	}

	cout << endl;

	// Calls function to dynamically allocated memory for an object that points to Dice
	Dice* dice1 = makeDie(numOfSides, typeOfDieP1, 1);

	/**************************************************
	** This is the same code that is run for player 2
	**************************************************/
	cout << "How many sides will dice 2 have?" << endl;
	cout << "Choose a number between 4 and 100" << endl;
	numOfSides = inputVal2.isPosInteger();
	while (numOfSides < 4 || numOfSides > 100)
	{
		cout << "Choose a number between 4 and 100" << endl;
		numOfSides = inputVal2.isPosInteger();
	}

	cout << "For a loaded die, type 'loaded', for a regular die, type 'regular.'" << endl;
	typeOfDieP2 = inputVal2.isString();
	while (typeOfDieP2 != "regular" && typeOfDieP2 != "loaded")
	{
		cout << "Enter either 'loaded' or 'regular'" << endl;
		typeOfDieP2 = inputVal2.isString();
	}

	cout << endl;

	Dice* dice2 = makeDie(numOfSides, typeOfDieP2, 2);


	// Runs the set rounds function to set the number of rounds for the game
	setRounds();

	// Outputs the number of sides and type of die for each player
	displayDice(dice1, dice2);

	cin.get();

	// Calls the rollDice function pass the dynamically allocated objects to the function
	rollDice(dice1, dice2);
}


/*******************************************************************************************************
**										makeDie function
**		This function accepts the input by user as a parameter and creates dynamically allocated dice
*******************************************************************************************************/
Dice* Game::makeDie(int n, string t, int p)
{
	// Runs this loops as long as the number passed through p is a 1 or a 2
	while (p == 1 || p == 2)
	{
		if (p == 1)
		{
			// If player 1's die is regular
			if (t == "regular")
			{
				// Then it returns a dynamically allocated Dice class object
				return new Dice(n);
			}
			// If it's loaded
			else if (t == "loaded")
			{
				// Then it returns a dynamically allocated LoadedDie class object
				return new LoadedDie(n);
			}
		}
		
		// Same comments as above, but for player 2
		else if (p == 2)
		{
			if (t == "regular")
			{
				return new Dice(n);
			}
			else if (t == "loaded")
			{
				return new LoadedDie(n);
			}
		}
	}
	
	// prints this message if a number other than 1 or 2 is passed
	cout << "You must have 2 players!" << endl;
	return 0;
}


/*******************************************************************************************************
**										setRounds function
**		This function asks the user to input the number of rounds and then changes the variable
*******************************************************************************************************/
void Game::setRounds()
{
	cout << "How many rounds would you like to play?" << endl;
	cout << "Choose a number between 1 and 50" << endl;
	numOfRounds = inputVal2.isPosInteger();
	while (numOfRounds < 1 || numOfRounds > 50)
	{
		cout << "Please enter a number between 1 and 50" << endl;
		numOfRounds = inputVal2.isPosInteger();
	}

	cout << endl;
}


/*******************************************************************************************************
**										rollDice function
**	This function calls the roll functions from each of the object pointers and increments score based
**						on which player returns the highest value from the roll
*******************************************************************************************************/
void Game::rollDice(Dice *dice1, Dice *dice2)
{
	for (int count = 0; count < numOfRounds; count++)
	{
		// Calls the roll functions from each of the object pointers for each player
		diceOneScore = dice1->roll();
		diceTwoScore = dice2->roll();

		// If/Else If statements evaluate the returned values and increment the proper player's score
		// If it's the same, then it's a draw
		if (diceOneScore > diceTwoScore)
		{
			playerOneScore++;
		}

		else if (diceOneScore < diceTwoScore)
		{
			playerTwoScore++;
		}

		else if (diceOneScore == diceTwoScore)
		{
			cout << "Draw" << endl;
		}

		// Outputs the results of each round
		cout << "Round number: " << count + 1 << endl;
		cout << "Player one: " << diceOneScore << endl;
		cout << "Player two: " << diceTwoScore << endl;
		cin.get();
	}

	// After turn limit is reached, the final result function, determine winner function, and deallocate memory
	// functions are called
	displayDice(dice1, dice2);
	determineWinner();
	deallocateMem(dice1, dice2);
}


/*******************************************************************************************************
**										determineWinner function
**				This functions determines the winner of the match based on total scores
*******************************************************************************************************/
void Game::determineWinner()
{
	if (playerOneScore > playerTwoScore)
	{
		cout << "Player one won the game!" << endl;
	}

	else if (playerOneScore < playerTwoScore)
	{
		cout << "Player two won the game!" << endl;
	}

	else if (playerOneScore == playerTwoScore)
	{
		cout << "It's a draw!" << endl;
	}
}


/*******************************************************************************************************
**										displayDice function
**						This function displays the die for each player.
*******************************************************************************************************/
void Game::displayDice(Dice *dice1, Dice *dice2)
{
	cout << "Player 1: " << endl;
	cout << dice1->getSides() << "-sided die" << endl;
	cout << typeOfDieP1 << " die" << endl;
	cout << endl;

	cout << "Player 2: " << endl;
	cout << dice2->getSides() << "-sided die" << endl;
	cout << typeOfDieP2 << " die" << endl;
	cout << endl;
}


/*******************************************************************************************************
**										deallocateMem function
**						This function deallocates dynamically allocated memory
*******************************************************************************************************/
void Game::deallocateMem(Dice *dice1, Dice *dice2)
{
	delete dice1;
	delete dice2;
}