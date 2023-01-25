// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<pair<int, int>> dp(n, {0,0});
        // {len, number of ways}
        int maxlen = 1;
        for (int i =0; i < n; i++) {
            dp[i] = {1,1};
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j].first >= dp[i].first) {
                        dp[i] = make_pair(dp[j].first + 1, dp[j].second);
                        maxlen = max(maxlen, dp[i].first);
                    } else if (dp[j].first + 1 == dp[i].first) {
                        dp[i] = {dp[i].first, dp[i].second + dp[j].second};
                    }
                }
            }
        }

        int ans = 0;

        for (int i =0; i < n; i++) {
            if (dp[i].first == maxlen) {
                ans += dp[i].second;
            }
        }

        return ans;
    }
};
