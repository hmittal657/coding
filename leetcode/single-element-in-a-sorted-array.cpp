// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        int l = 0;
        int h = n-1;

        while (l <= h) {
            if (h == l) return (nums[l]);

            int m = (l+h)/2;

            if (m+1 < n && m-1 >= 0 && nums[m] != nums[m-1] && nums[m] != nums[m+1]) {
                return nums[m];
            }

            int a = m-l+1;
            int b = n -  m - 2;

            if (m-1 >= 0 && nums[m-1] == nums[m]) {
                if (a % 2 == 1) {
                    h = m;
                } else {
                    l = m+1;
                }
            } else if (m+1 < n && nums[m] == nums[m+1]) {
                if (b%2 == 1) {
                    l = m;
                } else {
                    h = m-1;
                }
            }
        }

        return -1;

    }
};