// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int miscount = 0;

        int cur = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > cur) {
                miscount += arr[i]-cur;
                if (miscount >= k) {
                    miscount -= (arr[i] - cur);
                    return cur - 1 + (k-miscount);
                }
            }
            cur = arr[i]+1;
        }

        return cur - 1 + (k-miscount);
    }
};