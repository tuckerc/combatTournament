/**************************************************************************
** Program Filename: DynCharacterStack.hpp
** Author: Chase Tucker, Tony Gaddis, Judy Waters, Godfrey Muganda (See
**   reference below)
** Date: 7/26/15
** Description: This file provides the interface for the DynCharacterStack
**   class. The code in Starting out with C++ : early objects was used to 
**   develop this stack interface.
** Input: none
** Output: none
** Reference: Gaddis, T., Walters, J., & Muganda, G. (2014). Stacks and 
**   Queues. In Starting out with C : Early objects 
**   (8th ed., pp. 1077-1093). Boston, Massachusetts: Pearson 
**   Addison-Wesley.
**************************************************************************/

#ifndef DynCharacterStack_HPP
#define DynCharacterStack_HPP

#include "Character.hpp"

class DynCharacterStack
{
private:
	class StackNode
	{
		friend class DynCharacterStack;
		Character* ch;
		StackNode* next;
		StackNode(Character* c, StackNode* n = 0)
		{
			ch = c;
			next = n;
		}
	};
	StackNode* top;
public:
	DynCharacterStack() { top = 0; }
	void push(Character*);
	Character* peek();
	void pop();
	bool isEmpty() const;
};
#endif