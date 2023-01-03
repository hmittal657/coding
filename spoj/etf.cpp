#include <iostream>
#include <vector>
using namespace std;

// https://www.spoj.com/problems/ETF/

bool prime[2002];

#define ll long long

ll phi(ll n, vector<ll>& primes) {
	if (n == 1) return 1;

	if (n < 2002L) {
		if (prime[n] == false) {
			return (n-1);
		}
	}

	ll temp = n;

	vector<ll> factors;

	for (int i =0; i < primes.size(); i++) {
		ll p = primes[i];
		if (p > temp) break;
		if (temp % p == 0) {
			factors.push_back(p);
			while (temp % p == 0) {
				temp = temp/p;
			}
		}
	}

	if (factors.size() == 0) {
		return (n-1);
	}

	if (temp > 1) {
		factors.push_back(temp);
	}

	ll ans = n;

	for (int i = 0; i < factors.size(); i++) {
		ans = ans * (factors[i] - 1);
		ans = ans/(factors[i]);
	}

	return ans;

}

int main() {
	prime[0] = true;
	prime[1] = true;

	vector<ll> primes;

	for (int i = 2; i < 2002; i++) {
		if (prime[i] == false) {
			primes.push_back((ll)(i));
			for (ll j = i*i ; j < 2002; j+=i) {
				prime[j] = true;
			}
		}
	}

	std::ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while (t > 0) {
		ll n;
		cin >> n;

		cout << phi(n, primes) << endl;

		t--;
	}


	return 0;
}