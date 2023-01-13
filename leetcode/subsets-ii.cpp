// https://leetcode.com/problems/subsets-ii/

class Solution {
public:

    void dfs(int i, vector<int>& cur, vector<vector<int>>& ans, vector<int>& m) {
        if (i == m.size()) {
            ans.push_back(cur);
            return;
        }

        dfs(i+1, cur, ans, m);
        if (m[i] > 0) {
            m[i]--;
            cur.push_back(i-10);
            dfs(i, cur, ans, m);
            m[i]++;
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> cur;

        vector<int> m(21, 0);
        int n = nums.size();

        for (int i=0; i  < nums.size(); i++) {
            m[nums[i]+10]++;
        }

        dfs(0, cur, ans, m);

        return ans;

    }
};