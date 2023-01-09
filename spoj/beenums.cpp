#include <iostream>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/BEENUMS/

void solve(ll n) {

	ll l = 0;
	ll h = n;
	ll res = -1;
	while (l <= h) {
		ll mid = (l+h)/2;
		ll term = 3*mid*mid;
		term -= 3*mid;
		term++;

		if (term == n) {
			res = term;
			break;
		} else if (term > n) {
			h = mid-1;
		} else {
			l = mid+1;
		}
	}

	if (res != -1) {
		printf("Y\n");
	} else {
		printf("N\n");
	}

}

int main() {
	
	ll n;

	while (true) {
		scanf("%lld", &n);
		if (n == -1) break;
		solve(n);
	}

	return 0;
}