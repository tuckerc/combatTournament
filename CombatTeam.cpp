/**************************************************************************
** Program Filename: CombatTeam.cpp
** Author: Chase Tucker
** Date: 8/4/15
** Description: This file provides the implementation for the CombatTeam
**   class.
** Input: none
** Output: none
**************************************************************************/

#include "CombatTeam.hpp"
#include <iostream>

/**************************************************************************
** Function: CombatTeam
** Description: This function is a constructor for the CombatTeam class.
** Parameters: one integer
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
CombatTeam::CombatTeam(int size)
{
	teamSize = size;
	teamPts = 0;
	buildTeam();
}

/**************************************************************************
** Function: ~CombatTeam
** Description: This function is a destructor for the CombatTeam class.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
CombatTeam::~CombatTeam()
{
	teamQueue.clear();
}

/**************************************************************************
** Function: getTeamQueue 
** Description: This function retreives the teamQueue.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
DynCharacterQueue* CombatTeam::getTeamQueue()
{
	return &teamQueue;
}

/**************************************************************************
** Function: getTeamPts
** Description: This function retreives the teamPts.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
double CombatTeam::getTeamPts()
{
	return this->teamPts;
}

/**************************************************************************
** Function: buildTeam
** Description: This function allows the user to add team members based on
**   the defined team size.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
void CombatTeam::buildTeam()
{
	for (int i = 1; i < this->teamSize; i++)
	{
		std::cout << "Please select your next combatant: " << std::endl;
		std::cout << "1 - Goblin" << std::endl;
		std::cout << "2 - Barbarian" << std::endl;
		std::cout << "3 - Reptile Person" << std::endl;
		std::cout << "4 - Blue Man" << std::endl;
		std::cout << "5 - The Shadow" << std::endl;
		int selection;
		std::cin >> selection;
		if (selection == 1)
		{
			Character* newCombatant = new Goblin();
			this->teamQueue.addBack(newCombatant);
		}
		else if (selection == 2)
		{
			Character* newCombatant = new Barbarian();
			this->teamQueue.addBack(newCombatant);
		}
		else if (selection == 3)
		{
			Character* newCombatant = new ReptilePerson();
			this->teamQueue.addBack(newCombatant);
		}
		else if (selection == 4)
		{
			Character* newCombatant = new BlueMan();
			this->teamQueue.addBack(newCombatant);
		}
		else if (selection == 5)
		{
			Character* newCombatant = new Shadow();
			this->teamQueue.addBack(newCombatant);
		}
		else
		{
			std::cout << "Please select an integer 1-5";
			std::cout << std::endl;
			i--;
		}
	}
}

/**************************************************************************
** Function: addTeamPts
** Description: This function adds to the teamPts.
** Parameters: one double
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
void CombatTeam::addTeamPts(double p)
{
	this->teamPts += p;
}