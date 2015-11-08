/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, 
 * level by level from leaf to root).
 * 
 * For example: Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
  return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root)  return vector<vector<int>>();
    vector<pair<TreeNode*, int>> queue;
    queue.push_back(make_pair(root, 1));
     
    int currentLevel = 1;
    for (int i = 0; i < queue.size(); i++) {
      TreeNode* node = queue[i].first;
      currentLevel = queue[i].second;
      if (node->left)  queue.push_back(make_pair(node->left, currentLevel + 1));
      if (node->right)  queue.push_back(make_pair(node->right, currentLevel + 1));
    }
    vector<vector<int>> out(currentLevel, vector<int>());
    for (int i = 0; i < queue.size(); i++)
      out[currentLevel - queue[i].second].push_back(queue[i].first->val);
    return out;
  }
};
