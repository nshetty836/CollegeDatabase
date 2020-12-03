#include "BST.h"
#include "Student.h"
#include "Faculty.h"


class Transaction{
public:
  Transaction();
  Transaction(string t, string p, Person per);

  ~Transaction();

  // BST<Student>* studentTree;
  // BST<Faculty>* facultyTree;

  // int studID;
  // int facID;

  string personType;
  string type;
  Person personData;
};
