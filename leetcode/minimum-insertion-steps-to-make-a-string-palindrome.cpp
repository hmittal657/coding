// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

class Solution {
public:

    int dp[505][505];

    bool ispal(string& s) {
        int l = 0;
        int h = s.size()-1;

        while (l <= h) {
            if (s[l] != s[h]) return false;
            l++;
            h--;
        }

        return true;
    }

    int fun(int i, int j, string& s) {
        
        if (i > j) return 100000;

        if (i == j) return 0;
        if (i + 1 == j) {
            if (s[i] == s[j]) {
                return 0;
            } else {
                return 1;
            }
        }

        if (dp[i][j] != -1) return dp[i][j];

        int ans = j - i + 1;

        if (s[i] == s[j]) {
            ans = min(ans, fun(i+1, j-1, s));
        }
        ans = min(ans, 2 + fun(i+1, j-1, s));

        ans = min(ans, 1 + fun(i+1, j, s));
        ans = min(ans, 1 + fun(i, j-1, s));

        dp[i][j] = ans;

        return ans;
    }
 
    int minInsertions(string s) {
        if (ispal(s)) return 0;

        int n = s.size();

        int ans = s.size();

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                dp[i][j] = -1;
            }
        }

        return fun(0, n-1, s);

    }
};