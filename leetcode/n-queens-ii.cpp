// https://leetcode.com/problems/n-queens-ii

class Solution {
public:

    int ans = 0;

    bool isValid(vector<vector<int>>& v, int i, int j, int n) {
        for (int k = 0; k < i;k++) {
            if (v[k][j] == 1) return false;
        }
        int x = i-1;
        int y = j-1;
        while (x >= 0 && y < n && y >= 0 && x < n) {
            if (v[x][y] == 1) return false;
            x--;
            y--;
        }

        x = i-1;
        y = j+1;
        while (x >= 0 && y < n && y >= 0 && x < n) {
            if (v[x][y] == 1) return false;
            x--;
            y++;
        }

        return true;
    }

    void dfs(int i, vector<vector<int>>& v, int n) {
        if (i == n) {
            ans++;
            return;
        }

        for (int j = 0; j < n; j++) {
            v[i][j] = 1;
            if (isValid(v,i, j, n)) {
                dfs(i+1, v, n);
            }
            v[i][j] = 0;
        }

    }

    int totalNQueens(int n) {
        if (n == 1) return 1;
        if (n == 2 || n == 3) return 0;
        vector<vector<int>> v(n, vector<int>(n, 0));
        ans = 0;
        for (int i = 0; i < n; i++) {
            v[0][i] = 1;
            dfs(1, v, n);
            v[0][i] = 0;
        }

        return ans;

    }
};