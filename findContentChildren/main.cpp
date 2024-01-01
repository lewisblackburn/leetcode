#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    for (int j = 0; i < g.size() && j < s.size(); j++) {
      if (s[j] >= g[i]) {
        i++;
      }
    }
    return i;
  }
};

int main() {
  Solution solution;
  vector<int> g = {10, 9, 8, 7};
  vector<int> s = {5, 6, 7, 8};
  cout << solution.findContentChildren(g, s) << endl;
  return 0;
}
