#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

class Stack {
public:
  Stack();
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
private:
  class Node {
    public:
      Node(int data) : data_(data), prev_(NULL) {}
      int data_;
      Node *prev_;
  };

  Node *top_;
};

#endif
