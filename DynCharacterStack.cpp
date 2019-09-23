/**************************************************************************
** Program Filename: DynCharacterStack.cpp
** Author: Chase Tucker, Tony Gaddis, Judy Waters, Godfrey Muganda (See
**   reference below)
** Date: 7/26/15
** Description: This file provides the implementation for the DynCharacterStack
**   class. The code in Starting out with C++ : early objects was used to
**   develop this stack implementation.
** Input: none
** Output: none
** Reference: Gaddis, T., Walters, J., & Muganda, G. (2014). Stacks and
**   Queues. In Starting out with C : Early objects
**   (8th ed., pp. 1077-1093). Boston, Massachusetts: Pearson
**   Addison-Wesley.
**************************************************************************/

#include "DynCharacterStack.hpp"
#include <iostream>

/**************************************************************************
** Function: push
** Description: This function adds an integer to the top of the stack.
** Parameters: one integer
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
void DynCharacterStack::push(Character* ch)
{
	top = new StackNode(ch, top);
}

/**************************************************************************
** Function: peek
** Description: This function retrieves the value of the top StackNode
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
Character* DynCharacterStack::peek()
{
	return top->ch;
}

/**************************************************************************
** Function: pop
** Description: This function removes the top StackNode from the stack.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
void DynCharacterStack::pop()
{
	StackNode* temp = top;
	top = top->next;
	delete temp;
}

/**************************************************************************
** Function: isEmpty
** Description: This function tests if the stack is empty.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
bool DynCharacterStack::isEmpty() const
{
	if (!top) return true;
	else return false;
}