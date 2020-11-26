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
};
