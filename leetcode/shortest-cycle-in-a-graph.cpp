// https://leetcode.com/problems/shortest-cycle-in-a-graph

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 10001;

        for (int i = 0; i < n; i++) {
            vector<int> dist(n, 10001);
            vector<int> parent(n, -1);

            queue<int> q;

            q.push(i);
            dist[i] = 0;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int k = 0; k < adj[cur].size(); k++) {
                    int v = adj[cur][k];
                    if (dist[v] == 10001) {
                        dist[v] = dist[cur] + 1;
                        parent[v] = cur;
                        q.push(v);
                    } else if (parent[v] != cur && parent[cur] != v) {
                        ans = min(ans, dist[v] + dist[cur] + 1);
                    }
                }
            }

        }

        if (ans == 10001) return -1;

        return ans;

    }
};