#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reversePrefix(string word, char ch) {
    int index = word.find(ch);

    // if index exists
    if (index != string::npos) {
      string prefix = word.substr(0, index + 1); // +1 to include the character
      string suffix = word.substr(index + 1);    // +1 to exclude the character
      string reversedPrefix = string(prefix.rbegin(), prefix.rend());
      return reversedPrefix + suffix;
    }

    return word;
  }
};

int main() {
  Solution solution;
  string word = "abcdefd";
  char ch = 'd';
  string result = solution.reversePrefix(word, ch);
  cout << result << endl;
  return 0;
}
