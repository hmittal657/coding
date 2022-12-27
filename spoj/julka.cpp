#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/JULKA/

string substract(string& a, string& b) {
	if (a == b) {
		return "0";
	}
	string ans = "";
	int m = a.size();
	int n = b.size();

	for (int i =0; i <= m; i++) {
		ans.push_back('0');
	}

	bool carry = false;

	for (int i = 0; i < n; i++) {
		int x = a[m-1-i] - '0';
		int y = b[n-1-i] - '0';
		if (carry) {
			x--;
			carry = false;
		}

		if (x == -1) {
			x = 9;
			carry = true;
		} else if (x < y) {
			carry = true;
			x += 10;
		} else {
			// nothing
		}

		int t = x-y;

		ans[ans.size()-1-i] = (char)('0' + t);

	}

	for (int i = n ; i < m ; i++) {
		int x = a[m-1-i] - '0';
		if (carry) {
			x--;
			carry = false;
		}

		if (x == -1) {
			x = 9;
			carry = true;
		} else {

		}

		int t = x;
		ans[ans.size()-1-i] = (char)(t + '0');
	}

	int i = 0;

	while(true) {
		if (ans[i] == '0') {
			i++;
		} else{
			break;
		}
	}

	ans = ans.substr(i, ans.size()-i);

	return ans;
}

string add(string& a, string& b) {
	if (b == "0") {
		return a;
	}
	if (a == "0") {
		return b;
	}
	int m = a.size();
	int n = b.size();

	string ans = "";
	for (int i = 0; i < max(m,n)+2 ; i++) {
		ans.push_back('0');
	}

	bool carry = false;

	for (int i =0; i < min(m, n); i++) {
		int x = a[m-1-i] - '0';
		int y = b[n-1-i] - '0';

		int t = x+y;
		if (carry) {
			t++;
			carry = false;
		}

		if (t >= 10) {
			carry = true;
			t = t%10;
		}

		ans[ans.size()-1-i] = (char)('0' + t);
	}

	if (m > n) {
		for (int i = n; i < m; i++) {
			int x = a[m-1-i] - '0';
			int t = x;
			if (carry) {
				t++;
				carry = false;
			}

			if (t >= 10) {
				carry = true;
				t = t%10;
			}

			ans[ans.size()-1-i] = (char)('0' + t);
		}
	} else if (n > m) {
		for (int i = m; i < n; i++) {
			int x = b[n-1-i] - '0';
			int t = x;
			if (carry) {
				t++;
				carry = false;
			}

			if (t >= 10) {
				carry = true;
				t = t%10;
			}

			ans[ans.size()-1-i] = (char)('0' + t);
		}
	}

	if (carry) {
		ans[ans.size()-1-max(m,n)] = '1';
	}

	int i =0;

	while(true) {
		if (ans[i] == '0') {
			i++;
		} else {
			break;
		}
	}

	ans = ans.substr(i, ans.size()-i);

	return ans;
}

string half(string& a) {
	if (a == "0") {
		return "0";
	}
	string ans = "";
	int n = a.size();

	string cur = "";

	for (int i=0; i < n; i++) {
		cur.push_back(a[i]);
		int t = stoi(cur);
		if (t == 1) {
			ans.push_back('0');
			continue;
		}

		int r = t%2;
		int q = t/2;

		ans.push_back((char)('0' + q));

		if (r  == 1) {
			cur = "1";
		} else {
			cur = "";
		}

	}

	int i=0; 
	while (ans[i] == '0') {
		i++;
	}
	ans = ans.substr(i, ans.size()-i);

	return ans;

}

int main() {
	
	std::ios::sync_with_stdio(false);
	string a, b;
	for (int i=0; i < 10; i++) {
		cin>>a>>b;

		string db = substract(a, b);
		string hf = half(db);

		cout << add(hf, b) << endl;
		cout << hf << endl;
	}


	return 0;
}