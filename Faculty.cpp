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
  advisees = new DoublyLinkedList<int>();
}

//overloaded constructor
Faculty::Faculty(int i, string n, string l, string d, int adviseeID){
  id = i;
  name = n;
  level = l;
  department = d;
  advisees = new DoublyLinkedList<int>();
}

//overloaded constructor
Faculty::Faculty(int i, string n, string l, string d, DoublyLinkedList<int> *adviseeID){
  id = i;
  name = n;
  level = l;
  department = d;
  advisees = adviseeID;
}

//destructor
Faculty::~Faculty(){
  delete advisees;
}

DoublyLinkedList<int>* Faculty::getAdvisees(){
  return advisees;
}

void Faculty::addAdvisee(int* adviseeID){
  advisees->insertBack(adviseeID);
}

int* Faculty::setAdvisees(int position){
  return advisees->deletePos(position);
}

void Faculty::getInformantion(){
  cout << "ID: " << id;
  cout << "Name: " << name;
  cout << "Level: " << level;
  cout << "Department: " << department;
  cout << "Advisees ID: " << endl;
  advisees->printList();
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
  tester += advisees->returnList();
  return tester;
}

void Faculty::printAdvisees(){
  advisees->printList();
}
