// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i =0; i < n; i++) { 
            while (nums[i] > 0 && nums[i] <= n) {
                if (nums[i] == nums[nums[i]-1]) break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) {
                return (i+1);
            }
        }
        return (n+1);

    }
};