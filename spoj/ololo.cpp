#include <iostream>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/OLOLO/

int main() {

	int n;
	scanf("%d", &n);

	ll ans = 0;

	ll t;

	while (n  > 0) {
		scanf("%lld", &t);
		ans = ans^t;
		n--;
	}

	printf("%lld\n", ans);

	// your code goes here
	return 0;
}