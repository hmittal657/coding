// https://leetcode.com/problems/shift-2d-grid

class Solution {
public:

    void shift(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] += 1000;
                grid[i][j] = 2001 * grid[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int finali = (i + (j+k)/n) % m;
                int finalj = (j+k)%n;
                grid[finali][finalj] += (grid[i][j]/2001);
            }
        }

        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = grid[i][j] % 2001;
                grid[i][j] -= 1000;
            }
        }

    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        shift(grid, k);
        return grid;
    }
};