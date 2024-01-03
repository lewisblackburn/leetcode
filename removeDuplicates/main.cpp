#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    return nums.size();
  }
};

int main() {
  Solution solution;
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << solution.removeDuplicates(nums) << endl;
  return 0;
}
