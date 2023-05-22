// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                q.push(i);
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    int c = color[cur];
                    for (int j = 0; j < graph[cur].size(); j++) {
                        int k = graph[cur][j];
                        if (color[k] == c) return false;
                        if (color[k] == (1-c)) continue;
                        color[k] = 1-c;
                        q.push(k);
                    }
                }
            }
        }

        return true;

    }
};