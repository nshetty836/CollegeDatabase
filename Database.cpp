#include "Database.h"
#include "DoublyLinkedList.h"

Database::Database(){
  Student* s1 = new Student(5152541, "Nikita Shetty", "Sophomore", "Data", 3.97, 334444);
  Student* s2 = new Student(56666, "Rachna Shetty", "Sophomore", "Data", 3.97, 334444);
  Student* s3 = new Student(657571, "Suraj Shetty", "Sophomore", "Data", 3.97, 334444);

  masterStudent.insert(5152541, *s1);
  masterStudent.insert(56666, *s2);
  masterStudent.insert(657571, *s3);

  Faculty* f1 = new Faculty(5152541, "Kashish Pandey", "Sophomore", "hello");
  Faculty* f2 = new Faculty(5666666, "Rachna Shetty", "Sophomore", "wassup");
  Faculty* f3 = new Faculty(657571, "Suraj Shetty", "Sophomore", "hiii");
  //
  f1->addAdvisee(2222);
  // f1->advisees.printList();
  masterFaculty.insert(5152541, *f1);
  // masterFaculty.printTree();
  masterFaculty.insert(5666666, *f2);
  masterFaculty.insert(657571, *f3);

}
Database::~Database(){}

void Database::recoverDatabase(){}


void Database::showMenu(){
  cout << "\nStudent & Faculty Records Database\n----------------------------------\n";
  cout << "\n1.  Print all students and their information" << endl;
  cout << "2.  Print all faculty and their information" << endl;
  cout << "3.  Find and display student information" << endl;
  cout << "4.  Find and display faculty information" << endl;
  cout << "5.  Get faculty advisor of student" << endl;
  cout << "6.  Get advisees of a faculty member" << endl;
  cout << "7.  Add a new student" << endl;
  cout << "8.  Delete a student" << endl;
  cout << "9.  Add a new faculty member" << endl;
  cout << "10. Delete a faculty member" << endl;
  cout << "11. Change a student’s advisor" << endl;
  cout << "12. Remove an advisee from a faculty member" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
}
void Database::printStudents(){ //print all student info in ascending order
  masterStudent.printTree();
}
void Database::printFaculty(){
  masterFaculty.printTree(); //FIX TO MAKE IT PRINT LIST
}    //#2
void Database::findStudent(int studID){
  if(masterStudent.contains(studID)){
    cout << *masterStudent.find(studID) << endl;
  }
  else{
    cout << "ID not found." << endl;
  }
} //#3
void Database::findFaculty(int facID){
  if(masterFaculty.contains(facID)){
    cout << *masterFaculty.find(facID) << endl;
  }
  else{
    cout << "ID not found." << endl;
  }
}  //#4
void Database::findAdvisor(int studID){
  if(masterStudent.contains(studID)){
    Student stud = *masterStudent.find(studID);
    cout << "Advisor ID: " << stud.getAdvisor() << endl;
  }
  else{
    cout << "ID not found." << endl;
  }
}   //#5
void Database::findAdvisees(int facID){
  if(masterFaculty.contains(facID)){
    Faculty fac = *masterFaculty.find(facID);
    cout << "Advisee IDs: " << endl;
    fac.printAdvisees();
  }
  else{
    cout << "ID not found." << endl;
  }
}   //#6

