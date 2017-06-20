#ifndef  BINARYTREE_HH
#define  BINARYTREE_HH

#include <iostream>
#include <cstdlib>

#include "stoper.hh"

class Node {

public:

  int data;

  Node* leftChild;
  Node* rightChild;

};

class BinaryTree: public Node {

  Node* root;

  void inorder(Node* object);               //wyswietla elementy drzewa od najmniejszego do największego
  int sizeofTree(Node* object);             

  Node* makeEmpty(Node* object);
  Node* findMin(Node* object);
  Node* findMax(Node* object);
  Node* search(Node* object, int value);
  Node* insert(Node* object, int value);
  Node* remove(Node* object, int value);

public:

  BinaryTree();
  ~BinaryTree();

  /*
  Funkcje które uruchamiają te funkcje w części prywatnej
  */
  void insert(int value);
  void remove(int value);
  void search(int value);


  /*
  Zarządzanie drzewem
  */
  void enlarge(int value);
  void makeEmpty();
  void display();
  void measureTime();
  void sizeofTree();


};



#endif
