// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0;
        int h = n-1;
        if (target < nums[0]) return 0;
        if (target > nums[h]) return n;
        int res = -1;

        while (l <= h) {
            int mid = (l+h)/2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                res = mid;
                l = mid+1;
            } else {
                h = mid-1;
            }
        }

        return (res+1);

    }
};