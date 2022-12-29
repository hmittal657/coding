// https://leetcode.com/problems/n-queens/

class Solution {
public:

    void dfs(int i, int n, vector<string>& state, vector<vector<string>>& ans) {
        
        if (i == n) {
            ans.push_back(state);
            return;
        }


        for (int j = 0; j < n; j++) {
            bool isValid  = true;
            for (int k = 0; k < i; k++) {
                if (!isValid) {
                    break;
                }
                if (state[k][j] == 'Q') {
                    isValid = false;
                }
            }

            int x = i-1; 
            int y = j-1;

            while (x >= 0 && y >= 0) {
                if (!isValid) break;
                if (state[x][y] == 'Q') {
                    isValid = false;
                }
                x--;
                y--;
            }

            x = i-1;
            y = j+1;

            while (x >= 0 && y < n) {
                if (!isValid) break;
                if (state[x][y] == 'Q') {
                    isValid = false;
                }
                x--;
                y++;
            }

            if (isValid) {
                state[i][j] = 'Q';
                dfs(i+1, n, state, ans);
                state[i][j] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> state(n, "");

        for (int i =0; i < n; i++) {
            for (int j =0; j < n; j++) {
                state[i].push_back('.');
            }
        }

        dfs(0, n, state, ans);

        return ans;

    }
};