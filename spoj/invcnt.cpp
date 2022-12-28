#include <bits/stdc++.h>
using namespace std;

#define ll long long

// https://www.spoj.com/problems/INVCNT/

void merge(vector<ll>& nums, ll l, ll h, ll& ans) {
	
	if (l == h) {
		return;
	}

	if (h == l+1) {
		if (nums[h] < nums[l]) {
			swap(nums[l], nums[h]);
			ans++;
		}
		return;
	}

	ll m  = (l+h)/2;

	merge(nums, l, m, ans);
	merge(nums, m+1, h, ans);

	ll i = l;
	
	ll j = m+1;


	vector<ll> temp;

	while (temp.size() < (h - l +1)) {
		if (i > m) {
			temp.push_back(nums[j]);
			j++;
		} else if (j > h) {
			temp.push_back(nums[i]);
			i++;
		} else {
			if (nums[i] < nums[j]) {
				temp.push_back(nums[i]);
				i++;
			} else {
				temp.push_back(nums[j]);
				ans += (m-i + 1);
				j++;
			}
		}
	}

	for (ll i = l; i <= h; i++) {
		nums[i] = temp[i-l];
	}

}

ll solve(vector<ll>& nums, ll n) {
	if (n  < 2) return 0;

	ll i =0;
	ll h= n-1;

	ll ans = 0;

	merge(nums, 0, n-1, ans);

	return ans;

}

int main() {

	std::ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while (t  > 0) {
		ll n;
		cin >> n;
		vector<ll> nums(n);

		for (ll i=0; i < n; i++) {
			cin >> nums[i];
		}

		cout << solve(nums, n) << endl; 
		t--;
	}

	return 0;
}
