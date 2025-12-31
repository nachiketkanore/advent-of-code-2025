#include <bits/stdc++.h>
#define int int64_t
using namespace std;

map<string, vector<string>> adj;
map<string, int> dp;

int go(const string& node) {
	if (node == "out") {
		return 1;
	}
	if (dp.count(node)) {
		return dp[node];
	}
	int ways = 0;
	const auto& neighbors = adj[node];
	for (const string& v: neighbors) {
		ways += go(v);
	}
	dp[node] = ways;
	return ways;
}

int32_t main() {
	string line;
	string source;
	while (cin >> line) {
		if (line.back() == ':') {
			source = line;
			source.pop_back();
		} else {
			string neighbor = line;
			adj[source].push_back(neighbor);
		}
	}
	// for (auto [u, neigh]: adj) {
	// 	cout << "source = " << u << " ---> neighbors are = ";
	// 	for (string v: neigh) {
	// 		cout << v << " ";
	// 	} cout << "\n";
	// }

	int answer = go("you");
	cout << "answer = " << answer << '\n';
	return 0;
}

