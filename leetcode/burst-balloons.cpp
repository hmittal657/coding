// https://leetcode.com/problems/burst-balloons

class Solution {
public:

    int dp[305][305];
    int n;

    int dfs(int i, int j, vector<int>& nums) {
        if (i > j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        int z = 0;

        for (int k = i; k <= j; k++) {
            z = max(z, dfs(i, k-1, nums) + dfs(k+1, j, nums) + 
                nums[k] * nums[i-1] * nums[j+1]);
        }

        dp[i][j] = z;
        return dp[i][j];
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n+3; i++) {
            for (int j = i; j < n+3; j++) {
                dp[i][j] = -1;
            }
        }
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        n = nums.size();
        return dfs(1, n-2, nums);
    }
};