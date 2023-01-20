// https://leetcode.com/problems/non-decreasing-subsequences

class Solution {
public:

    void dfs(int i, vector<int>& cur, set<vector<int>>& ans,
        vector<int>& nums) {
        if (i == nums.size()) {
            if (cur.size() >= 2) {
                ans.insert(cur);
            }
            return;
        }

        dfs(i+1, cur, ans, nums);

        if (cur.size() > 0 && nums[i] < cur[cur.size()-1]) {
            return;
        }

        cur.push_back(nums[i]);
        dfs(i+1, cur, ans, nums);
        cur.pop_back();
            
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;

        vector<int> cur;

        dfs(0, cur, ans, nums);

        vector<vector<int>> f;
        for (vector<int> v1 : ans) {
            f.push_back(v1);
        }

        return f;

    }
};