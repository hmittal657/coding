// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:

    int dp[201][201];
    int m, n;

    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int fun(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) return dp[i][j];
        int t = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + delta[k][0];
            int y = j + delta[k][1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (matrix[x][y] < matrix[i][j]) {
                    t = max(t, 1 + fun(x, y, matrix));
                    
                }
            }
        }
        dp[i][j] = t;
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        int ans = 1;
        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                ans = max(ans, fun(i, j, matrix));
                cout << ans << endl;
            }
        }
        return ans;
    }
};