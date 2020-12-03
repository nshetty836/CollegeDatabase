//header file Stack.h
#include <iostream>
#include <string.h>
using namespace std;

template <class S>
class Stack{
  static const int ARR_SIZE = 5; //only five rollbacks kept
  public:
    class EmptyStackException{
    public:
      EmptyStackException(const string& err) {
        errorMsg = err;
      }
      string getError(){
        return errorMsg;
      }
    private:
      string errorMsg;
    };
    Stack();
    Stack(int mSize);
    ~Stack();
    void push(S data);
    S pop() throw(EmptyStackException);
    S peek() throw(EmptyStackException);
    bool isFull();
    bool isEmpty();
    int getSize();
    void printStack();
    int top;
    int maxSize;

    S *myArray;

};

template <class S>
Stack<S>::Stack(){
  maxSize = ARR_SIZE;
  myArray = new S[maxSize];
  top = -1; //because -1 is not a valid index in the array
}

template <class S>
Stack<S>::Stack(int mSize){
  myArray = new S[mSize];
  maxSize = mSize;
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
      S* newArray = new S[maxSize * 2];
      memcpy(newArray, myArray, sizeof(S) * maxSize);
      cout << sizeof(myArray) << endl;
      delete[] myArray;
      myArray = newArray;
      myArray[++top] = data;
      maxSize *= 2;
      cout << "The stack size is now: " << maxSize << endl;
   }
   else
     myArray[++top] = data;
}

template <class S>
S Stack<S>::pop() throw(EmptyStackException){
  if(isEmpty()){
    throw EmptyStackException("Could not pop from empty stack.");
  }
  return myArray[top--];
}

template <class S>
S Stack<S>::peek() throw(EmptyStackException){
    //check if empty before proceeding
  if(isEmpty()){
    throw EmptyStackException("Could not peek from empty stack.");
  }
  return myArray[top];

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
  return (top == maxSize-1);
}

template <class S>
bool Stack<S>::isEmpty(){
  return (top == -1);
}

template <class S>
int Stack<S>::getSize(){
  return top + 1;
}
