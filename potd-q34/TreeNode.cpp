#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  int balance = getHeight(subroot->left_) - getHeight(subroot->right_);
  if (balance == 2) {
    int lbalance = getHeight(subroot->left_->left_) - getHeight(subroot->left_->right_);
    if (lbalance == 1) {
      return TreeNode::right;
    } else if (lbalance == -1) {
      return TreeNode::leftRight;
    }
  } else if (balance == -2) {
    int lbalance = getHeight(subroot->right_->left_) - getHeight(subroot->right_->right_);
    if (lbalance == 1) {
      return TreeNode::rightLeft;
    } else if (lbalance == -1) {
      return TreeNode::left;
    }
  }
}
