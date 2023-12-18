#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProductDifference(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    return (nums[nums.size() - 1] * nums[nums.size() - 2]) -
           (nums[0] * nums[1]);
  }
};

int main() {
  Solution s;
  vector<int> nums = {5, 6, 2, 7, 4};
  int res = s.maxProductDifference(nums);
  cout << res << endl;

  return 0;
}
