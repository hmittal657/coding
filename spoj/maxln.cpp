#include <iostream>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/MAXLN/

int main() {
	
	int t;
	scanf("%d", &t);
	
	int count = 0;

	while (count < t) {
		
		ll n;
		scanf("%lld", &n);

		ll ans = 4 * (n) * (n);

		printf("Case %d: %lld.25\n", count+1, ans);

		count++;
	}

	return 0;
}