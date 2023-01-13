// https://leetcode.com/problems/jump-game-vii/

class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n-1] == '1') return false;

        vector<bool> dp(n, false);
        dp[0] = true;
        int count = 0;

        for (int i = 1; i < n; i++) {
            if (i - minJump >= 0 && dp[i-minJump]) {
                count++;
            }
            if (i - maxJump-1 >= 0 && dp[i-maxJump-1]) {
                count--;
            }
            if (s[i] == '0' && count > 0) {
                dp[i] = true;
            }
        }

        return dp[n-1];

    }
};