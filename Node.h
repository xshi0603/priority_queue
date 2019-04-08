#pragma once

struct loc {
  int r, c, priority;
};

class Node{
 private:
  struct loc data;
  Node *next;
 public:
  Node();
  Node(struct loc data);
  Node(struct loc data, Node* next);
  void setData(struct loc data);
  void setNext(Node *next);
  struct loc getData();
  struct loc& getRef();
  Node* getNext();  
};
