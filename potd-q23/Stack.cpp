#include "Stack.h"

Stack::Stack() : top_(NULL) {}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  int count = 0;
  Node *temp = top_;
  while (temp != NULL) {
    ++count;
    temp = temp->prev_;
  }
  return count;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  if (top_ == NULL) {
    return true;
  } else {
    return false;
  }
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
  Node *temp  = new Node(value);
  temp->prev_ = top_;
  top_ = temp;
  temp = NULL;
  return;
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  Node *temp = top_;
  int result = temp->data_;
  top_ = top_->prev_;
  delete temp;
  temp = NULL;
  return result;
}
