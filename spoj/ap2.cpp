#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/AP2/

#define ll long long

void solve(ll x, ll y, ll s) {

	ll S = 2*s;

	ll denom = (x) + (y);

	ll n = S/denom;

	ll num = (y - x);
	ll den = (n-5);

	ll r = num/den;

	ll a = x - (2 * r);

	cout << n << endl;

	for (ll i = 0; i < n; i++) {
		cout << (a + (i)* (r)) << " ";
	}
	cout << endl;


}

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;
	
	int count = 0;

	while(count < t) {
		
		ll x, y, s;

		cin >> x >> y >> s;

		solve(x, y, s);

		count++;

	}
	
	return 0;
}
