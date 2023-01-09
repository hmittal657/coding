// https://leetcode.com/problems/delete-and-earn

class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> arr(10001, 0);

        for (int i =0; i < n; i++) {
            arr[nums[i]]++;
        }

        int dp1 = 0;
        int dp2 = 0;

        int ans = 0;

        for (int i = 1; i <= 10000; i++) {
            int prevdp1 = dp1;
            int prevdp2 = dp2;
            dp1 = i*arr[i] + prevdp2;
            dp2 = max(prevdp1, prevdp2);
            
            ans = max(dp1, ans);
            ans = max(dp2, ans);
        }

        return ans;
    }
};