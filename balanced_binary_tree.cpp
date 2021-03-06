/**
 * Given a binary tree, determine if it is height-balanced. For this problem, a height-balanced binary tree is 
 * defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
  int getHeight(TreeNode* root) {
    if (!root)  return 0;
    return (1 + max(getHeight(root->left), getHeight(root->right)));
  }
  
  bool isBalanced(TreeNode* root) {
    if (!root)  return true;
    int leftHeight  = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
  }
};
