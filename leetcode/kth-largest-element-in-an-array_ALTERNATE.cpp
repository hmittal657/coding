// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:

    int partition(vector<int>& nums, int i, int j) {
        if (i == j) return i;
        int low = i;
        for (int x = i; x < j; x++) {
            if (nums[x] <= nums[j]) {
                swap(nums[x], nums[low]);
                low++;
            }
        }
        swap(nums[low], nums[j]);
        return low;
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();

        int l = 0;
        int h = n-1;

        while (true) {
            int p = partition(nums, l, h);
            if (p == n-k) return nums[p];
            if (p > n-k) {
                h = p-1;
            } else {
                l = p+1;
            }
        }

        return nums[n-1];
    }

};