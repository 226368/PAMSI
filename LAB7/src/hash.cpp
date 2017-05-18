#include "hash.hh"


Hash::Hash(int sizeTab)
{
  tab = new List*[sizeTab];
  for(int i=0;i<sizeTab;++i)
  {
    *(tab+i) = nullptr;
  }
}


Hash::~Hash()
{
  delete[] tab;
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

void Hash::addLink(int x)
{
  int index = hash(x);
  if(tab[index] == nullptr)
  {
    tab[index] = new List;
  }

  tab[index] -> pushFront(x);
}

int Hash::deleteLink(int x)
{

}
