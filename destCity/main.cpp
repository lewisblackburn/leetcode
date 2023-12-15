#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
public:
  string val;
  TreeNode *left;
  TreeNode *right;

  // Constructor to initialize a TreeNode with a given value
  TreeNode(string x) : val(x), left(nullptr), right(nullptr){};

  void insert(string x) {
    // string x < string val returns true if x is lexicographically less than
    // val
    if (x < val) {
      if (left == nullptr) {
        left = new TreeNode(x);
      } else {
        left->insert(x);
      }
    } else {
      // If the value is greater than or equal to the current node's value,
      // insert to the right
      if (right == nullptr) {
        right = new TreeNode(x);
      } else {
        right->insert(x);
      }
    }
  }

  // Function to print the values of the tree in-order
  void print() {
    if (left != nullptr) {
      left->print();
    }
    cout << val << endl;
    if (right != nullptr) {
      right->print();
    }
  }
};

// Class for the solution
class Solution {
public:
  // Function to find the destination city in a vector of paths
  string destCity(vector<vector<string>> &paths) {
    TreeNode *root = nullptr;

    // Iterate through each path in the vector
    for (auto &path : paths) {
      if (root == nullptr) {
        root = new TreeNode(path[0]);
      }
      // Insert the second city in the path into the binary tree
      root->insert(path[1]);
    }

    // Find the last item in the binary tree (rightmost node)
    TreeNode *node = root;
    while (node->right != nullptr) {
      node = node->right;
    }

    // Return the value of the last node, which represents the destination city
    return node->val;
  }
};

// Main function
int main() {
  Solution s;
  vector<vector<string>> paths = {
      {"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};

  cout << s.destCity(paths) << endl;
  return 0;
}
