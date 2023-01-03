// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();

        int dp2 = 0;
        int dp1 = 0;
        int dp = min(dp1, dp2);

        for (int i = 2; i <= n; i++) {
            dp = cost[i-1] + dp1;
            dp = min(dp, cost[i-2] + dp2);
            
            dp2 = dp1;
            dp1 = dp;

        }

        return dp;

    }
};