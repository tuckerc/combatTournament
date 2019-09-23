/*************************************************************************
** Program Filename: BlueMan.cpp
** Author: Chase Tucker
** Date: 7/23/15
** Description: This file provides the implementation for the BlueMan class
** Input: none
** Output: none
*************************************************************************/

#include "BlueMan.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

/*************************************************************************
** Function: BlueMan
** Description: This function is a constructor for the BlueMan class.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
BlueMan::BlueMan() : Character(2, 10, 3, 6, 3, 12, false, "Blue Man") {}

/*************************************************************************
** Function: attack
** Description: In this function, the calling BlueMan attacks another
**   Character.
** Parameters: 1 pointer to a Character
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int BlueMan::attack(Character* ch)
{
	int attackTotal = 0; //var to keep track of attack die count

						 //roll attack die twice
	attackTotal += rand() % 10 + 1;
	attackTotal += rand() % 10 + 1;

	//test if shadow effect occurs
	bool shadowEffect = rand() % 2;
	if ((shadowEffect == true) && (ch->getName() == "The Shadow"))
	{
		std::cout << "Shadow effect! Blue Man recieves zero ";
		std::cout << "attack points!" << std::endl;
		attackTotal = 0;
	}

	//if Achilles tendon is cut, attackTotal is cut in half
	if (this->achilles == true) attackTotal *= 0.5;

	return attackTotal;
}

/*************************************************************************
** Function: defend
** Description: This function returns the defensive points for the calling
**   Blue Man.
** Parameters: 1 pointer to a Character
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int BlueMan::defend()
{
	return (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
}