
#include <iostream>

#include "hash.hh"

using namespace std;

int* data;
int rozmiar = 13; //rozmiar tablicy

int main() {


Hash *object = new Hash;

object -> measureTime();

 

delete object;
	return 0;



}
