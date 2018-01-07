#include "TreeNode.h"
#include <algorithm>
#include <stack>

bool isHeightBalanced(TreeNode *subRoot) {
    // your code here
    return isBalancedInorder(subRoot);
}

bool isBalancedInorder(TreeNode *subRoot) {
    if (subRoot == NULL) {
        return true;
    }

    return isBalancedInorder(subRoot->left_) && getHeightBalance(subRoot) &&
           isBalancedInorder(subRoot->right_);
}

bool getHeightBalance(TreeNode *subRoot) {
    // your code here
    int heightLeft = 0;
    int heightRight = 0;

    if (subRoot->left_ != NULL) {
        heightLeft = 1 + getHeight(subRoot->left_);
    }

    if (subRoot->right_ != NULL) {
        heightRight = 1 + getHeight(subRoot->right_);
    }

    if (std::abs(heightLeft - heightRight) <= 1) {
        return true;
    } else {
        return false;
    }
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
