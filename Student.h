#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student{
  public:
      //default constructor
      Student();
      //overloaded constructor
      Student(int i, string n, string l, string m, double g, int f);
      //destructor
      ~Student();

      int id;
      string name;
      string level;
      string major;
      double gpa;
      int facultyAdvisor;

      //adding faculty advisor to student
      void facAdvisor(int fa);

      void getInformantion();
      string getFile();
      string toString();

      int getID();
      int returnID();
      friend ostream& operator<<(ostream& os, Student& s)
      {
        os << s.toString();
        return os;
      }

      friend bool operator<(const Student& s1, const Student& s2)
      {
        if(s1.id < s2.id)
          return true;
        else
          return false;
      }

      friend bool operator==(const Student& s1, const Student& s2)
      {
        if(s1.id == s2.id)
          return true;
        else
          return false;
      }
};


#endif
