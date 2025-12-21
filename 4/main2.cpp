#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {

	vector<string> mat;
	string line;
	while (cin >> line) {
		mat.push_back(line);
	}
	const int N = mat.size();
	const int M = mat[0].size();
	cout << "N = " << N << " M = " << M << endl;

	vector<pair<int,int>> cells;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == '@') {
				cells.push_back(make_pair(i, j));
			}
		}
	}


	vector<int> dx = { 0, 0, 1, -1, 1, -1, -1, 1};
	vector<int> dy = { 1, -1, 0, 0, 1, -1, 1, -1};

	const int MAX_ALLOWED = 4;
	int answer = 0;

	auto eligible = [&](int i, int j) -> bool {
		int cnt = 0;
		for (int idx = 0; idx < 8; idx++) {
			int ni = i + dx[idx]; 
			int nj = j + dy[idx];
			if (0 <= ni && ni < N && 0 <= nj && nj < M) {
				cnt += mat[ni][nj] == '@';
			}
		}
		return cnt < MAX_ALLOWED;
	};

	while (true) {
		bool found = false;
		vector<pair<int,int>> new_cells;

		for (auto [i, j]: cells) {
			if (eligible(i, j)) {
				answer++;
				found = true;
				mat[i][j] = '.';
			} else {
				new_cells.push_back(make_pair(i, j));

			}
		}
		cells = new_cells;
		if (!found) {
			break;
		}
	}


	cout << "part two answer = " << answer << '\n';
	
	return 0;
}

