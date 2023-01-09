// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

class Solution {
public:

#define ll long long

ll MOD = 1000000007L;

    ll fun(int n, vector<ll>& dp) {
        if (n == 0) return 1;
        if (n == 1) return 2;

        if (dp[n] != -1) {
            return dp[n];
        }

        ll ans = 1;

        if (n%2 == 1) {
            ans = fun(n/2, dp);
            ans = ans*fun(n/2, dp);
            ans = ans%MOD;
            ans = ans*2;
            ans = ans%MOD;
            dp[n] = ans;
            return dp[n];
        } else {
            ans = fun(n/2, dp);
            ans = ans*fun(n/2, dp);
            ans = ans%MOD;
            dp[n] = ans;
            return dp[n];
        }
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int res = 0;

        int n = nums.size();
        
        int l = 0;
        int h = n-1;

        ll ans = 0;

        vector<ll> dp(n, -1);

        while (l  < n) {

            if (2*nums[l] > target) break;

            if (l > h) {
                h = l;
            }
            
            while (l <= h && nums[l] + nums[h] > target) {
                h--;
            }

            ans += fun(h-l, dp);

            ans = ans % MOD;

            l++;
        }

        return (int)(ans);

    }   
};