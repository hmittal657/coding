// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:

    int MAX = 10000007;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, MAX);
        prices[src] = 0; 
        for (int i =0; i < k+1; i++) {
            vector<int> temp = prices;

            for (int j = 0; j < flights.size(); j++) {
                int s = flights[j][0];
                int d = flights[j][1];
                int p = flights[j][2];

                if (prices[s] >= MAX) continue;
                if (p + prices[s] < temp[d]) {
                    temp[d] = p + prices[s];
                }
            }
            prices = temp;
        }

        if (prices[dst] >= MAX) return -1;
        return prices[dst];

    }
};