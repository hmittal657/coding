// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:

    int dp[1005][1005] = {0};
    int n;

    int longestPalindromeSubseq(string s) {
        
        n = s.size();

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i+l-1;
                if (i == j) {
                    dp[i][j] = 1;
                } else if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};