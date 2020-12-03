// #ifndef ROLLBACK_H
// #define ROLLBACK_H
// #include "Stack.h"
// #include "Transaction.h"
//
// class Rollback{
// public:
//   Rollback();
//   Rollback(BST<Student>*& studTree, BST<Faculty>*& facTree);
//   ~Rollback();
//
//   Stack<Transaction>* stack;
//   BST<Student>* masterStudent;
//   BST<Faculty>* masterFaculty;
//
//   void undo();
//   void undoAddDelete(Transaction tran);
//   void undoChange(Transaction tran);
//   void addTransaction(Transaction tran);
//
// };
//
// #endif
