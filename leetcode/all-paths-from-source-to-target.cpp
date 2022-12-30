// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:

    void dfs(int i, int n, vector<int>& cur, vector<vector<int>>& ans,
        vector<vector<int>>& g) {
        if (i == n-1) {
            cur.push_back(n-1);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }

        cur.push_back(i);
        for (int j = 0; j < g[i].size(); j++) {
            dfs(g[i][j], n, cur, ans, g);
        }
        cur.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> cur;
        vector<vector<int>> ans;

        dfs(0, n, cur, ans, g);

        return ans;

    }
};