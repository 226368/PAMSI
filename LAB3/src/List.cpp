#include "List.hh"

int List::size()
{
  List *ptr;
  unsigned int counter = 0;
  ptr = start;

  while(ptr)
  {
    counter++;
    ptr = ptr -> next;
  }
  return counter;
}

/*bool List::isEmpty()
{

}*/

void List::pushFront(int value)
{
  List *ptr = new List;
  ptr -> data  = value;
  ptr -> next  = start;
  start = ptr;
}


void List::popFront(unsigned int position)
{
  List *ptr;
  ptr = start;
  if(ptr!=NULL)
  {
    start = ptr -> next;
    delete ptr;
  }
}

void List::pushBack(int value)
{
  List *ptr, *temp;
  temp = new List;          //służy jako zmnienna tymczasowa
  temp -> next = NULL;      //trzyma wartość i wskaźnik
  temp -> data = value;
  ptr = start;

  if(ptr!=NULL)
  {
    while(ptr->next)
    {
      ptr = ptr -> next;    //szukanie końca listy
    }
    ptr -> next = temp;     //wstawianie ostatniego wskaźnika
  }
  else
  {
    start = temp;   //jeśli lista była pusta
  }
}

void List::popBack()
{
  List *ptr = new List;
  if(ptr!=NULL)
  {
    if(ptr -> next)            //gdy mamy więcej niż jeden element na liście
    {
      while(ptr->next->next)   //szukanie przedostatniego elementu listy
      {
        ptr = ptr -> next;
      }
      delete ptr -> next;       // usuwanie ostatniego
      ptr -> next = NULL;       // nowy koniec listy
    }
    else
    {
      delete ptr;
      start = NULL;
    }
  }
}

void List::push(List *ptr, int value)
{
  skladnik * p = start;

  if(p == ptr)
  {
    pushFront(value); //zwykłe dodawnie na początku
  }
  else
  {
    while(p->next != ptr) p = p->next; //szukamy t
    p -> next =  new skladnik;
    p -> next -> next = ptr;
    p -> next -> data = value;
  }
}

List::List()
{

}

List::~List()
{

}
