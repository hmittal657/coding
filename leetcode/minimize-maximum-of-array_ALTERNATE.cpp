// https://leetcode.com/problems/minimize-maximum-of-array

class Solution {
public:

    #define ll long long

    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();

        ll presum = 0LL;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            presum += (ll)(nums[i]);
            ans = max(ans, (int)((presum + (ll)(i))/(ll)(i+1)));
        }

        return ans;

    }
};