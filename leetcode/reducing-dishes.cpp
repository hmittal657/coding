// https://leetcode.com/problems/reducing-dishes/

class Solution {
public:

    int dp[501][501];
    int n;

    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        
        sort(satisfaction.begin(), satisfaction.end());

        int ans = 0;

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (i == j) {
                    dp[i][j] = dp[i-1][j-1] + j * satisfaction[i-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] + j*satisfaction[i-1];
                    if (i-1 >= j) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    }
                }

                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};