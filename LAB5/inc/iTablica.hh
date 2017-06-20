#ifndef ITABLICA_HH
#define ITABLICA_HH

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "MeasureAble.hh"

class iTablica: public MeasureAble {


  public:

  virtual void zmien_rozmiar() = 0;
  virtual void wyswietl() = 0;
  virtual void measureTime() = 0;
  virtual int sizeTab() = 0;
  virtual void quickSort(int lewy, int prawy)=0;
  virtual void measureQuickSort() = 0;
  


};



#endif
