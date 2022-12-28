#include <bits/stdc++.h>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/WILLITST/

bool fun(ll i) {
	while (true) {
		if (i == 1) return 1;
		if (i % 2 == 1) {
			return false;
		}
		i = i/2;
	}

	return false;
}

int main() {

	std::ios::sync_with_stdio(false);

	ll n;

	cin >> n;

	if (fun(n)) {
		cout << "TAK" << endl;
	} else {
		cout << "NE" << endl;
	}

	return 0;
}
