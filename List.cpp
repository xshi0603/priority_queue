#include <iostream>

#include <string>
#include "List.h"

List::List(struct loc newDest){
  struct loc dummy = {-1, -1, -1};
  head = new Node(dummy, nullptr);
  currSize = 0;
  destination = newDest;
}

List::~List(){
  std::cout << "In the destructor\n";
  //if (head != nullptr){
  Node *t,*t2;
  
  t=head->getNext();
  while (t!=nullptr){
    t2=t;
    t=t->getNext();
    delete t2;
  }
  //} 
}

int getDistance(struct loc currentPos, struct loc destination) {
  return (abs(currentPos.r - destination.r) + abs(currentPos.c - destination.c));
}

void List::insert(struct loc data){
  //if (head==nullptr)
  //  head=t;
  //else{
  //
  //head->setNext(t);

  Node *t = new Node(data,head);


  data.priority = getDistance(data, destination);
  Node *inserter = new Node(data);

  while (t->getNext() != nullptr && data.priority > t->getNext()->getData().priority) { //while next is less than data and not null
    t = t->getNext();
  }

  inserter->setNext(t->getNext());
  t->setNext(inserter);

  currSize++;
}

std::string List::getDebugString(){
  std::string s = "";
  Node *t = head;
  while (t != nullptr){
    //s = s + t->getData()+"->";
    s = s + to_string(t->getData().r) + "," + to_string(t->getData().c) + "," + to_string(t->getData().priority) + "->";
    t=t->getNext();
  }
  s=s+" NULL\n";
  return s;
}
/*
void List::push_back(std::string data){ // inserts at the end of the vector

  Node *newNode = new Node(data);
  Node *t = head;
  while (t->getNext() != nullptr){
    t=t->getNext();
  }
  t->setNext(newNode);
  currSize++;

}
*/
int List::size(){ // returns the size
  return currSize;
}


struct loc &List::at(int index){ // returns the element at a location
  Node *t = head;
  for (int i = 0; i < index + 1; i++) {
    t=t->getNext();
  }
  return t->getRef();
}
/*
std::string List::insert(int index,std::string data){ // inserts string at location

  Node *t = head;
  Node *newNode;

  for (int i = 0; i < index; i++) {
    t=t->getNext();
  }

  newNode = new Node(data, t->getNext());
  t->setNext(newNode);
  currSize++;
  return t->getNext()->getData();

}
*/
void List::remove(int input) { // removes the element at location i

  Node *t = head;
  Node *temp = t->getNext();

  int counter = 0;

  while (counter < input) {
    t = temp;
    temp = temp->getNext();
    counter++;
  }

  t->setNext(temp->getNext()); 
  delete temp;
  
  currSize--;
}

struct loc &List::operator[](int input) { // overloaded square brackets
  return at(input);
}

