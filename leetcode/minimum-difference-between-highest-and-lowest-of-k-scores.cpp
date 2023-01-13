// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mini = INT_MAX;

        for (int i = k-1; i < n; i++) {
            mini = min(mini, nums[i] - nums[i-k+1]);
        }

        return mini;

    }
};