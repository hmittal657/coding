// https://leetcode.com/problems/count-ways-to-build-good-strings

class Solution {
public:

    #define ll long long

    ll mod = 1000000007;

    ll dp[100005];

    int countGoodStrings(int low, int high, int zero, int one) {
        dp[0] = 1;

        for (int i = 1; i <= high; i++) {
            dp[i] = 0;
            if (i - zero >= 0) {
                dp[i] += dp[i-zero];
                dp[i] = dp[i] % mod;
            }
            if (i - one >= 0) {
                dp[i] += dp[i-one];
                dp[i] = dp[i] % mod;
            }
        }

        ll ans = 0;

        for (int i = low; i <= high; i++) {
            ans += dp[i];
            ans = ans % mod;
        }

        return ans;

    }
};