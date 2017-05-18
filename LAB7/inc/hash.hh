#ifndef HASH_HH
#define HASH_HH

#include <string.h>
#include <iostream>
#include "List.hh"
#include "stoper.hh"

class Hash {

  static const int sizeTab = 23;
  List** tab;

public:

  Hash(int sizeTab);
  ~Hash();

  int   hash(const int value);
  int   changeString(string key);
  void  addLink(int x);
  int   deleteLink(int x);

};



#endif
