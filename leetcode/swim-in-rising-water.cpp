// https://leetcode.com/problems/swim-in-rising-water

class Solution {
public:

    bool canSwim(vector<vector<int>>& grid, int val, int n) {

        if (val < grid[0][0]) return false;
        if (val < grid[n-1][n-1]) return false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        visited[0][0] = true;
        q.push({0, 0});

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == n-1 && cur.second == n-1) return true;
            int i = cur.first;
            int j = cur.second;
            if (i - 1 >= 0) {
                if (!visited[i-1][j] && grid[i-1][j] <= val) {
                    visited[i-1][j] = true;
                    q.push({i-1, j});
                }
            }
            if (j - 1 >= 0) {
                if (!visited[i][j-1] && grid[i][j-1] <= val) {
                    visited[i][j-1] = true;
                    q.push({i, j-1});
                }
            }
            if (i + 1 < n) {
                if (!visited[i+1][j] && grid[i+1][j] <= val) {
                    visited[i+1][j] = true;
                    q.push({i+1, j});
                }
            }
            if (j + 1 < n) {
                if (!visited[i][j+1] && grid[i][j+1] <= val) {
                    visited[i][j+1] = true;
                    q.push({i, j+1});
                }
            }
        }

        return false;


    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int l = 0;
        int h = n*n - 1;

        int res = h;

        while (l <= h) {
            int mid = (l+h)/2;
            if (canSwim(grid, mid, n)) {
                res = mid;
                h = mid-1;
            } else {
                l = mid+1;
            }
        }

        return res;

    }
};