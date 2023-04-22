// https://leetcode.com/problems/minimize-the-total-price-of-the-trips/

class Solution {
public:
    
    void fun(int i, int j, int n, vector<vector<int>>& adj, vector<int>& path) {
        
        vector<int> parent(n, -2);
        
        parent[i] = -1;
        queue<int> q;
        q.push(i);
        parent[i] = -1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == j) break;
            for (int k = 0; k < adj[cur].size(); k++) {
                int v = adj[cur][k];
                if (v == cur) continue;
                if (parent[v] != -2) continue;
                parent[v] = cur;
                q.push(v);
            }
        }
        
        int x = j;
        
        while (x != -1) {
            path.push_back(x);
            x = parent[x];
        }
    }
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        unordered_map<int, int> m;
        
        for (int i =0; i < trips.size(); i++) {
            vector<int> path;
            fun(trips[i][0], trips[i][1], n, adj, path);
            
            for (int k = 0; k < path.size(); k++) {
                m[path[k]]++;
            }
            
        }
        
        vector<vector<int>> dp(n, vector<int>(2, -2));
        
        int ans = 1000000007;
                        
        return min(dfs(0, 0, dp, -1, adj, price, m), dfs(0, 1, dp, -1, adj, price, m));
        
    }
    
    int dfs(int i, int j, vector<vector<int>>& dp, int p,
        vector<vector<int>>& adj,  vector<int>& price, 
            unordered_map<int, int>& m) {
        if (dp[i][j] != -2) return dp[i][j];
        int cursum = 0;
        if (j == 1) {
            cursum += ((m[i] * price[i])/2);
        } else {
            cursum += ((m[i] * price[i]));
        }
        
        for (int k = 0; k < adj[i].size(); k++) {
            int z = 1000000007;
            int v = adj[i][k];
            if (v == p) continue;
            if (j == 1) {
                z = min(z, dfs(v, 0, dp, i, adj, price, m));
            } else {
                z = min(z, dfs(v, 0, dp, i, adj, price, m));
                z = min(z, dfs(v, 1, dp, i, adj, price, m));
            }
            cursum += z;
        }
        
        dp[i][j] = cursum;
        
        return dp[i][j];
        
    }
    
};