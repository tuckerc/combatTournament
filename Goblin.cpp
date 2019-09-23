/*************************************************************************
** Program Filename: Goblin.cpp
** Author: Chase Tucker
** Date: 7/23/15
** Description: This file provides the implementation for the Goblin class
** Input: none
** Output: none
*************************************************************************/

#include "Goblin.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

/*************************************************************************
** Function: Goblin
** Description: This function is a constructor for the Goblin class.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
Goblin::Goblin() : Character(2, 6, 1, 6, 3, 8, false, "Goblin") {}

/*************************************************************************
** Function: attack
** Description: In this function, the calling Goblin attacks another
**   Character.
** Parameters: 1 pointer to a Character
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Goblin::attack(Character* ch)
{
	int attackTotal = 0; //var to keep track of attack die count

	//roll attack die twice
	attackTotal += rand() % 6 + 1;
	attackTotal += rand() % 6 + 1;

	//test if shadow effect occurs
	bool shadowEffect = rand() % 2;
	if ((shadowEffect == true) && (ch->getName() == "The Shadow"))
	{
		std::cout << "Shadow effect! Goblin recieves zero attack";
		std::cout << " points!" << std::endl;
		attackTotal = 0;
	}

	//flip coin to determine if ch achilles tendon gets cut
	if ((ch->getName() != "Goblin") && (ch->getAchilles() == false) &&
		(attackTotal == 12))
	{
		std::cout << "Goblin cuts " << ch->getName() << "'s";
		std::cout << " Achilles tendon!" << std::endl;
		ch->setAchilles(true);
	}

	return attackTotal;
}

/*************************************************************************
** Function: defend
** Description: This function returns the defensive points for the Goblin.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Goblin::defend()
{
	return rand() % 6 + 1;
}
