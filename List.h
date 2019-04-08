#include <string>
#include <cmath>
#include "Node.cpp"
#pragma once

using std::cout;
using std::endl;
using std::to_string;

class List{
 private:
  Node *head;
  int currSize;
  struct loc destination;
 public:
  List(struct loc newDest);
  ~List();
  void insert(struct loc data);
  std::string getDebugString();
  //void push_back(std::string); // inserts at the end of the vector
  int size(); // returns the size
  struct loc &at(int); // returns the element at a location
  //std::string insert(int,std::string); // inserts string at location  
  void remove(); // removes the element at the front
  void remove(int i); // removes the element at location i
  struct loc &operator[](int); // overloaded square brackets
  struct loc front();
  bool empty();
};

int getDistance(struct loc a, struct loc b);
