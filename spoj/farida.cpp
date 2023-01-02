#include <iostream>
using namespace std;

// https://www.spoj.com/problems/FARIDA/

#define ll long long

int main() {

	int t;
	int count = 0;

	scanf("%d", &t);

	while (count < t) {
		count++;
		int n;
		scanf("%d", &n);

		if (n == 0) {
			printf("Case %d: %d\n", count, 0);
			continue;
		}

		ll x;
		scanf("%lld", &x);
		ll take_max = x;
		ll not_take_max = 0;
		ll ans = max(take_max, not_take_max);

		for (int i = 1; i < n; i++) {
			scanf("%lld", &x);
			ll u = take_max;
			ll v = not_take_max;
			take_max = not_take_max + x;
			not_take_max = max(u, v);
			ans = max(ans, not_take_max);
			ans = max(ans, take_max);
		}

		printf("Case %d: %lld\n", count, ans);
	}



	return 0;
}