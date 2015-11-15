/**
 * Given a binary tree where each node contains digits from 0-9 only and if each root-to-leaf path could be 
 * represented by a number, i.e. Consider an example where the root-to-leaf path 1->2->3 is represented by 
 * the number 123, find the total sum of all root-to-leaf numbers.
 *
 * For example:
     1
    / \
   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = 12 + 13 = 25.
 */

class Solution {
public:
  int sumNumbersUtil(TreeNode* root, int sum) {
    if (!root->left && !root->right)  return 10 * sum + root->val;
    int temp = 0;
    if (root->left)  temp += sumNumbersUtil(root->left, 10 * sum + root->val);
    if (root->right)  temp += sumNumbersUtil(root->right, 10 * sum + root->val);
    return temp;
  }

  int sumNumbers(TreeNode* root) {
    if (!root)  return 0;
    return sumNumbersUtil(root, 0);
  }
};
