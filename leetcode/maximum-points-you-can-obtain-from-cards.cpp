// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();
        int sz = n-k;

        int cur = 0;
        int sum = 0;
        for (int i =0; i < sz; i++) {
            cur += c[i];
        }

        int mini = cur;
        sum = cur;

        for (int i = sz; i < n; i++) {
            cur += c[i];
            sum += c[i];
            cur -= c[i-sz];
            mini = min(cur, mini);
        }

        return (sum-mini);

    }
};