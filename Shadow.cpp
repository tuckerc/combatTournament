/*************************************************************************
** Program Filename: Shadow.cpp
** Author: Chase Tucker
** Creation Date: 7/23/15 // Last Update: 10/1/19
** Description: This file provides the implementation for the Shadow class
** Input: none
** Output: none
*************************************************************************/

#include "Shadow.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

/*************************************************************************
** Function: Shadow
** Description: This function is a constructor for the Shadow class.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
Shadow::Shadow() : Character(2, 10, 1, 6, 0, 12.0, 12.0, false, "The Shadow") {}

/*************************************************************************
** Function: attack
** Description: In this function, the calling Shadow attacks another
**   Character.
** Parameters: 1 pointer to a Character
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Shadow::attack(Character* ch)
{
	int attackTotal = 0; //var to keep track of attack die count

	//roll attack die twice
	attackTotal += rand() % 10 + 1;
	attackTotal += rand() % 10 + 1;

	//test if shadow effect occurs
	bool shadowEffect = rand() % 2;
	if ((shadowEffect == true) && (ch->getName() == "The Shadow"))
	{
		std::cout << "Shadow effect! Shadow recieves zero attack";
		std::cout << " points!" << std::endl;
		attackTotal = 0;
	}

	//if Achilles tendon is cut, attackTotal is cut in half
	if (this->achilles == true) attackTotal *= 0.5;

	return attackTotal;
}

/*************************************************************************
** Function: defend
** Description: This function returns the defensive points for The Shadow.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Shadow::defend()
{
	return rand() % 6 + 1;
}