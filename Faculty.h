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
      int getID();
      bool hasAdvisee();
      int getNumAdvisees();
      int getAdvisee(int pos);
      void addAdvisee(int adviseeID);
      void deleteAdvisee(int adviseeID);
      bool containsAdvisee(int adviseeID);
      void printAdvisees();
      string toString();

      typedef Person super;

      //overloaded operators to compare Faculty objects
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
