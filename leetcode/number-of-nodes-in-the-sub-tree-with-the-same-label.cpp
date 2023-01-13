// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Solution {
public:

    void dfs(int i, int p, vector<vector<int>>& adj, vector<vector<int>>& v, string &label, vector<int>& ans) {

        v[i][label[i] - 'a']++;

        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == p) continue;
            dfs(adj[i][j], i, adj, v, label, ans);
            for (int k = 0; k < 26; k++) {
                v[i][k] += v[adj[i][j]][k];
            }
        }

        ans[i] = v[i][label[i]-'a'];

    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n, vector<int>(0));
        for (int i =0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n, 0);
        vector<vector<int>> v(n, vector<int>(26, 0));

        dfs(0, -1, adj, v, labels, ans);

        return ans;
    }
};