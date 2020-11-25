using namespace std;
#include <iostream>
#include <cstddef>
#include "List.h"

//List node used to implement the Doubly linked list
template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T* d);
    ~ListNode();
    T* data;
    ListNode<T> *next;
    ListNode<T> *prev;
};

template <class T>
ListNode<T>::ListNode(){
  data = 0;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T* d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  delete next;
  delete prev;
}

template <class T>
class DoublyLinkedList: public List<T>{
//single linked List
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertFront(T* d);
    void insertBack(T* d);
    T* removeFront(); 
    T* removeBack();
    T* deletePos(int pos);
    T* removeNode(T* key);
    T* getFront();
    T* getBack();
    void printList();
    int find(T* value);
    T* getAllValues();
    T* getNode(int index);

  private:
    ListNode<T> *front;
    ListNode<T> *back;
    int size;

};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //RESEARCH in ZYBOOKS
}

//inserts node at front of list
template <class T>
void DoublyLinkedList<T>::insertFront(T* d){
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0){
    //empty List
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

//inserts node at back of list
template <class T>
void DoublyLinkedList<T>::insertBack(T* d){
  ListNode<T> *node = new ListNode<T>(d);
  if(front == NULL){
    //empty List
    front = node;
  }
  else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  ++size;
}

//removes front node from list
template <class T>
T* DoublyLinkedList<T>::removeFront(){
  ListNode<T>* curr = front;
  if(back == NULL)
    return NULL;
  if(front->next == NULL){
    back = NULL;
  }
  else{
    front->next->prev = NULL;
  }
  front = front->next;
  curr->next = NULL;
  T* temp = curr->data;

  --size;
  delete curr;
  return temp;
}

//removes the node at back of the list
template <class T>
T* DoublyLinkedList<T>::removeBack(){
  if(back == NULL) return NULL;

	ListNode<T>* curr = back;

	if(back->prev == NULL)
    back = NULL;
	else
    back->prev->next = NULL;

	back = back->prev;
  size--;
  curr->prev = NULL;
  T* temp = back->data;

	delete curr;
  return temp;
}

//prints the entire list
template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr -> data->toString() << endl; //printing out data in current pointer
    curr = curr -> next;
  }
}

//returns the front node of list
template <class T>
T* DoublyLinkedList<T>::getFront(){
  if(front == NULL) return NULL;

  return front->data;
}

//returns the back node of list
template <class T>
T* DoublyLinkedList<T>::getBack(){
  if(back == NULL) return NULL;

  return back->data;
}

template <class T>
T* DoublyLinkedList<T>::getNode(int index){
  int pos = 0;
  ListNode<T> *curr = front;

  while(curr != NULL){
    if(pos == index){
      return curr->data;
    }
    pos++;
    curr = curr->next;
  }
  return NULL;
}

template <class T>
int DoublyLinkedList<T>::find(T* value){
  int pos = -1;
  ListNode<T> *curr = front;

  while(curr != NULL){
    //iterate until we reach the end and hopefully we find what we're looking for
    ++pos;
    if(curr->data == value) //if value is found break the loop
      break;
    else
      curr = curr -> next;  //checking next pointer
  }

  if(curr == NULL)   //value not found, reset pos to -1
    pos = -1;

  return pos;

}

//removing node at a given position
template <class T>
T* DoublyLinkedList<T>::deletePos(int pos){
  int p = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  //iterate to the correct position
  while(p != pos){
    prev = curr;
    curr = curr->next;
    p++;
  }
  //we found the position and our pointers are in their respective positions

  prev->next = curr ->next;
  curr->next = NULL;

  T* temp = curr->data;
  size--;

  delete curr;
  return temp;
}

//searching for node by value and then removing it
template <class T>
T* DoublyLinkedList<T>::removeNode(T* key){
  ListNode<T> *curr = front;

  //check if empty before proceeding **importanT*
  if(size == 0){
    return NULL;
  }
  //if not empty, you can leverage find() to determing if value exists

  while(curr->data != key){
    //iterate until we reach the end and hopefully we find what we're looking for
    curr = curr->next;

    if(curr == NULL){ //reached the end of the list and value does not exist
      return NULL;  //exits the function
    }
  }

  //if i make it here i found the node that needs to be deleted

  //3 cases: front, back, or between
  if(curr == front ){
    front = curr -> next;
    front->prev = NULL;
  }
  else if(curr == back){
    back = curr->prev;
    back->next = NULL;

  }
  else{ //between front and back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;

  T* temp = curr->data;
  size--;
  delete curr;

  return temp;

}
