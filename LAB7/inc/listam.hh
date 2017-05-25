#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class wezel {

public:

  int nazwa;
  wezel *next = nullptr;

};


class lista: public wezel {

  int length;

  wezel *head;
  wezel *tail;


public:

  lista();

  void pushFront(int nazwa);
  int pop(int x);
  int searchElem(int x);
  int returnFirst();


};
