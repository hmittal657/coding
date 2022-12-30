#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

void solve(ll n) {
	ll ans  = (n * (n+1));
	ans = ans * ((2*n) + 3);
	if (n % 2 == 0) {
		ans -= n;
	} else {
		ans -= (n+1);
	}
	ans = ans/8;
	cout << (ll)(ans) << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t>0) {
		ll n;
		cin >> n;
		solve(n);
		t--;
	}
	return 0;
}


// https://www.spoj.com/problems/TRICOUNT/