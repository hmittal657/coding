// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:

    int isSafe(int i, vector<int>& safe, vector<vector<int>>& graph) {
        if (safe[i] != -1) return safe[i];

        if (graph[i].size() == 0) {
            safe[i] = 2;
            return safe[i];
        }

        safe[i] = 1;

        int total = 0;
        for (int j = 0; j  < graph[i].size(); j++) {
            total += isSafe(graph[i][j], safe, graph);
        }
        if (total == 2*graph[i].size()) {
            safe[i] = 2;
        }

        return safe[i];

    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> safe(n, -1);
        
        for (int i =0; i < n; i++) {
            isSafe(i, safe, graph);
        }

        vector<int> ans;

        for (int i =0; i  < n; i++) {
            if (safe[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;

    }
};