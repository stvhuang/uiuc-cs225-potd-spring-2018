#include "TreeNode.h"
#include <iostream>
using namespace std;


TreeNode * findIOP(TreeNode *subRoot) {
  TreeNode *curr = subRoot->left_;
  TreeNode *part = NULL;

  if (subRoot->right_ == NULL) {
    // subRoot is the IOP
    return NULL;
  }

  while (curr->right_ != NULL) {
    part = curr;
    curr = curr->right_;
  }

  return part;
}

TreeNode * deleteNode(TreeNode* root, int key) {

  // your code here
  TreeNode * part = NULL;
  TreeNode * track = root;

  if (root->val_ == key) {
    return root;
  }

  while (track->val_ != key) {
    part = track;
    if (track->val_ > key) {
      track = track->left_;
    } else {
      track = track->right_;
    }
  }

  if (track->val_ != key) {
    cout << "SOMETHING WRONG!!!" << endl;
  }

  if (track->left_ == NULL && track->right_ == NULL) {
    // track is a leaf
    if (part->left_ == track) {
      part->left_ = NULL;
      delete track;
      track = NULL;
      return root;
    } else {
      part->right_ = NULL;
      delete track;
      track = NULL;
      return root;
    }
  } else if (track->left_ != NULL && track->right_ == NULL) {
    // track has only one child, left child
    if (part->left_ == track) {
      part->left_ = track->left_;
      delete track;
      track = NULL;
      return root;
    } else {
      part->right_ = track->left_;
      delete track;
      track = NULL;
      return root;
    }
  } else if (track->left_ == NULL && track->right_ != NULL) {
    // track has only one child, left child
    if (part->left_ == track) {
      part->left_ = track->right_;
      delete track;
      track = NULL;
      return root;
    } else {
      part->right_ = track->right_;
      delete track;
      track = NULL;
      return root;
    }
  } else {
    // track has two children, use IOP
    TreeNode *IOP = findIOP(track);
    if (IOP == NULL) {
      int temp = track->val_;
      track->val_ = track->left_->val_;
      track->left_->val_ = temp;
      if (track->left_->left_ == NULL && track->left_->right_ == NULL) {
        // is a leaf node
        delete track->left_;
        track->left_ = NULL;
      } else {
        deleteNode(track->left_, key);
      }
      return root;
    }

    deleteNode(track, key);
    return root;
  }
}
void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
