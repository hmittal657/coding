// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:

    struct S {
        int len;
        int arr[26];
    };

    int maxlen = 0;

    void dfs(int i, vector<S>& v, S cur) {
        if (i == v.size()) {
            int t = cur.len;
            maxlen = max(t, maxlen);
            return;
        }

        dfs(i+1, v, cur);

        if (cur.len == 0) {
            S tem = v[i];
            dfs(i+1, v, tem);
        } else {
            S tem = v[i];
            for (int j = 0; j < 26; j++) {
                if (tem.arr[j] >  0 && cur.arr[j] > 0) {
                    return;
                }
                tem.arr[j] = tem.arr[j] + cur.arr[j];
            }
            tem.len += cur.len;
            dfs(i+1, v, tem);
        }
    }

    int maxLength(vector<string>& a) {
        vector<S> v;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].size() > 26) continue;
            int temp[26];
            for (int j =0; j < 26; j++) {
                temp[j] = 0;
            }
            bool valid = true;
            for (int j = 0; j < a[i].size(); j++) {
                temp[a[i][j]- 'a']++;
                if (temp[a[i][j]- 'a'] > 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                S t;
                t.len = a[i].size(); 
                for (int j =0; j < 26; j++) {
                    t.arr[j] = temp[j];
                }
                v.push_back(t);
            }
        }
        maxlen = 0;
        S tem;
        tem.len = 0;
        for (int j=0; j < 26; j++) {
            tem.arr[j] = 0;
        }
        dfs(0, v, tem);
        return maxlen;
    }
};