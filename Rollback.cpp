// #include "Rollback.h"
//
// Rollback::Rollback(){}
//
// Rollback::Rollback(BST<Student>*& studTree, BST<Faculty>*& facTree){
//   masterStudent = studTree;
//   masterFaculty = facTree;
//   stack = new Stack<Transaction>();
// }
//
// Rollback::~Rollback(){}
//
// void Rollback::undo(){
//   if(stack->isEmpty()){
//     cout << "Nothing to undo." << endl;
//     return;
//   }
//   Transaction tran = stack->pop();
//   if(tran.type == "add"){
//     if(tran.person == "student"){
//
//     }
//     else if(tran.person == "faculty"){
//       masterFaculty = tran.facultyTree;
//     }
//     else{
//       cout << "Could not undo." << endl;
//     }
//   }
//   else if(tran.type == "delete"){
//
//   }
//   // else if(tran.type == "change"){
//   //   undoChange(tran);
//   // }
//   else{
//     cout << "Nothing to undo." << endl;
//   }
// }
//
// void Rollback::undoAddDelete(Transaction tran){
//   if(tran.person == "student"){
//     masterStudent = tran.studentTree;
//   }
//   else if(tran.person == "faculty"){
//     masterFaculty = tran.facultyTree;
//   }
//   else{
//     cout << "Could not undo." << endl;
//   }
// }
//
// // void Rollback::undoChange(Transaction tran){
// //   if(tran.person == "student"){
// //     masterStudent->find(tran.studID)->setAdvisor(tran.facID);
// //   }
// //   else if(tran.person == "faculty"){
// //     masterFaculty->find(tran.facID)->addAdvisee(tran.studID);
// //   }
// //   else{
// //     cout << "Could not undo." << endl;
// //   }
// // }
//
// void Rollback::addTransaction(Transaction tran){
//   stack->push(tran);
// }
