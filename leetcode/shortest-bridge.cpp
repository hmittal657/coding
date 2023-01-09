// https://leetcode.com/problems/shortest-bridge

class Solution {
public:

    void travel(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& grid1, int n)
    {
        if (grid1[i][j] != 0) return;
        grid1[i][j] = grid[i][j];
        grid[i][j] = 0;
        if (i -1 >= 0 && grid[i-1][j] == 1) {
            travel(grid, i-1, j, grid1, n);
        }
        if (j -1 >= 0 && grid[i][j-1] == 1) {
            travel(grid, i, j-1, grid1, n);
        }

        if (i +1 < n && grid[i+1][j] == 1) {
            travel(grid, i+1, j, grid1, n);
        }

        if (j + 1 < n && grid[i][j+1] == 1) {
            travel(grid, i, j+1, grid1,n);
        }
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& grid1, int n) {
        queue<pair<pair<int, int>, int>> q;

        for (int i =0; i < n; i++) {
            for (int j=0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 7;
                    q.push({{i,j},0});
                }
            }
        }

        while (!q.empty()) {
            pair<pair<int, int>, int> cur = q.front();
            int x = cur.first.first;
            int y = cur.first.second;
            q.pop();
            if (grid1[x][y] == 1) {
                cout << x << " " << y << endl;
                return (cur.second - 1);
            }

            if (x-1 >= 0 && grid[x-1][y] != 7) {
                grid[x-1][y] = 7;
                q.push({{x-1, y},cur.second+1});
            }

            if (y-1 >= 0 && grid[x][y-1] != 7) {
                grid[x][y-1] = 7;
                q.push({{x, y-1},cur.second+1});
            }

            if (x+1 < n && grid[x+1][y] != 7) {
                grid[x+1][y] = 7;
                q.push({{x+1, y},cur.second+1});
            }

            if (y+1 < n && grid[x][y+1] != 7) {
                grid[x][y+1] = 7;
                q.push({{x, y+1},cur.second+1});
            }
            
        }

        return -1;

    }

    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> grid1(n, vector<int>(n, 0));

        bool travelled = false;

        for (int i = 0; i < n; i++) {
            if (travelled) break;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    travel(grid, i, j, grid1, n);
                    travelled = true;
                    break;
                }
            }
        }

        return bfs(grid, grid1, n);

    }
};