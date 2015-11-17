/**
 * Given the inorder and postorder traversals of a tree, construct the binary tree.
 *
 * Note: You may assume that duplicates do not exist in the tree.
 *
 * Definition of a binary tree node:
 * struct TreeNode {
 *  int val;
 *  TreeNode* left;
 *  TreeNode* right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode* buildTreeUtil(int iBegin, int iEnd, int pEnd, vector<int>& inorder, vector<int>& postorder) {
    if (iBegin > iEnd)  return NULL;
    TreeNode* root = new TreeNode(postorder[pEnd]);
    int i = iBegin;
    for ( ; i <= iEnd && inorder[i] != root->val; i++);
    root->left = buildTreeUtil(iBegin, i - 1, pEnd + i - 1 - iEnd, inorder, postorder);
    root->right = buildTreeUtil(i + 1, iEnd, pEnd - 1, inorder, postorder);
    return root;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty())  return NULL;
    return buildTreeUtil(0, inorder.size() - 1, postorder.size() - 1, inorder, postorder);
  }
};
