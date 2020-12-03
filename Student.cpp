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
  // id = i;
  // name = n;
  // level = l;
  major = m;
  gpa = g;
  facultyAdvisor = f;
}


//destructor
Student::~Student(){
}

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
  temp += "\nName: " + name;
  temp += "\nID: " + to_string(id);
  temp += "\nLevel: " + level;
  temp += "\nMajor: " + major;
  temp += "\nGPA: " + to_string(gpa);
  temp += "\nAdvisor: " + to_string(facultyAdvisor) + "\n";
  return temp;
}

void Student::setAdvisor(int fa){
  facultyAdvisor = fa;
}
