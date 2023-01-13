// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int i = 0;

        int last = -10000;
        int n = nums.size();
        while (i < n) {
            if (nums[i] != last) {
                nums[l] = nums[i];
                last = nums[i];
                l++;
                i++;
            } else {
                i++;
            }
        }

        return l;

    }
};