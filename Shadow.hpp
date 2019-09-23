/*************************************************************************
** Program Filename: Shadow.hpp
** Author: Chase Tucker
** Date: 7/23/15
** Description: This file contains the interface for the Shadow class.
** Input: none
** Output: none
*************************************************************************/

#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "Character.hpp"
#include <string>

class Shadow : public Character
{
public:
	Shadow();
	virtual int attack(Character*);
	virtual int defend();
};

#endif
