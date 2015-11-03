/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * For example: Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
 * return [1,3,2].
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
  void inorder(TreeNode* root, vector<int>& out) {
    if (root) {
      inorder(root->left, out);
      out.push_back(root->val);
      inorder(root->right, out);
    }
  }
  
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> out;
    // Method 1: Recursive solution.
    //inorder(root, out);
    
    // Method 2: Iterative solution.
    if (!root)  return out;
    stack<TreeNode*> nodeStack;
    TreeNode* temp = root;
    while (temp) {
      nodeStack.push(temp);
      temp = temp->left;
    }
    while (!nodeStack.empty()) {
      temp = nodeStack.top();
      out.push_back(temp->val);
      nodeStack.pop();
      temp = temp->right;
      while (temp) {
        nodeStack.push(temp);
        temp = temp->left;
      }
    }
    return out;
  }
};