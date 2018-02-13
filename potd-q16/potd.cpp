#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
    // your code here!
    unsigned count = 0;
    string result = "";

    if (head == NULL) {
        return "Empty list";
    } else {
        while (1) {
            result += "Node ";
            result += to_string(count++);
            result += ": ";
            result += to_string(head->data_);
            if (head->next_ == NULL) {
                return result;
            } else {
                result += " -> ";
                head = head->next_;
                continue;
            }
        }
    }
}
