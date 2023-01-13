// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& e) {
        vector<vector<int>> adj(n, vector<int>(0));
        vector<vector<int>> revadj(n, vector<int>(0));

        for (int i =0; i < e.size(); i++) {
            int x = e[i][0];
            int y = e[i][1];

            adj[x].push_back(y);
            revadj[y].push_back(x);
        }

        int ans = 0;

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;

        q.push(0);

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (int j =0; j < adj[t].size(); j++) {
                if (!visited[adj[t][j]]) {
                    q.push(adj[t][j]);
                    ans++;
                    visited[adj[t][j]] = true;
                }
            }

            for (int j =0; j < revadj[t].size(); j++) {
                if (!visited[revadj[t][j]]) {
                    q.push(revadj[t][j]);
                    visited[revadj[t][j]] = true;
                }
            }
        }
        return ans;
    }
};