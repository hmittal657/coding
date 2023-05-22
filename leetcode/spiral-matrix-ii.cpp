// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:

    void travel(int i, int& num, int n, vector<vector<int>>& ans) {

        if (i >= n || ans[i][i] != -1) return;
        for (int k = i; k <= n-1-i; k++) {
            ans[i][k] = num;
            num++;
        }

        for (int k = i+1; k <= n-1-i; k++) {
            if (ans[k][n-1-i] != -1) return;
            ans[k][n-1-i] = num;
            num++;
        }

        for (int k = n-1-i-1; k >= i; k--) {
            if (ans[n-1-i][k] != -1) return;
            ans[n-1-i][k] = num;
            num++;
        }

        for (int k = n-1-i-1; k >= i+1; k--) {
            if (ans[k][i] != -1) return;
            ans[k][i] = num;
            num++;
        }

        travel(i+1, num, n, ans);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int num = 1;
        travel(0, num, n, ans);
        return ans;
    }
};