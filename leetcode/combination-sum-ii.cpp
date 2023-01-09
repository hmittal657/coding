// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:

    int n;

    void dfs(int i, vector<int>& c, vector<int>& cur,
        int curSum, int target, vector<vector<int>>& ans) {
        if (curSum == target) {
            ans.push_back(cur);
            return;
        }
        if (i == n) return;
        if (curSum > target) return;

        for (int j = i; j < n; j++) {
            if (j > i && c[j] == c[j-1]) continue;
            cur.push_back(c[j]);
            dfs(j+1, c, cur, curSum + c[j], target, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> ans;
        sort(c.begin(), c.end());
        n = c.size();
        vector<int> cur;
        dfs(0, c, cur, 0, target, ans);

        return ans;
    }
};