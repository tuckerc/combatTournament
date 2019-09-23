/*************************************************************************
** Program Filename: Barbarian.cpp
** Author: Chase Tucker
** Date: 7/23/15
** Description: This file provides the implementation for the Barbarian class
** Input: none
** Output: none
*************************************************************************/

#include "Barbarian.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

/*************************************************************************
** Function: Barbarian
** Description: This function is a constructor for the Barbarian class.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
Barbarian::Barbarian() : Character(2, 6, 2, 6, 0, 12, false, 
	"Barbarian") {}

/*************************************************************************
** Function: attack
** Description: In this function, the calling Barbarian attacks another
**   Character.
** Parameters: 1 pointer to a Character
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Barbarian::attack(Character* ch)
{
	int attackTotal = 0; //var to keep track of attack die count

						 //roll attack die twice
	attackTotal += rand() % 6 + 1;
	attackTotal += rand() % 6 + 1;

	//test if shadow effect occurs
	bool shadowEffect = rand() % 2;
	if ((shadowEffect == true) && (ch->getName() == "The Shadow"))
	{
		std::cout << "Shadow effect! Barbarian recieves zero ";
		std::cout << "attack points!" << std::endl;
		attackTotal = 0;
	}

	//if Achilles tendon is cut, attackTotal is cut in half
	if (this->achilles == true) attackTotal *= 0.5;
	
	return attackTotal;
}

/*************************************************************************
** Function: defend
** Description: This function returns the defend total for the Barbarian.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Barbarian::defend()
{
	return (rand() % 6 + 1) + (rand() % 6 + 1);
}
