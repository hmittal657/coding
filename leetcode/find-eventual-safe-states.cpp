// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> outdegrees(n);

        int zeros = 0;

        for (int i =0; i < graph.size(); i++) {
            outdegrees[i] = graph[i].size();
            zeros++;
        }

        if (zeros == 0) {
            return vector<int>(0);
        }

        int temp = 0;

        while (temp != zeros) {
            zeros = temp;
            temp = 0;
            for (int i=0; i < graph.size(); i++) {
                if (outdegrees[i] == 0) {
                    temp++;
                    continue;
                }
                for (int j = 0; j < graph[i].size(); j++) {
                    if (graph[i][j] != -37 && outdegrees[graph[i][j]] == 0) {
                        graph[i][j] = -37;
                        outdegrees[i]--;
                        if (outdegrees[i] == 0) {
                            temp++;
                            break;
                        }
                    }
                }
            }
        }

        vector<int> ans;
        for (int i =0; i < n; i++) {
            if (outdegrees[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;

    }
};