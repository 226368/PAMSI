#include "Stack.hh"

Stack::Stack()
{
  size = 10;
  sArray = new int [size];
  stackPtr = 0;
}

Stack::~Stack()
{
  delete [] sArray;
}

int Stack::top()
{
  if(stackPtr)
  {
    return sArray[stackPtr-1];
  }
  // return -MAXINT
}

void Stack::push(const int value)
{
  if(stackPtr < size )
  {
    sArray[stackPtr++] = value;
  }
}

int Stack::pop()
{
  int temp_value;
  if(stackPtr)
  {
    temp_value = sArray[stackPtr];
    stackPtr--;
  }
}

bool Stack::isEmpty()
{
  return !stackPtr;
}

/*(void changeSize()
{

}*/
