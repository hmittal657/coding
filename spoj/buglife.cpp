#include <bits/stdc++.h>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/BUGLIFE/

bool solve(int n, vector<vector<int>>& adj) {

	if (n <= 2) {
		return true;
	}

	vector<int> color(n+1, -1);

	for (int i = 1; i <= n; i++) {
		if (color[i] != -1) continue;

		queue<int> q;
		vector<int> color(n+1, -1);
		
		q.push(i);
		color[i] = 1;

		while (!q.empty()) {

			int t = q.front();
			q.pop();

			int cur = color[t];

			for (int j =0; j < adj[t].size(); j++) {
				int y = adj[t][j];
				if (color[y] != -1) {
					if (color[y] == cur) {
						return false;
					}
				} else {
					color[y] = 1 - cur;
					q.push(y);
				}
			}
		}
	}

	return true;

}

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;

	int count = 0;

	while (count < t) {

		int n, m;
		cin >> n >> m;

		vector<vector<int>> adj(n+1, vector<int>(0));

		int u, v;
		
		for (int i =0; i < m; i++) {
				cin >> u >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
		}

		cout << "Scenario #" << (count+1) << ":" << endl;

		if (solve(n, adj)) {
			cout << "No suspicious bugs found!" << endl;
		} else {
			cout << "Suspicious bugs found!" << endl;
		}

		count++;
	}

	return 0;
}
