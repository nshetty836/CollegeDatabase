#include <iostream>
#include "Faculty.h"
#include "Student.h"
#include "BST.h"
#include "Stack.h"
#include "Transaction.h"
#include <algorithm>
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
    void findByMajor();
    void clearDatabase();
    void writeToFile();

    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;
    Stack<Transaction> transactions;

    //used in findByMajor() function
    string makeLower(const string& in)
    {
      string out;
      transform( in.begin(), in.end(), back_inserter(out), ::tolower );
      return out;
    }


};
