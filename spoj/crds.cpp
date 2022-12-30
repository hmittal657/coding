#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/CRDS/

#define ll long long

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;
	
	ll MOD = 1000007;

	int count = 0;

	while(count < t) {
		ll n;
		cin>>n;

		ll ans = n;
		ans *= ((3 * n) + 1);
		ans = ans/2;
		
		ans = ans % MOD;

		cout << ans << endl;

		count++;
	}
	
	return 0;
}
