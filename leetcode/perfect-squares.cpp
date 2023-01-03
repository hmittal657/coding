// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int ind = 1;
            dp[i] = i;
            while ((i - (ind * ind)) >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - (ind * ind)]);
                ind++;
            }
        }

        return dp[n];

    }
};