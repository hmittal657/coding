// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:

#define ll long long

    bool isPerfectSquare(int num) {
        
        ll temp = (ll)num;

        ll l = 1;
        ll h = num;

        ll res = 1;

        while(l <= h) {
            ll mid = (l+h)/2;
            if (mid*mid == temp) return true;
            if (mid*mid > temp) {
                h = mid-1;
            } else {
                res = mid;
                l = mid+1;
            }
        }

        return (res*res == temp);

    }
};