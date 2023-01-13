// https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:

    map<pair<int, int>, int> dp; 

    int dfs(int i, int j, string& s, string& t) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;

        if (dp.find({i, j}) != dp.end()) return dp[{i, j}];

        int temp = dfs(i+1, j, s, t);

        if (s[i] == t[j]) {
            temp += dfs(i+1, j+1, s, t);
        }

        dp[{i, j}] = temp;
        return temp;

    }

    int numDistinct(string s, string t) {
        dp.clear();
        return dfs(0, 0, s, t);
    }
};