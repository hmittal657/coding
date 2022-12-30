// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:

    void dfs (int i, int j, int& unvisited, int targetx, int targety, 
        vector<vector<int>>& grid, int m, int n, int& ans) {
        if (i == targetx && j == targety) {
            unvisited--;
            if (unvisited == 0) {
                ans++;
            }
            unvisited++;
            return;
        }

        int temp = grid[i][j];
        unvisited--;

        grid[i][j] = 7;

        if (i + 1 < m) {
            if (grid[i+1][j] != 7 && grid[i+1][j] != -1) {
                dfs(i+1, j, unvisited, targetx, targety, grid,m,n,ans);
            }
        }
        if (i-1 >= 0) {
            if (grid[i-1][j] != 7 && grid[i-1][j] != -1) {
                dfs(i-1, j, unvisited, targetx, targety, grid,m,n,ans);
            }
        }
        if (j+1 < n) {
            if (grid[i][j+1] != 7 && grid[i][j+1] != -1) {
                dfs(i, j+1, unvisited, targetx, targety, grid,m,n,ans);
            }
        }
        if (j-1 >= 0) {
            if (grid[i][j-1] != 7 && grid[i][j-1] != -1) {
                dfs(i, j-1, unvisited, targetx, targety, grid,m,n,ans);
            }
        }

        unvisited++;
        grid[i][j] = temp;

    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int unvisited = 0;

        int startx, starty, targetx, targety;

        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    startx = i; 
                    starty = j;
                    unvisited++;
                } else if (grid[i][j] == 2) {
                    targetx = i;
                    targety = j;
                    unvisited++;
                } else if (grid[i][j] == 0) {
                    unvisited++;
                }
            }
        }

        int ans = 0;

        dfs(startx, starty, unvisited, targetx, targety, grid, m, n, ans);

        return ans;
    }
};