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

      int getID();
      int returnID();
};
