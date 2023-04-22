// https://leetcode.com/problems/word-break-ii/

class Solution {
public:

    void updateans(vector<string>& brk, vector<string>& ans) {
        string t = "";

        for (int i = 0; i < brk.size(); i++) {
            if (i == 0) {

            } else {
                t.push_back(' ');
            }

            for (int j =0; j < brk[i].size(); j++) {
                t.push_back(brk[i][j]);
            }

        }
        ans.push_back(t);
    }

    void fun(int i, string cur, vector<string>& brk, string& s, unordered_set<string>& d, vector<string>& ans) {

        if (i == s.size()) {
            if (cur == "") {
                updateans(brk, ans);
            }
            return;
        }

        cur.push_back(s[i]);
        if (d.find(cur) != d.end()) {
            brk.push_back(cur);
            fun(i+1, "", brk, s, d, ans);
            brk.pop_back();
        }

        fun(i+1, cur, brk, s, d, ans);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> d;
        
        for (int i =0; i < wordDict.size(); i++) {
            d.insert(wordDict[i]);
        }

        vector<string> ans;

        vector<string> brk;
        string cur = "";
        fun(0, cur, brk, s, d, ans);

        return ans;

    }
};