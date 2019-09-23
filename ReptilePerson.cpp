/*************************************************************************
** Program Filename: ReptilePerson.cpp
** Author: Chase Tucker
** Date: 7/23/15
** Description: This file provides the implementation for the 
**   ReptilePerson class.
** Input: none
** Output: none
*************************************************************************/

#include "ReptilePerson.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

/*************************************************************************
** Function: ReptilePerson
** Description: This function is a constructor for the ReptilePerson 
**   class.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
ReptilePerson::ReptilePerson() : Character(3, 6, 1, 6, 7, 18, false,
	"Reptile Person") {}

/*************************************************************************
** Function: attack
** Description: In this function, the calling ReptilePerson attacks another
**   Character.
** Parameters: 1 pointer to a Character
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int ReptilePerson::attack(Character* ch)
{
	int attackTotal = 0; //var to keep track of attack die count

	//roll attack die twice
	attackTotal += rand() % 6 + 1;
	attackTotal += rand() % 6 + 1;
	attackTotal += rand() % 6 + 1;

	//test if shadow effect occurs
	bool shadowEffect = rand() % 2;
	if ((shadowEffect == true) && (ch->getName() == "The Shadow"))
	{
		std::cout << "Shadow effect! Reptile Person recieves "; 
		std::cout << "zero attack points!" << std::endl;
		attackTotal = 0;
	}

	//if Achilles tendon is cut, attackTotal is cut in half
	if (this->achilles == true) attackTotal *= 0.5;

	return attackTotal;
}

/*************************************************************************
** Function: defend
** Description: This function returns the defensive points for the
**   Reptile Person.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int ReptilePerson::defend()
{
	return rand() % 6 + 1;
}
