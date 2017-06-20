#include "avlTree.hh"

Node* avlTree::insert(Node* object, int value)
{
  if(object == nullptr)
  {
    object = new Node;
    object -> data = value;
    object -> height = 0;
    object -> leftChild = object -> rightChild = nullptr;
  }

  else if(value < object -> data)
  {
    object -> leftChild = insert( object -> leftChild,value);
    if(height(object -> leftChild) - height( object -> rightChild) == 2)
    {
      if( value < object -> leftChild -> data)
      {
        object = rightRotate( object );
      }
      else
      {
        object = doubleRightRotate( object );
      }
    }
  }

  else if( value > object -> data)
  {
    object -> rightChild = insert( object -> rightChild, value);
    if(height(object -> rightChild) - height( object -> leftChild) == 2)
    {
      if( value > object -> rightChild -> data)
      {
        object = leftRotate( object );
      }
      else
      {
        object = doubleLeftRotate( object );
      }
    }
  }

  object -> height = max(height( object->leftChild ), height(object->rightChild))+1;
  return object;
}

Node* avlTree::rightRotate(Node* &object)
{
  Node* tmp = object -> leftChild;
  object -> leftChild = tmp -> rightChild;
  tmp -> rightChild = object;

  object -> height = max(height(object->leftChild),height(object->rightChild))+1;
  tmp -> height = max(height(tmp->leftChild), object->height )+1;

  return tmp;
}

Node* avlTree::leftRotate(Node* &object)
{
  Node* tmp = object -> rightChild;
  object -> rightChild = tmp -> leftChild;
  tmp -> leftChild = object;

  object -> height = max(height(object->leftChild),height(object->rightChild))+1;
  tmp -> height = max(height(tmp->rightChild), object->height )+1;

  return tmp;
}

Node* avlTree::doubleRightRotate(Node* &object)
{
  object -> leftChild = leftRotate( object -> leftChild);

  return rightRotate( object );
}

Node* avlTree::doubleLeftRotate(Node* &object)
{
  object -> rightChild = rightRotate( object -> rightChild);

  return leftRotate( object );
}

Node* avlTree::findMin(Node* object)
{
  if(object == nullptr)
  {
    return nullptr;
  }

  else if( object -> leftChild == nullptr)
  {
    return object;
  }

  else
  {
    return findMin( object -> leftChild);
  }
}

Node* avlTree::findMax(Node* object)
{
  if(object == nullptr)
  {
    return nullptr;
  }

  else if( object -> rightChild == nullptr)
  {
    return object;
  }

  else
  {
    return findMax( object -> rightChild);
  }
}

Node* avlTree::remove(Node* object, int value)
{
  Node* temp;

        if(object == nullptr)
            return nullptr;

        else if(value < object->data)
        {
          object->leftChild = remove( object -> leftChild, value);
        }
        else if(value > object->data)
        {
          object->rightChild = remove( object -> rightChild, value);
        }

        else if(object->leftChild && object->rightChild)
        {
            temp = findMin(object->rightChild);
            object->data = temp->data;
            object->rightChild = remove(object->rightChild, object->data);
        }

        else
        {
            temp = object;
            if(object->leftChild == nullptr)
                object = object->rightChild;
            else if(object->rightChild == nullptr)
                object = object->leftChild;
            delete temp;
        }
        if(object == nullptr)
            return object;

        object->height = max(height(object->leftChild), height(object->rightChild))+1;

        if(height(object->leftChild) - height(object->rightChild) == 2)
        {
            if(height(object->leftChild->leftChild) - height(object->leftChild->rightChild) == 1)
            {
              return leftRotate(object);
            }
            else
            {
              return doubleLeftRotate(object);
            }
        }

        else if(height(object->rightChild) - height(object->leftChild) == 2)
        {
            if(height(object->rightChild->rightChild) - height(object->rightChild->leftChild) == 1)
            {
              return rightRotate(object);
            }

            else
            {
              return doubleRightRotate(object);
            }
        }
        return object;
}

Node*  avlTree::search(Node* object, int value)
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

int avlTree::height(Node* object)
{
  return ( object == nullptr ? -1 : object -> height);
}

int avlTree::getBalance(Node* object)
{
  if(object == nullptr)
  {
    return 0;
  }
  else
  {
      return height(object -> leftChild) - height(object -> rightChild);
  }
}

void avlTree::inorder(Node* object)
{
  if( object == nullptr)
  {
    return;
  }

  inorder(object->leftChild);
  cout << object->data << " ";
  inorder(object->rightChild);
}

void avlTree::insert(int value)
{
  root = insert(root,value);
}

void avlTree::remove(int value)
{
  root = remove(root,value);
}

void avlTree::display()
{
  inorder(root);
  cout << endl;
}

Node* avlTree::makeEmpty(Node* object)
{
  if( object == nullptr)
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

void avlTree::makeEmpty()
{
  root = makeEmpty(root);
}

avlTree::avlTree()
{
  root = nullptr;
}

avlTree::~avlTree()
{
  makeEmpty(root);
}


int avlTree::sizeofTree(Node* object)
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
void avlTree::enlarge(int value)
{
  for(int i = 0; i < value; ++i)
  {
    insert(i);
  }
}

void avlTree::search(int value)
{
  root = search(root, value);
}

void avlTree::sizeofTree()
{
  cout << "rozmiar drzewa to: " << sizeofTree(root) << endl;
}

void avlTree::measureTime()
{
  srand(time(NULL));


  int sizeTree, quantity, which;
  stoper pomiar;


  cout << "Jaki pomiar chesz wykonać ? \n";
  cout << "1. Pomiar dodawanie elementow do drzewa AVL\n";
  cout << "2. Pomiar szukania elementow w drzewie AVL\n";
  cin >> which;
  cout << "Jaki chcesz miec rozmiar drzewa ? " << endl;
  cin >> sizeTree;
  cout << "ile chcesz dokonać pomiarów ? " << endl;
  cin >> quantity;

  if(which == 1)
  {
    for(int i = 0;i<quantity;++i)
    {
      //sizeofTree();
      makeEmpty();

      pomiar.startPomiar();
      enlarge(sizeTree);
      pomiar.koniecPomiar();
      //sizeofTree();
      makeEmpty();
      //sizeofTree();
    }
  }

  else if(which == 2)
  {
    //sizeofTree();
    makeEmpty();
    enlarge(sizeTree);
    //sizeofTree();

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
    //sizeofTree();
  }

  else
    return;

}
