#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    const int largest = *max_element(candies.begin(), candies.end());
    vector<bool> result(candies.size(), false);

    for (int &i : candies) {
      if (i + extraCandies >= largest) {
        result[&i - &candies[0]] = true;
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;
  vector<bool> result = sol.kidsWithCandies(candies, extraCandies);
  for (auto i : result) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
