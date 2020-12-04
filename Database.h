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
    void printStudents();
    void printFaculty();
    void findStudent();
    void findFaculty();
    void findAdvisor();
    void findAdvisees();
    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();
    void changeAdvisor();
    void removeAdvisee();
    void rollback();
    void clearDatabase();
    void writeToFile();

    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;
    Stack<Transaction> transactions;


};
