#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

class Faculty{
  public:
      //default constructor
      Faculty();
      //overloaded constructor
      Faculty(int i, string n, string l, string d, int adviseeID);
      //overloaded constructor
      Faculty(int i, string n, string l, string d, DoublyLinkedList<int> *adviseeID);
      //destructor
      ~Faculty();

      int id;
      string name;
      string level;
      string department;
      DoublyLinkedList<int> *advisees;

      void getInformantion();
      string getFile();
      int getID();


      // returning advisee table
      DoublyLinkedList<int>* getAdvisees();
      // deleting at specific position
      int* setAdvisees(int position);
      //adding to advisee list
      void addAdvisee(int* adviseeID);
      // id# of faculty advisee being printed
      void printAdvisees();
      string toString();

      friend ostream& operator<<(ostream& os, Faculty& f)
      {
        os << f.toString();
        return os;
      }

      friend bool operator<(const Faculty& f1, const Faculty& f2)
      {
        if(f1.id < f2.id)
          return true;
        else
          return false;
      }

      friend bool operator==(const Faculty& f1, const Faculty& f2)
      {
        if(f1.id == f2.id)
          return true;
        else
          return false;
      }
};
#endif
