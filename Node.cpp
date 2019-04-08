#include <iostream>
#include "Node.h"

Node::Node() : next(nullptr)
{
}

Node::Node(struct loc data){
  this->data = data;
  this->next = nullptr;
}

Node::Node(struct loc data, Node *next){
  this->data = data;
  this->next = next;
}

void Node::setData(struct loc data){
  this->data = data;
}

void Node::setNext(Node *next){
  this->next = next;
}

struct loc Node::getData(){
  return data;
}

struct loc &Node::getRef(){
  return data;
}

Node* Node::getNext(){
  return next;
}
