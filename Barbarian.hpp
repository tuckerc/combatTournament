/*************************************************************************
** Program Filename: Barbarian.hpp
** Author: Chase Tucker
** Creation Date: 7/23/15 // Last Update: 10/1/19
** Description: This file provides the interface for the Barbarian class.
** Input: none
** Output: none
*************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
#include <string>

class Barbarian : public Character
{
public:
	Barbarian();
	virtual int attack(Character*);
	virtual int defend();
};

#endif
