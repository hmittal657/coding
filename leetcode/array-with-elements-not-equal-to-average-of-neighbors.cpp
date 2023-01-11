// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int n = nums.size();
        int l = 0;
        int h = n-1;

        while (l <= h) {
            if (ans.size() == 0) {
                ans.push_back(nums[l]);
                l++;
            } else {
                if (nums[l] < ans[ans.size()-1]) {
                    ans.push_back(nums[l]);
                    l++;
                } else {
                    ans.push_back(nums[h]);
                    h--;
                }
            }
        }

        return ans;

    }
};