#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.spoj.com/problems/EKO/

#define ll long long

bool fun(vector<ll>& nums, ll m, ll M, vector<ll>& pre) {

	if (m >= nums[nums.size()-1]) {
		return false;
	}

	if (m <= nums[0]) {
		ll sum = pre[nums.size()-1];
		sum -= ((ll)(nums.size()) * (m));
		return (sum >= M);
	}

	int l = 0;
	int h = nums.size()-1;

	int ind = h;

	while (l <= h) {
		int mid  = (l+h)/2;
		if (nums[mid] <= m) {
			l = mid+1;
		} else {
			ind = min(ind, mid);
			h = mid-1;
		}
	}
	
	
	
	ll sum = pre[nums.size()-1] - pre[ind-1];
	sum -= ((ll)(nums.size() - ind) * m);
	
	return (sum >= M);

}

int main() {

	std::ios::sync_with_stdio(false);

	int n;
	ll m;

	cin>>n>>m;

	vector<ll> nums(n);

	ll maxi = 0;
	vector<ll> pre(n);
	for (int i =0; i < n; i++) {
		cin >> nums[i];
		maxi = max(maxi, nums[i]);
	}

	sort(nums.begin(), nums.end());
	pre[0] = nums[0];
	for (int i = 1; i < n; i++) {
		pre[i] = nums[i] + pre[i-1];
	}

	ll l = 0;
	ll h = maxi + 1;

	ll res = h;

	while (l <= h) {
		ll mid = (l+h)/2;
		if (!fun(nums, mid, m, pre)) {
			res = min(res, mid);
			h = mid - 1;
		} else {
			l = mid+1;
		}
	}

	cout << res-1 << endl;

	return 0;
}