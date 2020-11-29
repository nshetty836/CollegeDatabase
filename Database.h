#include <iostream>
#include "Faculty.h"
#include "Student.h"
#include "BST.h"
#include <fstream>

using namespace std;

class Database{
  public:
    //default constructor
    Database();
    ~Database();

    void recoverDatabase();
    void showMenu();
    void printStudents();  //#1
    void printFaculty();    //#2
    void findStudent(int studID); //#3
    void findFaculty(int facID);  //#4
    void findAdvisor(int studID);   //#5
    void findAdvisees(int facID);   //#6
    void addStudent(int studID);   //#6
    void deleteStudent(int studID);   //#6
    void addFaculty(int facID);   //#6
    void deleteFaculty(int facID);   //#6
    void changeAdvisor(int studID, int facID);   //#6
    void removeAdvisee(int studID, int facID);   //#6
    void rollback();   //#6
    void exitDatabase();   //#6

    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;


};
