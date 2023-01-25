// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = 0;
        int h = 0;

        int n = nums.size();

        int cur_sum = nums[0];

        int mini = 100000007;

        while (l < n) {
            if (cur_sum >= target) {
                mini = min(mini, h-l+1);
                cur_sum -= nums[l];
                l++;
            } else {
                h++;
                if (h  < n)  {
                    cur_sum += nums[h];
                } else {
                    break;
                }
            }
        }

        if (mini == 100000007) return 0;
        return mini;
    }
};