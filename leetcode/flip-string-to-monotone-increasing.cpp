// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> dp0(n, 0);
        vector<int> dp1(n, 0);
        if (s[0] == '0') {
            dp0[0] = 0;
            dp1[0] = 1;
        } else {
            dp0[0] = 1;
            dp1[1] = 0;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                dp0[i] = dp0[i-1];
                dp1[i] = min(dp0[i-1] + 1, dp1[i-1] + 1);
            } else {
                dp0[i] = dp0[i-1] + 1;
                dp1[i] = min(dp0[i-1], dp1[i-1]);
            }
        }

        return min(dp0[n-1], dp1[n-1]);
    }
};