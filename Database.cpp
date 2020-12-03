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
  int id, gpa, advisor, numAdv;
  string name, level, department, major, user;
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
        numAdv = stoi(fileIn);


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
    catch (const ifstream::failure& e) { //catches if the program tries to read past the end of file
      cout << "Tried to read past EOF" << endl;
      noFaculty = true;
    }
    catch (const invalid_argument &e) { //catches failed casts if the file is in the wrong format
      cout << "Error reading from Faculty Table file." << endl;
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
        Student newStud;

        newStud.name = fileString;
        getline(studentStream, fileString); //get the ID number
        newStud.id = stoi(fileString);
        getline(studentStream, fileString); //get the level
        newStud.level = fileString;
        getline(studentStream, fileString); //get the Major
        newStud.major = fileString;
        getline(studentStream, fileString); //get the gpa and cast to double.
        newStud.gpa = stod(fileString);
        getline(studentStream, fileString); //get the advisor ID
        newStud.facultyAdvisor = stoi(fileString);

        //ADD THE NEW STUDENT TO THE TABLE
        masterStudent.insert(newStud.id, newStud);
        noStudent = false;
      }
    }
    catch (const ifstream::failure& e) { //should catch a fail bit if trying to read past eof
      cout << "Tried to read past EOF" << endl;
      noStudent = true;
    }
    catch (const invalid_argument &e) { //catches failed casts that can result from a corrupted file
      cout << "Error reading from Student Table file." << endl;
      noStudent = true;
    }
  }
  else {
    cout << "studentTable does not exist." << endl;
    noStudent = true;
  }

  // Student Table End //

  if (noStudent || noFaculty) {
    cout << "\nStarting with empty database." << endl;
    masterFaculty.destroyRecursive(masterFaculty.root);
    masterStudent.destroyRecursive(masterStudent.root);
  }
}

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
  if(masterStudent.size == 0){
    cout << "No student records." << endl;
  }
}

