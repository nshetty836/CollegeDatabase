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


void Database::addStudent(int studID){//#7
  cout << "Please enter Student ID: ";
  cin >> id;

  if(masterStudent -> searchTree(id) != NULL){
    cout << "The ID number you entered is already in use. Please try again.";
    continue;
  }
    cout << "Please enter student name: ";
    cin >> name;
    cout << "Please enter student level: ";
    cin >> level;
    cout << "Please enter student major: ";
    cin >> major;
    cout << "Please enter student GPA: ";
    cin >> gpa;
    cout << "Please enter faculty advisor ID: ";
    cin >> facID;

    Student *s = new Student(id, name, level, major, gpa, facultyAdvisor);
      masterStudent->insert(id, s);

      if(masterFaculty->searchTree(facID) == NULL){
        cout << "The Faculty Advisor you entered seems to not exist in the tree. Try again." << endl;
        cout << "Please enter the Faculty Advisor ID: " << endl;
        cout << endl;

        cout << "Please enter faculty name: ";
        cin >> name;
        cout << "Please enter faculty level: ";
        cin >> level;
        cout << "Please enter faculty department: ";
        cin >> department;

        Faculty *f = new Faculty(id, name, level, department, adviseeID);
        masterFaculty->insert(faID, f);
      }
      else{
        masterFaculty->searchTree(facID)->addAdvisee(id);
      }
    }

void Database::deleteStudent(int studID){ //#8
        cout << "Please enter Student ID: ";
        cin >> studID;
        if(masterStudent->searchTree(studID) == NULL){
          cout << "The ID number you entered is not valid. Please try again." << endl;
          continue;
        }
        facID = masterStudent->searchTree(studID)->getID();
        masterFaculty->searchTree(facID)->setAdvisees(studID);
        masterStudent->deleter(studID)
}
void Database::addFaculty(int facID){ //#9
      cout << "Please enter ID: ";
      cin >> id;

      if(masterFaculty->searchTree(id) != NULL){
        cout << "The ID number you entered is not valid. Please try again."<< endl;
        continue;
      }

      cout << "Please enter faculty name: ";
      cin >> name;
      cout << "Please enter faculty level: ";
      cin >> level;
      cout << "Please enter faculty department: ";
      cin >> department;
      cout << "Please enter ID number of one advisees: ";
      cin >> advisees;

      Faculty *f = new Faculty(id, name, level, department, adviseeID);
      masterFaculty->insert(id, f);

      if(masterStudent->searchTree(adviseeID) == NULL){
        cout << "The student doesn't exist in the tree. Try again." << endl;
        cout << "Please enter student information" << endl;

        cout << "Please enter student name: ";
        cin >> name;
        cout << "Please enter student level: ";
        cin >> level;
        cout << "Please enter student major: ";
        cin >> major;
        cout << "Please enter student GPA: ";
        cin >> gpa;

        Student *s = new Student(ad, name, level, major, gpa, id);
        masterStudent->insert(ad, s);
      }
}
void Database::deleteFaculty(int facID){//#10
  cout << "Please enter faculty ID: ";
      cin >> id;
      if(masterFaculty->searchTree(facID) == NULL){
        cout << "The ID number you entered is not valid. Please try again." << endl;
        continue;
      }
      masterFaculty->searchTree(facID);
      masterFaculty->deleteNode(facID);
}
void Database::changeAdvisor(int studID, int facID)  //#11
{
  int origialFac = 0;
        cout << "Please enter student ID: ";
        cin >> studID;

        if(masterStudent->searchTree(studID) == NULL){
          cout << "The student ID number you entered is not valid. Please try again." << endl;
          continue;
        }

        cout << "Please enter the new faculty advisor ID: ";
        cin >> facID;

        origialFac = masterStudent->searchTree(studID)->getID();
        masterStudent->searchTree(studID)->changeFacultyAdvisor(facID);
        origialFac = masterFaculty->searchTree(origialFac)->setAdvisees(studID);

        // facID DNE -> adding facID
        if(masterFaculty->searchTree(facID) == NULL){
          cout << "The Faculty Advisor you entered does not exist in the tree." << endl;
          cout << "Please enter the Faculty Advisor information" << endl;

          cout << "Please enter faculty name: ";
          cin >> name;
          cout << "Please enter faculty level: ";
          cin >> level;
          cout << "Please enter faculty department: ";
          cin >> department;

          Faculty *f = new Faculty(facID, name, level, department, studID);
          masterFaculty->insert(facID, f);
        }
        else{
          masterFaculty->searchTree(facID)->addAdvisee(studID);
        }

}
void Database::removeAdvisee(int studID, int facID){ //#12
  cout << "Please enter faculty ID: ";
      cin >> facID;
      //id dne
      if(masterFaculty->searchTree(facID) == NULL){
        cout << "Please enter a valid faculty ID." << endl;
        continue;
      }
      cout << "Please enter the student ID you would like to remove: ";
      cin >> studID;

      // id dne
      if(masterStudent->search(studID) == NULL){
        cout << "Invalid Student ID, try again" << endl;
        continue;
      }
      studID = masterFaculty->search(facID)->setAdvisees(studID);
}
void Database::rollback(){}   //#13
void Database::exitDatabase(){}   //#14
