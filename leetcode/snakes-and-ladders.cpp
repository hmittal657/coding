// https://leetcode.com/problems/snakes-and-ladders

class Solution {
public:

    int getr(int x, int n) {
        
        x = x-1;

        int q = x/n;

        return n-1-q;

    }

    int geth(int x, int n) {
        int q = n - 1 - getr(x, n);
        int r = (x-1)%n;
        if (q % 2 == 0) {
            return r;
        } else {
            return (n-1-r);
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        vector<bool> visited(401, false);
        visited[1] = true;

        q.push({1, 0});

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if (x == n*n) return y;

            for (int i = 1; i <= 6; i++) {
                if (x + i > n*n) break;

                int t = x+i;

                int r = getr(t, n);
                int c = geth(t, n);

                if (board[r][c] != -1) {
                    t = board[r][c];
                }

                if (!visited[t]) {
                    visited[t] = true;
                    q.push({t, y+1});
                }
            }
        }

        return -1;
    }
};