#include "Transaction.h"
using namespace std;

// default constructor
Transaction::Transaction(){
}

// overloaded constructor
Transaction::Transaction(string t, string p, BST<Student>* tree){
  type = t;
  person = p;
  studentTree = new BST<Student>();
  studentTree->copyTree(tree->root);
}

// overloaded constructor
Transaction::Transaction(string t, string p, BST<Faculty>* tree){
  type = t;
  person = p;
  facultyTree = new BST<Faculty>();
  facultyTree->copyTree(tree->root);
}

// overloaded constructor
Transaction::Transaction(string t, string p, int sid, int fid){
  type = t;
  person = p;
  studID = sid;
  facID = fid;
}

// destructor
Transaction::~Transaction(){
}
