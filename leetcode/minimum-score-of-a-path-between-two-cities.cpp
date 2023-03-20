// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities

class Solution {
public:

    int parent[100005];

    int find(int x) {

        if (x == parent[x]) return x;

        parent[x] = find(parent[x]);

        return parent[x];

    }

    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) return;
        if (a < b) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < roads.size(); i++) {
            merge(roads[i][0], roads[i][1]);
        }

        int ans = -1;

        for (int i =0 ; i < roads.size(); i++) {
            if (find(roads[i][0]) == 1 && find(roads[i][1]) == 1) {
                if (ans == -1) {
                    ans = roads[i][2];
                } else {
                    ans = min(roads[i][2], ans);
                }
            }
        }

        return ans;

    }
};