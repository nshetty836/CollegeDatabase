#include <iostream>
#include "Database.h"

using namespace std;

int main(){
  //creating database
  Database db;
  db.recoverDatabase();
  int choice;
  cout << "\n-----------------------------------";
  cout << "\nStudent & Faculty Records Database";
  cout << "\n-----------------------------------\n";

  //runs until user chooses to exit
  while(true){
    db.showMenu();
    //getting user input
    try{
      cout << "Enter a number: " << endl;
      cin >> choice;
      cout << endl;
    }
    catch(exception e){
      cout << "Please enter a valid number." << endl;
      continue;
    }
    //print all student information
    if(choice == 1){
      db.printStudents();
    }
    //print all faculty information
    else if(choice == 2){
      db.printFaculty();
    }
    //find and print one student's information
    else if(choice == 3){
      db.findStudent();
    }
    //find and print one faculty's information
    else if(choice == 4){
      db.findFaculty();
    }
    //find and print the advisor of a student
    else if(choice == 5){
      db.findAdvisor();
    }
    //find and print advisees of a faculty member
    else if(choice == 6){
      db.findAdvisees();
    }
    //add a student record
    else if(choice == 7){
      db.addStudent();
    }
    //delete a student record
    else if(choice == 8){
      db.deleteStudent();
    }
    //add a faculty record
    else if(choice == 9){
      db.addFaculty();
    }
    //delete a faculty record
    else if(choice == 10){
      db.deleteFaculty();
    }
    //change advisor of a student
    else if(choice == 11){
      db.changeAdvisor();
    }
    //remove an advisee of a faculty member
    else if(choice == 12){
      db.removeAdvisee();
    }
    //undo an add/delete of study or faculty record or changed advisor of student
    else if(choice == 13){
      db.rollback();
    }
    //write database to a file before exiting
    else if(choice == 14){
      db.writeToFile();
      break;
    }
    //user entered a number outside of 1-14
    else{
      cout << "Please enter a number between 1-14." << endl;
    }

    //waiting for user to press enter to show menu again
    string temp;
    cout << "Press enter to go back to the menu. " << endl;
    cin.ignore();
    getline(cin, temp);
  }

  return 0;
}
