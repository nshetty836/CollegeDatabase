#include "BST.h"

class Transaction{
public:
  Transaction();
  Transaction(string t, string p, BST<Student>* tree);
  Transaction(string t, string p, BST<Faculty>* tree);
  Transaction(string t, string p, int sid, int fid);
  ~Transaction();

  BST<Student>* studentTree;
  BST<Faculty>* facultyTree;

  int studID;
  int facID;

  string person;
  string type;
};
