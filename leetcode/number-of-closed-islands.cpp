// https://leetcode.com/problems/number-of-closed-islands

class Solution {
public:

    
    int m, n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void fun(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        grid[i][j] = 1;

        q.push({i, j});

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = cur.first + dx[k];
                int y = cur.second + dy[k];
                if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 1) {
                    continue;
                }
                grid[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();

        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                fun(i, 0, grid);
            }
            if (grid[i][n-1] == 0) {
                fun(i, n-1, grid);
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) {
                fun(0, j, grid);
            }
            if (grid[m-1][j] == 0) {
                fun(m-1, j, grid);
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    fun(i, j, grid);
                }
            }
        }

        return ans;

    }
};