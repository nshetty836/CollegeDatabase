#include <iostream>
#include "Database.h"
#include "Student.h"
#include "Faculty.h"


using namespace std;

int main(){
  Database db;
  db.printStudents();
  db.printFaculty();
  cout << "\nFind Student: " << endl;
  db.findStudent(5152541);
  cout << "\nFind Faculty: " << endl;
  db.findFaculty(5666666);
  cout << "\nFind Advisor: " << endl;
  db.findAdvisor(5152541);
  cout << "\nFind Advisees: " << endl;
  db.findAdvisees(5152541);


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
