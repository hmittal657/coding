#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/PT07Z/

#define ll long long

int res = 0;

int dfs(int u, int p, vector<int>& dp2, vector<vector<int>>& adj) {
	if (dp2[u] != -1) {
		return dp2[u];
	}
	int ans = 0;

	for (int i =0; i < adj[u].size(); i++) {
		if (adj[u][i] == p) {
			continue;
		}
		ans = max(ans, 1 + dfs(adj[u][i], u, dp2, adj));
	}

	dp2[u] = ans;
	res = max(dp2[u], res);

	return dp2[u];

}

int dfs2(int u, int p, vector<int>& dp, vector<int>& dp2,
	vector<vector<int>>& adj) {
	if (dp[u] != -1) {
		return dp[u];
	}

	int cnt = 0;

	for (int i =0; i < adj[u].size(); i++) {
		if (adj[u][i] == p) {
			continue;
		}
		cnt++;
	}

	if (cnt == 0) {
		dp[u] = 0;
		return dp[u];
	}

	if (cnt == 1) {

		for (int i =0; i < adj[u].size(); i++) {
			if (adj[u][i] == p) continue;
			dp[u] = 1 + dfs(adj[u][i], u, dp2, adj);
			
		}

	} else {

		priority_queue<int> pq;

		for (int i=0; i < adj[u].size(); i++) {
			if (adj[u][i] == p) continue;
			pq.push(dfs(adj[u][i], u, dp2, adj));
		}

		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		dp[u] = 2 + a + b;


	}

	for (int i=0; i < adj[u].size(); i++) {
		if (adj[u][i] == p) continue;
		dfs2(adj[u][i], u, dp, dp2, adj);
	}

	res = max(dp[u], res);
	return dp[u];

}

int main() {

	std::ios::sync_with_stdio(false);
	
	int n ;
	cin >> n;
	res = 0;
	vector<vector<int>> adj(n+1, vector<int>(0));

	for (int i =1; i < n; i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> dp(n+1, -1);
	vector<int> dp2(n+1, -1);

	dfs2(1, -1, dp, dp2, adj);

	cout << res << endl;


	return 0;
}


/**
 * Some test cases
 * 
 * 
18
1 2
2 3
3 4
4 5
4 6
4 8
7 8
12 13
8 9
8 10
10 11
11 13
13 14
13 15
13 16
16 17
17 18
 ans = 10

4
1 2
2 3
3 4
ans = 3


 * 
 * /
