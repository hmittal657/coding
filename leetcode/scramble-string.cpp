// https://leetcode.com/problems/scramble-string/

class Solution {
public:
    unordered_map<string, bool> memo;

    bool isanagram(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for (int i =0; i < s1.size(); i++) {
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }

        for (int i =0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }

        return true;
    }

    bool isScramble(string s1, string s2) {
        int n= s1.size();

        if (s2.size() != n) return false;
        
        if (n == 0 || s1 == s2) return true;

        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        if (!isanagram(s1, s2)) return false;

        for (int i = 1; i < n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
                && isScramble(s1.substr(i), s2.substr(i))) {
                memo[key] = true;
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n - i))
                && isScramble(s1.substr(i), s2.substr(0, n - i))) {
                memo[key] = true;
                return true;
            }
        }

        memo[key] = false;
        return false;
    }
};
w