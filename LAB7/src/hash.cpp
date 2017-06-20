#include "hash.hh"


Hash::Hash()
{
  setSize();
  tab  = new Lista[sizeTab];
  dane = new int[sizeTab];
}


Hash::~Hash()
{
  delete[] tab;
}

bool Hash::liczba_pierwsza(int value)
{
	 if(value<2)
   {
	    return false;
	 }

	 for(int i=2;i*i<=value;i++)
   {
	    if(value%i == 0) return false;
   }

	 return true;

}

void Hash::setSize()
{
  int size;
  cout << "podaj rozmiar tablicy: ";

  do
  {
		cin >> size;
	}while(liczba_pierwsza(size) == false);
  cout << "wpisałes liczbę pierwszą :)\n" << endl;
  sizeTab = size;
}

void Hash::losowanieKluczy(int size)
{
  array = new int[size];

  int tmp, index;
  bool temp;
  srand(time(NULL));

  index = 0;

  do
  {
    tmp = 1 + rand() % size;

    temp = true;
    for(int i = 0;i<index;i++)
    {
      if(array[index] == tmp)
      {
        temp = false;
        break;
      }
    }

    if(temp)
    {
      array[index++] = tmp;
    }

  } while(index < size);

}

string Hash::stringGenerator()
{

  srand(time(NULL));
  char tab[6];
  for(int j=0; j<6; j++) // duza litera
  {
      tab[j] = ((rand() %24) + 65);
  }
  string str(tab);
  return str;

}

int Hash::changeString(string key)
{
  int lenght = key.length();
  int value;

  for(int i=0;i<lenght;i++)
  {
      value += (int)key[i];
  }

  //cout << "wartość to : " << value << endl;

  return value;
}

int Hash::hash(const int value)
{
  return value % sizeTab;
}

int Hash::hashSec(const int value)
{
  int a=0.1;

  return sizeTab*(a*value % 1) ;
}


int Hash::sizeOfTab()
{
  return sizeTab;
}

void Hash::fillKeys()
{
  losowanieKluczy(sizeOfTab());
}

void Hash::addLink()
{
  int temp;

  for(int i = 0;i < sizeOfTab();++i)
  {
    temp = *(array+i);
    int index = hashSec(temp);
    tab[index].pushFront(temp);
  }
}

void Hash::searchLink()
{
  int temp;

  for(int i = 0;i < sizeOfTab();++i)
  {
    temp = *(array+i);
    int szukana = temp;
    int ind = hashSec(szukana);
    //cout << "Szukamy liczby: " << szukana << endl;
    int indListy = 1;
    //cout << tab[ind].getElement(indListy) << endl;
    while(tab[ind].getElement(ind) != szukana )
    {
      indListy++;
    }
  }
}

void Hash::deleteLink()
{
  for(int i = 0;i < sizeOfTab();++i)
  {
	  tab[hashSec(*(array+i))].deleteFront();
  }

  //tab -> printAll();
}

void Hash::measureTime()
{
  int quantity = 10; //l. pomiarów
  stoper pomiar;

  fillKeys();

  for(int i=0;i<quantity;++i)
  {
    pomiar.startPomiar();
    addLink();
    pomiar.koniecPomiar();
    deleteLink();
  }

  /*addLink();
  for(int i=0;i<quantity;++i)
  {
    pomiar.startPomiar();
    searchLink();
    pomiar.koniecPomiar();  }

  deleteLink();
*/
}
