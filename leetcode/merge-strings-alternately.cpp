// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int i = 0;
        int j = 0;

        int dir = 0;

        while (i < word1.size() && j < word2.size()) {
            if (dir) {
                ans.push_back(word2[j]);
                j++;
                dir = 1-dir;
            } else {
                ans.push_back(word1[i]);
                i++;
                dir = 1-dir;
            }
        }

        while (i < word1.size()) {
            ans.push_back(word1[i]);
            i++;
        }

        while (j  < word2.size()) {
            ans.push_back(word2[j]);
            j++;
        }

        return ans;

    }
};