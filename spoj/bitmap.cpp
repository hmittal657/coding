#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/BITMAP/

int dp[187][187];
bool visited[187][187];
char arr[187][187];

int n, m;

void bfs() {

	queue<pair<pair<int, int>, int>> q;

	for (int i =0; i < n; i++) {
		for (int j =0; j < m; j++) {
			if (arr[i][j] == '1') {
				q.push(make_pair(make_pair(i, j), 0));
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();
		int i = cur.first.first;
		int j = cur.first.second;
		dp[cur.first.first][cur.first.second] = cur.second;
		if (i + 1 < n && visited[i+1][j] == false) {
			q.push(make_pair(make_pair(i+1, j), cur.second+1));
			visited[i+1][j] = true;
		}
		if (j + 1 < m && visited[i][j+1] == false) {
			q.push(make_pair(make_pair(i, j+1), cur.second+1));
			visited[i][j+1] = true;
		}
		if (i - 1 >= 0 && visited[i-1][j] == false) {
			q.push(make_pair(make_pair(i-1, j), cur.second+1));
			visited[i-1][j] = true;
		}
		if (j - 1 >= 0 && visited[i][j-1] == false) {
			q.push(make_pair(make_pair(i, j-1), cur.second+1));
			visited[i][j-1] = true;
		}
	}

}

int main() {

	int t;
	scanf("%d", &t);

	while (t > 0) {
		scanf("%d", &n);
		scanf("%d", &m);

		for (int i = 0; i < n; i++) {
			scanf("%s", &arr[i]);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = 10000;
				visited[i][j] = false;
			}
		}

		bfs();

		for (int i =0 ; i < n; i++) {
			for (int j=0;j<m-1; j++) {
				cout << dp[i][j] << " ";
			}
			cout << dp[i][m-1] << endl;
		}

		t--;
	}

	return 0;
}