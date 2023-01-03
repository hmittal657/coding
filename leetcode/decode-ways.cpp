// https://leetcode.com/problems/decode-ways

class Solution {
public:

    int getNum(string& s, int i, int j) {
        int ans = 0;
        ans += (s[i] - '0');
        if (j > i ) {
            ans = ans*10 + (int)(s[j] - '0');
        }
        return ans;
    }

    int numDecodings(string s) {

        int n = s.size();
        if (s[0] == '0') {
            return 0;
        }
        vector<int> dp(n, 0);

        dp[0] = 1;
        int ans = 0;

        for (int i = 1; i < n ; i++) {
           
           if (i-1 >= 0) {
                ans = getNum(s, i-1, i);
                if (ans >= 10 && ans <= 26) {
                    if (i-1 == 0) {
                        dp[i] += 1;
                    } else {
                        dp[i] += dp[i-2];
                    }
                }
           }

            ans = getNum(s, i, i);
            if (ans >= 1 && ans <= 9) {
                dp[i] += dp[i-1];
            }
        }

        return dp[n-1];

    }
};