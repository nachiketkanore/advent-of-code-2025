#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  int R = 50;
  const int MOD = 100;

  int answer = 0;
  while (cin >> line) {
    char direction = line[0];
    string count = line.substr(1);
    int value = stoi(count);
    // cout << direction << ' ' << value << '\n';
    if (direction == 'L') {
      int became_zero = 0;
      while (value--) {
        R = R - 1;
        became_zero += R == 0;
        if (R == -1) R = 99;
      }
      answer += became_zero;
    } else {
      int became_zero = 0;
      while (value--) {
        R = R + 1;
        if (R == 100) R = 0;
        became_zero += R == 0;
      }
      answer += became_zero;
    }
  }
  cout << answer << '\n';

  return 0;
}
