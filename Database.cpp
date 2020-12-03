#include "Database.h"
#include "DoublyLinkedList.h"

Database::Database(){
  // Student* s1 = new Student(1, "Nikita Shetty", "Sophomore", "Data", 3.97, 4);
  // Student* s2 = new Student(2, "Rachna Shetty", "Sophomore", "Data", 3.97, 4);
  // Student* s3 = new Student(3, "Suraj Shetty", "Sophomore", "Data", 3.97, 6);
  //
  // masterStudent.insert(1, *s1);
  // masterStudent.insert(2, *s2);
  // masterStudent.insert(3, *s3);
  //
  // Faculty* f1 = new Faculty(4, "Kashish Pandey", "Sophomore", "hello");
  // Faculty* f2 = new Faculty(5, "Rachna Shetty", "Sophomore", "wassup");
  // Faculty* f3 = new Faculty(6, "Suraj Shetty", "Sophomore", "hiii");
  // //
  // f1->addAdvisee(1);
  // f1->addAdvisee(2);
  // f3->addAdvisee(3);
  //
  // // f1->advisees.printList();
  // masterFaculty.insert(4, *f1);
  // // masterFaculty.printTree();
  // masterFaculty.insert(5, *f2);
  // masterFaculty.insert(6, *f3);
  //


}
Database::~Database(){}

void Database::recoverDatabase(){
  int id, gpa, advisor;
  string name, level, department, major;
  ifstream facultyStream;
  facultyStream.open("facultyTable.txt");
  bool noFaculty = false; //flag will be set if error encountered

  if(facultyStream.is_open()) {
    string fileIn = "";
    try {
      while(getline(facultyStream, fileIn)) { //get the name first
        if(fileIn == ""){
          break;
        }
        name = fileIn;
        getline(facultyStream, fileIn); //get the ID num
        id = stoi(fileIn);
        getline(facultyStream, fileIn); //get the level
        level = fileIn;
        getline(facultyStream, fileIn); //get the department
        department = fileIn;
        getline(facultyStream, fileIn); //get the number of advisees
        int numAdv = stoi(fileIn);

        //ADD THE NEW FACULTY MEMBER TO THE TABLE
        Faculty *newFac = new Faculty(id, name, level, department);
        // cout << *newFac << endl;

        if(numAdv == 0){
          newFac->addAdvisee(0);
        }
        for(int i = 0; i < numAdv; i++) { //add studentID to advisees list
          getline(facultyStream, fileIn);
          int tempSID = stoi(fileIn);
          newFac->addAdvisee(tempSID);
        }

        masterFaculty.insert(id, *newFac);
        noFaculty = false;
      }
    }
    catch (const ifstream::failure& e) { //should catch a fail bit if trying to read past eof
      cout << "Tried to read past EOF" << endl;
      noFaculty = true;
    }
    catch (const invalid_argument &e) { //catches failed casts that can result from a corrupted file
      cout << "Error reading from file." << endl;
      noFaculty = true;
    }

    facultyStream.close();
  }
  else {
    cout << "facultyTable does not exist." << endl;
    noFaculty = true;
  }

  // Faculty Table end //

  // Student Table begin //
  ifstream studentStream;
  studentStream.open("studentTable.txt");
  bool noStudent = true;

  if(studentStream.is_open()) {
    string fileString = "";
    try {
      while(getline(studentStream, fileString)) { //get the name first
        if(fileString == ""){
          break;
        }
        Student newStu;

        newStu.name = fileString;
        getline(studentStream, fileString); //get the ID number
        newStu.id = stoi(fileString);
        getline(studentStream, fileString); //get the level
        newStu.level = fileString;
        getline(studentStream, fileString); //get the Major
        newStu.major = fileString;
        getline(studentStream, fileString); //get the gpa and cast to double.
        newStu.gpa = stod(fileString);
        getline(studentStream, fileString); //get the advisor ID
        newStu.facultyAdvisor = stoi(fileString);

        //ADD THE NEW STUDENT TO THE TABLE
        masterStudent.insert(newStu.id, newStu);
        noStudent = false;
      }
    }
    catch (const ifstream::failure& e) { //should catch a fail bit if trying to read past eof
      cout << "Tried to read past EOF" << endl;
      noStudent = true;
    }
    catch (const invalid_argument &e) { //catches failed casts that can result from a corrupted file
      cout << "Error reading from file." << endl;
      noStudent = true;
    }
  }
  else {
    cout << "studentTable does not exist." << endl;
    noStudent = true;
  }

  // Student Table End //

  // if (noStudent || noFaculty) {
  //   cout << "Error reading from files. Starting with blank tables." << endl;
  //   masterFaculty.recursiveDelete(masterFaculty.getRoot());
  //   masterStudent.recursiveDelete(masterStudent.getRoot());
  // }
}

