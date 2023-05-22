// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position

class Solution {
public:

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        vector<int> tails;

        tails.push_back(nums[0]);

        ans[0] = 1;

        for (int i = 1; i < n; i++) {

            if (nums[i] >= tails[tails.size()-1]) {
                tails.push_back(nums[i]);
                ans[i] = tails.size();
                continue;
            }

            if (nums[i] < tails[0]) {
                tails[0] = nums[i];
                ans[i] = 1;
                continue;
            }

            int l = 0;
            int h = tails.size() - 1;


            int res = h;

            while (l <= h) {
                int mid = (l+h)/2;
                if (tails[mid] > nums[i]) {
                    res = min(res, mid);
                    h = mid-1;
                } else {
                    l = mid+1;
                }
            }

            tails[res] = nums[i];
            ans[i] = res+1;
        }

        return ans;
    }
};