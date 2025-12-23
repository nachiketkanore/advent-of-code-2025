#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1005;

struct DSU {
	int connected;
	int par[N], sz[N];
	bool vis[N];

	void init(int n) {
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
			vis[i] = false;
		}
		connected = n;
	}

	int getPar(int k) {
		while (k != par[k]) {
			par[k] = par[par[k]];
			k = par[k];
		}
		return k;
	}

	int getSize(int k) { return sz[getPar(k)]; }

	void unite(int u, int v) {
		int par1 = getPar(u), par2 = getPar(v);

		if (par1 == par2)
			return;

		connected--;

		if (sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};

void print_cord(const vector<int> &cord) {
	cout << cord[0] << "," << cord[1] << "," << cord[2] << '\n';
}

bool already[N][N];


int32_t main() {

	string line;
	vector<vector<int>> C;
	while (cin >> line) {
		int x = 0;
		vector<int> c;
		for (char ch: line) {
			if (isdigit(ch)) {
				x = x * 10 + (ch - '0');
			} else if (ch == ',') {
				c.push_back(x);
				x = 0;
			}
		}
		c.push_back(x);
		C.push_back(c);
		// for (int x: cords) {
		// 	cout << x << " ";
		// }	cout << '\n';
	}

	const int NODES = C.size();

	DSU dsu; dsu.init(NODES);

	auto distance = [](const vector<int>& one, const vector<int> &two) {
		assert(one.size() == 3);
		assert(two.size() == 3);
		int dist = 0;
		for (int i = 0; i < int(one.size()); i++) {
			dist += (one[i] - two[i]) * (one[i] - two[i]);
		}
		return dist;
	};

	vector<vector<int>> distances;

	for (int i = 0; i < NODES; i++){
		for (int j = i + 1; j < NODES; j++) {
			int dist = distance(C[i], C[j]);
			distances.push_back({ dist, i, j });
		}
	}
	sort(distances.begin(), distances.end());

	int answer = -1;

	for (auto dij: distances) {
		int dist = dij[0], i = dij[1], j = dij[2];
		dsu.unite(i + 1, j + 1);
		if (dsu.connected == 1) {
			print_cord(C[i]);
			print_cord(C[j]);
			cout << "FOUND ANSWER\n";
			answer = C[i][0] * C[j][0];
			break;
		}
	}

	assert(~answer);
	cout << "answer = " << answer << '\n';

	return 0;
}

