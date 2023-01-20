// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:

#define ll long long

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> next(n, -1);
        vector<ll> pre(n, 0);
        pre[0] = (ll)nums[0];

        for (int i=1; i < n; i++) {
            pre[i] = pre[i-1] + (ll)nums[i];
        }

        next[n-1] = -1;

        for (ll i = n-2; i >= 0; i--) {
            ll x = i+1;
            while (x != -1 && nums[x] <= nums[i]) {
                x = next[x];
            }
            next[i] = x; 
        }

        int i = 0;
        
        ll ans = 1;

        while (i != -1) {
            ll temp;
            if (next[i] == -1) {
                temp = (ll)(n-i);
            } else {
                temp = (ll)next[i] -(ll)i;
            }

            int h = i-1;
            int l = 0;

            ll res = -1;

            while (l <= h) {
                int mid = (l+h)/2;
                ll x = pre[i];
                if (mid > 0) {
                    x -= pre[mid-1];
                }
                ll z = (ll)(i- mid + 1) * ((ll)nums[i]);
                z -= x;
                if (z <= k) {
                    res = mid;
                    h = mid-1;
                } else {
                    l = mid+1;
                }
            }

            if (res != -1) {
                temp += (ll)(i-res);
            }

            ans = max(ans, temp);
            i = next[i];

        }


        return ans;

    }
};