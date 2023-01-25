// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();


/*        
            0 -> {2, 1}                         // candidate - 2
            1 -> {1, 2}                         // candidate - 2
            2 -> {1, 3}, {5, 1}              // candidate - 3, 5
            3 -> {1, 4}, {5, 2}, {6, 1}      // candidate - 4, 10, 6
            4 -> {1, 5}, {2, 3}             // candidate - 5, 6
            5 -> {1, 6}, {2, 4}, {3, 1}     // candidate - 6, 8, 3
  

    /*
    [2,2,5,6,2,3,2]

        {2, 1}
        {2, 2}
        {2, 3}, {5, 1}
        {2, 4}, {5, 2}, {6, 1}
        {2, 5}
        {2, 6}, {3, 1}
        {2, 7}



    // [[2,2,5,6,3,4,2]]

    // {2, 1}
    // {2, 2}
    // {2, 3}, {5, 1}
    // {2, 4}, {5, 2}, {6, 1}
    // {2, 5}, {3, 3}
    // {2, 6}, {3, 4}, {4, 1}
    // {2, 7}
*/

        vector<int> lefty(n, -1);

        for (int i = 1; i < n; i++) {
            int x = i-1;
            while (x != -1 && nums[x] >= nums[i]) {
                x = lefty[x];
            }
            lefty[i] = x;
        }

        vector<int> righty(n, -1);

        for (int i = n-2; i >= 0; i--) {
            int x = i+1;
            while (x != -1 && nums[x] >= nums[i]){
                x = righty[x];
            }
            righty[i] = x;
        }

        for (int i =0; i < n; i++) {
            int l = lefty[i];
            int h = righty[i];
            if (l == -1 && h == -1) {
                ans = max(ans, n*nums[i]);
            } else if (l == -1) {
                ans = max(ans, (h)* nums[i]);
            } else if (h == -1) {
                ans = max(ans, (n-1 - (l + 1) + 1)*nums[i]);
            } else {
                ans = max(ans, (h-l-1)*nums[i]);
            }

        }

        return ans;

    }
};