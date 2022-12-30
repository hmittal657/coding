// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)  return 0;

        int a0 = 0;
        int b0 = -1 * prices[0];
        int ans = a0;


        for (int i = 1; i < n; i++) {
            int a1 = b0 + prices[i];
            a1 = max(a1, a0);
            int b1 = a0 - prices[i];
            b1 = max(b1,b0);

            a0 = a1;
            b0 = b1;

            ans = max(ans, a0);
        }

        return ans;

    }
};