#include "Faculty.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Faculty::Faculty(){
  id = 0;
  name = " ";
  level = " ";
  department = " ";
}

//overloaded constructor
Faculty::Faculty(int i, string n, string l, string d){
  id = i;
  name = n;
  level = l;
  department = d;
}

Faculty::Faculty(int i){
  id = i;
}

//destructor
Faculty::~Faculty(){
  // delete advisees;
}

// DoublyLinkedList<int> Faculty::getAdvisees(){
//   return advisees;
// }

void Faculty::addAdvisee(int adviseeID){
  advisees.insertFront(&adviseeID);
}

int* Faculty::setAdvisees(int position){
  return advisees.deletePos(position);
}

void Faculty::getInformation(){
  cout << "ID: " << id;
  cout << "Name: " << name;
  cout << "Level: " << level;
  cout << "Department: " << department;
  cout << "Advisees ID: " << endl;
  advisees.printList();
}

int Faculty::getID(){
  return id;
}

string Faculty::getFile(){
  string tester = "";
  tester += to_string(id);
  tester += name;
  tester += level;
  tester += department;
  tester += advisees.returnList();
  return tester;
}

void Faculty::printAdvisees(){
  advisees.printList();
}

bool Faculty::hasAdvisee(){
  if(advisees.size == 0)
    return false;
  else
    return true;
}


string Faculty::toString(){
  string temp = "";
  temp += "ID: " + to_string(id);
  temp += "\nName: " + name;
  temp += "\nLevel: " + level;
  temp += "\nDepartment: " + department;
  temp += "\nAdvisees: \n";
  temp += advisees.returnList();
  return temp;
}
