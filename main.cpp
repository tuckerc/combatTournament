/*************************************************************************
** Program Filename: Main.cpp
** Author: Chase Tucker
** Date: 8/3/15
** Description: This file provides the main function for the Combat
**    Tournament Game.
** Input: none
** Output: none
*************************************************************************/

#include "Character.hpp"
#include "Goblin.hpp"
#include "Barbarian.hpp"
#include "ReptilePerson.hpp"
#include "BlueMan.hpp"
#include "Shadow.hpp"
#include "DynCharacterQueue.hpp"
#include "DynCharacterStack.hpp"
#include "CombatTeam.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

Character* battle(CombatTeam*, CombatTeam*);

int main()
{
	std::srand(std::time(0));	
	
	std::cout << std::endl;
	
	int combatantNum; //integer to hold number of combatants on each team
	std::cout << "Enter the number of combatants for each team: ";
	std::cout << std::endl;
	std::cin >> combatantNum;
	
	//build team 1
	CombatTeam team1(combatantNum);
	
	//build team 2
	CombatTeam team2(combatantNum);

	DynCharacterStack loserStack; //stack for loser of each round

	while (!team1.getTeamQueue()->isEmpty() || 
		!team2.getTeamQueue()->isEmpty())
	{
		Character* tempCharacter = battle(&team1, &team2);
		if (tempCharacter != NULL)
			loserStack.push(tempCharacter);

		//replenish fighter strength by 50% of expended
		Character* fighter = team1.getTeamQueue()->getFront();
		while (team1.getTeamQueue()->getFront() != fighter)
		{
			team1.getTeamQueue()->getFront()->addStrength((team1.
				getTeamQueue()->getFront()->getStrength())*1.5);
			Character* tempCharacter = team1.getTeamQueue()->getFront();
			team1.getTeamQueue()->removeFront();
			team1.getTeamQueue()->addBack(tempCharacter);
		}
	}
	
	char again; //var for play again? selection
	std::cout << std::endl;
	std::cout << "Play again? (Y or N)" << std::endl;
	std::cin.get(again);
	if (again == 'Y' || again == 'y')
	{
		std::cout << std::endl;
		main();
	}
		
	return 0;
}

Character* battle(CombatTeam* t1, CombatTeam* t2)
{
	std::cout << std::endl;
	
	int rounds = 0; //var to track number of combat rounds
	while ((t1->getTeamQueue->getFront->getStrength > 0) &&
		(t2->getTeamQueue->getFront->getStrength > 0))
	{
		rounds++;
		std::cout << "Round: " << rounds << std::endl << std::endl;
		std::cout << t1->getTeamQueue->getFront->getName << " attacks "
			<< t2->getTeamQueue->getFront->getName;
		std::cout << std::endl << std::endl;
		
		int damage; //int for damage total
		damage = (t1->getTeamQueue->getFront->
			attack(t2->getTeamQueue->getFront)) - 
			(t2->getTeamQueue->getFront->defend()) - 
			(t2->getTeamQueue->getFront->getArmor());
		if (damage > 0)
		{
			t2->getTeamQueue->getFront->addStrength(-damage);
			t1->addTeamPts(damage);
		}

		std::cout << t1->getTeamQueue->getFront->getName << " strength: " 
			<< t1->getTeamQueue->getFront->getStrength << std::endl;
		std::cout << t2->getTeamQueue->getFront->getName << " strength: " 
			<< t2->getTeamQueue->getFront->getStrength << std::endl 
			<< std::endl;
		std::cout << t2->getTeamQueue->getFront->getName << " attacks "
			<< t1->getTeamQueue->getFront->getName;
		std::cout << std::endl << std::endl;

		damage = (t2->getTeamQueue->getFront->
			attack(t1->getTeamQueue->getFront)) -
			(t1->getTeamQueue->getFront->defend()) -
			(t1->getTeamQueue->getFront->getArmor());
		if (damage > 0)
		{
			t1->getTeamQueue->getFront->addStrength(-damage);
			t2->addTeamPts(damage);
		}

		t2->getTeamQueue->getFront->attack(t1->getTeamQueue->getFront);
        std::cout << t1->getTeamQueue->getFront->getName 
			<< " strength: " << t1->getTeamQueue->getFront->getStrength 
			<< std::endl;
		std::cout << t2->getTeamQueue->getFront->getName << " strength: " 
			<< t2->getTeamQueue->getFront->getStrength << std::endl 
			<< std::endl;
	}

	//case if team 1 wins
	if (t1->getTeamQueue->getFront->getStrength > 0 &&
		t2->getTeamQueue->getFront->getStrength <= 0)
	{
		std::cout << t1->getTeamQueue->getFront->getName << " defeats ";
		std::cout << t2->getTeamQueue->getFront->getName << " after ";
		std::cout << rounds << " rounds!" << std::endl;
		
		//return team 1 combatant to end of queue
		Character* tempCharacter = t1->getTeamQueue->getFront;
		t1->getTeamQueue->removeFront();
		t1->getTeamQueue->addBack(tempCharacter);
		
		//throw team 2 loser on loserStack
		tempCharacter = t2->getTeamQueue->getFront;
		t2->getTeamQueue->removeFront();
		return tempCharacter;
	}

	//case if team 2 wins
	else if (t2->getTeamQueue->getFront->getStrength > 0 &&
		     t1->getTeamQueue->getFront->getStrength <= 0)
	{
		std::cout << t2->getTeamQueue->getFront->getName << " defeats ";
		std::cout << t1->getTeamQueue->getFront->getName << " after ";
		std::cout << rounds << " rounds!" << std::endl;

		//return team 2 combatant to end of queue
		Character* tempCharacter = t2->getTeamQueue->getFront;
		t2->getTeamQueue->removeFront();
		t2->getTeamQueue->addBack(tempCharacter);

		//throw team 1 loser on loserStack
		tempCharacter = t1->getTeamQueue->getFront;
		t1->getTeamQueue->removeFront();
		return tempCharacter;
	}

	//case if tie
	else if (t1->getTeamQueue->getFront->getStrength <= 0 &&
		     t2->getTeamQueue->getFront->getStrength <= 0)
	{
		std::cout << "The combat ended in a tie after ";
		std::cout << rounds << " rounds!" << std::endl;

		//return both combatants to their queues
		Character* tempCharacter = t1->getTeamQueue->getFront;
		t1->getTeamQueue->removeFront();
		t1->getTeamQueue->addBack(tempCharacter);
		tempCharacter = t2->getTeamQueue->getFront;
		t2->getTeamQueue->removeFront();
		t2->getTeamQueue->addBack(tempCharacter);
		return NULL;
	}

	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore(100000, '\n');
	std::cout << "Press Enter to continue...";
	std::cin.ignore(100000, '\n');
}
