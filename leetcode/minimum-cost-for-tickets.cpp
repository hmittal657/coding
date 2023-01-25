// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:

    int dp[366];

    int cost(int i, set<int>& days, vector<int>& costs) {
        if (i > 365) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        if (days.find(i) == days.end()) {
            int t = cost(i+1, days, costs);
            dp[i] = t;
        } else {
            int t = costs[0] + cost(i+1, days, costs);
            t = min(t, costs[1] + cost(i+7, days, costs));
            t = min(t, costs[2] + cost(i+30, days, costs));
            dp[i] = t;
        }

        return dp[i];
        
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        for (int j = 0; j < 366; j++) {
            dp[j] = -1;
        }
        set<int> st;
        for (int i =0; i < days.size(); i++) {
            st.insert(days[i]);
        }

        return cost(0, st, costs);

    }
};