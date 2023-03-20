// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3) return 0;

        sort(nums.begin(), nums.end());

        int ans = nums[n-1] - nums[0];

        ans = min(nums[n-4] - nums[0], ans);
        ans = min(nums[n-3] - nums[1], ans);
        ans = min(nums[n-2] - nums[2], ans);
        ans = min(nums[n-1] - nums[3], ans);

        return ans;

    }

    



};