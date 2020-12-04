#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h"
using namespace std;

class Student: public Person{
  public:
      //default constructor
      Student();
      //overloaded constructor
      Student(int i, string n, string l, string m, double g, int f);
      Student(int i);
      //destructor
      ~Student();

      string major;
      double gpa;
      int facultyAdvisor;

      string getInformation();
      string toString();

      int getID();
      int getAdvisor();
      void setAdvisor(int fa);

      typedef Person super;

      //overloaded operators to compare Student objects
      friend ostream& operator<<(ostream& os, Student& s)
      {
        os << s.toString();
        return os;
      }

      friend bool operator<(const Student& s1, const Student& s2)
      {
        return (s1.id < s2.id);
      }

      friend bool operator==(const Student& s1, const Student& s2)
      {
        return (s1.id == s2.id);
      }

      friend bool operator!=(const Student& s1, const Student& s2)
      {
        return(s1.id != s2.id);
      }
};


#endif
