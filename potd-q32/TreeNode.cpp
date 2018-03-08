#include <algorithm>
#include <queue>
#include "TreeNode.h"

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  TreeNode *deepestUnbalanced = NULL;

  std::queue<TreeNode *> q;
  q.push(root);

  TreeNode *curr = NULL;

  while (!q.empty()) {
    curr = q.front();
    if (curr->left_ != NULL) {
      q.push(curr->left_);
    }

    if (curr->right_ != NULL) {
      q.push(curr->right_);
    }

    curr->balance_ = getBalance(curr);
    if (std::abs(getBalance(curr)) > 1) {
      deepestUnbalanced = curr;
    }
    q.pop();
  }

  return deepestUnbalanced;
}

int getHeight(TreeNode* subRoot) {
  if (subRoot == NULL) {
    return 0;
  }

  if (subRoot->left_ == NULL && subRoot->right_ == NULL) {
    // leaf node, empty tree
    return 0;
  } else {
    return 1 + std::max(getHeight(subRoot->left_), getHeight(subRoot->right_));
  }
}

int getBalance(TreeNode *subRoot) {
  // your code here
  int heightLeft = 0;
  int heightRight = 0;

  if (subRoot->left_ != NULL) {
    heightLeft = 1 + getHeight(subRoot->left_);
  }

  if (subRoot->right_ != NULL) {
    heightRight = 1 + getHeight(subRoot->right_);
  }

  return heightLeft - heightRight;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

