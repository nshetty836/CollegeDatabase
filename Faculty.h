#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "DoublyLinkedList.h"
#include "Person.h"

using namespace std;

class Faculty: public Person{
  public:
      //default constructor
      Faculty();
      //overloaded constructor
      Faculty(int i, string n, string l, string d);
      Faculty(int i);
      //destructor
      ~Faculty();

      string department;
      DoublyLinkedList<int> advisees;

      string getInformation();
      string getFile();
      int getID();
      bool hasAdvisee();
      int getNumAdvisees();


      // returning advisee table
      int getAdvisee(int pos);
      // deleting at specific position
      //adding to advisee list
      void addAdvisee(int adviseeID);
      void deleteAdvisee(int adviseeID);
      bool containsAdvisee(int adviseeID);
      // id# of faculty advisee being printed
      void printAdvisees();
      string toString();
      typedef Person super;

      friend ostream& operator<<(ostream& os, Faculty& f)
      {
        os << f.toString();
        return os;
      }

      friend bool operator<(const Faculty& f1, const Faculty& f2)
      {
        return (f1.id < f2.id);
      }

      friend bool operator==(const Faculty& f1, const Faculty& f2)
      {
        return (f1.id == f2.id);
      }

      friend bool operator!=(const Faculty& f1, const Faculty& f2)
      {
        return (f1.id != f2.id);
      }
};
#endif
