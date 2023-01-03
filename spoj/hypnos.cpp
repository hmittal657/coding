#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/HPYNOS/

int steps(ll n) {
	if (n == 1) return 0;

	unordered_map<ll, int> m;
	m[n] = 1;

	while (true) {
		vector<ll> digits;
		ll temp = n;
		while(temp > 0) {
			digits.push_back(temp%10);
			temp = temp/10;
		}

		ll sq = 0;
		for (int i =0; i < digits.size(); i++) {
			sq += (digits[i]*digits[i]);
		}
		if (sq == 1) {
			return m.size();
		}
		if (m.find(sq) != m.end()) {
			return -1;
		}
		m[sq] = 1;
		n = sq;
	}

	return 10;


}

int main() {

	ll n;
	scanf("%lld", &n);
	printf("%d\n", steps(n));
	return 0;
}