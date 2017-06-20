#ifndef STACK_HH
#define STACK_HH

#include "iStack.hh"
#include "MeasureAble.hh"
#include <string.h>
#include "stoper.hh"
#include <iostream>
using namespace std;

class Stack: public iStack{

	int size;					//rozmiar stosu
	int stackPtr;			//wskaźnik na gorny element stosu
	int* sArray; 				//tablica

	void powStos();																//gdy stos jest pełny powiększa go
	void pushElements(unsigned int volume);       //funkcja która dodaje do stosu wiele elementów
	//void resetStack();													//usuwa wszystkie elementy stosu

public:

	Stack();
	virtual ~Stack();


	virtual int  top();
	virtual void push(const int value);
	virtual void pop();
	virtual bool isEmpty();
	virtual int  sizeStack();
	virtual void changeSize();
	virtual void resetStack();
	virtual void measureTime();



};


#endif
