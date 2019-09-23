/*************************************************************************
** Program Filename: Character.cpp
** Author: Chase Tucker
** Date: 7/23/15
** Description: This file provides the implementation for the Character
**   class.
** Input: none
** Output: none
*************************************************************************/

#include "Character.hpp"
#include <string>

/*************************************************************************
** Function: Character
** Description: This function is a constructor for the Character class.
** Parameters: 6 integers and 1 bool
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
Character::Character(int attNum, int attQty, int defNum, int defQty,
	int arm, double s, double ms, bool ach, std::string n)
{
	attackNum = attNum;
	attackQty = attQty;
	defenseNum = defNum;
	defenseQty = defQty;
	armor = arm;
	strength = s;
	maxStrength = ms;
	achilles = ach;
	name = n;
	totalPts = 0;
}

/*************************************************************************
** Function: addStrength
** Description: This function adds strength to the Character.
** Parameters: 1 int
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
void Character::addStrength(double st)
{
	strength += st;

	if (strength > maxStrength)
	{
		strength = maxStrength;
	}
}

/*************************************************************************
** Function: addTotalPts
** Description: This function adds to the totalPts variable for the
**   Character.
** Parameters: 1 double
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
void Character::addTotalPts(double t)
{
	totalPts += t;
}

/*************************************************************************
** Function: setAchilles
** Description: This function sets the achilles variable for the
**   Character.
** Parameters: 1 bool
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
void Character::setAchilles(bool a)
{
	achilles = a;
}

/*************************************************************************
** Function: getDefenseNum
** Description: This function retrieves the defenseNum variable for the
**    Character.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Character::getDefenseNum()
{
	return defenseNum;
}

/*************************************************************************
** Function: getDefenseQty
** Description: This function retrieves the defenseQty variable for the
**   Character.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Character::getDefenseQty()
{
	return defenseQty;
}

/*************************************************************************
** Function: getArmor
** Description: This function retrieves the armor variable for the
**   Character.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
int Character::getArmor()
{
	return armor;
}

/*************************************************************************
** Function: getStrength
** Description: This function retrieves the strength variable for the
**   Character.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
double Character::getStrength()
{
	return strength;
}

/*************************************************************************
** Function: getMaxStrength
** Description: This function retrieves the maxStrength variable for the
**   Character.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
double Character::getMaxStrength()
{
	return maxStrength;
}

/*************************************************************************
** Function: getTotalPts
** Description: This function retrieves the totalPts variable for the
**   Character.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
double Character::getTotalPts()
{
	return totalPts;
}

/*************************************************************************
** Function: getAchilles
** Description: This function retrieves the achilles variables for the
**    Character.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
bool Character::getAchilles()
{
	return achilles;
}

/*************************************************************************
** Function: getName
** Description: This function retrieves the name variables for the
**    Character.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*************************************************************************/
std::string Character::getName()
{
	return name;
}
