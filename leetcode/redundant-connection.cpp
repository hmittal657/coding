// https://leetcode.com/problems/redundant-connection

class Solution {
public:

    int parent[1001];

    int find(int i) {
        while (i != parent[i]) {
            i = parent[i];
        }
        return i;
    }

    void merge (int i, int j) {
        parent[j] = i;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i =0; i  < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int x = find(u);
            int y = find(v);
            if (x == y) {
                return edges[i];
            }
            merge(min(x, y), max(x, y));
        }

        return vector<int>(0);

    }
};