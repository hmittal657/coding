// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:

    bool possible(vector<int>& weights, int days, int capacity) {
        int cnt = 0;
        int cur = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > capacity) return false;
            cur += weights[i];
            if (cur > capacity) {
                cur = weights[i];
                cnt++;
                if (cnt > days) return false;
            }
        }
        if (cur > 0) {
            cnt++;
        }

        return (cnt <= days);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 500000000;
        int h = 0;

        for (int i =0 ; i < weights.size(); i++) {
            l = min(l, weights[i]);
            h += weights[i];
        }

        int res = h;

        while (l <= h) {
            int m = (l+h)/2;
            if (possible(weights, days, m)) {
                res = m;
                h = m-1;
            } else {
                l = m+1;
            }
        }

        return res;

    }
};