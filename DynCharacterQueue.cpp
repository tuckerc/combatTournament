/**************************************************************************
** Program Filename: DynCharacterQueue.cpp
** Author: Chase Tucker, Tony Gaddis, Judy Waters, Godfrey Muganda (See
**   reference below)
** Creation Date: 7/23/15 // Last Update: 10/1/19
** Description: This file provides the implementation for the
**   DynCharacterQueue class. The code in Starting out with C++ : early 
**   objects was used to develop this queue implementation.
** Input: none
** Output: none
** Reference: Gaddis, T., Walters, J., & Muganda, G. (2014). Stacks and
**   Queues. In Starting out with C : Early objects
**   (8th ed., pp. 1077-1093). Boston, Massachusetts: Pearson
**   Addison-Wesley.
**************************************************************************/

#include "DynCharacterQueue.hpp"
#include <iostream>

/**************************************************************************
** Function: DynCharacterQueue
** Description: This function is a constructor for the queue.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
DynCharacterQueue::DynCharacterQueue()
{
	front = NULL;
	back = NULL;
}

/**************************************************************************
** Function: ~DynCharacterQueue
** Description: This function is a destructor for the queue.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
DynCharacterQueue::~DynCharacterQueue()
{
	clear();
}

/**************************************************************************
** Function: addBack
** Description: This function adds a QueueNode to the back of the queue.
** Parameters: one integer
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
void DynCharacterQueue::addBack(Character* ch)
{
	if (isEmpty())
	{
		front = new QueueNode(ch);
		back = front;
	}
	else
	{
		back->next = new QueueNode(ch);
		back = back->next;
	}
}

/**************************************************************************
** Function: getFront
** Description: This function returns the value of the front QueueNode.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
Character* DynCharacterQueue::getFront()
{
	return front->ch;
}

/**************************************************************************
** Function: removeFront
** Description: This function removes the front QueueNode.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
void DynCharacterQueue::removeFront()
{
	QueueNode* temp = front;
	front = front->next;
	delete temp;
}

/**************************************************************************
** Function: clear
** Description: This function clears the queue.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
void DynCharacterQueue::clear()
{
	while (!isEmpty())
	{
		removeFront();
	}
}

/**************************************************************************
** Function: isEmpty
** Description: This function tests if queue is empty.
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
**************************************************************************/
bool DynCharacterQueue::isEmpty() const
{
	if (front == NULL)
	{
		return true;
	}
	else return false;
}