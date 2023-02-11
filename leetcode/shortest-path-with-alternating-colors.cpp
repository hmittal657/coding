// https://leetcode.com/problems/shortest-path-with-alternating-colors

class Solution {
public:

    struct V {
        int ver;
        int dist;
        int color;
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>> redadj(n, vector<int>(0));
        vector<vector<int>> blueadj(n, vector<int>(0));

        for (int i =0; i < redEdges.size(); i++) {
            int x = redEdges[i][0];
            int y = redEdges[i][1];
            redadj[x].push_back(y);
        }

        for (int i =0; i < blueEdges.size(); i++) {
            int x = blueEdges[i][0];
            int y = blueEdges[i][1];
            blueadj[x].push_back(y);
        }

        vector<int> ans(n, -1);
        ans[0] = 0;



        unordered_set<int> visited;

        visited.insert(101*0 + 0);
        visited.insert(101*0 + 1);

        queue<V> q;

        for (int j = 0; j < redadj[0].size(); j++) {
            V temp;
            temp.ver = redadj[0][j];
            temp.dist = 1;
            temp.color = 0;
            visited.insert(101* redadj[0][j] + 0);
            q.push(temp);
        }

        for (int j = 0; j < blueadj[0].size(); j++) {
            V temp;
            temp.ver = blueadj[0][j];
            temp.dist = 1;
            temp.color = 1;
            visited.insert(101* blueadj[0][j] + 1);
            q.push(temp);
        }

        while (!q.empty()) {
            V cur = q.front();
            int x = cur.ver;
            if (ans[x] == -1) {
                ans[x] = cur.dist;
            } else if (ans[x] > cur.dist){
                ans[x] = cur.dist;
            }
            q.pop();
            if (cur.color == 0) {
                for (int j = 0; j  < blueadj[x].size(); j++) {
                    if (visited.find(101*blueadj[x][j] + 1) != visited.end()) continue;
                    V temp;
                    temp.ver = blueadj[x][j];
                    temp.dist = cur.dist + 1;
                    temp.color = 1;
                    visited.insert(101*blueadj[x][j] + 1);
                    q.push(temp);
                }
            } else {
                for (int j = 0; j  < redadj[x].size(); j++) {
                    if (visited.find(101*redadj[x][j] + 0) != visited.end()) continue;
                    V temp;
                    temp.ver = redadj[x][j];
                    temp.dist = cur.dist + 1;
                    temp.color = 0;
                    visited.insert(101*redadj[x][j] + 0);
                    q.push(temp);
                }
            }
        }

        return ans;

    }
};