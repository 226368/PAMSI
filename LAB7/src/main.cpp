
#include <iostream>
#include "hash.hh"
using namespace std;

int main()
{

	Hash *object = new Hash;

	object->measureTime();


	delete object;

	return 0;
}
