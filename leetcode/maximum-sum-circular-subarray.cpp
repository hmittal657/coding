// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];

        int curSum = 0;

        int totalsum = 0;

        for (int i=0; i < n; i++) {
            totalsum += nums[i];
            curSum += nums[i];
            if (curSum < 0) {
                maxsum = max(maxsum, curSum);
                curSum = 0;
            } else {
                maxsum = max(curSum, maxsum);
            }
            maxsum = max(maxsum, totalsum);
        }


        curSum = 0;
        int minisum = nums[0];
        for (int i =0; i < n; i++) {
            curSum += nums[i];
            if (curSum > 0) {
                minisum = min(minisum, curSum);
                curSum = 0;
            } else {
                minisum = min(minisum, curSum);
            }
        }

        if (totalsum - minisum != 0) {
            maxsum = max(maxsum, totalsum - minisum);
        }
        return maxsum;
    }
};