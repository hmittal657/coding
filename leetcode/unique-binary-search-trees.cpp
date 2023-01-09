// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:

    int dfs(int i, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        int t = 0;

        for (int k = 1; k <= i; k++) {
            t += dfs(i-k, dp) * dfs(k-1, dp);
        }

        dp[i] = t;

        return dp[i];

    }

    int numTrees(int n) {
        vector<int> dp(n+1, -1);      
        dp[0] = 1;
        dp[1] = 1;

        return dfs(n, dp);
    }
};