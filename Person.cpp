#include "Person.h"
using namespace std;

Person::Person(){

}

Person::~Person(){

}

string Person::getName(){
  return name;
}

string Person::getLevel(){
  return level;
}

int Person::getID(){
  return idNum;
}
void Person::setID(int i){
  idNum = idNum;
}
