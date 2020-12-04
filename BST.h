#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstddef>
#include <algorithm>
using namespace std;

template <class T>
class TreeNode{

  public:
    TreeNode();
    TreeNode(int key, T data);
    virtual ~TreeNode();

    int key;
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

template <class T>
TreeNode<T>:: TreeNode(){
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k, T d){
  left = NULL;
  right = NULL;
  key = k;
  data = d;
}

template <class T>
TreeNode<T>::~TreeNode(){
  //research this
  //delete left;
  //delete right;
}

template <class T>
class BST{

public:
  BST();
  ~BST();

  void insert(int value, T k);
  bool contains(int value);
  bool deleter(int value);
  T* find(int k);
  void destroyRecursive(TreeNode<T>* node);

  bool isEmpty();
  T* getMax();
  T* getMin();
  void recPrint(TreeNode<T> *node); //recursive print, takes a node so we can print any part of the tree
  void printTree();
  void recMajor(TreeNode<T> *node, string major);
  bool printByMajor(string major);
  void recData(TreeNode<T>* node, string *temp);
  string getData();

  //returns the sucessor of the node to be deleted, d
  TreeNode<T>* getSuccessor(TreeNode<T> *d);
  int getNext(int value, T k);
  void copyTree(TreeNode<T>* node);
  int size;
  bool hasMajor = false;
  TreeNode<T> *root;

  //used in findByMajor() function
  string makeLower(const string& in)
  {
    string out;
    transform( in.begin(), in.end(), back_inserter(out), ::tolower );
    return out;
  }
};

template <class T>
BST<T>::BST(){
  root = NULL;
}

template <class T>
BST<T>::~BST(){
  //iterate and delete, this is O(n)
  destroyRecursive(root);
}

template <class T>
void BST<T>::destroyRecursive(TreeNode<T>* node){
  if (node == root) {
    root = NULL;
    size = 0;
  }
  if(node != NULL) {
    if(node->left)
      destroyRecursive(node->left);
    if(node->right)
      destroyRecursive(node->right);
    delete node;
    node = NULL;
  }

}

//prints tree given a node to start from
template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
  if(node == NULL)
    return;

  recPrint(node->left);
  cout << node->data << endl;
  recPrint(node->right);
}


//prints entire tree
template <class T>
void BST<T>::printTree(){
  recPrint(root);
}

//prints student records if they have the given major
template <class T>
void BST<T>::recMajor(TreeNode<T> *node, string major){
  if(node == NULL)
    return;

  recMajor(node->left, major);
  if(makeLower(node->data.major) == major){
    cout << node->data << endl;
    hasMajor = true;
  }
  recMajor(node->right, major);
}

//prints all students of given major
template <class T>
bool BST<T>::printByMajor(const string major){
  recMajor(root, major);
  return hasMajor;
}

template <class T>
T* BST<T>::getMax(){
  if(isEmpty()) // nothing in tree
    return NULL;

  TreeNode<T> *current = root;

  while (current->right != NULL) {
    //until it's rightmost node
    current = current->right;
  }
  return &(current->data);
}

template <class T>
T* BST<T>::getMin(){
  if(isEmpty())
    return NULL;

  TreeNode<T> *current = root;

  while (current->left != NULL) {
    //until it is leftmost node
    current = current->left;
  }
  return &(current->data);
}

template <class T>
void BST<T>::insert(int value, T k){
  TreeNode<T> *newNode = new TreeNode<T>(value, k);

  // check if tree is empty, make node root if so
  if(isEmpty())
    root = newNode;
  else{

    TreeNode<T> *parent;
    TreeNode<T> *current = root;

    while(true)
    {
      parent = current;
      if(value < current->key){
        //go left
        current = current->left;
        if(current == NULL){
          //found insertion point
          parent->left = newNode;
          break;
        }
      }
      else{
        //go right
        current = current->right;
        if(current == NULL){
          //found insertion point
          parent->right = newNode;
          break;
        }
      }
    }
  }
  size++;
}

template <class T>
bool BST<T>::contains(int value){
  if(isEmpty())
    return false;
  else{
    //tree is not empty, let's go look for the value
    TreeNode<T> *current = root;

    while(current->key != value){
      if(value < current->key)
        current = current->left;
      else
        current = current->right;

      if(current == NULL)      //did not find the value
        return false;
    }
  }
  return true; // found the value
}

template <class T>
T* BST<T>::find(int value){
  if(isEmpty())
    return NULL;
  else{
    //tree is not empty, let's go look for the value
    TreeNode<T> *current = root;

    while(current->key != value){
      if(value < current->key)
        current = current->left;
      else
        current = current->right;

      if(current == NULL)      //did not find the value
        return NULL;
    }
    return &(current->data); // found the value
  }
}

template <class T>
bool BST<T>::deleter(int k){
  if(isEmpty())
    return false;

  TreeNode<T> *parent;
  TreeNode<T> *current = root;
  bool isLeftNode = true;

  //usual code to find a TreeNode
  while(current->key !=k){
    parent = current;

    if(k < current->key){
      //go left
      isLeftNode = true;
      current = current->left;
    }
    else{
      isLeftNode = false;
      current = current->right;
    }

    if(current == NULL){
      //value does not exist
      return false;
    }
  }

  //if we make it here, then we found it, now lets proceed to delete

  //case: node to delete has no children, AKA leaf node
  if(current->left == NULL && current->right == NULL){
    if(current== root){
      root = NULL;
    }
    else if(isLeftNode){
      parent->left = NULL;
    }
    else{
      parent->right = NULL;
    }
  }

  //case: node to be deleted has one child. need to determine whether child is left or right
  else if(current->right == NULL){
    //node has left child, no right children
    if(current == root)
      root = current->left;
    else if(isLeftNode)
      parent->left = current->left;
    else
      parent->right = current->left;
  }

  else if(current->left == NULL){
    //node has right child, no left children
    if(current == root)
      root = current->right;
    else if(isLeftNode){
      parent ->left = current->right;
    }
    else
      parent->right = current ->right;
  }

  else{
    //node to be deleted has two children. we need to find the successor in this case

    TreeNode<T> *successor = getSuccessor(current); //current is the node to be deleted

    if(current == root)
      root = successor;
    else if (isLeftNode)
      parent ->left = successor;
    else
      parent->right = successor;

    successor->left = current->left;
  }
  size--;
  return true;
}

//d represents the node to be deleted
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){
    //descendant of the right children
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;

}

template <class T>
bool BST<T>::isEmpty(){
  if(root == NULL)
    return true;
  else
    return false;
}

template <class T>
void BST<T>::recData(TreeNode<T>* node, string *temp){
  if(node == NULL)
    return;
  recData(node->left, temp);
  *temp += node->data.getInformation();
  recData(node->right, temp);
}

template <class T>
string BST<T>::getData(){
  string temp;
  recData(root, &temp);
  return temp;
}

// // Returns Random node
// template <class T>
// T* BST<T>::randomNode()
// {
//
//     srand(time(0));
//
//     int count = rand() % (root->children + 1);
//     return randomNodeUtil(root, count);
// }




#endif
