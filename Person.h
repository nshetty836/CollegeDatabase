#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person{

public:
  int id;
  string level;
  string name;

  Person();
  Person(int i, string l, string n);
  ~Person();

  string getName();
  string getLevel();

  int getID();
  void setID(int i);

};
#endif
