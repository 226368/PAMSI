#ifndef ISTACK_HH
#define ISTACK_HH

#include "MeasureAble.hh"

class iStack/*: public MeasureAble */{

public:

	virtual int  	top() =0;
	virtual void 	push(const int value) =0;
	virtual void 	pop() =0;
	virtual bool 	isEmpty()=0;
	virtual int  	sizeStack() = 0;
	virtual void 	changeSize() =0;
	virtual void 	resetStack() = 0;
	virtual void 	measureTime() = 0;

};

#endif
