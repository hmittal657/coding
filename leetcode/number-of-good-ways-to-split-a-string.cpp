// https://leetcode.com/problems/number-of-good-ways-to-split-a-string

class Solution {
public:
    int numSplits(string s) {
        int n = s.size();


        unordered_map<char, int> m;
        
        vector<int> pre(n, 0);

        for (int i =0; i < s.size(); i++) {
            m[s[i]]++;
            if (i-1 >= 0) pre[i] = pre[i-1];
            if (m[s[i]] == 1) {
                pre[i]++;
            }
        }

        vector<int> suf(n, 0);

        m.clear();

        for (int i = n-1; i >= 0; i--) {
            if (i+1 < n) suf[i] = suf[i+1];
            m[s[i]]++;
            if (m[s[i]] == 1) {
                suf[i]++;
            }
        }

        int ans = 0;

        for (int i = 0; i < n-1; i++) {
            if (pre[i] == suf[i+1]) {
                ans++;
            }
        }

        return ans;

    }
};