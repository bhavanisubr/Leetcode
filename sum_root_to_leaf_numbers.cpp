class Solution {
public:
  int sumNumbersUtil(TreeNode* root, int sum) {
    if (!root->left && !root->right)  return  10 * sum + root->val;
    int temp = 0;
    if (root->left)  temp += sumNumbersUtil(root->left, 10 * sum + root->val);
    if (root->right)  temp += sumNumbersUtil(root->right, 10 * sum + root->val);
    return  temp;
  }

  int sumNumbers(TreeNode* root) {
    if (!root)  return 0;
    return  sumNumbersUtil(root, 0);
  }
};
