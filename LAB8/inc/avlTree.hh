#ifndef AVLTREE_HH
#define AVLTREE_HH

#include <iostream>
#include <cstdlib>
#include "stoper.hh"
#include "iAvlTree.hh"

using namespace std;

class Node {

public:

  int data;

  Node* leftChild;
  Node* rightChild;

  int height;

};

class avlTree: public Node, public iAvlTree {

  Node* root;

  Node* insert(Node* object, int value);
  Node* remove(Node* object, int value);
  Node* search(Node* object, int value);

  // ROTACJE ELEMENTOW DRZEWA
  Node* doubleRightRotate(Node* &object);
  Node* doubleLeftRotate(Node* &object);
  Node* rightRotate(Node* &object);
  Node* leftRotate(Node* &object);

  Node* findMin(Node* object);
  Node* findMax(Node* object);
  Node* makeEmpty(Node* object);


  int height(Node* object);
  int getBalance(Node* object);
  int sizeofTree(Node* object);

  void inorder(Node* object);

public:

  avlTree();
  ~avlTree();


  /*
    Funkcje które uruchamiają te funkcje w części prywatnej
  */
  void insert(int value);
  void remove(int value);
  void search(int value);
  void display();

  /*
    Zarządzanie drzewem
  */
  void enlarge(int value);
  void makeEmpty();
  void measureTime();
  void sizeofTree();

};




#endif
