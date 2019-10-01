/*************************************************************************
** Program Filename: BlueMan.hpp
** Author: Chase Tucker
** Creation Date: 7/23/15 // Last Update: 10/1/19
** Description: This file provides the interface for the BlueMan class.
** Input: none
** Output: none
*************************************************************************/

#ifndef BLUEMAN_HPP
#define BLUEMAN_HPP

#include "Character.hpp"
#include <string>

class BlueMan : public Character
{
public:
	BlueMan();
	virtual int attack(Character*);
	virtual int defend();
};

#endif
