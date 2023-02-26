// https://leetcode.com/problems/minimize-deviation-in-array/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;

        int mini = INT_MAX;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                pq.push(nums[i] * 2);
                mini  = min(nums[i]*2, mini);
                maxi = max(nums[i]*2, maxi);
            } else {
                pq.push(nums[i]);
                mini = min(nums[i], mini);
                maxi = max(nums[i], maxi);
            }
        }

        int ans = maxi - mini;

        while (!pq.empty()) {
            int cur = pq.top();
            ans = min(ans, cur-mini);
            pq.pop();
            if (cur % 2 ==  0) {
                mini = min(cur/2, mini);
                pq.push(cur/2);
            } else {
                break;
            }
        }

        return ans;

    }
};