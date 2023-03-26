// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:

    int parent[100005];

    int find(int x) {
        if (x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    int merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) return 1;
        if (a < b) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
        return 0;
    }

    int makeConnected(int n, vector<vector<int>>& c) {
        for (int i =0; i < n; i++) {
            parent[i] = i;
        }

        int cylpoints = 0;

        for (int i = 0; i < c.size(); i++) {
            cylpoints += merge(c[i][0], c[i][1]);
        }

        unordered_set<int> comp;

        for (int i =0; i < n; i++) {
            comp.insert(find(i));
        }

        if (comp.size() - 1 <= cylpoints) {
            return (comp.size()-1);
        } else {
            return -1;
        }

    }
};