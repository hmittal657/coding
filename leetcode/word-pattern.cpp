// https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> m;
        unordered_map<char, string> m2;

        string cur = "";
        int ind = 0;
        for (int i =0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (m.find(cur) != m.end()) {
                    if (m[cur] != pattern[ind]) {
                        return false;
                    }
                }
                if (m2.find(pattern[ind]) != m2.end()) {
                    if ( m2[pattern[ind]] != cur) {
                        return false;
                    }
                }

                m[cur] = pattern[ind];
                m2[pattern[ind]] = cur;

                ind++;
                cur = "";
            } else {
                cur.push_back(s[i]);
            }
        }

        if (m.find(cur) != m.end()) {
            if (m[cur] != pattern[ind]) {
                return false;
            }
            
        }
        if (m2.find(pattern[ind]) != m2.end()) {
            if ( m2[pattern[ind]] != cur) {
                return false;
            }
        }
        ind++;

        if (ind != pattern.size()) {
            return false;
        }

        return true;
    }
};