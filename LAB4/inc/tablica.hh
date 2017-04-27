
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "stoper.hh"
//#include "zbior_danych.hh"
#include "iTablica.hh"
#include "iStoper.hh"

using namespace std;



class Tablica : public iTablica {

private:
	void zmniejsz_tab(unsigned int n_rozm);				    //tworzenie nowej tab, kopiowanie el.
	void powieksz_tab(unsigned int n_rozm);				    //tworzenie nowej, kopiowaniem, wypełnianie liczbami losowymi od 0 do 10


	int *tablica;
	unsigned int rozmiar = 2;


public:

	Tablica()
	{
		tablica = new int[rozmiar];
		for(unsigned int i=0;i<rozmiar;i++)
		{
			*(tablica+i)=i;
		}
	}

	~Tablica()
	{
		delete [] tablica;
	}

	virtual void wyswietl();
	virtual void zmien_rozmiar();						//zarządza zmiana rozmiaru
	virtual void measureTime();
	void zwiekszanie_tablicy(unsigned int nowy_rozmiar,int wybrana_metoda);		//wybiera jakie ma byc zwiekszanie tablicy czy o 1, czy 2x
	void zmniejszanie_tablicy(unsigned int nowy_rozmiar);  //j.w tylko zmniejszanie
	void powieksz_operacja_pom(unsigned int nowy_rozmiar,unsigned int &temp_rozm);
	void zmniejsz_operacja_pom(unsigned int nowy_rozmiar,unsigned int &temp_rozm);
	void resetTablicy();
	virtual int sizeTab();


};