// void Database::recoverDatabase(){
//   int id, gpa, advisor;
//   string name, level, department, major;
//   int lineType = 1, line = 1, numLines;
//   Faculty *f;
//   if(facFile->checkFile()){
//     numLines = facFile->getNumOfLines();
//     while(line < numLines){
//       switch(lineType){
//         case(1):
//           name = facFile->readLine(line);
//           lineType++;
//           line++;
//           break;
//         case(2):
//           try{
//             id = stoi(facFile->readLine(line));
//             lineType++;
//             line++;
//           }
//           catch (exception e)
//           {
//             cout << "\nError in text file.\n" << endl;
//             line = numLines;
//           }
//           break;
//         // case(3):
//         //   try{
//         //     id = stoi(facFile->readLine(line));
//         //     lineType++;
//         //     line++;
//         //   }
//         //   catch (exception e)
//         //   {
//         //     cout << "\nError in text file.\n" << endl;
//         //     line = numLines;
//         //   }
//         //   break;
//
//       }
//     }
//     // for(int i = 0; i < facFile->getNumOfLines(); i++){
//     //   facFile.readLine(i);
//     //   f = new Faculty(id, name, level, department)
//     //   if(facFile.readLine(i) != "----" && isAdvisee == true){
//     //     f.addAdvisee(stoi(facFile.readLine(i)));
//     //   }
//     //   masterFaculty.insert();
//     // }
//   }
//   if(studFile->checkFile()){
//     for(int i = 0; i < studFile->getNumOfLines(); i++){
//
//     }
//   }
// }

//shows all options for user to pick
void Database::showMenu(){
  cout << "\nMENU\n---------";
  cout << "\n1.  Print all students and their information" << endl;
  cout << "2.  Print all faculty and their information" << endl;
  cout << "3.  Find and display student information" << endl;
  cout << "4.  Find and display faculty information" << endl;
  cout << "5.  Get faculty advisor of student" << endl;
  cout << "6.  Get advisees of a faculty member" << endl;
  cout << "7.  Add a new student" << endl;
  cout << "8.  Delete a student" << endl;
  cout << "9.  Add a new faculty member" << endl;
  cout << "10. Delete a faculty member" << endl;
  cout << "11. Change a student’s advisor" << endl;
  cout << "12. Remove an advisee from a faculty member" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
}

//print all student info in ascending order
void Database::printStudents(){
  cout << "\n----------------------------------";
  cout << "\n\tStudent Records\n----------------------------------\n";
  masterStudent.printTree();
}

//print all faculty info in ascending order
void Database::printFaculty(){
  cout << "\n----------------------------------";
  cout << "\n\tFaculty Records\n----------------------------------\n";
  masterFaculty.printTree();
}    //#2
void Database::findStudent(){
  int studID;
  cout << "Enter the student ID: " << endl;
  cin >> studID;
  if(masterStudent.contains(studID)){
    cout << *masterStudent.find(studID) << endl;
  }
  else{
    cout << "ID not found." << endl;
  }
} //#3
void Database::findFaculty(){
  int facID;
  cout << "Enter the faculty ID: " << endl;
  cin >> facID;
  //checking if faculty ID is in the databas
  if(masterFaculty.contains(facID)){
    Faculty fac = *masterFaculty.find(facID);
    cout << fac << endl;
    //printing advisee information
    if(fac.hasAdvisee()){
      cout << "\n-----Advisees----- " << endl;
      for(int i = 0; i < fac.getNumAdvisees(); i++){
        if(masterStudent.contains(fac.getAdvisee(i)))
          cout << *masterStudent.find(fac.getAdvisee(i)) << endl;
      }
    }
  }
  else{
    cout << "ID not found." << endl;
  }
}  //#4
void Database::findAdvisor(){
  int studID;
  cout << "Enter the student ID: " << endl;
  cin >> studID;
  //checking is student is in database and then printing advisor
  if(masterStudent.contains(studID)){
    Student stud = *masterStudent.find(studID);
    cout << "Advisor ID: " << stud.getAdvisor() << endl;
  }
  else{
    cout << "ID not found." << endl;
  }
}   //#5
void Database::findAdvisees(){
  int facID;
  while(true){
    try{
      cout << "Enter Faculty ID: ";
      cin >> facID;
      break;
    }
    catch(exception e){
      cout << "Error. Please enter a valid integer." << endl;
      continue;
    }
  }
  if(masterFaculty.contains(facID)){
    Faculty fac = *masterFaculty.find(facID);// CHECK IF THIS WORKS
    if(fac.hasAdvisee()){
      cout << "\n-----Advisees----- " << endl;
      for(int i = 0; i < fac.getNumAdvisees(); i++){
        if(masterStudent.contains(fac.getAdvisee(i)))
          cout << *masterStudent.find(fac.getAdvisee(i)) << endl;
      }
    }
    else
      cout << "No advisees found.\n" << endl;
  }
  else{
    cout << "ID not found." << endl;
  }
}   //#6

