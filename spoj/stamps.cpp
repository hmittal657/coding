#include <bits/stdc++.h>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/STAMPS/

static bool comp(int& a, int& b) {
	return a > b;
}

int solve(vector<int>& nums, int target) {

	int n= nums.size();

	int sum = 0;
	for (int i =0;  i < n ; i++) {
		sum += nums[i];
	}

	if (sum < target) return -1;

	sort(nums.begin(), nums.end(), comp);

	if (nums[0] >= target) {
		return 1;
	}

	for (int i = 1; i < n; i++) {
		nums[i] += nums[i-1];
		if (nums[i] >= target) {
			return (i+1);
		}
	}

	return -1;

}

int main() {

	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;

	int count = 0;

	while(count < t) {
		int target, n;

		cin>>target>>n;

		if (target == 0) {
			cout << "Scenario #" << (count+1) << ":" << endl;
			cout << 0 << endl;
			cout << endl;
			count++;
			int x;
			for (int i=0; i < n; i++) {
				cin >> x;
			}
			continue;
		}

		if (n == 0) {
			cout << "Scenario #" << (count+1) << ":" << endl;
			cout << 0 << endl;
			cout << endl;
			count++;
			continue;
		}

		vector<int> nums(n);

		for (int i =0; i < n; i++) {
			cin >> nums[i];
		}

		cout << "Scenario #" << (count+1) << ":" << endl;

		int ans = solve(nums, target);

		if (ans == -1) {
			cout << "impossible" << endl;
		} else {
			cout << ans << endl;
		}
		cout << endl;

		count++;
	}

	return 0;
}
