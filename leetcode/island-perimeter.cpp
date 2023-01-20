// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i-1 >= 0) {
                        if (grid[i-1][j] == 1) {
                            ans--;
                        }
                    }
                    if (i+1 < m) {
                        if (grid[i+1][j] == 1) {
                            ans--;
                        }
                    }
                    if (j-1 >= 0) {
                        if (grid[i][j-1] == 1) {
                            if (grid[i][j-1] == 1) {
                                ans--;
                            }
                        }
                    }
                    if (j+1 < n) {
                        if (grid[i][j+1] == 1) {
                            ans--;
                        }
                    }
                }
            }
        }

        return ans;

    }
};