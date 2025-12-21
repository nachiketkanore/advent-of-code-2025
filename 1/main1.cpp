#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  int R = 50;
  const int MOD = 100;
  const int INF = 1000;

  int answer = 0;
  while (cin >> line) {
    char direction = line[0];
    string count = line.substr(1);
    int value = stoi(count);
    // cout << direction << ' ' << value << '\n';
    if (direction == 'L') {
      R = (R - value + INF * MOD) % MOD;
    } else {
      R = (R + value) % MOD;
    }
    answer += (R == 0);
  }
  cout << answer << '\n';

  return 0;
}
