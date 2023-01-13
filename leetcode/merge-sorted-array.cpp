// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;

        int ind = m+n-1;

        while (i >= 0 && j >= 0) {
            if (nums2[j] >= nums1[i]) {
                nums1[ind] = nums2[j];
                ind--;
                j--;
            } else {
                nums1[ind] = nums1[i];
                i--;
                ind--;
            }
        }

        while (i >= 0) {
            nums1[ind] = nums1[i];
            i--;
            ind--;
        }

        while (j >= 0) {
            nums1[ind] = nums2[j];
            j--;
            ind--;
        }

    }
};