/**
 * Given a binary tree, populate each next pointer to point to its next right node. If there 
 * is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * 
 * Note: 
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, 
 * and every parent has two children).
 * 
 * For example: Given the following perfect binary tree,
  
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

 * After calling your function, the tree should look like the following:
  
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 * 
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
class Solution {
public:
  TreeLinkNode* getNextRight(TreeLinkNode* node) {
    node = node->next;
    while (node) {
      if (node->left)  return node->left;
      if (node->right)  return node->right;
      node = node->next;
    }
    return NULL;
  }
  void connect(TreeLinkNode* root) {
    if (!root)  return;
    if (root->left)  root->left->next = root->right ? root->right : getNextRight(root);
    if (root->right)  root->right->next = getNextRight(root);
    connect(root->left);
    connect(root->right);
  }
};
