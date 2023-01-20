// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur_e = nums[0];
        int curf = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (curf == 0) {
                cur_e = nums[i];
                curf = 1;
                continue;
            }
            if (nums[i] != cur_e) {
                curf--; 
            } else {
                curf++;
            }
        }

        return cur_e;
    }
};