#include "TreeNode.h"

#include <cstddef>
#include <iostream>
#include <algorithm>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  if (left_ == NULL && right_ == NULL) {
    return 0;
  } else if (left_ != NULL && right_ != NULL) {
    return 1 + max(left_->getHeight(), right_->getHeight());
  } else if (left_ != NULL && right_ == NULL) {
    return 1 + left_->getHeight();
  } else {  // left == NULL && right != NULL
    return 1 + right_->getHeight();
  }
}
