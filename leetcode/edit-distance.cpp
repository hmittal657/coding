// https://leetcode.com/problems/edit-distance


class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();

        vector<int> f(n+1, 0);
        vector<int> s(n+1, 0);

        for (int j = 0; j <= n; j++) {
            f[j] = j;
        }

        for (int i = 1; i <= m; i++) {
            s[0] = i;
            for (int j = 1; j <= n ; j++) {
                s[j] = 1 + f[j-1];
                if (word1[i-1] == word2[j-1]) {
                    s[j] = min(s[j], f[j-1]);
                }
                s[j] = min(s[j], 1 + f[j]);
                s[j] = min(s[j], 1 + s[j-1]);
            }

            for (int j = 0; j <= n; j++) {
                f[j] = s[j];
            }
        }

        return f[n];
    }
};