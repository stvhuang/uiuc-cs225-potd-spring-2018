#include "Queue.h"

Queue::Queue() : front(NULL), rear(NULL) {}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  if (isEmpty()) {
    return 0;
  } else {
    int count = 1;
    Node *curr = front;
    while (curr != rear) {
      curr = curr->next;
      ++count;
    }
    curr = NULL;
    return count;
  }
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  if (front == NULL && rear == NULL) {
    return true;
  } else {
    return false;
  }
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
  if (front == NULL && rear == NULL) {
    front = new Node(value);
    rear = front;
  } else {
    rear->next = new Node(value);
    rear = rear->next;
  }
  return;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  int result = 0;
  if (front == rear) {
    result = front->data;
    delete front;
    front = NULL;
    rear = NULL;
  } else {
    result = front->data;
    Node *temp = front;
    front = front->next;
    delete temp;
    temp = NULL;
  }
  return result;
}
