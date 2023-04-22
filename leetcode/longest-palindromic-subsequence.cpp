// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:

    int pre[1005][26];
    int suf[1005][26];

    int dp[1005][1005];
    int n;

    const int NOPOS = -2;

    int fun(int i, int j, string& s) {
        if (dp[i][j] != NOPOS) return dp[i][j];
        if (i == 0) {
            if (i != j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2;
                    return 2;
                } else {
                    dp[i][j] = 0;
                    return 0;
                }
            } else {
                dp[i][j] = 1;
                return 1;
            }
        }
        if (j == n-1) {
            if (j != i) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2;
                    return 2;
                } else {
                    dp[i][j] = 0;
                    return 0;
                }
            } else {
                dp[i][j] = 1;
                return 1;
            }
        }

        int x;

        if (i == j) {
            x = 1;
        } else {
            if (s[i] != s[j]) {
                dp[i][j] = 0;
                return 0;
            }
            x = 2;
        }

        int maxt = 0;

        for (int k = 0; k < 26; k++) {
            if (i-1 >= 0 && j + 1 < n && pre[i-1][k] != NOPOS && suf[j+1][k] != NOPOS) {
                maxt = max(maxt, fun(pre[i-1][k], suf[j+1][k], s));
            }
        }

        dp[i][j]  = x + maxt;

        return dp[i][j];

    }

    int longestPalindromeSubseq(string s) {
        
        n = s.size();

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                for (int j = 0; j < 26; j++) {
                    pre[i][j] = NOPOS;
                }
            } else {
                for (int j = 0; j < 26; j++) {
                    pre[i][j] = pre[i-1][j];
                }
            }
            pre[i][s[i]-'a'] = i;
        }

        for (int i = n-1; i>= 0; i--) {
            if (i == n-1) {
                for (int j = 0; j < 26; j++) {
                    suf[i][j] = NOPOS;
                }
            } else {
                for (int j = 0; j < 26; j++) {
                    suf[i][j] = suf[i+1][j];
                }
            }
            suf[i][s[i]-'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dp[i][j] = NOPOS;
            }
        }

        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    ans = max(ans, fun(i, j, s));
                }
            }
        }

        return ans;
    }
};