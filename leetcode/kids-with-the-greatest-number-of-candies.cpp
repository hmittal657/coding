// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int curMax = candies[0];

        for (int i = 0; i < candies.size(); i++) {
            curMax = max(curMax, candies[i]);
        }

        int n = candies.size();

        vector<bool> ans(n);

        for (int i =0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= curMax) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }

        return ans;

    }
};