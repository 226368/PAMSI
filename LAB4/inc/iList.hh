#ifndef ILIST_HH
#define ILIST_HH

/*#include "MeasureAble.hh"*/

class iList/*: public MeasureAble*/ {

	int *next;
	int data;

public:

	virtual int  size(int *ptr) = 0;
	virtual void push_front(int value) = 0;
	virtual void pop_front() = 0;
	virtual bool isEmpty() = 0;

};

#endif
