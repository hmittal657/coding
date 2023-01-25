// https://leetcode.com/problems/concatenated-words

class Solution {
public:

    unordered_map<string, int> dp;
    unordered_map<string, int> m;

    int solve(string word, int cnt) {
        if (m.find(word) != m.end() && cnt > 0) {
            return 1;
        }

        if (dp.find(word) != dp.end()) return dp[word];

        for (int i = 1; i < word.size(); i++) {
            if (m.find(word.substr(0, i)) != m.end()) {
                if (solve(word.substr(i, word.size()-i), cnt + 1) == 1) {
                    dp[word] = 1;
                    return dp[word];
                }
            }
        }
        dp[word] = -1;
        return dp[word];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        m.clear();
        dp.clear();
        for (int i =0; i < words.size(); i++) {
            m[words[i]] = 1;
        }

        vector<string> ans;

        for (int i =0; i < words.size(); i++) {
            int temp = solve(words[i], 0);
            if (temp == 1) {
                ans.push_back(words[i]);
            }
        }

        return ans;

    }
};