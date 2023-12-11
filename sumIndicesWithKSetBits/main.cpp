#include <iostream>
#include <vector>

class Solution {
private:
  int getBinaryOnes(int num) {
    int count = 0;

    // Iterate through each bit in the binary representation of the input
    // integer
    while (num > 0) {
      // Check if the least significant bit (LSB) is 1
      if (num & 1) {
        count++;
      }

      // Right shift the binary representation of num by 1 bit (equivalent to
      // dividing by 2)
      num >>= 1;
    }

    return count;
  }

public:
  int sumIndicesWithKSetBits(std::vector<int> &nums, int k) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      std::cout << getBinaryOnes(nums[i]) << std::endl;
      if (getBinaryOnes(i) == k) {
        sum += nums[i];
      }
    }

    return sum;
  }
};

int main() {
  Solution solution;
  std::vector<int> nums = {5, 10, 1, 5, 2};
  int k = 1;
  int result = solution.sumIndicesWithKSetBits(nums, k);
  std::cout << result << std::endl;

  return 0;
}
