#include "TreeNode.h"
#include <algorithm>
#include <iostream>
using namespace std;

int getHeightBalance(TreeNode *root) {
    // your code here
    int heightLeft = 0;
    int heightRight = 0;

    if (root->left_ != NULL) {
        heightLeft = 1 + getHeight(root->left_);
    }

    if (root->right_ != NULL) {
        heightRight = 1 + getHeight(root->right_);
    }

    return heightLeft - heightRight;
}

int getHeight(TreeNode *subRoot) {
    if (subRoot == NULL) {
        return 0;
    }

    if (subRoot->left_ == NULL && subRoot->right_ == NULL) {
        // leaf node, empty tree
        return 0;
    } else {
        return 1 +
               std::max(getHeight(subRoot->left_), getHeight(subRoot->right_));
    }
}

void deleteTree(TreeNode *root) {
    if (root == NULL)
        return;
    deleteTree(root->left_);
    deleteTree(root->right_);
    delete root;
    root = NULL;
}
