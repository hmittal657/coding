// https://leetcode.com/problems/stickers-to-spell-word

class Solution {
public:

    struct S {
        int arr[26];
    };

    int minans = 1000701;

    void dfs(int i, vector<S>& v, S rem, int cur) {
        if (cur >= minans) return;
        bool solved = true;
        for (int j =0; j < 26; j++) {
            if (rem.arr[j] > 0) {
                solved = false;
                break;
            }
        }

        if (solved) {
            minans = min(minans, cur);
            return;
        }
        if (i >= v.size()) return;

        int reduced;
        int cnt = 0;
        while ((cur + cnt) < minans) {
            dfs(i+1, v, rem, cur+cnt);
            reduced = 0;
            cnt++;
            for (int j = 0; j < 26; j++) {
                if (rem.arr[j] > 0 && v[i].arr[j] > 0) {
                    int t = rem.arr[j];
                    rem.arr[j] = max(0, rem.arr[j]-v[i].arr[j]);
                    reduced += (t - rem.arr[j]);
                }
            }
            if (reduced == 0) break;
        }
    }

    int minStickers(vector<string>& stickers, string t) {
        minans = 1000701;
        S target;

        for (int i=0; i  < 26; i++) {
            target.arr[i] = 0;
        }

        for (int i=0; i < t.size(); i++) {
            target.arr[t[i]-'a']++;
        }

        vector<S> v;

        for (int i =0; i < stickers.size(); i++) {
            bool valid = false;
            S temp;
            for (int j =0; j < 26; j++) {
                temp.arr[j] = 0;
            }
            for (int j = 0; j < stickers[i].size(); j++) {
                if (target.arr[stickers[i][j]-'a'] > 0) {
                    temp.arr[stickers[i][j]-'a']++;
                    valid = true;
                }
            }
            if (valid) {
                v.push_back(temp);
            }
        }

        if (v.size() == 0) return -1;

        vector<bool> eliminate(v.size(), false);

        for (int i=0; i < v.size(); i++) {
            for (int j = i+1; j < v.size(); j++) {
                S a = v[i];
                S b = v[j];
                bool el = true;
                for (int k =0; k < 26; k++) {
                    if (a.arr[k] > b.arr[k]) {
                        el = false;
                        break;
                    }
                }
                if (el) {
                    eliminate[i] = true;
                    break;
                }
            }
        }

        vector<S> v2;

        for (int i=0; i < v.size(); i++) {
            if (!eliminate[i]) {
                v2.push_back(v[i]);
            }
        }

        dfs(0, v2, target, 0);

        if (minans == 1000701) return -1;

        return minans;

    }
};