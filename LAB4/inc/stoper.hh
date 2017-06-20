
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "iStoper.hh"
#pragma once

using namespace std;

class stoper: public iStoper{

	clock_t start;
	clock_t koniec;
	double *ptr;										// wskaźnik do tablicy dynamicznej przechowującej czasy pomiaru
	int     size = 0;								// obecny rozmiar tablicy dynamicznej

public:

	stoper();
	~stoper();

	virtual void startPomiar();
	virtual void koniecPomiar();

};
