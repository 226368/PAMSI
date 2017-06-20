#ifndef QUEUE_HH
#define QUEUE_HH

#include "iQueue.hh"
#include "stoper.hh"
#include "MeasureAble.hh"

class Queue: public iQueue {

	int size;
	int counter,queuePtr;
	int *qArray;

public:

	Queue();

	~Queue();


	virtual void enqueue(const int value);
	virtual void  dequeue();
	virtual bool isEmpty();
	virtual int  front();
	void addElement(int v);
	void enlargeQueue();
	void enqueueElements(unsigned int volume);
	int sizeQueue();
	void resetQueue();
	virtual void measureTime();


};

#endif
