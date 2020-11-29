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
  return id;
}
void Person::setID(int i){
  id = i;
}
