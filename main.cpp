#include <iostream>
#include "BST.h"
using namespace std;

int main(){
  BST<int> b;
  b.insert(3);
  b.insert(90);
  b.insert(1);
  b.insert(20);
  b.insert(45);
  b.insert(7);
  b.insert(24);
  b.insert(6);
  cout << "contains: " << (b.contains(99) ? "found it" : "not in tree") << endl;
  b.insert(99);
  cout << "contains: " << (b.contains(99) ? "found it" : "not in tree") << endl;
  b.deleter(3);
  cout << "contains: " << (b.contains(3) ? "found it" : "not in tree") << endl;
  b.printTree();

  cout << "MAX:" << * (b.getMax()) << endl; //using de-referencing operator
  cout << "MIN:" << * (b.getMin()) << endl; //using de-referencing operator

  cout << endl;

  return 0;
}
