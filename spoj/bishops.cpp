#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/BISHOPS/

string mul(string& s) {
	if (s == "0") return "0";
	int n = s.size();
	string ans = "";
	for (int i = 0; i < n+2; i++) {
		ans.push_back('0');
	}

	int carry = 0;

	for (int i = 0; i < n; i++) {
		int t = s[n-1-i]-'0';
		t = t*2;
		t += carry;
		if (t >= 10) {
			carry = 1;
			t = t%10;
		} else {
			carry = 0;
		}

		ans[ans.size()-1-i] = (char)(t + '0');
	}

	if (carry > 0) {
		ans[ans.size()-1-n] = '1';
	}

	int l = 0;
	while (ans[l] == '0') {
		l++;
	}

	return ans.substr(l, ans.size()-l);
}

string sub2(string& s) {
	if (s == "2") return "0";
	int n = s.size();
	string ans = "";
	for (int i = 0; i < n+2; i++) {
		ans.push_back('0');
	}

	int carry = 0;

	int t = (s[n-1] - '0');

	if (t >= 2) {
		ans[ans.size()-1] = (char)((t-2) + '0');
		carry = 0;
	} else {
		t = 10+t;
		t -= 2;
		carry = 1;
		ans[ans.size()-1] = (char)(t + '0');
	}
	for (int i =1; i < n; i++) {
		t = s[n-1-i] - '0';
		if (carry == 1) {
			t--;
		}
		if (t < 0) {
			t += 10;
			t = t%10;
			carry = 1;
		} else {
			carry = 0;
		}
		ans[ans.size()-1-i] = (char)(t + '0');
	}

	int l = 0;
	while (ans[l] == '0') {
		l++;
	}

	return ans.substr(l, ans.size()-l);

}

int main() {

	std::ios::sync_with_stdio(false);

	string s;
	while (cin>>s) {
		if (s == "1") {
			cout << "1" << endl;
			continue;
		}
		string ans = mul(s);
		ans = sub2(ans);
		cout << ans << endl;
	}

	return 0;
}
