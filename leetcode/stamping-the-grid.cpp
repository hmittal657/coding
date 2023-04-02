// https://leetcode.com/problems/stamping-the-grid/

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int sh,
        int sw) {
        int m = grid.size();
        int n = grid[0].size();

        int d1[m+1][n+1], d2[m+1][n+1],
        d3[m+1][n+1];

        memset(d1, 0, sizeof(d1));

        memset(d2, 0, sizeof(d2));

        memset(d3, 0, sizeof(d3));

        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                d1[i+1][j+1] = d1[i][j+1] + d1[i+1][j] - d1[i][j] + grid[i][j];
            }
        }

        for (int i =0; i < m; i++) {
            if (i + sh > m) break;
            for (int j = 0; j < n; j++) {
                if (j + sw > n) break;
                int x = d1[i+sh][j+sw] - d1[i+sh][j] - d1[i][j+sw] + d1[i][j];
                if (x == 0) {
                    d2[i][j]++;
                    d2[i+sh][j+sw]++;
                    d2[i+sh][j]--;
                    d2[i][j+sw]--;
                }
            }
        }

        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                d3[i+1][j+1] = d2[i][j] + d3[i][j+1] + d3[i+1][j] - d3[i][j];
            }
        }

        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (grid[i][j] == 0 && d3[i+1][j+1] == 0) return false;
            }
        }

        return true;

    }
};