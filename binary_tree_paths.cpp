/**
 * Given a binary tree, return all root-to-leaf paths.
 * For example: Given the following binary tree:
   1
 /   \
2     3
 \
  5
  
 * All root-to-leaf paths are: ["1->2->5", "1->3"]
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
  void getPath(vector<string>& out, TreeNode* root, string path) {
    if (!root->left && !root->right) {
      out.push_back(path);
      return;
    }
    if (root->left)  getPath(out, root->left, path + "->" + to_string(root->left->val));
    if (root->right)  getPath(out, root->right, path + "->" + to_string(root->right->val));
    return;
  }

  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> out;
    if (!root)  return out;
    getPath(out, root, to_string(root->val));
    return out;
  }
};