//print all faculty info in ascending order
void Database::printFaculty(){
  cout << "\n----------------------------------";
  cout << "\n\tFaculty Records\n----------------------------------\n";
  masterFaculty.printTree();
  if(masterFaculty.size == 0){
    cout << "No faculty records." << endl;
  }
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

//asks user for information for student to be added to the database
void Database::addStudent(){
  int id, advisor;
  double gpa;
  string name, level, major, userInput;
  //checking for valid student ID number and whether it is already in data base
  while(true){
    try{
      cout << "Enter Student ID: ";
      cin.ignore();
      getline(cin, userInput);
      id = stoi(userInput);

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
      // cin.ignore();
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
    Student *newStudent = new Student(id, name, level, major, gpa, advisor);
    masterStudent.insert(id, *newStudent);
    masterFaculty.find(advisor)->addAdvisee(id);
    cout << "\nStudent successfully added.\n" << endl;

    //for rollback
    Transaction tran(7, *newStudent);
    transactions.push(tran);

    delete newStudent;
  }
}

void Database::deleteStudent(){ //#8
    int id;
    //getting id number
    cout << "Enter Student ID to delete: ";
    cin >> id;
    //if the student is in the database, delete the student id from advisor's list and delete student
    if(masterStudent.contains(id)){
      Student *stud = masterStudent.find(id);
      int advisor = stud->getAdvisor();
      masterFaculty.find(advisor)->deleteAdvisee(id);

      //for rollback
      Transaction tran(8, *stud);
      transactions.push(tran);

      masterStudent.deleter(id);
      cout << "\nStudent successfully deleted.\n" << endl;

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
    cout << "\nFaculty member successfully added.\n" << endl;

    //for rollback
    Transaction tran(9, *f);
    transactions.push(tran);

    delete f;
}

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
            if(masterFaculty.contains(newAdvisor) && newAdvisor != id){
              masterFaculty.find(newAdvisor)->addAdvisee(studID);
            }
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

    //for rollback
    Transaction tran(10, *fac);
    transactions.push(tran);

    masterFaculty.deleter(id);
    cout << "\nFaculty member successfully deleted.\n" << endl;
  }
}

void Database::changeAdvisor()  //#11
{
  int facID, studID;
  Faculty *newAdvisor, *prevAdvisor;
  Student *stud;

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
    stud = masterStudent.find(studID);
    cout << "Enter a new advisor ID: ";
    cin >> facID;
    if(masterFaculty.contains(facID)){
      newAdvisor = masterFaculty.find(facID);
      prevAdvisor = masterFaculty.find(stud->getAdvisor());
      prevAdvisor->deleteAdvisee(studID);

      if(!newAdvisor->containsAdvisee(studID)){
        newAdvisor->addAdvisee(studID);
      }
      else
        cout << "ERROR: Student already has this advisor." << endl;

      //for rollback
      Transaction tran(11, *stud, *newAdvisor);
      transactions.push(tran);

      stud->setAdvisor(facID);
      cout << "\nAdvisor successfully changed.\n" << endl;
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
      Faculty *fac = masterFaculty.find(facID);
      fac->advisees.printList();
      //printing all advisees of the faculty member for user to choose from
      if(fac->hasAdvisee()){
        cout << "\n-----Advisees----- " << endl;
        cout << "Num: " << fac->getNumAdvisees() << endl;
        for(int i = 0; i < fac->getNumAdvisees(); i++){
          if(masterStudent.contains(fac->getAdvisee(i)))
            cout << *masterStudent.find(fac->getAdvisee(i)) << endl;
        }
        //asking user to input which student to remove
        cout << "Enter the advisee ID you would like to remove: ";
        cin >> studID;
        if(masterStudent.contains(studID)){
          Student *stud = masterStudent.find(studID);
          if(stud != NULL){
            if(fac->containsAdvisee(studID)){
              //checking that there is an alternate advisor to advise the student
              if(masterFaculty.size != 1){
                cout << "DELETING: " << endl;
                fac->deleteAdvisee(studID);
                //asking user to select new advisor for student
                while(true){
                  try{
                    int newAdvisor;
                    cout << "Enter the replacement advisor for Student with ID# " << studID << ": " << endl;
                    cin >> newAdvisor;
                    if(masterFaculty.contains(newAdvisor)){
                      masterFaculty.find(newAdvisor)->addAdvisee(studID);
                      stud->setAdvisor(newAdvisor);
                    }
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
                cout << "\nAdvisee successfully removed.\n" << endl;
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
  bool hasTransaction = true;
  Transaction lastTrans;
  try {
    lastTrans = transactions.pop();
  }
  catch (const Stack<Transaction>::EmptyStackException &e) {
    cout << "No commands to roll back." << endl;
    hasTransaction = false;
  }

  if(hasTransaction) {
    if(lastTrans.num == 7) { //undo add student
      masterStudent.deleter(lastTrans.s.id);
      cout << "Last added student has been removed." << endl;
    }
    else if(lastTrans.num == 8) { //undo delete student
      cout << "Last removed student has been added." << endl;
      masterStudent.insert(lastTrans.s.id, lastTrans.s);

      //update the advisor with the student
      Faculty *oldAdvisor = masterFaculty.find(lastTrans.s.facultyAdvisor);
      oldAdvisor->addAdvisee(lastTrans.s.id);

    }
    else if(lastTrans.num == 9) { //undo add Faculty
      cout << "Last added faculty member has been removed." << endl;
      masterFaculty.deleter(lastTrans.f.id);
    }
    else if(lastTrans.num == 10) { //undo delete Faculty
      cout << "Last removed faculty member has been added." << endl;
      masterFaculty.insert(lastTrans.f.id, lastTrans.f);

      for(int i = 0; i < lastTrans.f.getNumAdvisees(); i++) {
        //update advisor for each student
        Student* stud = masterStudent.find(lastTrans.f.getAdvisee(i));
        stud->setAdvisor(lastTrans.f.id);
      }
    }
    else if(lastTrans.num == 11) { //undo change advisor
      cout << "Student advisor changed back to old advisor." << endl;
      //the Transaction obj's Student has the OLD advisor
      //and Faculty is the NEW advisor.

      //remove the advisee from the NEW advisor
      Faculty *newAdv = masterFaculty.find(lastTrans.f.id);
      newAdv->deleteAdvisee(lastTrans.s.id);
      //add the student back to the OLD advisor.
      Faculty *oldAdv = masterFaculty.find(lastTrans.s.facultyAdvisor);
        oldAdv->addAdvisee(lastTrans.s.id);

      //change the student's advisor ID.
      Student *stud = masterStudent.find(lastTrans.s.id);
      stud->setAdvisor(lastTrans.s.facultyAdvisor);
    }

  }
}

//write the data base to a file
void Database::writeToFile(){
  ofstream fout;
  fout.open("facultyTable.txt");
  fout << masterFaculty.getData() << endl;
  fout.close();
  fout.open("studentTable.txt");
  fout << masterStudent.getData() << endl;
  fout.close();
}  
