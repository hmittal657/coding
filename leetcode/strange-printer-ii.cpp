// https://leetcode.com/problems/strange-printer-ii

class Solution {
public:

    bool erase(vector<vector<int>>& t,
        unordered_map<int, vector<int>>& m, int c) {
        for (int i = m[c][0]; i <= m[c][2]; i++) {
            for (int j = m[c][1]; j <= m[c][3]; j++) {
                if (t[i][j] == c || t[i][j] == 0) {

                } else {
                    return false;
                }
            }
        }

        for (int i = m[c][0]; i <= m[c][2]; i++) {
            for (int j = m[c][1]; j <= m[c][3]; j++) {
                t[i][j] = 0;
            }
        }

        return true;
    }

    bool isPrintable(vector<vector<int>>& t) {

        unordered_map<int, vector<int>> m;

        // color -> {xstart, ystart, xend, yend}

        unordered_set<int> colors;

        for (int i =0; i < t.size(); i++) {
            for (int j = 0; j < t[i].size(); j++) {
                int c = t[i][j];
                if (m.find(c) == m.end()) {
                    colors.insert(c);
                    m[c].push_back(i);
                    m[c].push_back(j);
                    m[c].push_back(i);
                    m[c].push_back(j);
                } else {
                    m[c][0] = min(i, m[c][0]);
                    m[c][1] = min(j, m[c][1]);
                    m[c][2] = max(i, m[c][2]);
                    m[c][3] = max(j, m[c][3]);
                }
            }
        }

        while (colors.size() > 0) {
            unordered_set<int> mm;
            for (int c : colors) {
                if (!erase(t, m, c)) {
                    mm.insert(c);
                }
            }

            if (colors.size() == mm.size()) return false;
            colors = mm;
        }

        return true;

    }
};