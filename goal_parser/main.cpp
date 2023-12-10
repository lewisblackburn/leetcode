#include <iostream>
#include <map>
#include <string>

class Solution {
public:
  std::string interpret(std::string command) {
    std::map<std::string, std::string> m = {
        {"G", "G"}, {"()", "o"}, {"(al)", "al"}};

    for (auto it = m.begin(); it != m.end(); ++it) {
      for (int i = 0; i < command.length(); ++i) {
        if (command.find(it->first) != std::string::npos) {
          command.replace(command.find(it->first), it->first.length(),
                          it->second);
          std::cout << it->first << " " << it->second << std::endl;
        }
      }
    }

    return command;
  }
};

int main() {
  Solution s;
  std::cout << s.interpret("G()()()()()(al)") << std::endl;
  return 0;
}
