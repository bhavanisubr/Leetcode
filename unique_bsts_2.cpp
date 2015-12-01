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
    if (n == 0)  return vector<TreeNode*>();
    return generateTreesUtil(1, n);
  }
};
