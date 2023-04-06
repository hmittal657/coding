// https://leetcode.com/problems/trapping-rain-water-ii

class Solution {
public:

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};

    struct H {
        int i;
        int j;
        int h;
    };

    class Comp {

        public:

        bool operator()(H& a, H& b) {
            return a.h > b.h;
        }

    };

    int m, n;

    int trapRainWater(vector<vector<int>>& height) {
        
        m = height.size();
        n = height[0].size();

        if (m < 3 || n < 3) return 0;

        vector<vector<bool>> v(m, vector<bool>(n, false));

        priority_queue<H, vector<H>, Comp> pq;

        for (int i =0; i < m; i++) {
            if (!v[i][0]) {
                pq.push({i, 0, height[i][0]});
                v[i][0] = true;
            }
            if (!v[i][n-1]) {
                pq.push({i, n-1, height[i][n-1]});
                v[i][n-1] = true;
            }            
        }

        for (int j = 0; j < n; j++) {
            if (!v[0][j]) {
                pq.push({0, j, height[0][j]});
                v[0][j] = true;
            }

            if (!v[m-1][j]) {
                pq.push({m-1, j, height[m-1][j]});
                v[m-1][j] = true;
            }
        }

        int ans = 0;

        while (!pq.empty()) {
            H cur = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int x = cur.i + dx[k];
                int y = cur.j + dy[k];
                if (x < 0 || y < 0 || x  >= m || y >= n || v[x][y]) {
                    continue;
                }
                v[x][y] = true;
                ans += max(0, cur.h - height[x][y]);
                pq.push({x, y, max(cur.h, height[x][y])});
            }
        }

        return ans;

    }
};