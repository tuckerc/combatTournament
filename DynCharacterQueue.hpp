/**************************************************************************
** Program Filename: DynCharacterQueue.hpp
** Author: Chase Tucker, Tony Gaddis, Judy Waters, Godfrey Muganda (See
**   reference below)
** Creation Date: 7/23/15 // Last Update: 10/1/19
** Description: This file provides the interface for the DynCharacterQueue
**   class. The code in Starting out with C++ : early objects was used to
**   develop this queue interface.
** Input: none
** Output: none
** Reference: Gaddis, T., Walters, J., & Muganda, G. (2014). Stacks and
**   Queues. In Starting out with C : Early objects
**   (8th ed., pp. 1077-1093). Boston, Massachusetts: Pearson
**   Addison-Wesley.
**************************************************************************/

#ifndef DynCharacterQueue_HPP
#define DynCharacterQueue_HPP

#include "Character.hpp"

class DynCharacterQueue
{
private:
	class QueueNode
	{
		friend class DynCharacterQueue;
		Character* ch;
		QueueNode* next;
		QueueNode(Character* c, QueueNode* n = 0)
		{
			ch = c;
			next = n;
		}
	};
	QueueNode* front; //QueueNode to track front of queue
	QueueNode* back; //QueueNode to track back of queue
public:
	DynCharacterQueue();
	~DynCharacterQueue();
	void addBack(Character*);
	Character* getFront();
	void removeFront();
	void clear();
	bool isEmpty() const;
};
#endif