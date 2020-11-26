#include "Database.h"

Database::Database(){}
Database::~Database(){}

void Database::recoverDatabase(){}
void Database::showMenu(){}
void Database::printStudents(){}  //#1
void Database::printFaculty(){}    //#2
void Database::findStudent(int studID){} //#3
void Database::findFaculty(int facID){}  //#4
void Database::findAdvisor(int studID){}   //#5
void Database::findAdvisee(int facID){}   //#6
void Database::addStudent(int studID){}   //#6
void Database::deleteStudent(int studID){}   //#6
void Database::addFaculty(int facID){}   //#6
void Database::deleteFaculty(int facID){}   //#6
void Database::changeAdvisor(int studID, int facID){}   //#6
void Database::removeAdvisee(int studID, int facID){}   //#6
void Database::rollback(){}   //#6
void Database::exitDatabase(){}   //#6
