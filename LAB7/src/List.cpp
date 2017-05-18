#include "List.hh"

using namespace std;

List::List()
{
  head = nullptr;
}



unsigned int List::size()
{
  unsigned int counter = 0;
  listH *ptr = head;

  while(ptr)
  {
    counter++;
    ptr = ptr -> next;
  }
  return counter;
}

void List::pushFront(int value)
{
  listH *ptr = new listH;
  ptr -> next  = head;
  ptr -> data  = value;
  head = ptr;
}

void List::pushBack(int value)
{
  listH *ptr, *ptr_2;
  ptr_2 = new listH;          //służy jako zmnienna tymczasowa
  ptr_2 -> next = nullptr;      //trzyma wartość i wskaźnik
  ptr_2 -> data = value;
  ptr = head;

  if(ptr!=nullptr)
  {
    while(ptr->next)
    {
      ptr = ptr -> next;    //szukanie końca listy
    }
    ptr -> next = ptr_2;     //wstawianie ostatniego wskaźnika
  }
  else
  {
    head = ptr_2;   //jeśli lista była pusta
  }
}

void List::pushBefore(listH *ptr, int value)
{
  listH * wsk = head;

  if(wsk == ptr)
  {
    pushFront(value); //zwykłe dodawnie na początku
  }
  else
  {
    while(wsk->next != ptr) wsk = wsk->next; //szukamy t
    wsk -> next =  new listH;
    wsk -> next -> next = ptr;
    wsk -> next -> data = value;
  }
}

void List::popFront()
{
  listH *ptr = head;
  if(ptr!=nullptr)
  {
    head  = ptr -> next;
    delete ptr;
  }
}

void List::popBack()
{
  listH *ptr = head;
  if(ptr!=nullptr)
  {
    if(ptr -> next)            //gdy mamy więcej niż jeden element na liście
    {
      while(ptr->next->next)   //szukanie przedostatniego elementu listy
      {
        ptr = ptr -> next;
      }
      delete ptr -> next;       // usuwanie ostatniego
      ptr -> next = nullptr;       // nowy koniec listy
    }
    else
    {
      delete ptr;
      head = nullptr;
    }
  }
}

void List::remove(listH *ptr)
{

}

void List::printList()
{
  listH *ptr = head;
  cout << "Lista składa się z: " << size() << "elementów" << endl << endl;
  for(unsigned int i=1;ptr;ptr  = ptr->next)
  {
    cout << "Element #" << i++ << "  = " << ptr->data <<endl;
  }
  cout << endl << endl;
}


List::~List()
{
  while(head)
  {
    popFront();
  }
}

void List::addElem(unsigned long int sizeList)
{
  unsigned long int i=0;
  while(i<sizeList)
  {
    pushFront(i);
    //cout << "dodaje element: #" << i << endl;
    ++i;
  }
  //printList();
}

void List::resetList()
{
  unsigned long int i,sizea=size();

  for(i =0;i<sizea;++i)
    {
      //listH *ptr = head;
      //while(ptr)
      {
        popFront();
        //ptr = ptr -> next;
      }
    }
}

void List::measureTime()
{
    unsigned long int sizeList;
    unsigned int quantity;
    stoper pomiar;

    cout << "żądana liczba elementów listy to:";
    cin >> sizeList;
    cout << endl << endl;
    cout  << "ile chcesz wykonać pomiarów ? ";
    cin >> quantity;
    cout << endl << endl;

    for(unsigned int i=0;i<quantity;++i)
    {
      pomiar.startPomiar();
      addElem(sizeList);
      pomiar.koniecPomiar();
      //printList();
      resetList();
      //cout << "Lista składa się z: " << size() << "elementów" << endl << endl;

    }
}
