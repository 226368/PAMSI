#ifndef LIST_HH
#define LIST_HH

#include "iList.hh"
#include "stoper.hh"
#include <iostream>


class listH {

public:

	listH * next;
	int data;

};

class List: public iList{

	listH *head;

public:

	List();

	~List();


	virtual unsigned int size();

	virtual void  pushFront(int value);
	virtual void  pushBack(int value);
	virtual void  pushBefore(listH *ptr,int value);

	virtual void  popBack();
	virtual void 	popFront();

	virtual void 	printList();

	virtual void 	remove(listH *ptr);
	virtual void 	resetList();   																		//usuwa wszystkie elementy listy
	virtual void 	addElem(unsigned long int sizeList);							//powiększa liste do zadanego rozmiaru
	virtual void  measureTime();
};

#endif
