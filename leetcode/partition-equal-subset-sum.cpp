// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:

    int dfs(int i, int rem, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            if (rem == 0) return 1;
            return 0;
        }
        if (rem == 0) {
            return 1;
        }
        if (rem < 0) return 0;

        if (dp[i][rem] != -1) return dp[i][rem];

        int ans = 0;

        int a = dfs(i+1, rem, nums, dp);
        if (a == 1) {
            dp[i][rem] = 1;
            return 1;
        }
        int b = dfs(i+1, rem - nums[i], nums, dp);
        if (b == 1) {
            dp[i][rem] = 1;
            return 1;
        }

        dp[i][rem] = 0;
        return 0;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 
        int sum = 0;
        for (int i =0; i < n; i++) {
            sum += nums[i];
        }
        if (sum%2 == 1) return false;

        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        
        return (dfs(0, sum/2, nums, dp) == 1);
    }
};