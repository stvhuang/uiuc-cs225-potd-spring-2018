#include "Node.h"
#include <iostream>
using namespace std;

void mergeList(Node *first, Node *second) {
    // your code here!
    Node *f = first;
    Node *tmp = NULL;

    if (first == NULL && second == NULL) {
        return;
    } else if (first == NULL && second != NULL) {
        first = second;
        return;
    }

    while (1) {
        if (f->next_ == NULL) {
            f->next_ = second;
            return;
        } else if (second == NULL) {
            return;
        } else {
            tmp = second->next_;
            second->next_ = f->next_;
            f->next_ = second;
            second = tmp;
            f = f->next_->next_;
        }
    }
}

Node::Node() { numNodes++; }

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() { numNodes--; }

int Node::numNodes = 0;
