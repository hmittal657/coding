#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/STPAR/

string solve(vector<int>& nums) {
	int n = nums.size();

	if (n == 1) {
		return "yes";
	}

	stack<int> s;

	int travelled = 0;

	for (int i =0; i < n; i++) {

		while (!s.empty()) {
			int t = s.top();
			if (t == travelled + 1) {
				travelled++;
				s.pop();
			} else {
				break;
			}
		}

		if (nums[i] == travelled+1) {
			travelled++;
		} else {
			s.push(nums[i]);
		}
	}

	while (!s.empty()) {
		int t = s.top();
		if (t == travelled + 1) {
			travelled++;
			s.pop();
		} else {
			break;
		}
	}

	if (travelled == n) {
		return "yes";
	} else {
		return "no";
	}

}

int main() {

	std::ios::sync_with_stdio(false);

	int n;
	

	while (true) {
		
		cin >> n;
		if (n == 0) {
			break;
		}

		vector<int> nums(n);

		for (int  i =0; i < n; i++) {
			cin>>nums[i];
		}

		cout << solve(nums) << endl;
	}

	return 0;
}


/**
 * 
 * Some test cases
 
5
5 1 2 4 3 => yes
5
5 1 3 4 2 => no
3
1 2 3 => yes
1
1 => yes
6
6 2 1 3 4 5 => yes
0

 * /
