#include <iostream>
#include "Faculty.h"
#include "Student.h"
#include "BST.h"
#include "Stack.h"
#include "FileProcessor.h"
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
    void findStudent(); //#3
    void findFaculty();  //#4
    void findAdvisor();   //#5
    void findAdvisees();   //#6
    void addStudent();   //#6
    void deleteStudent();   //#6
    void addFaculty();   //#6
    void deleteFaculty();   //#6
    void changeAdvisor(int studID, int facID);   //#6
    void removeAdvisee();   //#6
    void rollback();   //#6
    void exitDatabase();   //#6

    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;
    FileProcessor *studFile;
    FileProcessor *facFile;


};
