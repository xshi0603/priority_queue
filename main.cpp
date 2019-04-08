#include <iostream>
#include "List.h"

int main()
{

  struct loc d = {20, 30, -1};

  List *l = new List(d);
  std::cout << l->getDebugString();

  cout << l->empty() << endl;

  std::cout << "Testing insert" << endl;
  l->insert({0, 0, -1});
  l->insert({2, 9, -1});
  l->insert({13, 4, -1});
  l->insert({6, 20, -1});
  l->insert({1, 2, -1});
  l->insert({-5, -3, -1});
  l->insert({100, 100, -1});
  l->insert({20, 30, -1});
  std::cout << l->getDebugString();
  std::cout << endl;

  cout << l->empty() << endl;

  l->remove();
  std::cout << l->getDebugString();
  std::cout << endl;


  /*
  struct loc temp = l->front();
  std::cout << temp.r << " " << temp.c << " " << temp.priority << endl;
  */
  /*
  std::cout << "Testing push_back" << endl;
  l->push_back("one");
  l->push_back("two");
  l->push_back("three");
  l->push_back("four");
  std::cout << l->getDebugString();
  std::cout << endl;

  std::cout << "Testing at" << endl;
  std::cout << "The element at index 3 is: " << l->at(3) << endl;
  std::cout << endl;

  std::cout << "Testing insert" << endl;
  l->insert(2, "hello1");  
  std::cout << l->getDebugString();
  std::cout << endl;

  std::cout << "Testing remove" << endl;
  l->remove(3);
  std::cout << l->getDebugString();
  std::cout << endl;

  std::cout << "Testing []" << endl;
  std::cout << "l[1]:" << (*l)[1] << endl;

  std::cout << "Testing size" << endl;
  std::cout << "Size: " << l->size() << endl;
  */

  return 0;
}
