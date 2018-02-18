#include "Node.h"

using namespace std;

void sortList(Node **head) {
    if (*head == NULL)
        return;
  // your code here!
    Node *first = *head;
    Node *pre_first = NULL;
    Node *pre = first;
    Node *next = pre->next_;
    Node *pre_max = NULL;
    Node *tmp = NULL;
    int max_data = 0;
    int numNodes = first->getNumNodes();

    for (int i = 0; i < numNodes - 1; ++i) {
        max_data = first->data_;
        while (next != NULL) {
            if (next->data_ < max_data) {
                pre_max = pre;
                max_data = next->data_;
            }

            pre = pre->next_;
            next = next->next_;
        }

        if (pre_max != NULL) {
            tmp = pre_max->next_;
            pre_max->next_ = pre_max->next_->next_;
            tmp->next_ = first;
            first = tmp;
            if (i != 0) {
                pre_first->next_ = first;
            }
        }

        if (i == 0) {
            *head = first;
            pre_first = first;
        }
        
        first = first->next_;
        pre = first;
        pre_max = NULL;
        next = pre->next_;
        max_data = first->data_;
        if (i != 0) {
            pre_first = pre_first->next_;
        }
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

