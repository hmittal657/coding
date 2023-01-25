#include <iostream>
#include <algorithm>
using namespace std;

// https://www.spoj.com/problems/PIGBANK/

#define ll long long

struct Coin {
	int price;
	int weights;
};

ll INVALID = -1L;

ll dp[10001];

Coin arr[501];

static bool comp(Coin a, Coin b) {
	return a.weights < b.weights;
}

int main() {
	
	int t;
	scanf("%d", &t);

	while (t > 0) {

		int e, f;
		scanf("%d", &e);
		scanf("%d", &f);

		int n;

		scanf("%d", &n);

		for (int i =0; i < n; i++) {
			ll p;
			int w;

			scanf("%lld", &p);
			scanf("%d", &w);

			arr[i] = {p, w};
		}

		sort(arr, arr+n, comp);

		for (int i = e+1; i <= f; i++) {
			dp[i-e] = INVALID;
		}

		dp[0] = 0;

		for (int i = 1; i <= f; i++) {
			for (int j = 0; j < n; j++) {
				if (i - arr[j].weights < 0) break;
				if (dp[i-arr[j].weights] != INVALID) {
					if (dp[i] == INVALID) {
						dp[i] = dp[i-arr[j].weights] + arr[j].price;
					} else {
						dp[i] = min(dp[i], dp[i-arr[j].weights] + arr[j].price);
					}
				}
			}
		}

		if (dp[f-e] == INVALID) {
			printf("This is impossible.\n");
		} else {
			printf("The minimum amount of money in the piggy-bank is %lld.\n", dp[f-e]);
		}

		t--;
	}

	return 0;
}