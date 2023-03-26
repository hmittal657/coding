// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
public:

#define ll long long

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

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        for (int i =0; i  < n; i++) {
            parent[i] = i;
        }

        for (int i =0 ; i < edges.size(); i++) {
            merge(edges[i][0], edges[i][1]);
        }

        unordered_map<int, ll> m;

        for (int i = 0; i < n; i++) {
            m[find(i)]++;
        }

        ll ans = 0;

        for (auto &it : m) {
            ans += ((it.second)*((ll)(n) - it.second));
        }

        ans = ans/2;

        return ans;
    }
};