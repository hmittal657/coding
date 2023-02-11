// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        for (int i =0; i < nums.size(); i++) {
            nums[i] = 1001 * nums[i];
        }

        int l = 0;

        int i = 0;
        int j = n;

        int dir = 1;

        while (l < nums.size()) {
            if (dir == 1) {
                nums[l] += (nums[i]/1001);
                i++;
                dir = 1-dir;
            } else {
                nums[l] += (nums[j]/1001);
                j++;
                dir = 1-dir;
            }
            l++;
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] % 1001;
        }

        return nums;

    }
};