#ifndef HASH_HH
#define HASH_HH

#include <string.h>
#include <iostream>
#include "listam.hh"
#include "stoper.hh"



class Hash {

  Lista* tab;
  int* dane;       //
  int *array;      // przechowuje losowe klucze

  int licznikKlucz = 0;
  int sizeTab;


public:


  Hash();
  ~Hash();

  //FUNKCJE HASZUJĄCE
  //
  //hash(int)    - haszowanie modularne
  //hashSec(int) - haszowanie przez mnożenie
  int   hash(const int value);
  int   hashSec(const int value);


  //Rozwiazanie kolizji przez linkowanie
  void addLink();
  void searchLink();
  void deleteLink();

  //  Funkcje pomocnicze, które ułatwiają działanie programu
  void fillKeys();
  int sizeOfTab();
  void measureTime();
  void setSize();
  bool liczba_pierwsza(int value);
  void losowanieKluczy(int size);


  // Funkcje gotowe do użycia wtedy kiedy chcemy aby klucze były
  // przygotowywane na bazie słów (zastosowanie: słownik)
  string stringGenerator();
  int   changeString(string key);



};



#endif
