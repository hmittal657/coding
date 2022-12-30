#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/EDIST/

int solve(string& a, string& b) {
	
	int m = a.size();
	int n = b.size();

	vector<int> f(n+1, 0);
	vector<int> s(n+1, 0);

	f[0] = 0;

	for (int i = 0; i <= n; i++) {
		f[i] = i;
	}

	for (int i = 1; i<=m; i++) {
		s[0] = i;
		for (int j = 1; j<=n ; j++) {
			s[j] = max(i, j);
			if (a[i-1] == b[j-1]) {
				s[j] = min(s[j], f[j-1]);
			} else {
				s[j] = min(s[j], 1 + f[j-1]);
			}
			s[j] = min(s[j], 1 + f[j]);
			s[j] = min(s[j], 1 + s[j-1]);
			
		}

		for (int j = 0; j <= n; j++) {
			f[j] = s[j];
		}
	}

	return s[n];

}

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;

	int count = 0;

	string a, b;

	while(count < t) {
		
		cin>>a>>b;

		cout << solve(a, b) << endl;

		count++;
	}
	
	return 0;
}
