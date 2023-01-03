#include <iostream>
#include <vector>
#include <string>
using namespace std;

// https://www.spoj.com/problems/AIBOHP/

string rev(string& s) {
	string ans = "";
	for (int i = s.size()-1 ;  i >= 0; i--) {
		ans.push_back(s[i]);
	}
	return ans;
}

int lcs(string& a, string& b) {

	int n = a.size();

	vector<int> f(n+1, 0);
	vector<int> s(n+1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i-1] == b[j-1]) {
				s[j] = 1 + f[j-1];
			} else {
				s[j] = max(s[j-1], f[j]);
			}
		}

		for (int j =0; j <= n; j++) {
			f[j] = s[j];
		}
	}

	return s[n];

}

int main() {

	int t;

	std::ios::sync_with_stdio(false);

	cin >> t;

	while (t > 0) {
		string s;
		cin >> s;
		string r = rev(s);

		int l = lcs(s, r);

		cout << (s.size() - l) << endl;

		t--;
	}

	// your code goes here
	return 0;
}