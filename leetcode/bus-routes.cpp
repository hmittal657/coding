// https://leetcode.com/problems/bus-routes/

class Solution {
public:

    int travel(vector<bool>& visited, 
        int s, unordered_map<int, vector<int>>& m, int target, 
        vector<vector<int>>& routes) {
        
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, 0});

        vector<bool> routevisited(routes.size(), false);

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == target) return cur.second;
            for (int i = 0; i < m[cur.first].size(); i++) {
                if (routevisited[m[cur.first][i]]) continue;
                for (int j = 0; j < routes[m[cur.first][i]].size();j++) {
                    int x = routes[m[cur.first][i]][j];
                    if (visited[x]) continue;
                    visited[x] = true;
                    q.push({x, cur.second+1});
                }
                routevisited[m[cur.first][i]] = true;
            }
        }

        return -1;

    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        unordered_map<int, vector<int>> m;
        int maxi = 0;
        for (int i = 0 ; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                maxi = max(routes[i][j], maxi);
                m[routes[i][j]].push_back(i);
            }
        }

        vector<bool> visited(maxi + 1, false);

        return travel(visited, source, m, target, routes);

    }
};