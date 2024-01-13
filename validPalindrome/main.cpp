#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool validPalindrome(string s) {
    string reversed = string(s.rbegin(), s.rend());

    if (reversed == s)
      return true;

    for (int i = 0; i < s.size(); i++) {
      string temp = s;
      temp.erase(i, 1);
      string reversed = string(temp.rbegin(), temp.rend());
      if (reversed == temp) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution sol;
  string s = "abccda";
  cout << sol.validPalindrome(s) << endl;
  return 0;
}
