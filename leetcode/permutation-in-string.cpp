// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:

    bool iseq(vector<int> a, vector<int> b) {
        for (int i=0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        
        if (s1.size() > s2.size()) return false;
        if (s1 == s2) return true;

        vector<int> v1(26, 0);

        for (int i =0; i < s1.size(); i++) {
            v1[s1[i]-'a']++;
        }

        vector<int> cur(26, 0);
        
        for (int i =0; i < s1.size(); i++) {
            cur[s2[i]-'a']++;
        }
        if (iseq(cur, v1)) return true;

        for (int i = s1.size(); i< s2.size(); i++) {
            cur[s2[i]-'a']++;
            cur[s2[i-s1.size()] - 'a']--;
            if (iseq(cur, v1)) return true;
        }

        return false;
    }
};