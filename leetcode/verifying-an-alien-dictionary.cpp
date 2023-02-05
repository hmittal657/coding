// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:

    bool fun(string& a, string& b, vector<int>& dict) {
        for (int i =0; i < min(a.size(), b.size()); i++) {
            if (dict[a[i]-'a'] < dict[b[i]-'a']) return true;
            if (dict[a[i]-'a'] > dict[b[i]-'a']) return false;
        }

        return (a.size() <= b.size()); 
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(26, 0);

        for (int i =0; i < order.size(); i++) {
            dict[order[i]-'a'] = i;
        }

        for (int i =0; i < words.size()-1; i++) {
            if (!fun(words[i], words[i+1], dict)) return false;
        }
        return true;
    }
};