#include <iostream>
using namespace std;

// https://www.spoj.com/problems/TRT/

#define ll long long

int n;

ll nums[2001];

ll dp[2001][2001];

ll fun(int i, int j) {
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (i == j) {
		ll f = (ll)(n+1 -1);
		dp[i][j] = f * nums[i];
		return dp[i][j];
	}

	ll f = (ll)(n + 1 - (j-i+1));
	dp[i][j] = max(f * nums[i] + fun(i+1, j), f*nums[j] + fun(i, j-1));

	return dp[i][j];

}

int main() {

	scanf("%d", &n);

	for (int i =0; i< n; i++) {
		scanf("%lld", &nums[i]);
	}

	for (int i =0; i < n; i++) {
		for (int j = i; j < n; j++) {
			dp[i][j] = -1;
		}
	}

	printf("%lld\n", fun(0, n-1));

	return 0;
}