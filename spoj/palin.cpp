#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/PALIN/

bool checkPal(string& s) {
	int l = 0;
	int h = s.size()-1;

	while (l <= h) {
		if (s[l] != s[h]) {
			return false;
		}
		l++;
		h--;
	}
	return true;
}

string gennext(string& s) {

	int n = s.size();
	bool all9 = true;

	for (int i=0; i < n; i++) {
		if (s[i] != '9') {
			all9 = false;
			break;
		}
	}

	if (all9) {
		string ans = "1";
		for (int i=0; i < n-1; i++) {
			ans.push_back('0');
		}
		ans.push_back('1');
		return ans;
	}
	int l,h;

	if (n % 2 == 0) {
		l = n/2;
		l--;
	} else {
		l = n/2;
	}

	int temp = l;

	while(true) {
		if (s[l] != '9') {
			int x = s[l] - '0';
			x++;
			s[l] = (char)(x + '0');
			break;
		} else {
			l--;
		}
	}
	
	for (int i = l+1; i <= temp; i++) {
		s[i] = '0';
	}

	
	if (n%2 == 0) {
		l = n/2;
		l--;
		h = l+1;
	} else {
		l = n/2;
		h = l;
	}

	while (l >= 0 && h  <  n) {
		s[h] = s[l];
		l--;
		h++;
	}

	return s;

}

string solve(string& s) {
	int n = s.size();

	if (s == "9") {
		return "11";
	}

	if (n == 1) {
		int x = s[0] - '0';
		string ans = "";
		
		ans.push_back((char)('0' + x + 1));
		return ans;
	}

	bool all9 = true;

	for (int i=0; i < n; i++) {
		if (s[i] != '9') {
			all9 = false;
		}
	}

	if (all9) {
		string ans = "1";
		for (int i=0; i < n-1; i++) {
			ans.push_back('0');
		}
		ans.push_back('1');
		return ans;
	}

	int l = 0;
	int h = n-1;

	bool isPal = true;
	int firstchange = -1;

	while (l <= h) {
		
		int x = s[l];
		int y = s[h];

		if (x != y) {
			isPal = false;
		}

		if (x > y) {
			firstchange = l;
			s[h] = s[l];
			l++;
			h--;
		} else {
			l++;
			h--;
		}
	}

	if (isPal) {
		return gennext(s);
	} else {
		if (checkPal(s)) {
			return s;
		} else {
			
			if (firstchange != -1) {
				int i = firstchange-1;
				while (i >= 0) {
					s[n-1-i] = s[i];
					i--;
				}
				if (checkPal(s)) {
					return s;
				} else {
					return gennext(s);
				}
			} else {
				return gennext(s);
			}
		}
	}

}

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t > 0) {
		
		string s;
		cin >> s;

		cout << solve(s) << endl;
		
		t--;

	}

	return 0;
}

/**
Some test cases to test correctness
808 => 818
2133 => 2222
231645 => 232232
100000000 => 100000001
645236 => 645546
8928932 => 8929298
101 => 111
2222 => 2332
10234284 => 10244201
299393 => 299992
909 => 919
0 => 1
9999999999999 => 10000000000001
892390 => 893398
19913393 => 19922991
1289489 => 1289821
10393884 => 10399301
101001 => 101101
4908320 => 4909094
9 => 11
75 => 77
776 => 777
4891 => 4994
92764 => 92829
999539 => 999999
7059657 => 7060607
48756572 => 48766784
633149324 => 633151336
2096785014 => 2096886902
80448359477 => 80448384408
237762850363 => 237763367732
7730351516591 => 7730351530377
79541453924626 => 79541455414597
*/