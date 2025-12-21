#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	string line;
	vector<pair<int, int>> ranges;
	while (cin >> line) {
		if (line.find("-") != string::npos) {
			int idx = line.find('-');
			int l = stoll(line.substr(0, idx + 1));
			int r = stoll(line.substr(idx + 1));
			ranges.push_back(make_pair(l, r));
		}
	}
	sort(ranges.begin(), ranges.end());
	const int N = ranges.size();

	int answer = 0;

	for (int i = 0; i < N;) {
					// extends to the right (take max)
		int L = ranges[i].first, R = ranges[i].second;

		int j = i + 1;
		while (j < N) {
			int l = ranges[j].first, r = ranges[j].second;
			if (l <= R) {
				R = max(R, r);
			} else {
				break;
			}
			j += 1;
		}
		answer += R - L + 1;
		i = j;
	}

	cout << "answer = " << answer << '\n';
	
	return 0;
}
