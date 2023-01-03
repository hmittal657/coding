// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        for (int i =0; i < s.size(); i++) {
            int x = s[i];
            int y = t[i];
            
            if (m1.find(x) != m1.end() && m2.find(y) != m2.end()) {
                if (m1[x] != y   ||  m2[y] != x) {
                    return false;
                }
            } else if (m1.find(x) != m1.end()) {
                return false;
            } else if (m2.find(y) != m2.end()) {
                return false;
            } else {
                m1[x] = y;
                m2[y] = x;
            }

        }

        return true;
    }
};