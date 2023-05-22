// https://leetcode.com/problems/evaluate-division

class Solution {
public:

    void dfs(string start, string& end, bool& found, double& val, unordered_map<string, vector<string>>& adj, unordered_map<string, double>& m, unordered_set<string>& visited) {
        if (visited.find(start) != visited.end()) return;
        if (found) return;
        visited.insert(start);
        for (int i = 0; i < adj[start].size(); i++) {
            string ch = adj[start][i];
            val *= m[start + "-" + ch];
            if (ch == end) {
                found = true;
                return;
            }
            dfs(ch, end, found, val, adj, m, visited);
            if (found) return;
            val /= m[start + "-" + ch];
        }
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, double> m;

        unordered_map<string, vector<string>> adj;

        for (int i =0; i < eq.size(); i++) {
            m[eq[i][0] + "-" + eq[i][1]] = values[i];
            m[eq[i][1] + "-" + eq[i][0]] = 1.000/values[i];

            adj[eq[i][0]].push_back(eq[i][1]);
            adj[eq[i][1]].push_back(eq[i][0]);
        }

        vector<double> ans;


        for (int i =0; i < queries.size(); i++) {
            string start = queries[i][0];
            string end = queries[i][1];

            if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
                ans.push_back(-1);
                continue;
            }

            bool found = false;
            double val = 1;

            unordered_set<string> visited;

            if (start == end) {
                found = true;
            }

            dfs(start, end, found, val, adj, m, visited);
            if (found) {
                ans.push_back(val);
            } else {
                ans.push_back(-1);
            }

        }

        return ans;

    }
};