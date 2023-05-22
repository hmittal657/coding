// https://leetcode.com/problems/maximize-score-after-n-operations

class Solution {
public:

    int fun(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        return fun(b, a % b);
    }

    int ones(int x) {
        int c = 0;
        while (x > 0) {
            if (x%2 == 1) {
                c++;
            }
            x = x/2;
        }

        return c;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> gcd(n, vector<int>(n));

        for (int i =0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int x = fun(nums[i], nums[j]);
                gcd[i][j] = x;
                gcd[j][i] = x;
            }
        }
        
        vector<int> dp((1<<n), 0);

        for (int i = 1; i < (1<<n); i++) {
            int o = ones(i);
            if (o % 2 == 0) {
                for (int y = 0; y < n; y++) {
                    if (((i>>y) & 1) == 0) continue;
                    for (int z = y+1; z < n; z++) {
                        if (((i>>z) & 1) == 0) continue;
                        dp[i] = max(dp[i], (o/2) * gcd[y][z] + dp[i - (1<<y) - (1<<z)]);
                    }
                }
            }
        }

        return dp[dp.size()-1];
    }   
};