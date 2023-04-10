// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:

    int dfs(vector<vector<int>>& adj, int i, int myrank, vector<int>& rank, vector<vector<int>>& res, int n) {
        if (rank[i] != -2) return rank[i];

        rank[i] = myrank;
        int lowest = myrank;

        for (int k = 0; k < adj[i].size(); k++) {
            int v = adj[i][k];
            if (rank[v] == myrank-1 || rank[v] == n) {
                continue;
            } else {
                int neighborrank = dfs(adj, v, myrank+1, rank, res, n);
                lowest = min(neighborrank, lowest);
                if (neighborrank > myrank) {
                    res.push_back({min(i, v), max(i, v)});
                }
            }
        }

        rank[i] = n;
        return lowest;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        
        vector<vector<int>> adj(n);

        for (int i =0; i < c.size(); i++) {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }

        vector<int> rank(n, -2);

        vector<vector<int>> res;

        dfs(adj, 0, 0, rank, res, n);

        return res;

    }
};