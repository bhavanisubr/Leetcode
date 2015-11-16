/**
 * Given a binary tree where each node is defined as follows:
 * 
 * struct TreeLinkNode {
 *   int val;
 *   TreeLinkNode *left;
 *   TreeLinkNode *right;
 *   TreeLinkNode *next;
 *   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 *
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer 
 * should be set to NULL. Initially, all next pointers are set to NULL.
 * 
 * Note: You may only use constant extra space.
 *
 * For example: Given the following binary tree,
 *     1
 *    /  \
 *   2    3
 *  / \    \
 * 4   5    7
 * 
 * After calling your function, the tree should look as follows:
 *     1 -> NULL
 *    /  \
 *   2 -> 3 -> NULL
 *  / \    \
 * 4-> 5 -> 7 -> NULL
 */

class Solution {
public:
  void connect(TreeLinkNode* root) {
    TreeLinkNode* head = new TreeLinkNode(0);
    TreeLinkNode* temp = head;
    while (root) {
      if (root->left) {
        temp->next = root->left;
        temp = temp->next;
      }
      if (root->right) {
        temp->next = root->right;
        temp = temp->next;
      }
      root = root->next;
      if (!root) {
        temp = head;
        root = temp->next;
        temp->next = NULL;
      }
    }
  }
};
