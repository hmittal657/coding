// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown


class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int ans = 0;
        int s0p, s1p, s2p, s0c, s1c, s2c;
        s0p = 0;
        s1p = -1 * p[0];
        s2p = 0;

        for (int i = 1; i < n; i++) {
            s0c = max(s0p, s2p);
            ans = max(ans, s0c);
            s1c = max(s1p, s0p - p[i]);
            ans = max(ans, s1c);
            s2c = s1p + p[i];
            ans = max(ans, s2c);
            s0p = s0c;
            s1p = s1c;
            s2p = s2c;
        }

        return ans;

    }
};