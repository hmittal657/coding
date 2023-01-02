// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<int> left(26, 0);

        vector<int> right(26, 0);

        for (int i =0; i <s.size(); i++) {
            right[s[i]-'a']++;
        }

        unordered_set<int> m;

        for (int i =0; i  < s.size(); i++) {
            right[s[i]-'a']--;

            for (int j = 0; j < 26; j++) {
                if (left[j] > 0 && right[j] > 0) {
                    int hash = 27 * (s[i] - 'a');
                    hash += (27 * 27 * j);
                    hash += j;
                    m.insert(hash);
                }
            }

            left[s[i]-'a']++;
        }

        return m.size();
    }
};