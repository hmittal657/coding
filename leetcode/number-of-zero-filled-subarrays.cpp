// https://leetcode.com/problems/number-of-zero-filled-subarrays

class Solution {
public:

#define ll long long

    ll fun(ll cur) {
        ll ans = (cur)*(cur+1);
        ans = ans/2;

        return ans;
    }

    long long zeroFilledSubarray(vector<int>& nums) {
        
        ll cur = 0LL;
        ll ans = 0LL;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cur++;
            } else {
                ans += fun(cur);
                cur = 0LL;
            }
        }

        if (cur > 0) {
            ans += fun(cur);
        } 

        return ans;

    }
};