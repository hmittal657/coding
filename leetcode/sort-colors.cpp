// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int cnt[3] = {0,0,0};

        for (int i =0; i  < nums.size(); i++) {
            cnt[nums[i]]++;
        }

        int l = 0;

        for (int ind = 0; ind < 3; ind++) {
            while (cnt[ind] > 0) {
                nums[l] = ind;
                l++;
                cnt[ind]--;
            }
        }
    }
};