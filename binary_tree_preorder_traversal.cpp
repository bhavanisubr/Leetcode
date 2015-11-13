/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * For example: Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
 * return [1,2,3].
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
  void preorder(TreeNode* root, vector<int>& out) {
    if (root) {
      out.push_back(root->val);
      preorder(root->left, out);
      preorder(root->right, out);
    }
  }

  vector<int> preorderTraversal(TreeNode* root) {
    // Method 1: Recursive solution
    /*vector<int> out;
    preorder(root, out);
    return out;*/
    
    // Method 2: Alternative recursive solution
    vector<int> out;
    if (!root)  return out;
    out.push_back(root->val);
    vector<int> leftPath = preorderTraversal(root->left);
    vector<int> rightPath = preorderTraversal(root->right);
    out.insert(out.end(), leftPath.begin(), leftPath.end());
    out.insert(out.end(), rightPath.begin(), rightPath.end());
    return out;

    // Method 3: Iterative solution
    /*vector<int> out;
    if (!root)  return out;
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
      TreeNode* temp = nodeStack.top();
      out.push_back(temp->val);
      nodeStack.pop();
      if (temp->right)  nodeStack.push(temp->right);
      if (temp->left)  nodeStack.push(temp->left);
    }
    return out;*/
  }
};