// void Database::addStudent(int studID){//#7
//   cout << "Please enter Student ID: ";
//   cin >> id;
//
//   if(masterStudent -> find(id) != NULL){
//     cout << "The ID number you entered is already in use. Please try again.";
//     continue;
//   }
//     cout << "Please enter student name: ";
//     cin >> name;
//     cout << "Please enter student level: ";
//     cin >> level;
//     cout << "Please enter student major: ";
//     cin >> major;
//     cout << "Please enter student GPA: ";
//     cin >> gpa;
//     cout << "Please enter faculty advisor ID: ";
//     cin >> facID;
//
//     Student *s = new Student(id, name, level, major, gpa, facultyAdvisor);
//       masterStudent.insert(id, s);
//
//       if(masterStudent.find(facID) == NULL){
//         cout << "The Faculty Advisor you entered seems to not exist in the tree. Try again." << endl;
//         cout << "Please enter the Faculty Advisor ID: " << endl;
//         cout << endl;
//
//         cout << "Please enter faculty name: ";
//         cin >> name;
//         cout << "Please enter faculty level: ";
//         cin >> level;
//         cout << "Please enter faculty department: ";
//         cin >> department;
//
//         Faculty *f = new Faculty(id, name, level, department, adviseeID);
//         masterStudent.insert(faID, f);
//       }
//       else{
//         masterStudent.find(facID)->addAdvisee(id);
//       }
//     }
//
// void Database::deleteStudent(int studID){ //#8
//         cout << "Please enter Student ID: ";
//         cin >> studID;
//         if(masterStudent.find(studID) == NULL){
//           cout << "The ID number you entered is not valid. Please try again." << endl;
//           continue;
//         }
//         facID = masterStudent.find(studID)->getID();
//         masterStudent.find(facID)->setAdvisees(studID);
//         masterStudent.deleter(studID)
// }
// void Database::addFaculty(int facID){ //#9
//       int id, advisee;
//       string name, level, department;
//       cout << "Please enter ID: ";
//       cin >> id;
//
//       if(masterStudent.find(id) != NULL){
//         cout << "The ID number you entered is not valid. Please try again."<< endl;
//           // continue;
//       }
//
//       cout << "Please enter faculty name: ";
//       cin >> name;
//       cout << "Please enter faculty level: ";
//       cin >> level;
//       cout << "Please enter faculty department: ";
//       cin >> department;
//
//
//       Faculty *f = new Faculty(id, name, level, department, adviseeID);
//
//       while(true){
//         cout << "Please enter ID number of one advisees: ";
//         cin >> advisees;
//       }
//
//       masterStudent.insert(id, f);
//
//       if(masterStudent.find(adviseeID) == NULL){
//         cout << "The student doesn't exist in the tree. Try again." << endl;
//         cout << "Please enter student information" << endl;
//
//         cout << "Please enter student name: ";
//         cin >> name;
//         cout << "Please enter student level: ";
//         cin >> level;
//         cout << "Please enter student major: ";
//         cin >> major;
//         cout << "Please enter student GPA: ";
//         cin >> gpa;
//
//         Student *s = new Student(ad, name, level, major, gpa, id);
//         masterStudent.insert(ad, s);
//       }
// }
// void Database::deleteFaculty(int facID){//#10
//   cout << "Please enter faculty ID: ";
//       cin >> id;
//       if(masterStudent.find(facID) == NULL){
//         cout << "The ID number you entered is not valid. Please try again." << endl;
//         continue;
//       }
//       masterStudent.find(facID);
//       masterStudent.deleteNode(facID);
// }
// void Database::changeAdvisor(int studID, int facID)  //#11
// {
//   int origialFac = 0;
//         cout << "Please enter student ID: ";
//         cin >> studID;
//
//         if(masterStudent.find(studID) == NULL){
//           cout << "The student ID number you entered is not valid. Please try again." << endl;
//           continue;
//         }
//
//         cout << "Please enter the new faculty advisor ID: ";
//         cin >> facID;
//
//         origialFac = masterStudent.find(studID)->getID();
//         masterStudent.find(studID)->changeFacultyAdvisor(facID);
//         origialFac = masterStudent.find(origialFac)->addAdvisee(studID);
//
//         // facID DNE -> adding facID
//         if(masterStudent.find(facID) == NULL){
//           cout << "The Faculty Advisor you entered does not exist in the tree." << endl;
//           cout << "Please enter the Faculty Advisor information" << endl;
//
//           cout << "Please enter faculty name: ";
//           cin >> name;
//           cout << "Please enter faculty level: ";
//           cin >> level;
//           cout << "Please enter faculty department: ";
//           cin >> department;
//
//           Faculty *f = new Faculty(facID, name, level, department, studID);
//           masterStudent.insert(facID, f);
//         }
//         else{
//           masterStudent.find(facID)->addAdvisee(studID);
//         }
//
// }
// void Database::removeAdvisee(int studID, int facID){ //#12
//   cout << "Please enter faculty ID: ";
//       cin >> facID;
//       //id dne
//       if(masterStudent.find(facID) == NULL){
//         cout << "Please enter a valid faculty ID." << endl;
//         // continue;
//       }
//       cout << "Please enter the student ID you would like to remove: ";
//       cin >> studID;
//
//       // id dne
//       if(masterStudent.find(studID) == NULL){
//         cout << "Invalid Student ID, try again" << endl;
//         // continue;
//       }
//       studID = masterStudent.find(facID)->setAdvisees(studID);
// }
void Database::rollback(){}   //#13
void Database::exitDatabase(){}   //#14
