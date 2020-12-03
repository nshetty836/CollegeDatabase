#include <iostream>
#include "Database.h"
#include "Student.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"


using namespace std;

int main(){
  // DoublyLinkedList<int> dll;
  // dll.insertFront(1);
  // dll.insertFront(2);
  // dll.insertFront(3);
  // dll.insertFront(4);
  //
  // dll.removeNode(2);
  // dll.printList();
  //
  // dll.removeNode(3);
  // dll.printList();
  //
  // dll.removeNode(4);
  // dll.printList();
  //
  // dll.removeNode(1);
  // dll.printList();
  Database db;

  db.recoverDatabase();
  int choice;
  cout << "\n-----------------------------------";
  cout << "\nStudent & Faculty Records Database";
  cout << "\n-----------------------------------\n";
  while(true){
    db.showMenu();
    try{
      cout << "Enter a number: " << endl;
      cin >> choice;
      cout << endl;
    }
    catch(exception e){
      cout << "Please enter a valid number" << endl;
      continue;
    }
    if(choice == 1){
      db.printStudents();
    }
    else if(choice == 2){
      db.printFaculty();
    }
    else if(choice == 3){
      db.findStudent();
    }
    else if(choice == 4){
      db.findFaculty();
    }
    else if(choice == 5){
      db.findAdvisor();
    }
    else if(choice == 6){
      db.findAdvisees();
    }
    else if(choice == 7){
      db.addStudent();
    }
    else if(choice == 8){
      db.deleteStudent();
    }
    else if(choice == 9){
      db.addFaculty();
    }
    else if(choice == 10){
      db.deleteFaculty();
    }
    else if(choice == 11){
      db.changeAdvisor();
    }
    else if(choice == 12){
      db.removeAdvisee();
    }
    else if(choice == 13){
      db.rollback();
    }
    else if(choice == 14){
      db.exitDatabase();
      break;
    }
    else{
      cout << "Please enter a number between 1-14." << endl;
    }

    string temp;
    cout << "Press enter to go back to the menu. " << endl;
    cin.ignore();
    getline(cin, temp);
  }

  return 0;
}
