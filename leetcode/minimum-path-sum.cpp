// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> f(n, 0);
        vector<int> s(n, 0);

        f[0] = grid[0][0];
        for (int i =1; i < n; i++) {
            f[i] = grid[0][i] + f[i-1];
        }

        if (m == 1) {
            return f[n-1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s[j] = grid[i][j];
                if (j-1 >= 0 && i-1 >= 0) {
                    s[j] = min(s[j] + f[j], s[j] + s[j-1]);
                } else if (i - 1 >= 0) {
                    s[j] = s[j] + f[j];
                } else if (j-1 >= 0) {
                    s[j] = s[j] + s[j-1];
                }
            }
            for (int j = 0; j < n ; j++) {
                f[j] = s[j];
            }
        }

        return s[n-1];

    }
};