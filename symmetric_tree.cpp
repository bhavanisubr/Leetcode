/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree is symmetric:
 
        1
       / \
      2   2
     / \ / \
    3  4 4  3
    
    But the following is not:
    
        1
       / \
      2   2
       \   \
       3    3
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
  bool isSymmetricUtil(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)  return true;
    if (!root1 || !root2)  return false;
    return (root1->val == root2->val && isSymmetricUtil(root1->left, root2->right)
              && isSymmetricUtil(root1->right, root2->left));
  }
  
  bool isSymmetric(TreeNode* root) {
    if (!root)  return true;
    return isSymmetricUtil(root->left, root->right);
  }
};
