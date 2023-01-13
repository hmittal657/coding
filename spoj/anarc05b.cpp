#include <iostream>
#include <unordered_map>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/ANARC05B/

ll arr1[10001];
ll arr2[10001];

int m, n;

ll dp1[10001];
ll dp2[10001];

unordered_map<ll, int> m1;
unordered_map<ll, int> m2;

ll fun1(int i);
ll fun2(int i);

ll fun1(int i) {
	if (i < 0) return 0;
	if (dp1[i] != -1) return dp1[i];
	ll ans;
	if (m2.find(arr1[i]) == m2.end()) {
		ans = fun1(i-1) + arr1[i];
	} else {
		ans = fun1(i-1) + arr1[i];
		ans = max(ans, fun2(m2[arr1[i]] - 1) + arr1[i]);
	}
	dp1[i] = ans;
	return dp1[i];
}

ll fun2(int i) {
	if (i < 0) return 0;
	if (dp2[i] != -1) return dp2[i];
	ll ans;
	if (m1.find(arr2[i]) == m1.end()) {
		ans = fun2(i-1) + arr2[i];
	} else {
		ans = fun2(i-1) + arr2[i];
		ans = max(ans, fun1(m1[arr2[i]] - 1) + arr2[i]);
	}
	dp2[i] = ans;
	return dp2[i];
}

int main() {

	while (true) {
		scanf("%d", &m);
		if (m == 0) break;

		ll sum1 = 0;

		for (int i =0; i < m; i++) {
			scanf("%lld", &arr1[i]);
			m1[arr1[i]] = i;
			dp1[i] = -1;
			sum1 += arr1[i];
		}

		scanf("%d", &n);

		ll sum2 = 0;

		for (int i =0; i < n; i++) {
			scanf("%lld", &arr2[i]);
			m2[arr2[i]] = i;
			dp2[i] = -1;
			sum2 += arr2[i];
		}

		ll ans = max(sum1, sum2);


		dp1[0] = arr1[0];
		dp2[0] = arr2[0];

		ans = max(fun1(m-1), ans);
		ans = max(fun2(n-1), ans);

		printf("%lld\n", ans);

		m1.clear();
		m2.clear();

	}

	return 0;
}