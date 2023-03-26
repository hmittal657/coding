// https://leetcode.com/problems/longest-cycle-in-a-graph

class Solution {
public:

    bool visited[100005];
    int n;

    int ans = -1;

    void dfs(int i, vector<int>& edges, unordered_map<int, int>& m,
        int ind) {
        if (m.find(i) != m.end()) {
            ans = max(ans, ind - m[i]);
            return;
        }

        if (visited[i]) return;

        m[i] = ind;
        visited[i] = true;

        if (edges[i] != -1) {
            dfs(edges[i], edges, m, ind+1);
        }
    }

    int longestCycle(vector<int>& edges) {
        ans = -1;
        
        n = edges.size();

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        for (int i = 0 ; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> m;
                dfs(i, edges, m, 0);
            }
        }

        return ans;
    }
};