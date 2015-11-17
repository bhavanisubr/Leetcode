/**
 * Given a binary tree, imagine yourself standing on the right side of the tree and return the values 
 * of the nodes you can see ordered from top to bottom.
 *
 * For example: 
 * 1. Given the following binary tree,
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
 * You should return [1, 3, 4].
 *
 * 2. Given the following binary tree,
 *         1
 *       /   \
 *      2     5
 *    /   \
 *   4     3
 *  /
 * 6
 * You should return [1, 5, 3, 6].
 *
 * Definition for a binary tree node:
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> path;
    if (!root)  return path;
    deque<pair<TreeNode*, int>> nodeQueue;
    int currentLevel = 1, lastLevelAdded = 0;
    nodeQueue.push_back(make_pair(root, currentLevel));
    while (!nodeQueue.empty()) {
      TreeNode* node = nodeQueue.front().first;
      if (lastLevelAdded < nodeQueue.front().second) {
        ++lastLevelAdded;
        path.push_back(node->val);
        ++currentLevel;
      }
      nodeQueue.pop_front();
      if (node->right)  nodeQueue.push_back(make_pair(node->right, currentLevel));
      if (node->left)  nodeQueue.push_back(make_pair(node->left, currentLevel));
    }
  }
};
