// https://leetcode.com/problems/surrounded-regions

class Solution {
public:

    int m, n;

    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(vector<vector<char>>& board) {
        
        m = board.size();
        n = board[0].size();

        queue<pair<int, int>> q;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                if (!visited[0][j]) {
                    q.push({0, j});
                    visited[0][j] = true;
                }
            }
            if (board[m-1][j] == 'O') {
                if (!visited[m-1][j]) {
                    q.push({m-1, j});
                    visited[m-1][j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                if (!visited[i][0]) {
                    q.push({i, 0});
                    visited[i][0] = true;
                }
            }

            if (board[i][n-1] == 'O') {
                if (!visited[i][n-1]) {
                    q.push({i, n-1});
                    visited[i][n-1] = true;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            board[i][j] = '7';

            for (int k  = 0; k < 4; k++) {
                int x = i + d[k][0];
                int y = j + d[k][1];
                if (x >= 0 && y >= 0 && x < m && y < n && !visited[x][y] && board[x][y] == 'O') {
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }
        }

        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (board[i][j] == '7') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

    }
};