#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void print_mat(const vector<string> &mat) {
	cout << "---------------------\n";
	for (string row: mat) {
		cout << row << '\n';
	}
	cout << "---------------------\n";
}

int32_t main() {
	vector<string> lines;

	string line;
	while (getline(cin, line)) {
		lines.push_back(line);
	}
	string temp = lines.back(); lines.pop_back();
	string ops;
	for (char ch : temp) {
		if (ch == '*' || ch == '+') {
			ops += ch;
		}
	}

	cout << "ops = " << ops << '\n';

	vector<vector<string>> mats;

	const int N = lines.size();
	while (!lines[0].empty()) {
		bool all_digits = true;

		for (const string line: lines) {
			all_digits &= isdigit(line[0]);
		}

		if (all_digits) {
			// left aligned
			vector<string> mat;
			int col = 0;
			for (const string line: lines) {
				const int M = line.size();
				for (int j = 0; j < M; j++) {
					if (isdigit(line[j])) col = max(col, j);
					else break;
				}
			}
			for (string &line: lines) {
				mat.push_back(line.substr(0, col + 1));
				// remove the prefix
				if (col + 1 < int(line.size())) line = line.substr(col + 1);
				else line.clear();
			}

			// print_mat(mat);
			mats.push_back(mat);
		} else {
			// right aligned
			int row = -1;
			for (int i = 0; i < N; i++) if (isdigit(lines[i][0])) {
				row = i;
				break;
			}
			assert(~row);
			int col = -1;
			const int M = lines[row].size();
			// cout << "selected row = " << row << '\n';
			// cout << "selected row = " << lines[row] << '\n';
			for (int j = 0; j < M; j++) {
				if (isdigit(lines[row][j])) {
					col = j;
				} else {
					break;
				}
			}
			assert(~col);
			vector<string> mat;
			for (string &line: lines) {
				mat.push_back(line.substr(0, col + 1));
				// remove the prefix
				if (col + 1 < int(line.size())) line = line.substr(col + 1);
				else line.clear();
			}

			// print_mat(mat);
			mats.push_back(mat);

		}

		// trimming spaces from prefix

		while (true) {
			bool all_spaces = true;
			for (const string line: lines) {
				all_spaces &= !line.empty() && line[0] == ' ';
			}
			if (all_spaces) {
				for (string &line: lines) {
					if (1 < line.size()) {
						line = line.substr(1);
					} else line.clear();
				}
			} else {
				break;
			}
		}
	}

	assert(mats.size() == ops.size());
	cout << "parsing done\n";

	int max_len = 0;

	auto compute = [](const vector<string> &mat, const char symbol) {
		const int ROWS = mat.size();
		const int COLS = mat[0].size();

		int value = symbol == '+'? 0 : 1;
		for (int j = 0; j < COLS; j++) {
			int number = 0;
			for (int i = 0; i < ROWS; i++) { // NOTE:: used COLS instead of ROWS here earlier
				if (isdigit(mat[i][j])) {
					number = number * 10 + int(mat[i][j] - '0');
				}
			}
			cout << "created number = " << number << '\n';

			if (symbol == '+') value += number;
			if (symbol == '*') value *= number;
		}

		return value;
	};

	const int LEN = mats.size();


	for (auto mat: mats) {
		print_mat(mat);
	}

	uint64_t answer = 0;
	for (int i = 0; i < LEN; i++) {
		int result = compute(mats[i], ops[i]);
		cout << " result = " << result << '\n';
		answer += result;
	}

	cout << "answer = " << answer << '\n';
	
	return 0;
}

// 16728927853 - attempt 1
// 9876636978528 - attempt 2 (solution)
