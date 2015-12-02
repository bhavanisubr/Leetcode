/**
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example: Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
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
  vector<TreeNode*> generateTreesUtil(int begin, int end) {
    vector<TreeNode*> list;
    if (begin > end) {
      list.push_back(NULL);
      return list;
    }
    for (int i = begin; i <= end; i++) {
      vector<TreeNode*> leftSubtree = generateTreesUtil(begin, i - 1);
      vector<TreeNode*> rightSubtree = generateTreesUtil(i + 1, end);
      for (int j = 0; j < leftSubtree.size(); j++) {
        for (int k = 0; k < rightSubtree.size(); k++) {
          TreeNode* node = new TreeNode(i);
          node->left = leftSubtree[j];
          node->right = rightSubtree[k];
          list.push_back(node);
        }
      }
    }
    return list;
  }

  vector<TreeNode*> generateTrees(int n) {
    if (!n)  return vector<TreeNode*>();
    return generateTreesUtil(1, n);
  }
};
