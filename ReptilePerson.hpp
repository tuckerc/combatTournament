/*************************************************************************
** Program Filename: ReptilePerson.hpp
** Author: Chase Tucker
** Date: 7/23/15
** Description: This file provides the interface for the ReptilePerson
**   class.
** Input: none
** Output: none
*************************************************************************/

#ifndef REPTILEPERSON_HPP
#define REPTILEPERSON_HPP

#include "Character.hpp"
#include <string>

class ReptilePerson : public Character
{
public:
	ReptilePerson();
	virtual int attack(Character*);
	virtual int defend();
};

#endif
