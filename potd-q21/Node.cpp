#include "Node.h"

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

Node *listIntersection(Node *first, Node *second) {
    // your code here
    Node *head = NULL;
    Node *curr = NULL;

    if ((first == NULL) || (second == NULL)) {
        return NULL;
    } else {  // (first != NULL) && (second != NULL)
        while (first != NULL) {
            if (isInList(second, first->data_) &&
                !(isInList(head, first->data_))) {
                if (head == NULL) {
                    head = new Node(*first);
                    head->next_ = NULL;
                    curr = head;
                } else {
                    curr->next_ = new Node(*first);
                    curr = curr->next_;
                    curr->next_ = NULL;
                }
            }
            first = first->next_;
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
