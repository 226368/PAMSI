#ifndef MEASUREABLE_HH
#define MEASUREABLE_HH

class MeasureAble {

  public:

  virtual void zmien_rozmiar() = 0;
  virtual void wyswietl() = 0;
  virtual void measureTime() = 0;
  virtual int sizeTab()=0;
  virtual void quickSort(int left,int right)=0;
  //virtual void changeSize() = 0;
  virtual void measureQuickSort() = 0;


  //       STACK
/*
  virtual int top()=0;
  virtual void push(const int value)=0;
	virtual void pop()=0;
	virtual bool isEmpty()=0;
	virtual int  sizeStack()=0;
	virtual void changeSize()=0;
	virtual void resetStack()=0;*/
};


#endif
