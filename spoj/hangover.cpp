#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/HANGOVER/

void solve (double pre[], double target) {

	int l = 0;
	int h = 300;

	int res = 300;

	while (l <= h) {
		int m = (l+h)/2;
		if (pre[m] < target) {
			l++;
		} else {
			res = min(res, m);
			h--;
		}
	}

	cout <<  res << " card(s)" << endl;

}

int main() {

	std::ios::sync_with_stdio(false);

	double pre[302];

	pre[0] = 0;

	double target;
	double sum = 0;
	for (int i=1; i < 302; i++) {
		double num = (1);
		double denom = (double)(i+1);
		sum += (num/denom);
		pre[i] = sum;
	}

	double n; 

	while(true) {
		cin >> n;
		if (n == 0.00) {
			break;
		}

		solve(pre, n);

	}

	return 0;
}

// pre[300] is 5.28599