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
Faculty::Faculty(int i, string n, string l, string d): super(i, n, l){
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

int Faculty::getAdvisee(int pos){
  int temp = *advisees.getNode(pos);
  return temp;
}

void Faculty::addAdvisee(int adviseeID){
  advisees.insertFront(adviseeID);
}

void Faculty::deleteAdvisee(int adviseeID){
  advisees.removeNode(adviseeID);
}

bool Faculty::containsAdvisee(int adviseeID){
  if(advisees.find(adviseeID) == -1)
    return false;
  else
    return true;
}

int Faculty::getNumAdvisees(){
  return advisees.size;
}

string Faculty::getInformation(){
  string temp = "";
  temp += name + "\n";
  temp += to_string(id) + "\n";
  temp += level + "\n";
  temp += department + "\n";
  temp += to_string(advisees.size) + "\n";
  temp += advisees.returnList();
  return temp;
}

int Faculty::getID(){
  return id;
}

// string Faculty::getFile(){
//   string tester = "";
//   tester += to_string(id);
//   tester += name;
//   tester += level;
//   tester += department;
//   tester += advisees.returnList();
//   return tester;
// }

void Faculty::printAdvisees(){
  if(hasAdvisee())
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
  temp += "\nName: " + name;
  temp += "\nID: " + to_string(id);
  temp += "\nLevel: " + level;
  temp += "\nDepartment: " + department;
  temp += "\nAdvisee IDs: ";
  temp += advisees.returnList();
  return temp;
}
