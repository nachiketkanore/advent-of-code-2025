#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	vector<string> mat;
	string line; 
	while (cin >> line) mat.push_back(line);

	const int N = mat.size(), M = mat[0].size();

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

	int answer = 0;

	while (!beams.empty()) {
		set<pair<int,int>> new_beams;
		for (auto [i, j]: beams) {
			if (inside(i + 1, j) && mat[i + 1][j] == '^') {
				answer += 1;
				if (inside(i + 1, j - 1)) {
					new_beams.insert(make_pair(i + 1, j - 1));
				}
				if (inside(i + 1, j + 1)) {
					new_beams.insert(make_pair(i + 1, j + 1));
				}
			} else if (inside(i + 1, j) && mat[i + 1][j] == '.') {
				new_beams.insert(make_pair(i + 1, j));
			}
		}
		beams = new_beams;
	}
	

	cout << "answer = " << answer << '\n';
	return 0;
}

