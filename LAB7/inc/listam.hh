#ifndef LISTAM_HH
#define LISTAM_HH

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Lista {
private:

	int count = 0;    // zlicza elementy na liscie, poczatkowa wartosc 0, przy kazdym dodatniu elementu do listy count++
	int element;      // zmienna przechowujaca wartosc elementu
	Lista *next;	  // wskaznik do następnego elementu listy, służy do wiązania elementów w liste
	Lista *head;    // wskazniki na poczatek listy

public:
	Lista();          // konstruktor inicjalizujacy wskaznik next na null , wartosc info nieokreslona
	Lista(int i,Lista *in); //drugi konstruktor gdy uzytkownik poda wartosc elementu

	int getElement(int number);
	int getNext();

	void pushFront(int);

	int deleteFront();
	int deleteElement(int number);
	int sum();
	void printAll();
	void deleteAll();
	virtual ~Lista();
};

#endif
