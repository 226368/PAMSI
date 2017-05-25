#include "hash.hh"


Hash::Hash()
{
  tab = new lista*[sizeTab];
  for(int i=0;i<sizeTab;++i)
  {
    *(tab+i) = nullptr;
  }
}


Hash::~Hash()
{
  delete[] tab;
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

void Hash::addLink(int x)
{
  int index = hash(x);
  if(tab[index] == nullptr)
  {
    tab[index] = new lista;
  }

  tab[index] -> pushFront(x);
}

int Hash::deleteLink(int x)
{
  int index = hash(x);
  int b = tab[index] -> pop(x);
  return b;
}

bool Hash::wyszukaj_linkowanie(int x) //wyszukiwanie przez linkowanie
{
  bool zwroc_wartosc = false;
  int index = hash(x); //hashowanie
  if (tab[index]->searchElem(x)==0)
  {
    zwroc_wartosc=false;
  } //jesli nie znaleziono elementu to funkcja zwraca 0
  else
  {
    zwroc_wartosc=true;
    cout<<tab[index]->searchElem(x)<<" ";
  } // jesli znaleziono, to zwraca true oraz wypisuje ilosc probkowan
  return zwroc_wartosc;
}


void Hash::dodaj_probkowanie(int x) //dodawanie rozwiazane przez probkowanie liniowe
{

    int index = hash(x);
    int pom = index;
    int flag=0;
        while (tab[pom]!=NULL && flag<sizeTab)
        {
                pom=(pom+1)%sizeTab; //jesli element zajety, to sprawdz kolejny
                flag++;
        }
    if (tab[pom]==NULL) //jesli jest miejsce to dodaj, jesli nie to blad
    {
        tab[pom] = new lista;
        tab[pom] ->pushFront(x);
    }
    else
        cerr << "Brak miejsca w tablicy" << endl;
}


int Hash::usun_probkowanie(int x) //usuwanie przez probkowanie liniowe
{
    int element;
    int index = hash(x);
    int pom = index;
    int flag=0;
        while (tab[pom]->returnFirst()!=x && flag<sizeTab)
        {
                pom=(pom+1)%sizeTab; //jesli element nie jest rowny x to przejdz do nastepnego
                flag++;
        }

    if(tab[pom]->returnFirst() ==  x) //jesli element rowny x to usun i zwroc, jesli nie to blad
    {
    element=tab[pom]->pop(x);
    }
    else
        cerr << "brak elementu" << endl;

return element;
}

bool Hash::wyszukaj_probkowanie(int x) //wyszukiwanie przez probkowanie liniowe
{
    int index = hash(x);
    int pom = index;
        int flag=1;
        while (tab[pom]->returnFirst()!=x && flag<=sizeTab)
        {
                pom=(pom+1)%sizeTab; //jelsi element rozny od x to przejdz do nastepnego
                flag++;
        }
    if(tab[pom]->returnFirst() ==  x) //jesli element rowny x to funkca zwraca true
    {
        //cout<< flag <<" "; //wypisz ilosc probkowan
        //cout << endl;
        return true;
    }
    else
        return false;
}

int Hash::sizeOfTab()
{
  return sizeTab;
}


void Hash::generujTab()
{
  bool t; //zmienne pomocnicze do generowania liczb losowych
	int p;
	int licznik = 0;
	do      //generowanie liczb losowych bez powtorzen
	{
      string temp  = stringGenerator();

			//p =  rand() % 400; //zakres 1-40
      p = changeString(temp);

			t = true;
			for(int i = 0; i < licznik; i++)
					if(dane[i] == p) //jesli wygenerowany element rowny juz istniejacemu, to t ma wartosc false
					{
							t = false;
							break;
					}

			if(t)
      {
        dane[licznik++] = p; //jesli t pozostalo true to wpisz element p do tablicy
        //klucze[licznik++] =
      }

	} while(licznik < sizeTab); //petla do wypelnienia tablicy
}

void Hash::measureTime()
{


  generujTab();




  for (int i=0;i<sizeTab;++i)
      {
        dodaj_probkowanie(dane[i]);
      }


      for (int i=0;i<sizeTab;i++)
      {
        wyszukaj_probkowanie(dane[i]);
      }
      //cout << endl;


      for (int i=0;i<sizeTab;i++)
      {
         usun_probkowanie(dane[i]);
      }


}
