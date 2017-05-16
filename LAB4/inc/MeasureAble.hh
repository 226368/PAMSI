#ifndef MEASUREABLE_HH
#define MEASUREABLE_HH

class MeasureAble {

  public:

  virtual void measureTime() = 0;
  virtual void quickSort(int left,int right)=0;
  virtual void measureQuickSort() = 0;



};


#endif
