#include "Queue.hh"

void Queue::enqueue(const int value)
{
  int temp;
  if(counter < size)
  {
    temp = queuePtr + counter++;
    if(temp >= size)
    {
      temp -= size;
    }
    qArray[temp] = value;
  }
}

int Queue::dequeue()
{
  if(counter)
  {
    counter--;
    queuePtr++;
    if(queuePtr == size)
    {
      queuePtr = 0;
    }
  }
}

bool Queue::isEmpty()
{
  return !counter;
}

int Queue::front()
{
  if(counter) return qArray[queuePtr];
  // return -MAXINT
}

Queue::Queue()
{
  size = 10;
  qArray = new int[size];
  counter = queuePtr = 0;
}

Queue::~Queue()
{
  delete [] qArray;
}
