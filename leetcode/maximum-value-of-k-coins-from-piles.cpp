// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles

class Solution {
public:


    int fun(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if (k == 0) {
            return 0;
        }
        if (i >= piles.size()) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int sz = piles[i].size();

        int x = 0;

        int cursum = 0;
        int n = piles.size();
        for (int j = 0; j <= min(sz, k); j++) {
            
            if (j > 0) {
                cursum += piles[i][j-1];
            }
            if (i != n-1) {
                x =  max(x, cursum + fun(i+1, k - j, piles, dp));
            } else {
                x = max(x, cursum);
            }
        }

        dp[i][k] = x;
        return dp[i][k];
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();

        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

        return fun(0, k, piles, dp);
    }
};