// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:

#define ll long long

    long long maxAlternatingSum(vector<int>& nums) {
        
        ll oddSum = (ll)(nums)[0];
        ll evenSum = 0;
        ll ans = oddSum;
        for (int i = 1; i < nums.size(); i++) {
            ll prevOddSum = oddSum;

            oddSum = max(oddSum, (ll)(nums[i]) + evenSum);
            evenSum = max(evenSum, prevOddSum - (ll)(nums[i]));

            ans = max(ans, oddSum);
            ans = max(ans, evenSum);
        }

        return ans;

    }
};