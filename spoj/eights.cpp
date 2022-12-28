#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/EIGHTS/

#define ll long long

int main() {

	std::ios::sync_with_stdio(false);
	
	ll t;
	cin >> t;

	vector<ll> last3;

	for (ll i = 0; i <= 1000; i++) {
		ll term = pow(i, 3);
		if (term % 1000 == 888) {
			last3.push_back(i);
		}
	}

	ll N = last3.size();

	while (t > 0) {

		ll a;

		cin >> a;

		ll pre = (a/N) * (1000L);

		ll r = (a + N) % N;

		if (r == 0) {
			pre -= 1000;
			r = N;
		}

		ll suf = last3[r-1];

		cout << (pre + suf) << endl;

		t--;
	}


	return 0;
}