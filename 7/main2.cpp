#include <bits/stdc++.h>
#define int int64_t
using namespace std;


int32_t main() {
	vector<string> mat;
	string line; 
	while (cin >> line) mat.push_back(line);

	const int N = mat.size(), M = mat[0].size();

	vector<vector<int>> dp(N, vector<int> (M, 0));

	auto inside = [&](int i, int j) {
		return i >= 0 && i < N && j >= 0 && j < M;
	};

	int si = -1, sj = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == 'S') si = i, sj = j;
		}
	}
	assert(~si && ~sj);

	set<pair<int,int>> beams;
	beams.insert(make_pair(si + 1, sj));
	dp[si+1][sj] = 1;

	while (!beams.empty()) {
		set<pair<int,int>> new_beams;
		for (auto [i, j]: beams) {
			if (inside(i + 1, j) && mat[i + 1][j] == '^') {
				if (inside(i + 1, j - 1)) {
					// creating new beam
					new_beams.insert(make_pair(i + 1, j - 1));
					dp[i+1][j-1] += dp[i][j];
				}
				if (inside(i + 1, j + 1)) {
					// creating new beam
					new_beams.insert(make_pair(i + 1, j + 1));
					dp[i+1][j+1] += dp[i][j];
				}
			} else if (inside(i + 1, j) && mat[i + 1][j] == '.') {
				// creating new beam
				new_beams.insert(make_pair(i + 1, j));
				dp[i+1][j] += dp[i][j];
			}
		}
		beams = new_beams;
	}

	int answer = 0;

	
	for (int j = 0; j < M; j++) {
		cout << dp.back()[j] << " ";
		answer += dp.back()[j];
	}

	cout << "answer = " << answer << '\n';
	return 0;
}

