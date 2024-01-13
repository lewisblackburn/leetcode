#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int result = 0;

    if (nums.size() == 0) {
      result = -1;
    } else if (nums.size() == 1) {
      result = 0;
    } else {
      for (int number = 0; number < nums.size(); number++) {
        if (number == 0) {
          if (nums[number] > nums[number + 1]) {
            result = number;
          }
        } else if (number == nums.size() - 1) {
          if (nums[number] > nums[number - 1]) {
            result = number;
          }
        } else if (nums[number - 1] < nums[number] &&
                   nums[number] > nums[number + 1]) {
          result = number;
        }
      }
    }

    return result;
  };
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1};
  int output = solution.findPeakElement(nums);
  cout << "test" << endl;
  return 0;
}
