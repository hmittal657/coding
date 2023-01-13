// https://leetcode.com/problems/swim-in-rising-water

class Solution {
public:

    struct P {
        int val;
        int i;
        int j;
    };

    class Comp {
        public:
        bool operator()(P a, P b) {
            return a.val > b.val;
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<P, vector<P>, Comp> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        P a;
        a.i  =0;
        a.j = 0;
        a.val = grid[0][0];

        pq.push(a);

        vector<vector<int>> dirs = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};

        while (!pq.empty()) {
            P a = pq.top();
            pq.pop();
            if (a.i == n-1 && a.j == n-1) {
                return a.val;
            }
            int cur = a.val;

            for (int k = 0; k < 4; k++) {
                int x = a.i + dirs[k][0];
                int y = a.j + dirs[k][1];
                if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
                    P temp;
                    temp.i = x;
                    temp.j = y;
                    temp.val = max(grid[x][y], cur);
                    visited[x][y] = true;
                    pq.push(temp);
                }
            }
        }

        return -1;
        

    }
};