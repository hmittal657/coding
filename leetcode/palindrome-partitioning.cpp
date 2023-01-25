// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:

    void dfs(vector<vector<string>>& ans, string& s, int i, vector<vector<bool>>& dp,
        vector<string>& cur) {

        if (i == s.size()) {
            ans.push_back(cur);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (dp[i][j]) {
                cur.push_back(s.substr(i, j-i+1));
                dfs(ans, s, j+1, dp, cur);
                cur.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i=0; i < n; i++) {
            int l = i;
            int h = i;

            while (l >= 0 && h < n) {
                if (s[l] == s[h]) {
                    dp[l][h] = true;
                    l--;
                    h++;
                } else {
                    break;
                }
            }

            l = i;
            h = i+1;

            while (l >= 0 && h < n) {
                if (s[l] == s[h]) {
                    dp[l][h] = true;
                    l--;
                    h++;
                } else {
                    break;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> cur;

        dfs(ans, s, 0, dp, cur);

        return ans;
    }
};