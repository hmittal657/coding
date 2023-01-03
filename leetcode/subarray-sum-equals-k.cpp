// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }

        unordered_map<int, int> m;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cur = pre[i];
            if (cur == k) {
                ans++;
            }
            ans += m[cur-k];
            m[cur]++;
        }

        return ans;

    }
};