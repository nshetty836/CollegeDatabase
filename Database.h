#include <iostream>
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
    void findStudent(int studId); //#3
    void findFaculty(int facID);  //#4
    void findAdvisor(int studID);   //#5
    void findAdvisee(int facId);   //#6


}
