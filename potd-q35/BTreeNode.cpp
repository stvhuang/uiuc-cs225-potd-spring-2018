#include <vector>
#include "BTreeNode.h"

BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    if (root->children_.size() == 0) {
        // Leaf node, no children
        for (unsigned i = 0; i < root->elements_.size(); ++i) {
            if (root->elements_[i] == key) {
                return root;
            }
        }
        return NULL;
    } else {
        // Non-leaf note
        for (unsigned i = 0; i < root->elements_.size(); ++i) {
            if (root->elements_[i] > key) {
                return find(root->children_[i], key);
            } else if (root->elements_[i] == key) {
                return root;
            }
        }
        return find(root->children_[root->children_.size() - 1], key);
    }
}
