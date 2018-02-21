#include "Node.h"
#include <iostream>

using namespace std;

bool isInList(Node *head, int data) {
  while (head != NULL) {
    if (head->data_ == data) {
      return true;
    }
    head = head->next_;
  }

  return false;
}

void printList2(Node *head) {
  cout << "\n\n\n";
  while (head != NULL) {
    cout << head->data_ << endl;
    head = head->next_;
  }
  cout << "\n\n\n";
  return;
}

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
  Node *head = NULL;
  Node *tail = NULL;
  Node *myFirst = first;
  Node *mySecond = second;

  if ((first == NULL) && (second == NULL)) {
      return NULL;
  } else if (first == NULL) {
    head = new Node(*second);
    head->next_ = NULL;
    tail = head;
    second = second->next_;

    while (second != NULL && !isInList(head, second->data_)) {
      tail->next_ = new Node(*second);
      tail = tail->next_;
      tail->next_ = NULL;
    }

    return head;
  } else if (second == NULL) {
    head = new Node(*first);
    head->next_ = NULL;
    tail = head;
    first = first->next_;

    while (first != NULL && !isInList(head, first->data_)) {
      tail->next_ = new Node(*first);
      tail = tail->next_;
      tail->next_ = NULL;
    }

    return head;
  } else {  // (first != NULL) && (second != NULL)
    while (myFirst != NULL) {
      if (!isInList(second, myFirst->data_) && !isInList(head, myFirst->data_)) {
        if (head == NULL) {
          head = new Node(*myFirst);
          head->next_ = NULL;
          tail = head;
        } else {
          tail->next_ = new Node(*myFirst);
          tail = tail->next_;
          tail->next_ = NULL;
        }
      }
      myFirst = myFirst->next_;
    }

    while (mySecond != NULL) {
      if (!isInList(first, mySecond->data_) && !isInList(head, mySecond->data_)) {
        if (head == NULL) {
          head = new Node(*mySecond);
          head->next_ = NULL;
          tail = head;
        } else {
          tail->next_ = new Node(*mySecond);
          tail = tail->next_;
          tail->next_ = NULL;
        }
      }
      mySecond = mySecond->next_;
    }
    return head;
  }
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
