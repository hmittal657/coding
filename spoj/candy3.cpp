#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/CANDY3/

#define ll long long

int main() {

	ll t; 
	
	scanf("%lld", &t);

	while (t > 0) {
		ll n;
		scanf("%lld", &n);

		if (n == 0) {

			continue;
		}

		ll temp;
		ll sum = 0;

		for (ll i=0; i < n; i++) {
			scanf("%lld", &temp);
			temp = temp % n;
			sum += temp;
			sum = sum % n;
		}
		
		if (sum % n == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		
		t--;

	}

	return 0;
}