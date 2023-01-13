// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:

    bool isMatch(string s, string p) {
        
        int m = p.size();
        int n = s.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            dp[0][i] = false;
        }

        for (int i = 1; i <= m; i++) {
            if (p[i-1] == '.') {
                dp[i][0] = false;
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = dp[i-1][j-1];
                }
            } else if (p[i-1] == '*') {
                if (p[i-2] == '.') {
                    for (int j = 0; j <= n; j++) {
                        for (int k = 0; k <= j; k++) {
                            dp[i][j] = (dp[i][j] || dp[i-2][k]);
                            if (dp[i][j]) break;
                        }
                    }
                } else {
                    char t = p[i-2];
                    dp[i][0] = dp[i-2][0];
                    for (int j = 1; j <= n; j++) {
                        for (int k = j; k >= 0; k--) {
                            dp[i][j] = (dp[i][j] || dp[i-2][k]);
                            if (dp[i][j]) break;
                            if (k > 0 && t != s[k-1]) break;
                        }
                    }
                }
            } else {
                dp[i][0] = false;
                for (int j = 1; j <= n; j++) {
                    if (p[i-1] == s[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }

        return dp[m][n];
        

    }
};