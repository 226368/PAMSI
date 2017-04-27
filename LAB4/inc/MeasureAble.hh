#ifndef MEASUREABLE_HH
#define MEASUREABLE_HH

class MeasureAble {

  public:

  virtual void zmien_rozmiar() = 0;
  virtual void wyswietl() = 0;
  virtual void measureTime() = 0;
  virtual int sizeTab()=0;

};


#endif
