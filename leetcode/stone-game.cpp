// https://leetcode.com/problems/stone-game

class Solution {
public:

    int fun(int i, int j, vector<vector<int>>& dp, vector<int>& piles) {
        if (i == j) {
            return piles[i];
        }
        if (i+1 == j) {
            dp[i][j] = max(piles[i]-piles[j], piles[j]-piles[i]);
            return dp[i][j];
        }

        if (dp[i][j] != -3800) return dp[i][j];

        int len = j-i+1;
        
        dp[i][j] = max(piles[i] + fun(i+1, j, dp, piles), piles[j] + fun(i, j-1, dp, piles));

        return dp[i][j];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -3800));

        return (fun(0, n-1, dp, piles) > 0);
    }
};