// https://leetcode.com/problems/largest-color-value-in-a-directed-graph

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
      int n = colors.size();
      
      vector<vector<int>> adj(n);

      vector<int> indeg(n, 0);

      for (int i=0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        indeg[edges[i][1]]++;
      }

      vector<vector<int>> v(n, vector<int>(26, 0));

      queue<int> q;

      for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
          q.push(i);
          v[i][colors[i]-'a']++;
        }
      }

      int seen = 0;
      int ans = 1;

      while (!q.empty()) {

        int u = q.front();
        q.pop();
        seen++;
        int maxi = 1;
        for (int i = 0; i < 26; i++) {
          maxi = max(maxi, v[u][i]);
        }

        ans = max(ans, maxi);

        for (int i = 0; i < adj[u].size(); i++) {
          int s = adj[u][i];
          for (int j = 0; j < 26 ;j++) {
            int ad = 0;
            if ((colors[s] - 'a') == j) {
              ad=1;
            }
            v[s][j] = max(v[u][j] + ad, v[s][j]);
          }
          indeg[s]--;
          if (indeg[s] == 0) {
            q.push(s);
          }
        }

      }

      if (seen < n) return -1;

      return ans;
 
    }
};