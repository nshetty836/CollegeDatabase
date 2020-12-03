#include "Transaction.h"
using namespace std;

// default constructor
Transaction::Transaction(){
}

// // overloaded constructor
// Transaction::Transaction(string t, string p, BST<Student>* tree){
//   type = t;
//   person = p;
//   studentTree = new BST<Student>();
//   studentTree->copyTree(tree->root);
// }
//
// // overloaded constructor
// Transaction::Transaction(string t, string p, BST<Faculty>* tree){
//   type = t;
//   person = p;
//   facultyTree = new BST<Faculty>();
//   facultyTree->copyTree(tree->root);
// }

// overloaded constructor
Transaction::Transaction(string t, string p, Person per){
  type = t;
  personType = p;

}

// destructor
Transaction::~Transaction(){
}
