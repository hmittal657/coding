// https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        
        if (coins < costs[0]) return 0;

        for (int i =1; i < n; i++) {
            costs[i] += costs[i-1];
            if (costs[i] > coins) {
                return i;
            }
        }

        return n;

    }
};