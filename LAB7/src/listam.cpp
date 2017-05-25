#include "listam.hh"

lista::lista()
{
  head = nullptr;
  tail = nullptr;
  length = 0;
}

void lista::pushFront(int nazwa)
{
  wezel *nowy = new wezel;
  nowy -> nazwa = nazwa;

  if(lista::length == 0 )
  {
    head = nowy;
    tail = nowy;
    lista::length++;
  }
  else
  {
    nowy-> next = head;
    head = nowy;
    lista::length++;
  }
}

int lista::pop(int x)
{
  int value;
  wezel *tmp = head;

  if(head == nullptr)
  {
    cerr << "pusta lista!\n";
  }

  if(head -> nazwa == x )
  {
    value = tmp -> nazwa;
    head = tmp -> next;
    length--;
    return value;
  }

  while(tmp -> next->nazwa != x && tmp -> next != nullptr)
  {
    tmp = tmp -> next;
  }

  if(tmp -> next == nullptr)
  {
    value = tmp -> next -> nazwa;
    wezel *ptr = tmp -> next;
    tmp -> next = ptr -> next;
    lista::length--;
    delete ptr;
    return value;
  }

}

int lista::returnFirst()
{
  if( head == nullptr)
  {
    return 0;
  }

  else
  {
    int value;
    value = head -> nazwa;
    return value;
  }
}



int lista::searchElem(int x)
{
wezel * tmp = head;
int p=1; //zmienna p to ilosc probek
if(head==NULL){   //jesli pusto to wyswietl napis
		cerr<<"PUSTO"<<endl; p=0;
	}

while (tmp->nazwa!=x && tmp!=NULL) {   //przesuniecie elementu o jeden  dalej
            tmp=tmp->next;
            p++;}
if(tmp->nazwa!=x)
        {p=0; cerr<<"brak elementu"<<endl;}

return p;
}
