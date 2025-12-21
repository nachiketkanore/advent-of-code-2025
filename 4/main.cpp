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

	// for (int i = 0; i < N; i++) {
	// 	cout << mat[i] << '\n';
	// }

	vector<string> result = mat;

	vector<int> dx = { 0, 0, 1, -1, 1, -1, -1, 1};
	vector<int> dy = { 1, -1, 0, 0, 1, -1, 1, -1};

	const int MAX_ALLOWED = 4;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int cnt = 0;
			for (int idx = 0; idx < 8; idx++) {
				int ni = i + dx[idx]; 
				int nj = j + dy[idx];
				if (0 <= ni && ni < N && 0 <= nj && nj < M) {
					cnt += mat[ni][nj] == '@';
				}
			}
			if (cnt < MAX_ALLOWED && mat[i][j] == '@') {
				answer += 1;
				result[i][j] = 'x';
			}

		}
	}

	// for (int i = 0; i < N; i++) {
	// 	cout << result[i] << '\n';
	// }

	cout << "part one answer = " << answer << '\n';
	
	return 0;
}

