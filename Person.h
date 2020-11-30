#include <iostream>
using namespace std;

class Person{

public:
  int id;
  string level;
  string name;

  Person();
  ~Person();

  string getName();
  string getLevel();

  int getID();
  void setID(int i);

};
