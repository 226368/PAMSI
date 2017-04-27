#ifndef QUEUE_HH
#define QUEUE_HH

#include "iQueue.hh"

class Queue: public iQueue {

	int size;
	int counter,queuePtr;
	int *qArray;

public:

	Queue();

	~Queue();

	//virtual int  size();
	virtual void enqueue(const int value);
	virtual int  dequeue();
	virtual bool isEmpty();
	virtual int  front();


};

#endif
