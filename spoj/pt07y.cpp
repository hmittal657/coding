#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/PT07Y/

int find(int parent[], int u) {
	int x = u;

	while (x != parent[x]) {
		x = parent[x];
	}

	return x;
}

void merge(int parent[], int u, int v) {
	int x = find(parent, u);
	int y = find(parent, v);

	if (x == y) return ;

	if (x < y) {
		parent[y] = x;
	} else {
		parent[x] = y;
	}

}

int main() {

	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n;
	cin >> m;

	vector<vector<int>> adj(n, vector<int>(0));

	int parent[10001];

	for (int i=0 ; i < n; i++) {
		parent[i] = i;
	}

	for (int i=0; i < m; i++) {
		cin>>u>>v;
		merge(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	set<int> cmps;

	for (int i = 0; i  < n; i++) {
		cmps.insert(parent[i]);
	}

	if (cmps.size() > 1) {
		cout << "NO" << endl;
	} else {
		if (m >= n) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}


	return 0;
}