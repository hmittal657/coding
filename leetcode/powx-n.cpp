// https://leetcode.com/problems/powx-n

class Solution {
public:

    double fun(double x, long n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        double ans = 1;
        double half = fun(x, n/2);
        if (n%2 == 1) {
            ans = x * half * half;
        } else {
            ans = half * half;
        }
        return ans;
    }

    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        if (x == 1) {
            return 1;
        } else if (x == -1) {
            if (n%2 == 0) {
                return 1;
            } else {
                return -1;
            }
        }

        long bn = (long)(n);
        bn = abs(bn);

        double ans = fun(x, bn);

        
        if (n < 0) {
            ans = 1.000/ans;
        }

        return ans;
    }
};