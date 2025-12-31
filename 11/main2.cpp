#include <bits/stdc++.h>
#define int int64_t
using namespace std;

map<string, vector<string>> adj;
map<string, int> dp[2][2];

const string DAC = "dac";
const string FFT = "fft";

int go(const string& node, bool dac_visited, bool fft_visited) {
	if (node == "out") {
		return dac_visited && fft_visited;
	}
	if (dp[dac_visited][fft_visited].count(node)) {
		return dp[dac_visited][fft_visited][node];
	}
	int ways = 0;
	const auto& neighbors = adj[node];
	for (const string& v: neighbors) {
		ways += go(v, dac_visited || DAC == v, fft_visited || FFT == v);
	}
	dp[dac_visited][fft_visited][node] = ways;
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

	int answer = go("svr", false, false);
	cout << "answer = " << answer << '\n';
	return 0;
}

