#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstddef>
using namespace std;

template <class T>
class TreeNode{

  public:
    TreeNode();
    TreeNode(T key);
    virtual ~TreeNode();

    T key;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

template <class T>
TreeNode<T>:: TreeNode(){
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
  left = NULL;
  right = NULL;
  key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){
  //research this
  //delete left;
  //delete right;
}

template <class T>
class BST{
private:
  TreeNode<T> *root;

public:
  BST();
  virtual ~BST();

  void insert(T value);
  bool contains(T value);
  bool deleter(T value);
  void destroyRecursive(TreeNode<T>* node);

  bool isEmpty();
  T* getMax();
  T* getMin();
  void recPrint(TreeNode<T> *node); //recursive print, takes a node so we can print any part of the tree
  void printTree();
  void multNodes(int n);
  void multNodes(TreeNode<T>* node, int n);
  T nearestAncestor(T a, T b);

  //returns the sucessor of the node to be deleted, d
  TreeNode<T>* getSuccessor(TreeNode<T> *d);
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
  if(node){
    destroyRecursive(node->left);
    destroyRecursive(node->right);
    delete node;
  }
}

//prints tree given a node to start from
template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
  if(node == NULL)
    return;

  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);
}

//prints entire tree
template <class T>
void BST<T>::printTree(){
  recPrint(root);
}

template <class T>
void BST<T>::multNodes(int n){
  multNodes(root, n);
}

template <class T>
void BST<T>::multNodes(TreeNode<T>* node, int n){
  if(node == NULL) return;
  node->key *= n;
  if(node->left != NULL){
    node->left->key *= n;
    multNodes(node->left, n);
  }
  if (node->right!=NULL){
    node->right->key *= n;
    multNode(node->right, n);
  }
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
  return &(current->key);
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
  return &(current->key);
}

template <class T>
void BST<T>::insert(T value){
  TreeNode<T> *newNode = new TreeNode<T>(value);

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
}

template <class T>
bool BST<T>::contains(T value){
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
T BST<T>::nearestAncestor(T a, T b){
  if((root == NULL) || (root->key == a) || (root->key == b))
    return -1;
  TreeNode<T>* current = root;
  TreeNode<T>* parent = NULL;

  while(true){
    if(a < current->key && b < current->key)
      current = current->left;
    else if(a > current->key && b > current->key)
      current = current->right;
    else if(a == current->key || b == current->key)
      return parent->key;
    else
      return current->key;
    parent = current;
  }
}

template <class T>
bool BST<T>::deleter(T k){
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

  else if(current->left ==NULL){
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
#endif
