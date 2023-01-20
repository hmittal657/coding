// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i =0; i < nums.size(); i++) {
            x = x ^ (nums[i] + 30001);
        }

        return (x-30001);
    }
};