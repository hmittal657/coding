// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        vector<int> pre(n, 0);
        pre[0] = (nums[0] + 10000*k) % k;

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
            pre[i] = (pre[i] + + 10000*k)%k;
        }

        unordered_map<int, int> m;

        m[0] = 1;

        for (int i =0; i < n; i++) {
            ans += m[pre[i]];
            m[pre[i]]++;
        }
        
        return ans;

    }
};