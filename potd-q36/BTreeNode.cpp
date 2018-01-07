#include "BTreeNode.h"
#include <vector>

void traverse(BTreeNode *subRoot, std::vector<int> &v) {
    if (subRoot->children_.size() == 0) {  // Leaf node
        for (unsigned i = 0; i < subRoot->elements_.size(); ++i) {
            v.push_back(subRoot->elements_[i]);
        }
    } else {  // Non-leaf node
        for (unsigned i = 0; i < subRoot->elements_.size(); ++i) {
            traverse(subRoot->children_[i], v);
            v.push_back(subRoot->elements_[i]);
        }
        traverse(subRoot->children_[subRoot->children_.size() - 1], v);
    }
    return;
}

std::vector<int> traverse(BTreeNode *root) {
    // your code here
    std::vector<int> v;
    traverse(root, v);
    return v;
}
