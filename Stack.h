//header file GenStack.h
#include <iostream>
#include <string.h>
using namespace std;

template <class S>
class Stack{
  int top;
  int mSize;

  S *myArray;
  public:
    Stack();
    Stack(int maxSize);
    ~Stack();
    void push(S data);
    S pop();
    S peek();
    bool isFull();
    bool isEmpty();
    int getSize();
    void printStack();
};

template <class S>
Stack<S>::Stack(){
  myArray = new S[256];
  mSize = 256;
  top = -1; //because -1 is not a valid index in the array
}

template <class S>
Stack<S>::Stack(int maxSize){
  myArray = new S[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class S>
Stack<S>::~Stack(){
  delete [] myArray;
}

template <class S>
void Stack<S>::push(S data){
  //checking if the stack is full and making it bigger if so
  if(isFull())
  {
      S* newArray = new S[mSize * 2];
      memcpy(newArray, myArray, sizeof(S) * mSize);
      cout << sizeof(myArray) << endl;
      delete[] myArray;
      myArray = newArray;
      myArray[++top] = data;
      mSize *= 2;
      cout << "The stack size is now: " << mSize << endl;
   }
   else
     myArray[++top] = data;
}

template <class S>
S Stack<S>::pop(){
  try{
    //check if empty before proceeding
    if(isEmpty()){
      throw "empty"s;
    }
    return myArray[top--];
  }
  catch(string e){
    return '\0';
  }
}

template <class S>
S Stack<S>::peek(){
  try{
    //check if empty before proceeding
    if(isEmpty()){
      throw "empty"s;
    }
    return myArray[top];
  }
  catch(string e){
    return '\0';
  }
}

template <class S>
void Stack<S>::printStack(){
  for(int i = 0; i < sizeof(myArray); i++){
    if(myArray[i] != '\0')
      cout << myArray[i] << ", ";
  }
  cout << endl;
}


template <class S>
bool Stack<S>::isFull(){
  return (top == mSize-1);
}

template <class S>
bool Stack<S>::isEmpty(){
  return (top == -1);
}

template <class S>
int Stack<S>::getSize(){
  return top + 1;
}
