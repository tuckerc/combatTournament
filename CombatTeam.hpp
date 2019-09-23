/**************************************************************************
** Program Filename: CombatTeam.hpp
** Author: Chase Tucker
** Date: 8/4/15
** Description: This file provides the interface for the CombatTeam class.
** Input: none
** Output: none
**************************************************************************/

#ifndef COMBATTEAM_HPP
#define COMBATTEAM_HPP

#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMan.hpp"
#include "Goblin.hpp"
#include "ReptilePerson.hpp"
#include "Shadow.hpp"
#include "DynCharacterQueue.hpp"

class CombatTeam
{
private:
	int teamSize;
	double teamPts;
	DynCharacterQueue teamQueue;

public:
	CombatTeam(int);
	~CombatTeam();
	DynCharacterQueue* getTeamQueue();
	double getTeamPts();
	void buildTeam();
	void addTeamPts(double);
};
#endif