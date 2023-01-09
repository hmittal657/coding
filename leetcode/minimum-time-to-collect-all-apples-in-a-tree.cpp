// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree

class Solution {
public:

    int travel(int i, int p, vector<vector<int>>& adj, vector<bool>& hasApple,
        vector<int>& dp) {
        int t = 0;

        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == p) continue;
            t += travel(adj[i][j], i, adj, hasApple, dp);
        }

        if (hasApple[i]) {
            t++;
        }

        dp[i] = t;
        
        return dp[i];
    }

    int dfs(int i, int p, vector<vector<int>>& adj,
        vector<int> &dp) {
        int t = 0;

        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == p) continue;
            if (dp[adj[i][j]] > 0) {
                t += dfs(adj[i][j], i, adj, dp);
                t+=2;
            }
        }

        return t;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n, vector<int>(0));

        vector<int> dp(n);

        for (int i=0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        travel(0, -1, adj, hasApple, dp);

        return dfs(0, -1, adj, dp);

    }
};