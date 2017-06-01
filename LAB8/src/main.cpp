#include <iostream>
#include "BinaryTree.hh"

int main()
{

  BinaryTree* ptr = new BinaryTree;

  ptr -> measureTime();

  delete ptr;

  return 0;
}
