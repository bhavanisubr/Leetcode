/**
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * 
 * Note: You may assume k is always valid, 1 ? k ? BST's total elements.
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
  int getNodeCount(TreeNode* node) {
    if (!node)  return 0;
    return 1 + getNodeCount(node->left) + getNodeCount(node->right);
  }

  int kthSmallest(TreeNode* root, int k) {
    // Method 1: Iterative in-order traversal - O(n) time (n is the number of nodes in the BST)
    /*stack<TreeNode*> nodeStack;
    TreeNode* temp = root;
    while (temp) {  
      nodeStack.push(temp);
      temp = temp->left;
    }   
    while (k) {  
      TreeNode* node = nodeStack.top();
      nodeStack.pop();
      if (--k == 0)  return node->val;
      TreeNode* right = node->right;
      while (right) {  
        nodeStack.push(right);
        right = right->left;
      }   
    }*/
    
    // Method 2: Binary Search - O(h) time (h is the height of the BST).
    int nodeCount = getNodeCount(root->left);
    if (k <= nodeCount)  return kthSmallest(root->left, k);
    if (k > nodeCount + 1)  return kthSmallest(root->right, k - nodeCount - 1);
    return root->val;
  }
};
