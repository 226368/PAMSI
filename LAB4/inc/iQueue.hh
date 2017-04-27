#ifndef IQUEUE_HH
#define IQUEUE_HH

//#include "MeasureAble.hh"

class iQueue/*: public MeasureAble */{

public:

	//virtual int  size() = 0;
	virtual void enqueue(const int value) = 0;
	virtual int  dequeue() = 0;
	virtual bool isEmpty()= 0;
	virtual int  front() = 0;

};

#endif
