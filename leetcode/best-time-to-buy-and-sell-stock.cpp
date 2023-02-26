// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi = 0;

        int l = prices[0];
        for (int i = 1 ; i < prices.size(); i++) {
            maxi = max(maxi, prices[i] - l);
            l = min(prices[i], l);
        }

        return maxi;

    }
};