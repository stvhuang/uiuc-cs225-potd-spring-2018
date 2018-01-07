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

Node *listUnion(Node *first, Node *second) {
    // your code here
    // return NULL;
    if ((first == NULL) && (second == NULL)) {
        return NULL;
    }

    Node *head;

    if (first == NULL) {
        head = new Node(*second);
        cout << __LINE__ << second->data_ << endl;
        second = second->next_;
    } else if (second == NULL) {
        head = new Node(*first);
        first = first->next_;
    } else {
        if (first->data_ < second->data_) {
            head = new Node(*first);
            first = first->next_;
        } else {
            head = new Node(*second);
            second = second->next_;
        }
    }

    head->next_ = NULL;
    Node *curr = head;

    while ((first != NULL) || (second != NULL)) {
        if (first == NULL) {
            if (!isInList(head, second->data_)) {
                curr->next_ = new Node(*second);
                second = second->next_;
                curr->next_->next_ = NULL;
                curr = curr->next_;
            } else {
                second = second->next_;
            }
        } else if (second == NULL) {
            if (!isInList(head, first->data_)) {
                curr->next_ = new Node(*first);
                first = first->next_;
                curr->next_->next_ = NULL;
                curr = curr->next_;
            } else {
                first = first->next_;
            }
        } else {  // first != NULL && second != NULL
            if (first->data_ < second->data_) {
                if (!isInList(head, first->data_)) {
                    curr->next_ = new Node(*first);
                    first = first->next_;
                    curr->next_->next_ = NULL;
                    curr = curr->next_;
                } else {
                    first = first->next_;
                }
            } else {
                if (!isInList(head, second->data_)) {
                    curr->next_ = new Node(*second);
                    second = second->next_;
                    curr->next_->next_ = NULL;
                    curr = curr->next_;
                } else {
                    second = second->next_;
                }
            }
        }
    }

    return head;
}

Node::Node() { numNodes++; }

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() { numNodes--; }

int Node::numNodes = 0;
