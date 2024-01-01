#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    for (int i = 0; i < g.size(); i++) {
      for (int j = 0; j < s.size(); j++) {
        if (s[j] >= g[i]) {
          if (s[j] > 1) {
            s[j] -= 1;
          } else {
            s.erase(s.begin() + j);
          }
          break;
        }
      }
    }
    return s.size();
  }
};

int main() {
  Solution solution;
  vector<int> g = {1, 2, 3};
  vector<int> s = {1, 1};
  cout << solution.findContentChildren(g, s) << endl;
  return 0;
}
