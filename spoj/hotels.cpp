#include <iostream>
#include <vector>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/HOTELS/

int main() {

	int n;
	ll m;
	scanf("%d", &n);
	scanf("%lld", &m);

	vector<ll> arr(n);

	scanf("%lld", &arr[0]);

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ll t;
		scanf("%lld", &arr[i]);
		t = arr[i];
		if (t <= m) {
			ans = max(ans, t);
		}
	}

	vector<ll> pre(n);
	pre[0] = arr[0];

	for (int i = 1; i < n; i++) {
		pre[i] = pre[i-1] + arr[i];
	}

	int j = 0;

	ll cur = 0;
	
	for (int i = 0; i < n; i++) {
		if (i > j) {
			j = i;
		}
		if (i == j) {
			cur = arr[i];
		} else {
			if (i-1 >= 0) {
				cur = pre[j]-pre[i-1];
			} else {
				cur = pre[j];
			}
		}

		if (cur <= m) {
			ans = max(ans, cur);
		} else {
			continue;
		}

		for (int k = j+1; k < n; k++) {
			cur += arr[k];
			if (cur > m) {
				j = k-1;
				break;
			} else {
				ans = max(ans, cur);
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}