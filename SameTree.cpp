/**
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if (!p && !q)   return true;
       if (p && q && p->val == q->val) {
          bool isLeftSame = isSameTree(p->left, q->left);
          bool isRightSame = isSameTree(p->right, q->right);
          if (isLeftSame && isRightSame)   return true;
       }
       return false;
    }
};
