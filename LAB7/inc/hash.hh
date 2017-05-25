#ifndef HASH_HH
#define HASH_HH

#include <string.h>
#include <iostream>
#include "listam.hh"
#include "stoper.hh"



class Hash {

  static const int sizeTab = 5;
  lista** tab;
  int dane[sizeTab];
  string *klucze[sizeTab];
  int licznikKlucz = 0;

public:

  Hash();
  ~Hash();

  int   hash(const int value);
  int   hashSec(const int value);
  int   changeString(string key);
  void  addLink(int x);
  int   deleteLink(int x);

  bool wyszukaj_linkowanie(int x); //wyszukiwanie przez linkowanie


  void dodaj_probkowanie(int x);
  bool wyszukaj_probkowanie(int x);
  int usun_probkowanie(int x);

  int sizeOfTab();

  void generujTab();
  string stringGenerator();
  void measureTime();



};



#endif
