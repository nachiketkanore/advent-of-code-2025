#include <bits/stdc++.h>
#define int int64_t
using namespace std;


int mask_to_integer(const string &mask) {
	int result = 0;
	for (int i = 0; i < int(mask.size()); i++) {
		if (mask[i] == '#') {
			result |= 1ll << i;
		}
	}
	return result;
}

const int INF = 1e9;
const int MAX_NODES = 1<<11;
vector<pair<int, int>> g[MAX_NODES];

void dijkstra(int s, vector<int> &d) {

  d[s] = 0;
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty()) {
    int v = q.top().second;
    int d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
      continue;

    for (auto edge : g[v]) {
      int to = edge.first;
      int len = edge.second;

      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        q.push({d[to], to});
      }
    }
  }
}

bool vis[MAX_NODES];
void dfs(int u, const vector<int> &ops) {
	if (vis[u]) return;
	vis[u] = true;

	for (int op: ops) {
		int to = u ^ op;
		g[u].push_back(make_pair(to, 1));
		dfs(to, ops);
	}
}

int solve(int target, const vector<int> &ops) {
	for (int i = 0; i < MAX_NODES; i++) {
		g[i].clear();
		vis[i] = false;
	}

	vector<int> distances(MAX_NODES, INF);
	distances[0] = 0;

	dfs(0, ops);

	dijkstra(0, distances);

	cout << "target = " << target <<  " answer = " << distances[target] << '\n';
	return distances[target];
}

int32_t main() {
	int answer = 0;
	string in;
	int req_num = 0;
	vector<int> ops;
	while (cin >> in) {
		// cout << "in = " << in << '\n';
		if (in[0] == '[') {
			const int LEN = in.size();
			string req_mask = in.substr(1, LEN - 2);
			req_num = mask_to_integer(req_mask);
		} else if (in[0] == '(') {
			string nums = in.substr(1);
			int xor_mask = 0;
			for (char ch: nums) {
				if (isdigit(ch)) {
					int digit = int(ch - '0');
					xor_mask |= 1ll << digit;
				}			
			}
			ops.push_back(xor_mask);

		} else if (in[0] == '{') {
			// ignore for part 1

			answer += solve(req_num, ops);
			// cout << "req_num = " << req_num << '\n';
			// for (int op: ops) {
			// 	cout << op << " ";
			// } cout << '\n';

			req_num = 0;
			ops.clear();
		}
	}

	cout << "part one answer = " << answer << '\n';
	
	return 0;
}

