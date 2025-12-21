#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int LEN = 12;

int32_t main() {
	int answer = 0;
	string line;
	while (cin >> line) {
		const int N = line.size();
		string best;
		for (int i = 0; i < N; i++) {
			int digit = line[i] - '0';
			string number; number += line[i];

			int idx = i + 1;
			int digits_remain = 11;
			while (digits_remain--) {
				int chosen_idx = -1;
				for (int j = idx; j < N; j++) {
					int new_digit = line[j] - '0';
					int right_digits = N - j - 1;
					int digits_taken = int(number.size()) + 1;
					int digits_req = 12 - digits_taken;
					if (right_digits >= digits_req) {
						if (chosen_idx == -1 || line[j] > line[chosen_idx]) {
							chosen_idx = j;
						}
					}
				}
				if (chosen_idx == -1) {
					break;
				} else {
					number += line[chosen_idx];
					idx = chosen_idx + 1;
				}
			}
			if (int(number.size()) == LEN) {
				best = max(best, number);
			}
		}
		cout << "best = " << best << '\n';
		answer += stoll(best);
	}

	cout << "part two answer = " << answer << '\n';
	
	return 0;
}

