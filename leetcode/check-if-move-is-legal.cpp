// https://leetcode.com/problems/check-if-move-is-legal

class Solution {
public:

    void travel(int dx, int dy, int x, int y, char &endColor,
        int &len, vector<vector<char>>& board, int m, int n, char color) {
        
        while (x >= 0 && x < m && y >= 0 && y < n) {
            if (board[x][y] == '.') break;
            len++;
            endColor = board[x][y];
            if (board[x][y] == color) break;
            x += dx;
            y += dy;
        }
    }

    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> dirs = {{1, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, 1}, {0, -1}};
        board[rMove][cMove] = color;
        for (int i =0; i < dirs.size(); i++) {
            int len = 1;
            char endColor = '.';
            travel(dirs[i][0], dirs[i][1], rMove+dirs[i][0], cMove+dirs[i][1], endColor, len, board, m, n, color);
            if (len >= 3 && endColor == color) {
                return true;
            }
        }

        return false;
    }
};