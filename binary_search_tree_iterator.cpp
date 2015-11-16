/**
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root 
 * node of the BST. Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height 
 * of the tree.
 *
 * Your BSTIterator will be called as follows:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 *
 * Definition for a binary tree node:
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
  stack<TreeNode*> nodeStack;
  void pushAllNodesToStack(TreeNode* root) {
    while (root) {
      nodeStack.push(root);
      root = root->left;
    }
  }
public:
  BSTIterator(TreeNode* root) {
    pushAllNodesToStack(root);
  }

  // Returns whether we have a next smallest number in O(1) time
  bool hasNext() {
    return !nodeStack.empty();
  }

  /* Returns the next smallest number in the BST
   * Time complexity: theta(1) average time and O(h) worst-case time
   * Space complexity: O(h) space
   * where h is the height of the BST
   */
  int next() {
    if (!hasNext())  return INT_MAX;
    TreeNode* node = nodeStack.top();
    nodeStack.pop();
    pushAllNodesToStack(node->right);
    return node->val;
  }
};
