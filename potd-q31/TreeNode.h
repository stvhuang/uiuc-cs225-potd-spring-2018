#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
        left_ = NULL;
        right_ = NULL;
        val_ = x;
    }
};

bool isHeightBalanced(TreeNode *subRoot);

bool isBalancedInorder(TreeNode *subRoot);

bool getHeightBalance(TreeNode *subRoot);

int getHeight(TreeNode *subRoot);

void deleteTree(TreeNode *root);

#endif
