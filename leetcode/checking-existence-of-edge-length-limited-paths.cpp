// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths

class Solution {
public:

    struct Q {
        int ind;
        int p;
        int q;
        int limit;
    };

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

    static bool comp(Q& a, Q& b) {
        return (a.limit < b.limit);
    }

    static bool comp2(vector<int>& a, vector<int>& b) {
        return (a[2] < b[2]);
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e,
        vector<vector<int>>& queries) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int sz = queries.size();
        vector<bool> ans(sz);
        vector<Q> qr;
        for (int i =0; i < queries.size(); i++) {
            Q z;
            z.p = queries[i][0];
            z.q = queries[i][1];
            z.ind = i;
            z.limit = queries[i][2];
            qr.push_back(z);
        }

        sort(qr.begin(), qr.end(), comp);
        sort(e.begin(), e.end(), comp2);


        int ind = 0;
        
        for (int i =0; i < qr.size(); i++) {
            int curlimit = qr[i].limit;
            while (ind < e.size()) {
                if (e[ind][2] < curlimit) {
                    merge(e[ind][0], e[ind][1]);
                    ind++;
                } else {
                    break;
                }
            }

            int a = find(qr[i].p);
            int b = find(qr[i].q);

            if (a == b) {
                ans[qr[i].ind] = true;
            } else {
                ans[qr[i].ind] = false;
            }
        }


        return ans;
    }
};