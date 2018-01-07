#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>

class Queue {
  public:
    Queue();
    int size() const;
    bool isEmpty() const;
    void enqueue(int value);
    int dequeue();

  private:
    class Node {
      public:
        Node() : data(0), next(NULL){};
        Node(int value) : data(value), next(NULL){};
        int data;
        Node *next;
    };

    Node *front;
    Node *rear;
};

#endif
