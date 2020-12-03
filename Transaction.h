#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Faculty.h"
#include "Student.h"

class Transaction {
public:
    Transaction() {};
    //~Transaction();
    Transaction(int tran, Student& stud){
      num = tran;
      s = stud;
    }
    Transaction(int tran, Faculty& fac){
      num = tran;
      f = fac;
    }
    Transaction(int tran, Student& stud, Faculty& fac) {
      num = tran;
      s = stud;
      f = fac;
    }

    Student s;
    Faculty f;
    int num; //number corresponding to the Transaction type based on menu
    /*
    7. Add Student
    8. Delete Student
    9. Add Faculty
    10. Delete Faculty
    11. Change Advisor
    12. Remove Advisee
    */
};

#endif