void Database::addStudent(){//#7
  int id, advisor;
  double gpa;
  string name, level, major, userInput;
  while(true){
    try{
      cout << "Enter Student ID: ";
      cin >> id;

      if(masterStudent.contains(id) == true){
        cout << "The ID number you entered is already in use. Please enter another." << endl;
      }
      else
        break;
    }
    catch(exception e){
      cout << "Error. Please enter a valid integer." << endl;
      continue;
    }
  }
  //getting user input for student specs
  while(true){
    try{
      cout << "Please enter student name: ";
      cin.ignore();
      getline(cin, name);
      cout << "Please enter student level: ";
      getline(cin, level);
      cout << "Please enter student major: ";
      getline(cin, major);
      cout << "Please enter student GPA: ";
      getline(cin, userInput);
      gpa = stoi(userInput);
      cout << "Please enter faculty advisor ID: ";
      getline(cin, userInput);
      advisor = stoi(userInput);
      break;
    }
    catch (exception e)
    {
      cout << "Error. Please enter a valid input." << endl;
      continue;

    }
  }

  //checking if the given advisor ID is in database and adding student if it is
  if(masterFaculty.contains(advisor) == false)
    cout << "\nThe faculty advisor you entered is not in the database. Please add them before continuing." << endl;
  else{
    Student *s = new Student(id, name, level, major, gpa, advisor);
    masterStudent.insert(id, *s);
    masterFaculty.find(advisor)->addAdvisee(id);
    cout << "Student successfully added." << endl;
  }
}

void Database::deleteStudent(){ //#8
    int id;
    while(true){
      try{
        cout << "Enter Student ID to delete: ";
        cin >> id;
        break;
      }
      catch (exception e){
        cout << "\nError. Please enter an integer.\n" << endl;
        continue;
      }
    }
    //if the student is in the database, delete the student id from advisor's list and delete student
    if(masterStudent.contains(id)){
      int advisor = masterStudent.find(id)->getAdvisor();
      masterFaculty.find(advisor)->deleteAdvisee(id);
      masterStudent.deleter(id);
      cout << "Student successfully deleted." << endl;

    }
    else{
      cout << "\nStudent record not found." << endl;
    }
}

void Database::addFaculty(){ //#9
    int id, advisee;
    string name, level, department;
    while(true){
      try{
        cout << "Enter Faculty ID: ";
        cin >> id;

        if(masterFaculty.contains(id) == true){
          cout << "The ID number you entered is already in use. Please enter another." << endl;
        }
        else
          break;
      }
      catch(exception e){
        cout << "Error. Please enter a valid integer." << endl;
        continue;
      }
    }
    while(true){
      try{
        cout << "Please enter faculty name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Please enter faculty level: ";
        getline(cin, level);
        cout << "Please enter faculty department: ";
        getline(cin, department);
        break;
      }
      catch (exception e)
      {
        cout << "Error. Please enter a valid input." << endl;
        continue;

      }
    }

    Faculty *f = new Faculty(id, name, level, department);
    masterFaculty.insert(id, *f);
    cout << "Faculty member successfully added." << endl;

}

//TO DO: finish this
void Database::deleteFaculty(){//#10
  int id;
  while(true){
    try{
      cout << "Enter Faculty ID to delete: ";
      cin >> id;
      break;
    }
    catch(exception e){
      cout << "Error. Please enter a valid integer." << endl;
      continue;
    }
  }

  if(!masterFaculty.contains(id)){
    cout << "\nFaculty record not found." << endl;
  }
  //check for advisees to reassign
  else{
    Faculty *fac = masterFaculty.find(id);
    int numAdvisees = fac->getNumAdvisees();
    //need to reassign advisees to another advisor
    if(numAdvisees > 0){
      Student *stud;
      for(int i = 0; i < numAdvisees; i++){
        stud = masterStudent.find(fac->getAdvisee(i));
        int studID = stud->getID();
        while(true){
          try{
            int newAdvisor;
            cout << "Enter the replacement advisor for Student with ID# " << studID << ": " << endl;
            cin >> newAdvisor;
            if(masterFaculty.contains(newAdvisor) && newAdvisor != id)
              masterFaculty.find(newAdvisor)->addAdvisee(studID);
            else{
              cout << "ERROR: Faculty record not found. Here are the faculty members in the database:" << endl;
              printFaculty();
              continue;
            }
            break;
          }
          catch(exception e){
            cout << "ERROR: Please enter an integer ID number." << endl;
            continue;
          }

        }
      }
    }

    masterFaculty.deleter(id);
    cout << "Faculty member successfully deleted." << endl;
  }
}

