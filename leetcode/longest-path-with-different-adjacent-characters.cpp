// https://leetcode.com/problems/longest-path-with-different-adjacent-characters

class Solution {
public:

    int dfs2(int i, vector<int>& dp2, vector<int>& dp1, vector<int>& parent,
        vector<vector<int>>& adj, string& s) {
        if (dp2[i] != -1) return dp2[i];
        int a = 0;
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == parent[i]) continue;
            if (s[i] == s[adj[i][j]]) continue;
            a = max(a, dfs2(adj[i][j], dp2, dp1, parent, adj, s));
        }
        dp2[i] = 1 + a;
        return dp2[i];
    }

    int dfs1(int i, vector<int>& dp2, vector<int>& dp1, vector<int>& parent,
        vector<vector<int>>& adj, string& s) {
        if (dp1[i] != -1) return dp1[i];
        int a = -1;
        int b = -1;
        for (int j =0; j < adj[i].size(); j++) {
            if (adj[i][j] == parent[i]) continue;
            if (s[i] == s[adj[i][j]]) continue;
            if (a == -1) {
                a = dfs2(adj[i][j], dp2, dp1, parent, adj, s);
            } else if (b == -1) {
                b = dfs2(adj[i][j], dp2, dp1, parent, adj, s);
                int tempa = a;
                int tempb = b;
                a = max(tempa, tempb);
                b = min(tempa, tempb);
            } else {
                int t = dfs2(adj[i][j], dp2, dp1, parent, adj, s);
                if (b >= t) continue;
                if (a >= t && b <= t) {
                    b = t;
                } else if (t >= a) {
                    b = a;
                    a = t;
                }
            }
        }
        if (a == -1 && b == -1) {
            dp1[i] = 1;
            return dp1[i];
        }
        if (b == -1) {
            dp1[i] = 1 + a;
            return dp1[i];
        }
        dp1[i] = 1 + a + b;
        return dp1[i];
    }

    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        vector<vector<int>> adj(n, vector<int>(0));

        for (int i=0; i < parent.size(); i++) {
            if (parent[i] == -1) continue;
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        int ans = 1;

        for (int i =0; i < n; i++) {
            ans = max(ans, dfs1(i, dp2, dp1, parent, adj, s));
            ans = max(ans, dfs2(i, dp2, dp1, parent, adj, s));
        }

        return ans;
    }
};