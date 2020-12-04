#include "Student.h"
#include <string>
#include <iostream>
#include <iomanip>
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
Student::Student(int i, string n, string l, string m, double g, int f): super(i, n, l){
  major = m;
  gpa = g;
  facultyAdvisor = f;
}


//destructor
Student::~Student(){}

string Student::getInformation(){
  stringstream ss;
  ss <<  name + "\n";
  ss << id << "\n";
  ss << level + "\n";
  ss << major + "\n";
  ss << fixed << setprecision(2) << gpa << "\n";
  ss << facultyAdvisor << "\n";
  return ss.str();
}

int Student::getID(){
  return id;
}

int Student::getAdvisor(){
  return facultyAdvisor;
}
void Student::setAdvisor(int fa){
  facultyAdvisor = fa;
}

string Student::toString(){
  stringstream ss;
  ss <<  "\nName: " + name;
  ss << "\nID: " << id;
  ss << "\nLevel: " + level;
  ss << "\nMajor: " + major;
  ss << "\nGPA: " << fixed << setprecision(2) << gpa;
  ss << "\nAdvisor: " + to_string(facultyAdvisor) + "\n";
  return ss.str();
}
