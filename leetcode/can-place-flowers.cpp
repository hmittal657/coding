// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int accones = 0;

        int m = nums.size();

        for (int i =0; i < m; i++) {
            if (nums[i] == 1) continue;
            if (i-1 >= 0 && nums[i-1] == 1) continue;
            if (i+1 < m && nums[i+1] == 1) continue;
            nums[i] = 1;
            accones++;
            if (accones >= n) return true;
        }

        return (accones >= n);

    }
};