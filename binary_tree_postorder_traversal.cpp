/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example: Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 * return [3,2,1]
 *
 * Definition for a binary tree node:
 * struct TreeNode {
 *   int val;
 *   TreeNode* left;
 *   TreeNode* right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  void postorderTraversalUtil(TreeNode* root, vector<int>& path) {
    if (!root)  return;
    postorderTraversalUtil(root->left, path);
    postorderTraversalUtil(root->right, path);
    path.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode* root) {
    // Method 1: Recursive solution
    /*vector<int> path;
    postorderTraversalUtil(root, path);
    return path;*/

    // Method 2: Iterative solution
    vector<int> path;
    if (!root)  return path;
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
      TreeNode* node = nodeStack.top();
      nodeStack.pop();
      path.insert(path.begin(), node->val);
      if (node->left)  nodeStack.push(node->left);
      if (node->right)  nodeStack.push(node->right);
    }
    return path;
  }
};
