/*************************************************************************
** Program Filename: Character.hpp
** Author: Chase Tucker
** Creation Date: 7/23/15 // Last Update: 10/1/19
** Description: This file provides the interface for the Character class.
** Input: none
** Output: none
*************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character
{
protected:
	int attackNum, attackQty, defenseNum, defenseQty, armor;
	double strength, maxStrength, totalPts;
	bool achilles;
	std::string name;

public:
	Character(int, int, int, int, int, double, double, bool, 
		std::string);
	void addStrength(double);
	void addTotalPts(double);
	void setAchilles(bool);
	int getDefenseNum();
	int getDefenseQty();
	int getArmor();
	double getStrength();
	double getMaxStrength();
	double getTotalPts();
	bool getAchilles();
	std::string getName();
	virtual int attack(Character*) = 0;
	virtual int defend() = 0;
};

#endif
