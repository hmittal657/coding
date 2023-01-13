// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i =0; i < nums.size(); i++) {
            while (nums[i] <= n && nums[i] >= 1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        vector<int> ans;

        for (int i =0; i < n; i++) {
            if (nums[i] != i+1) {
                ans.push_back(i+1);
            }
        }

        return ans;

    }
};