#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {
    // your code here!
    if (*head == NULL) {
        insert->next_ = NULL;
        *head = insert;
        return;
    }

    // *head is not NULL
    Node *curr = *head;
    Node *&refHead = *head;
    if (refHead->data_ > insert->data_) {
        insert->next_ = refHead;
        refHead = insert;
        return;
    }

    while (1) {
        if (insert->data_ > curr->data_) {
            if (curr->next_ == NULL) {
                insert->next_ = NULL;
                curr->next_ = insert;
                return;
            } else if (insert->data_ < curr->next_->data_) {
                insert->next_ = curr->next_;
                curr->next_ = insert;
                return;
            } else {
                curr = curr->next_;
            }
        } else {  // insert->data_ < curr->data_
            insert->next_ = curr;
            curr = insert;
        }
    }

    return;
}
