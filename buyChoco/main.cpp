#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int buyChoco(vector<int> &prices, int money) {
    sort(prices.begin(), prices.end());
    if (prices.size() < 2) {
      return money;
    }

    int cheapestChocolates = prices[0] + prices[1];

    return cheapestChocolates <= money ? money - cheapestChocolates : money;
  }
};

int main() {
  Solution sol;
  vector<int> prices = {1, 2, 2};
  int money = 3;
  cout << sol.buyChoco(prices, money) << endl;
  return 0;
}
