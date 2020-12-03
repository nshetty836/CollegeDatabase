#include <iostream>
#include "Faculty.h"
#include "Student.h"
#include "BST.h"
#include "Stack.h"
#include "Transaction.h"
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
    void changeAdvisor();   //#6
    void removeAdvisee();   //#6
    void rollback();   //#6
    void writeToFile();   //#6

    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;
    Stack<Transaction> transactions;


};
