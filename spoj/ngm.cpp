#include <iostream>
using namespace std;

// https://www.spoj.com/problems/NGM/

#define ll long long

int main() {

	ll x;
	cin >> x;

	if (x % 10L != 0) {
		cout << 1 << endl;
		cout << (x%10L) << endl;
	} else {
		cout << 2 << endl;
	}

	return 0;
}