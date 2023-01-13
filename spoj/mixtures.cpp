#include <iostream>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/MIXTURES/
int n;
ll nums[101];

ll dp[101][101];

ll pre[101];

ll solve(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];

	if (i == j) {
		dp[i][j] = 0;
		return dp[i][j];
	}


	ll ans = -1L;

	for (int k = i; k < j; k++) {
		ll a = solve(i, k) + solve(k+1, j);
		ll pre1 = pre[k];
		if (i-1 >= 0) {
			pre1 -= pre[i-1];
		}

		pre1 = (pre1 + 100)%100;

		ll pre2 = pre[j];
		if (k >= 0) {
			pre2 -= pre[k];
		}

		pre2 = (pre2 + 100)%100;

		a += (pre1 * pre2);
		if (ans == -1) {
			ans = a;
		} else {
			ans = min(ans, a);
		}
	}

	dp[i][j] = ans;
	return dp[i][j];
}

int main() {

	while (scanf("%d", &n) != EOF) {

		for (int i = 0; i < n; i++) {
			scanf("%lld", &nums[i]);
		}

		pre[0] = nums[0];
		for (int i =1; i < n; i++) {
			pre[i] = pre[i-1] + nums[i];
			pre[i] = pre[i] % 100;
		}

		for (int i =0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1;
			}
		}

		printf("%lld\n", solve(0, n-1));

	}

	return 0;
}