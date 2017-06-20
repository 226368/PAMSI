#include "Queue.hh"

void Queue::addElement(int v)
{
  int temp = queuePtr + counter++;
  if(temp >= size)
  {
    temp -= size;
  }
  qArray[temp] = v;
}
void Queue::enlargeQueue()
{
  int temp = size*2;
  int *ptr = new int[temp];

  memcpy(ptr,qArray,sizeof(int)*size);

  delete [] qArray;
  qArray = ptr;

  size = temp;
//  cout<< endl << "size jest równy: " << size << endl << endl << endl;

}

void Queue::enqueueElements(unsigned int volume)
{
  for(unsigned int i =0;i<volume;++i)
  {
    enqueue(rand() % 100);
  }
}

int Queue::sizeQueue()
{
  return queuePtr;
}

void Queue::resetQueue()
{
  while(!isEmpty())
  {
    dequeue();
  }
}

void Queue::enqueue(const int value)
{

  if(counter < size)
  {
    addElement(value);
  }
  else
  {
    enlargeQueue();
    addElement(value);
  }
}

void Queue::dequeue()
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
  //return -MAXINT;
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

void Queue::measureTime()
{
  unsigned long int size;
  unsigned int quantity;
  stoper pomiar;

  cout << "żądana liczba elementów kolejki to: \n";
  cout <<"Zalecane rozmiary: 16, 128, 1024, 16384, 131072, 1048576 \n";
  cin >> size;
  cout << endl << endl;
  cout  << "ile chcesz wykonać pomiarów ? ";
  cin >> quantity;
  cout << endl << endl;

  for(unsigned int i=0;i<quantity;++i)
  {
    resetQueue();
    //printList();
    pomiar.startPomiar();
    enqueueElements(size);
    pomiar.koniecPomiar();
    resetQueue();
    //printList();
  }
}
