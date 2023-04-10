// https://leetcode.com/problems/shortest-path-visiting-all-nodes

class Solution {
public:

    int setbit(int x, int i) {
        int z = (x | (1<<i));
        return z;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();

        int dist[(1<<n)][n];

        for (int i = 0; i < (1<<n); i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = -1;
            }
        }

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            dist[setbit(0, i)][i] = 0;
            q.push({setbit(0, i), i});
        }

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == ((1<<n) - 1)) {
                return dist[cur.first][cur.second];
            }
            int r = cur.second;
            for (int i = 0; i < graph[r].size(); i++) {
                int newmask = setbit(cur.first, graph[r][i]);
                if (dist[newmask][graph[r][i]] != -1) {
                    continue;
                }
                dist[newmask][graph[r][i]] = 
                        dist[cur.first][cur.second] + 1;
                q.push({newmask, graph[r][i]});
            }
        }

        return 2200;

    }
};