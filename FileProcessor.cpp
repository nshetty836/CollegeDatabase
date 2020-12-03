#include "FileProcessor.h"

using namespace std;

//constructor
FileProcessor::FileProcessor(){}

//overloaded constructor-
FileProcessor::FileProcessor(string fname){
  fileName = fname;
}

FileProcessor::~FileProcessor(){
}


//checks if file can be opened
bool FileProcessor::checkFile(){
  fileIn.open(fileName);
  if (fileIn.is_open() == false)
  {
    return false;
  }
  fileIn.close();
  return true;
}


//returning file as a string
string FileProcessor::readFile(){
  fileIn.open(fileName);
  string tempLine;

  while(fileIn.eof() == false){
    fileIn >> tempLine;
    fileText += tempLine;
  }
  fileIn.close();
  return fileText;
}

string FileProcessor::readLine(int num){
  fileIn.open(fileName);
  string line;
  lineNum = 0;

  while(lineNum != num){
    getline(fileIn, line);
    lineNum++;
  }
  fileIn.close();
  return line;
}

int FileProcessor::getLineNum(){
  return lineNum;
}

int FileProcessor::getNumOfLines(){
  fileIn.open(fileName);
  string line;

  while(getline(fileIn, line)){
    numOfLines++;
  }
  fileIn.close();
  return numOfLines;
}
//writing given string to file
void FileProcessor::writeFile(string outFileName, string output){
    ofstream fout;
    // override whatever content is in the file
    fout.open(outFileName);
    fout << output << endl;
    fout.close();
}

//clear file
void FileProcessor::clearFile(string outFileName){
  ofstream fout;
  fout.open(outFileName);
  fout.close();
}
