// https://leetcode.com/problems/removing-stars-from-a-string

class Solution {
public:
    string removeStars(string s) {
        
        vector<char> st;

        for (int i =0; i < s.size(); i++) {
            if (s[i] == '*') {
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }

        string ans = "";

        for (int i = 0; i < st.size(); i++) {
            ans.push_back(st[i]);
        }

        return ans;

    }
};