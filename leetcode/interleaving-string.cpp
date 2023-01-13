// https://leetcode.com/problems/interleaving-string

class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int m = s1.size();
        int n = s2.size();

        vector<bool> dp1(n+1, 0);
        vector<bool> dp2(n+1, 0);

        dp1[0] = true;
        dp2[0] = true;

        for (int j = 1; j <= n; j++) {
            dp1[j] = dp1[j-1] && (s2[j-1] == s3[j-1]);
        }

        for (int i = 1; i <= m; i++) {
            dp2[0] = dp1[0] && (s1[i-1] == s3[i-1]);            
            for (int j = 1; j <= n; j++) {
                dp2[j] = (dp1[j] && s1[i-1] == s3[j + i-1])
                        || (dp2[j-1] && s2[j-1] == s3[i+j-1]);
            }
            for (int j = 0 ; j <= n; j++) {
                dp1[j] = dp2[j];
            }
        }

        return dp1[n];

    }
};