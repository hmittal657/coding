// https://leetcode.com/problems/count-subarrays-with-fixed-bounds

class Solution {
public:

    #define ll long long

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        ll ans = 0;

        ll leftbound = -1;

        ll maxPosition = -1;
        ll minPosition = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftbound = i;
            }

            if (nums[i] == minK) {
                minPosition = i;
            }

            if (nums[i] == maxK) {
                maxPosition = i;
            }

            ans += max(0LL, min(maxPosition, minPosition) - leftbound);
        }

        return ans;
    }
};