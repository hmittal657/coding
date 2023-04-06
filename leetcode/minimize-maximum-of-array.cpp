// https://leetcode.com/problems/minimize-maximum-of-array

class Solution {
public:

    #define ll long long

    bool possible(vector<int>& nums, int m) {

        ll dec = 0;

        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] <= m) {
                if (dec < 0) {
                    dec += (ll)(m-nums[i]);
                    dec = min(dec, 0LL);
                }
            } else {
                dec -= (ll)(nums[i]-m);
            }
        }

        if (dec < 0) return false;
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();

        int mini = nums[0];
        int maxi = nums[0];

        for (int i=0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        if (maxi == mini) return maxi;

        int l = mini;
        int h = maxi;

        int res = h;

        while (l <= h) {
            int m = (l+h)/2;
            if (possible(nums, m)) {
                res = min(m, res);
                h = m-1;
            } else {
                l = m+1;
            }
        }

        return res;

    }
};