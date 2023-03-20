// https://leetcode.com/problems/accounts-merge

class Solution {
public:

    int parent[1001];

    int find(int x) {
        while (x != parent[x]) {
            x = parent[x];
        }

        return x;
    }

    void merge(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return;
        if (x < y) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        
        int n = acc.size();
        for (int i = 0 ; i< n ; i++) {
            parent[i] = i;
        }

        unordered_map<string, int> m;

        for (int i =0 ; i < acc.size(); i++) {
            string name = acc[i][0];
            for (int j = 1; j < acc[i].size(); j++) {
                if (m.find(acc[i][j]) != m.end()) {
                    merge(m[acc[i][j]], i);
                }
                m[acc[i][j]] = find(i);
            }
        }

        unordered_map<int, vector<string>> res;

        for (auto it : m) {
            int y = find(it.second);
            res[y].push_back(it.first);
        }

        vector<vector<string>> ans;

        for (auto it : res) {
            vector<string> x;
            x.push_back(acc[it.first][0]);
            vector<string> temp = it.second;
            sort(temp.begin(), temp.end());
            for (int j = 0; j < temp.size(); j++) {
                x.push_back(temp[j]);
            }
            ans.push_back(x);
        }

        return ans;

    }
};