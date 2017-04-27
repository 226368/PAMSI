
#include "Stack.hh"


Stack::Stack()
{
  size = 2;
  sArray = new int [size];
  stackPtr = 0;
}

Stack::~Stack()
{
  delete [] sArray;
}

int Stack::sizeStack()
{
  return stackPtr;
}

void Stack::powStos()
{
  int temp = size*2;
  int *ptr = new int[temp];

  memcpy(ptr,sArray,sizeof(int)*size);

  delete [] sArray;
  sArray = ptr;

  size = temp;
//  cout<< endl << "size jest równy: " << size << endl << endl << endl;

}

void Stack::pushElements(unsigned int volume)
{
  for(unsigned int i =0;i<volume;++i)
  {
    push(rand() % 10);
  }
}

int Stack::top()
{
  if(stackPtr)
  {
    return sArray[stackPtr-1];
  }
  //return -MAXINT
}

void Stack::push(const int value)
{
 if(stackPtr < size )
  {
    sArray[stackPtr++] = value;
  }
 else
  {
    powStos();
    sArray[stackPtr++] = value;
  }
}

void Stack::pop()
{
  if(stackPtr)
  {
    stackPtr--;
  }
}

bool Stack::isEmpty()
{
  return !stackPtr;
}

void Stack::changeSize()
{
   int tmp_size;
   cout << "żądany rozmiar stosu to: " << endl;
   cin >> tmp_size;
   cout << endl << endl;

   pushElements(tmp_size);
}

void Stack::resetStack()
{
  while(!isEmpty())
  {
    pop();
  }
}

void Stack::measureTime()
{
  unsigned long int size;
  unsigned int quantity;
  stoper pomiar;

  cout << "żądana liczba elementów stosu to: \n";
  cout <<"Zalecane rozmiary: 16, 128, 1024, 16384, 131072, 1048576 \n";
  cin >> size;
  cout << endl << endl;
  cout  << "ile chcesz wykonać pomiarów ? ";
  cin >> quantity;
  cout << endl << endl;

  for(unsigned int i=0;i<quantity;++i)
  {
    resetStack();
    //printList();
    pomiar.startPomiar();
    pushElements(size);
    pomiar.koniecPomiar();
    resetStack();
    //printList();
  }
}
