/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
  TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int begin, int end) {
    if (begin <= end) {   
      int mid = begin + (end - begin) / 2;
      TreeNode* root = new TreeNode(nums[mid]);
      root->left = sortedArrayToBSTUtil(nums, begin, mid - 1); 
      root->right = sortedArrayToBSTUtil(nums, mid + 1, end);
      return root;
    }   
    return NULL;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty())  return NULL;
    return sortedArrayToBSTUtil(nums, 0, nums.size() - 1); 
  }
};
