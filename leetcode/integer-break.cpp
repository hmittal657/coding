// https://leetcode.com/problems/integer-break

class Solution {
public:

#define ll long long

    ll dfs(ll n, vector<ll>& dp) {
        if (n < 2) return n;
        if (dp[n] != -1) {
            return dp[n];
        }
        
        ll ans = n;

        for (ll k = 1; k < n ; k++) {
            ans = max(ans, k * dfs(n-k, dp));
        }

        dp[n] = ans;
        return dp[n];

    }

    int integerBreak(int a) {
        ll n = (ll)(a);
        vector<ll> dp(n+1, -1);
        ll ans = (n-1);

        for (ll i = 1; i < n; i++) {
            ans = max(ans, i * dfs(n-i, dp));
        }

        return ans;

    }
};