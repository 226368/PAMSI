#include "BinaryTree.hh"

BinaryTree::BinaryTree()
{
  root = nullptr;
}

BinaryTree::~BinaryTree()
{
   makeEmpty();
}

void BinaryTree::inorder(Node* object)
{
  if( object == nullptr)
  {
    return;
  }

  inorder( object -> leftChild);

  cout << object -> data << " ";

  inorder( object -> rightChild);
}

Node* BinaryTree::makeEmpty(Node* object)
{
  if(object == nullptr)
  {
    return nullptr;
  }

  else
  {
    makeEmpty(object -> leftChild);
    makeEmpty(object -> rightChild);

    delete object;
  }

  return nullptr;
}

Node*  BinaryTree::findMin(Node* object)
{
  if( object == nullptr)
  {
    return nullptr;
  }

  else if( object -> leftChild == nullptr)
  {
    return object;
  }

  else
  {
    return findMin(object -> leftChild);
  }
}

Node*  BinaryTree::findMax(Node* object)
{
  if( object == nullptr)
  {
    return nullptr;
  }

  else if( object -> rightChild == nullptr)
  {
    return object;
  }

  else
  {
    return findMax(object -> rightChild);
  }
}


Node*  BinaryTree::search(Node* object, int value)
{
  if( object == nullptr)
  {
    return nullptr;
  }

  else if( value < object -> data)
  {
    return search( object -> leftChild, value);
  }

  else if( value > object -> data)
  {
    return search( object -> rightChild, value);
  }

  else
  {
    return object;
  }
}

Node*  BinaryTree::insert(Node* object, int value)
{

  if( value < object -> data)
  {
    if(object->leftChild != nullptr)
    {
      insert( object -> leftChild, value);
    }
    else
    {
      object -> leftChild = new Node;
      object -> leftChild -> data = value;
      object -> leftChild -> leftChild = nullptr;
      object -> leftChild -> rightChild = nullptr;
    }
  }

  else if(value >= object -> data)
  {
    if(object->rightChild != nullptr)
    {
      insert( object -> rightChild, value);
    }
    else
    {
      object -> rightChild = new Node;
      object -> rightChild -> data = value;
      object -> rightChild -> rightChild = nullptr;
      object -> rightChild -> leftChild = nullptr;
    }
  }
  return object;

}

Node*  BinaryTree::remove(Node* object, int value)
{
  Node *pointer;

  if( object == nullptr)
  {
    return nullptr;
  }

  else if( value < object -> data)
  {
    object -> leftChild = remove( object -> leftChild, value );
  }

  else if( value > object -> data)
  {
    object -> rightChild = remove( object -> rightChild, value );
  }

  else if( object -> leftChild && object -> rightChild)
  {
    pointer = findMin( object -> rightChild);
    object -> data = pointer -> data;
    object -> rightChild = remove(object -> rightChild, object -> data);
  }

  else
  {
    pointer = object;
    if( object -> leftChild == nullptr)
    {
      object = object -> rightChild;
    }

    else if ( object -> rightChild == nullptr)
    {
      object = object -> leftChild;
    }

    delete pointer;
  }

  return object;

}

int BinaryTree::sizeofTree(Node* object)
{
  //int sizeTree = 0;

  if(object == nullptr)
  {
    return 0;
  }

  else
  {
    return(sizeofTree(object -> leftChild) + 1 + sizeofTree(object -> rightChild));
  }
}

void BinaryTree::insert(int value)
{
  if(root != nullptr)
  {
    root = insert(root, value);
  }
  else
  {
    root = new Node;
    root -> data = value;
    root -> leftChild = nullptr;
    root -> rightChild = nullptr;
  }
}

void BinaryTree::remove(int value)
{
  root = remove(root, value);
}

void BinaryTree::search(int value)
{
  root = search(root, value);
}

void BinaryTree::display()
{
  inorder(root);
  cout << endl;
}

void BinaryTree::enlarge(int value)
{
  for(int i = 0; i < value; ++i)
  {
    insert(i);
  }
}

void BinaryTree::makeEmpty()
{
   root = makeEmpty(root);
}

void BinaryTree::sizeofTree()
{
  cout << "rozmiar drzewa to: " << sizeofTree(root) << endl;
}

void BinaryTree::measureTime()
{
  srand(time(NULL));


  int sizeTree, quantity;
  stoper pomiar;

  cout << "Jaki chcesz miec rozmiar drzewa ? " << endl;
  cin >> sizeTree;
  cout << "ile chcesz dokonać pomiarów ? " << endl;
  cin >> quantity;


  sizeofTree();
  makeEmpty();
  enlarge(sizeTree);
  sizeofTree();

for(int i=0;i<10;++i)
{
  pomiar.startPomiar();

  for(int i=0;i<quantity;++i)
  {
    search( rand() % sizeTree);
  }

  pomiar.koniecPomiar();
}

  makeEmpty();
  sizeofTree();
}
