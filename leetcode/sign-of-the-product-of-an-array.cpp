// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int i =0; i < nums.size(); i++) {
            if (nums[i] == 0) return 0;
            if (nums[i] < 0) {
                sign = -1 * sign;
            }
        }

        return sign;
    }
};