void Database::changeAdvisor()  //#11
{
  int facID, studID;
  while(true){
    try{
      cout << "Enter Student ID: ";
      cin >> studID;

      break;
    }
    catch(exception e){
      cout << "ERROR: Please enter a valid integer." << endl;
      continue;
    }
  }

  // id dne
  if(masterStudent.contains(studID)){
    Student *stud = masterStudent.find(studID);
    cout << "Enter a new advisor ID: ";
    cin >> facID;
    if(masterFaculty.contains(facID)){
      Faculty *newAdvisor = masterFaculty.find(facID);
      Faculty *prevAdvisor = masterFaculty.find(stud->getAdvisor());
      if(prevAdvisor->containsAdvisee(studID)){
        prevAdvisor->deleteAdvisee(studID);
      }
      else
        cout << "ERROR: Student is not an advisee of this advisor." << endl;

      if(!newAdvisor->containsAdvisee(studID)){
        newAdvisor->addAdvisee(studID);
      }
      else
        cout << "ERROR: Student already has this advisor." << endl;

      stud->setAdvisor(facID);
    }
    else
      cout << "ERROR: Faculty record not found.\n" << endl;
    }

  else
    cout << "ERROR: Student record not found." << endl;

}

void Database::removeAdvisee(){ //#12
    int facID, studID;
    while(true){
      try{
        cout << "Enter Faculty ID: ";
        cin >> facID;

        break;
      }
      catch(exception e){
        cout << "ERROR: Please enter a valid integer." << endl;
        continue;
      }
    }

    // id dne
    if(masterFaculty.contains(facID)){
      Faculty fac = *masterFaculty.find(facID);
      fac.advisees.printList();
      //printing all advisees of the faculty member for user to choose from
      if(fac.hasAdvisee()){
        cout << "\n-----Advisees----- " << endl;
        cout << "Num: " << fac.getNumAdvisees() << endl;
        for(int i = 0; i < fac.getNumAdvisees(); i++){
          if(masterStudent.contains(fac.getAdvisee(i)))
            cout << *masterStudent.find(fac.getAdvisee(i)) << endl;
        }
        //asking user to input which student to remove
        cout << "Enter the advisee ID you would like to remove: ";
        cin >> studID;
        if(masterStudent.contains(studID)){
          Student *stud = masterStudent.find(studID);
          if(stud != NULL){
            if(fac.containsAdvisee(studID)){
              //checking that there is an alternate advisor to advise the student
              if(masterFaculty.size != 1){
                fac.deleteAdvisee(studID);
                //asking user to select new advisor for student
                while(true){
                  try{
                    int newAdvisor;
                    cout << "Enter the replacement advisor for Student with ID# " << studID << ": " << endl;
                    cin >> newAdvisor;
                    if(masterFaculty.contains(newAdvisor))
                      masterFaculty.find(newAdvisor)->addAdvisee(studID);
                    else{
                      cout << "Faculty record not found. Here are the faculty members in the database:" << endl;
                      printFaculty();
                      continue;
                    }
                    break;
                  }
                  catch(exception e){
                    cout << "Error. Please enter an integer ID number." << endl;
                    continue;
                  }

                }
              }
              else
                cout << "ERROR: No alternate faculty member to advise student. Please add a faculty member before removing advisee." << endl;
            }
            else
              cout << "ERROR: Student is not an advisee of this advisor." << endl;
          }
        }
        else
          cout << "ERROR: Advisee not found.\n" << endl;

      }
      else
        cout << "ERROR: No advisees found for this faculty member.\n" << endl;
    }
    else
      cout << "ERROR: Faculty record not found." << endl;


}
void Database::rollback(){

}   //#13
void Database::exitDatabase(){
  ofstream fout;
  fout.open("facultyTable.txt");
  fout << masterFaculty.getData() << endl;
  fout.close();
  fout.open("studentTable.txt");
  fout << masterStudent.getData() << endl;
  fout.close();
}   //#14
