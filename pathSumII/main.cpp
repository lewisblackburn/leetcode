#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;

    pathSumHelper(root, targetSum, path, result);

    return result;
  }

private:
  void pathSumHelper(TreeNode *node, int targetSum, std::vector<int> &path,
                     std::vector<std::vector<int>> &result) {
    if (!node) {
      return;
    }

    // Add the current node's value to the path
    path.push_back(node->val);

    // Check if it's a leaf node and the path sum equals the target
    if (!node->left && !node->right && targetSum == node->val) {
      // std::cout << "Adding " << path.back() << std::endl;
      result.push_back(path);
    }

    // Recursively check left and right subtrees
    pathSumHelper(node->left, targetSum - node->val, path, result);
    pathSumHelper(node->right, targetSum - node->val, path, result);

    // std::cout << "Removing " << path.back() << std::endl;

    // Backtrack: remove the current node from the path
    path.pop_back();
  }
};

int main() {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->left = new TreeNode(5);
  root->right->right->right = new TreeNode(1);

  Solution solution;
  std::vector<std::vector<int>> result = solution.pathSum(root, 22);

  // Print the result
  for (const auto &path : result) {
    std::cout << "Path: ";
    for (int value : path) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }

  // Clean up allocated memory
  delete root->right->right->right;
  delete root->right->right->left;
  delete root->right->right;
  delete root->right->left;
  delete root->right;
  delete root->left->left->right;
  delete root->left->left->left;
  delete root->left->left;
  delete root->left;
  delete root;

  return 0;
}
