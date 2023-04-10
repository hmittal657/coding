// https://leetcode.com/problems/super-egg-drop/

class Solution {
public:

    int find(int k, int n, vector<vector<int>>& dp) {
        if (n == 0 || n == 1 || k == 1) return n;

        if (dp[k][n] != -1) return dp[k][n];

        int l = 1;
        int h = n;

        int ans = n;

        while (l <= h) {
            int m = (l+h)/2;
            int left = find(k-1, m-1, dp);
            int right = find(k, n-m, dp);
            ans = min(ans, 1 + max(left, right));
            if (left > right) {
                h = m-1;
            } else {
                l = m+1;
            }
        }

        dp[k][n] = ans;
        return dp[k][n];

    }

    int superEggDrop(int k, int n) {

        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));

        return find(k, n, dp);


    }
};