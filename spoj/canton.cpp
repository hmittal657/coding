#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/CANTON/

void solve(int n) {
	if (n < 1) return;
	
	int l = 0;
	int h = 10001;

	int res = 0;


	while (l <= h) {
		int m = (l+h)/2;
		int temp = (m)*(m+1);
		temp = temp/2;
		if (temp < n) {
			res = max(res, m);
			l = m+1;
		} else if (temp == n) {
			res = (m-1);
			break;
		} else {
			h = m-1;
		}
	}
	
	if (res % 2 == 0) {
		int temp = (res)* (res+1);
		temp = temp/2;
		temp++;
		int num = res+1;
		int denom = 1;
		while (temp < n) {
			temp++;
			num--;
			denom++;
		}

		cout << "TERM " << n << " IS " << num << "/" << denom << endl;
	} else {
		int temp = (res)* (res+1);
		temp = temp/2;

		temp++;
		int num = 1;
		int denom = res+1;
		while (temp < n) {
			temp++;
			num++;
			denom--;
		}

		cout << "TERM " << n << " IS " << num << "/" << denom << endl;
	}

}

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;

	int count = 0;


	while(count < t) {
		
		int n;
		cin>>n;

		solve(n);

		count++;
	}
	
	return 0;
}
