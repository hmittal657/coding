// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:


    int dfs(int st, int i, string& s, vector<vector<int>>& dp) {
        if (i == s.size() && st == 0) {
           return 1;
        }
        if (i == s.size()) {
            return 0;
        }

        if (dp[st][i] != -1) return dp[st][i];

        if (s[i] == '(') {
            dp[st][i] = dfs(st + 1, i+1, s, dp);
            return dp[st][i];
        } else if (s[i] == ')') {
            if (st == 0) {
                dp[st][i] = 0;
                return dp[st][i];
            }
            dp[st][i] = dfs(st-1, i+1, s, dp);
            return dp[st][i];
        } else {
            int ret = dfs(st, i+1, s, dp);
            if (ret == 1) {
                dp[st][i] = 1;
                return dp[st][i];
            }
            if (st > 0) {
                int x = dfs(st-1, i+1, s, dp);
                if (x == 1) {
                    dp[st][i] = 1;
                    return dp[st][i];
                }
            }
            int y = dfs(st+1, i+1, s, dp);
            dp[st][i] = y;
            return dp[st][i];
        }
    }

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return (dfs(0, 0, s, dp) == 1);

    }
};