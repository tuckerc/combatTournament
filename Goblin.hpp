/*************************************************************************
** Program Filename: Goblin.hpp
** Author: Chase Tucker
** Date: 7/23/15
** Description: This file contains the interface for the Goblin class.
** Input: none
** Output: none
*************************************************************************/

#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Character.hpp"
#include <string>

class Goblin : public Character
{
public:
	Goblin();
	~Goblin();
	virtual int attack(Character*);
	virtual int defend();
};

#endif
