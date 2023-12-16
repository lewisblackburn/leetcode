#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    map<char, int> charMap;
    for (int i = 0; i < s.length(); i++) {
      charMap[s[i]]++;
    }

    for (int i = 0; i < t.length(); i++) {
      if (charMap.find(t[i]) == charMap.end()) {
        return false;
      } else {
        charMap[t[i]]--;
        if (charMap[t[i]] == 0) {
          charMap.erase(t[i]);
        }
      }
    }

    return true;
  }
};

int main() {
  Solution solution;
  string s = "anagram";
  string t = "nagaram";
  cout << solution.isAnagram(s, t) << endl;
}
