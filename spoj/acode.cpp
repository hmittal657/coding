#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/ACODE/

#define ll long long

int to_int(string& x) {

	if (x == "0") {
		return 0;
	}

	int ans = 0;

	for (int i =0; i < x.size(); i++) {
		ans = 10 * ans + (x[i]-'0');
	}

	return ans;

}

ll solve(string& s) {
	int n= s.size();

	if (n < 2) {
		if (s == "0") {
			return 0;
		}
		return 1;
	}

	vector<ll> dp(n+1, 0);

	dp[0] = 1;
	if (s[0] == '0') {
		dp[1] = 0;
	} else {
		dp[1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp[i] = 0;
		string a = "";
		a.push_back(s[i-2]);
		a.push_back(s[i-1]);
		int t = to_int(a);
		if (t >= 10 && t <= 26) {
			dp[i] += dp[i-2];
		}

		a = "";
		a.push_back(s[i-1]);
		t = to_int(a);
		if (t >= 1 && t <= 26) {
			dp[i] += dp[i-1];
		}
	}

	return dp[n];

}

int main() {

	std::ios::sync_with_stdio(false);
	string s;

	while(true) {
		cin>>s;

		if (s == "0") break;

		cout << solve(s) << endl;

	}

	return 0;
}