#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor
Student::Student(){
  id = 0;
  name = " ";
  level = " ";
  major = " ";
  gpa = 0.0;
  facultyAdvisor = 0;
}

//overloaded constructor
Student::Student(int i, string n, string l, string m, double g, int f){
  id = i;
  name = n;
  level = l;
  major = m;
  gpa = g;
  facultyAdvisor = f;
}

//destructor
Student::~Student(){
}

void Student::getInformantion(){
  cout << "ID: " << id;
  cout << "Name: " << name;
  cout << "Level: " << level;
  cout << "Major: " << major;
  cout << "GPA: " << gpa;
  cout << "Faculty Advisor ID: " << facultyAdvisor;
}

int Student::returnID(){
  return id;
}

int Student::getID(){
  return facultyAdvisor;
}

string Student::getFile(){
  string tester = " ";
  tester += to_string(id);
  tester += name;
  tester += level;
  tester += major;
  tester += to_string(gpa);
  tester += to_string(facultyAdvisor);
  return tester;
}

string Student::toString(){
  string temp = "";
  temp += "ID: " + to_string(id);
  temp += "\nName: " + name;
  temp += "\nLevel: " + level;
  temp += "\nMajor: " + major;
  temp += "\nGPA: " + to_string(gpa);
  temp += "\nAdvisor: " + to_string(facultyAdvisor) + "\n";
  return temp;
}

void Student::facAdvisor(int fa){
  facultyAdvisor = fa;
}
