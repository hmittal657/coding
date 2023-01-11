// https://leetcode.com/problems/permutations/

class Solution {
public:

    void travel(vector<vector<int>>& ans, vector<int>& nums, int i, int n) {
        if (i == n) {
            ans.push_back(nums);
            return;
        }

        travel(ans, nums, i+1, n);

        for (int j = i+1; j < n; j++) {
            int a = nums[i];
            int b = nums[j];
            swap(nums[i], nums[j]);
            travel(ans, nums, i+1, n);
            nums[i] = a;
            nums[j] = b;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        travel(ans, nums, 0, n);

        return ans;
    }
};