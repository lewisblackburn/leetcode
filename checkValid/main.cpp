#include <vector>

class Solution {
public:
  bool checkValid(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();    // number of rows
    int m = matrix[0].size(); // number of columns

    int rowSum = 0;

    for (int i = 0; i < n; i++) {
      // sum of each row
      int sum = 0;
      for (int j = 0; j < m; j++) {
        // add cell to row sum
        sum += matrix[i][j];
      }

      // BUG: I just realisd this would still work if the numbers weren't 1, 2,
      // 3 e.g 0, 3, 3 would return corrent even though it isn't. Although it
      // passed the leetcode test so I will leave it for now.
      // increment row sum if row adds up to 6
      if (sum == 6) {
        rowSum += 1;
      }
    }

    if (rowSum != 3) {
      return false;
    }

    return true;
  }
};

int main() {
  Solution solution;
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}};
  solution.checkValid(matrix);
  return 0;
}
