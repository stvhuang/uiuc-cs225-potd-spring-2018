#include "TreeNode.h"
#include <algorithm>

void rightRotate(TreeNode *root) {
    // Your code here
    TreeNode *temp = root->left_;
    root->left_ = root->left_->right_;
    root->left_->parent_ = root;
    temp->parent_ = NULL;
    temp->right_ = root;
    root->parent_ = temp;
    temp = NULL;

    return;
}

void leftRotate(TreeNode *root) {
    // your code here
    TreeNode *temp = root->right_;
    root->right_ = root->right_->left_;
    root->right_->parent_ = root;
    temp->parent_ = NULL;
    temp->left_ = root;
    root->parent_ = temp;
    temp = NULL;

    return;
}

void deleteTree(TreeNode *root) {
    if (root == NULL)
        return;
    deleteTree(root->left_);
    deleteTree(root->right_);
    delete root;
    root = NULL;
}
