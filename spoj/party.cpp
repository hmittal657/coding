#include <iostream>
using namespace std;

// https://www.spoj.com/problems/PARTY/

int weights[101];
int fun[101];

int main() {

	int w, n;
	 while (true) {
	 	scanf("%d", &w);
	 	scanf("%d", &n);
	 	if (w == 0 && n == 0) {
	 		break;
	 	}

	 	for (int i = 0; i < n; i++) {
	 		scanf("%d", &weights[i]);
	 		scanf("%d", &fun[i]);
	 	}

	 	int dp[501][101];

	 	for (int j = 0; j <= n; j++) {
	 		dp[0][j] = 0;
	 	}

	 	for (int i = 0; i <= w; i++) {
	 		dp[i][0] = 0;
	 	}

	 	for (int i = 0; i <= w; i++) {
	 		for (int j = 1; j <= n; j++) {
	 			dp[i][j] = dp[i][j-1];
	 			if (i - weights[j-1] >= 0) {
	 				dp[i][j] = max(dp[i][j], dp[i-weights[j-1]][j-1] + fun[j-1]);
	 			}
	 		}
	 	}

	 	int r = w;
	 	while (r >= 0 && dp[r][n] == dp[w][n]) {
	 		r--;
	 	}

	 	printf("%d %d\n", r+1, dp[r+1][n]);

	 }

	return 0;
}