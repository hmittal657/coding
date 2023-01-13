// https://leetcode.com/problems/number-of-good-paths

class Solution {
public:

    struct S {
        int count;  
        int highest;
    };

    struct V {
        int ind;
        int val;
    };

    static bool comp(V a, V b) {
        return a.val < b.val;
    }

    set<int> st;

    int parent[30001];

    unordered_map<int, S> arr;

    int find(int u) {
        if (u == parent[u]) return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v, int z) {
        int x = find(u);
        int y = find(v);
        if (x == y) return;
        S a = arr[x];
        S b = arr[y];
        int t = 0;

        if (a.highest == z) {
            t += a.count;
        }
        if (b.highest == z) {
            t += b.count;
        }

        if (x < y) {
            parent[y] = x;
            S temp;
            temp.highest = z;
            temp.count = t;
            arr[x] = temp;
            st.insert(x);
        } else {
            parent[x] = y;
            S temp;
            temp.highest = z;
            temp.count = t;
            arr[y] = temp;
            st.insert(y);
        }
    }

    int ans = 0;

    void valuate(int value) {
        set<int> temp;

        for (int x : st) {
            temp.insert(find(x));
        }

        for (int x : temp) {
            S cur = arr[x];
            if (cur.count == 1) {
                ans++;
            } else {
                int t = cur.count * (cur.count + 1);
                t = t/2;
                ans += t;
            }
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n, vector<int>(0));
        ans = 0;
        for (int i =0; i  < n; i++) {
            parent[i] = i;
            S temp2;
            temp2.highest = vals[i];
            temp2.count = 1;
            arr[i] = temp2;
        }

        for (int i = 0; i < edges.size(); i++) {
            int x = vals[edges[i][0]];
            int y = vals[edges[i][1]];
            
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<V> v1;
        for (int i=0; i < vals.size(); i++) {
            V x;
            x.ind = i;
            x.val = vals[i];
            v1.push_back(x);
        }

        sort(v1.begin(), v1.end(), comp);

        int cur = -1;

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i].val == cur) {
                bool nomerge = true;
                for (int j = 0; j < adj[v1[i].ind].size(); j++) {
                    if (vals[adj[v1[i].ind][j]] < vals[v1[i].ind]) {
                        merge(v1[i].ind, adj[v1[i].ind][j], cur);
                        nomerge = false;
                    } else if (vals[adj[v1[i].ind][j]] == vals[v1[i].ind]) {
                        if (v1[i].ind  < adj[v1[i].ind][j]) {
                            merge(v1[i].ind, adj[v1[i].ind][j], cur);
                        }
                        nomerge = false;
                    }
                }
                if (nomerge) {
                    st.insert(v1[i].ind);
                }
            } else {
                valuate(cur);
                st.clear();
                cur = v1[i].val;
                bool nomerge = true;
                for (int j = 0; j < adj[v1[i].ind].size(); j++) {
                    if (vals[adj[v1[i].ind][j]] < vals[v1[i].ind]) {
                        merge(v1[i].ind, adj[v1[i].ind][j], cur);
                        nomerge = false;
                    } else if (vals[adj[v1[i].ind][j]] == vals[v1[i].ind]) {
                        if (v1[i].ind  < adj[v1[i].ind][j]) {
                            merge(v1[i].ind, adj[v1[i].ind][j], cur);
                        }
                        nomerge = false;
                    }
                }
                if (nomerge) {
                    st.insert(v1[i].ind);
                }
            }
        }

        valuate(cur);

        return ans;
    }
};