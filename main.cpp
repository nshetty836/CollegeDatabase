#include <iostream>
#include "Database.h"
#include "Student.h"
#include "Faculty.h"
#include "FileProcessor.h"


using namespace std;

int main(){
  Database db;
  FileProcessor *fp = new FileProcessor();
  // db.printStudents();
  // db.printFaculty();
  // cout << "\nFind Student: " << endl;
  // db.findStudent(5152541);
  // cout << "\nFind Faculty: " << endl;
  // db.findFaculty(5666666);
  // cout << "\nFind Advisor: " << endl;
  // db.findAdvisor(5152541);
  // cout << "\nFind Advisees: " << endl;
  // db.findAdvisees(5152541);

  // db.deleteFaculty();
  // db.printFaculty();
  db.recoverDatabase();
  int choice;
  while(true){
    db.showMenu();
    try{
      cout << "Enter a number: " << endl;
      cin >> choice;
      cout << endl;
    }
    catch(exception e){
      cout << "Please enter a valid number" << endl;
      continue;
    }
    if(choice == 1){
      db.printStudents();
    }
    else if(choice == 2){
      db.printFaculty();
    }
    else if(choice == 3){
      db.findStudent();
    }
    else if(choice == 4){
      db.findFaculty();
    }
    else if(choice == 5){
      db.findAdvisor();
    }
    else if(choice == 6){
      db.findAdvisees();
    }
    else if(choice == 7){
      db.addStudent();
    }
    else if(choice == 8){
      db.deleteStudent();
    }
    else if(choice == 9){
      db.addFaculty();
    }
    else if(choice == 10){
      db.deleteFaculty();
    }
    else if(choice == 11){
      // db.changeAdvisor();
    }
    else if(choice == 12){
      db.removeAdvisee();
    }
    else if(choice == 13){
      db.rollback();
    }
    else if(choice == 14){
      db.exitDatabase();
      break;
    }
    else{
      cout << "Please enter a number between 1-14." << endl;
    }

    string temp;
    cout << "Press enter to go back to the menu. " << endl;
    cin.ignore();
    getline(cin, temp);
  }



  // Student* f = new Student(5152541, "Nikita Shetty", "Sophomore", "Data", 3.97, 334444);
  // Student* f1 = new Student(5152541, "Rachna Shetty", "Sophomore", "Data", 3.97, 334444);

  // Faculty* f1 = new Faculty(5152541, "Nikita Shetty", "Sophomore", "hello", 555);
  // Faculty* f2 = new Faculty(7575757, "Nikita Shetty", "Sophomore", "hello", 555);
  //
  //
  // cout << boolalpha << (*f1 < *f2) << endl;

  // BST<int> b;
  // b.insert(3);
  // b.insert(90);
  // b.insert(1);
  // b.insert(20);
  // b.insert(45);
  // b.insert(7);
  // b.insert(24);
  // b.insert(6);
  // cout << "contains: " << (b.contains(99) ? "found it" : "not in tree") << endl;
  // b.insert(99);
  // cout << "contains: " << (b.contains(99) ? "found it" : "not in tree") << endl;
  // b.deleter(3);
  // cout << "contains: " << (b.contains(3) ? "found it" : "not in tree") << endl;
  // b.printTree();
  //
  // cout << "MAX:" << * (b.getMax()) << endl; //using de-referencing operator
  // cout << "MIN:" << * (b.getMin()) << endl; //using de-referencing operator
  //
  // cout << endl;

  return 0;
}
