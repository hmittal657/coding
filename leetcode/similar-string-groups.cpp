// https://leetcode.com/problems/similar-string-groups

class Solution {
public:

    int parent[301];

    bool similar(string& a, string& b) {
        if (a.size() != b.size()) return false;
        if (a == b) return true;
        vector<int> difs;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                difs.push_back(i);
                if (difs.size() > 2) return false;
            }
        }

        if (a[difs[0]] == b[difs[1]]
            && a[difs[1]] == b[difs[0]]) {
            return true;
        }

        return false;
    }

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

    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();

        for (int i =0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (find(i) == find(j)) {
                    continue;
                }
                if (similar(strs[i], strs[j])) {
                    merge(i, j);
                }
            }
        }

        unordered_set<int> s;

        for (int i = 0 ; i < n; i++) {
            int a = find(i);
            s.insert(a);
        }

        return s.size();

    }
};