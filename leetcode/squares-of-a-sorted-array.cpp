// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;

        int l = 0;
        int h = nums.size()-1;

        while (l <= h) {
            int a = nums[l]*nums[l];
            int b = nums[h]*nums[h];
            if (a > b) {
                ans.push_back(a);
                l++;
            } else {
                ans.push_back(b);
                h--;
            }
        }

        l = 0;
        h = ans.size()-1;


        while (l <= h) {
            swap(ans[l], ans[h]);
            l++;
            h--;
        }

        return ans;

    }
};