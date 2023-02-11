// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:

    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();

        queue<pair<pair<int, int>, int>> q;

        unordered_set<int> visited;

        int ans = -1;

        for (int i =0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    visited.insert(101* i + j);
                }
            }
        }

        while (!q.empty()) {
            pair<pair<int, int>, int> cur = q.front();
            int a = cur.first.first;
            int b = cur.first.second;
            if (grid[a][b] == 0) {
                ans = max(ans, cur.second);
            }
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = a + delta[i][0];
                int y = b + delta[i][1];

                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (visited.find(101*x + y) == visited.end()) {
                        visited.insert(101*x + y);
                        q.push({{x, y}, cur.second + 1});
                    }
                }
            }
        }

        return ans;

    }
};