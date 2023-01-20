// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m == 0 && n == 0) return true;
        if (m == 0) return true;
        if (n == 0) return false;

        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return (i == m);

    }
};