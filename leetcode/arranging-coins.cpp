// https://leetcode.com/problems/arranging-coins

class Solution {
public:

    #define ll long long

    int arrangeCoins(int n) {
        
        ll target = (ll)(n);

        ll l = 1;
        ll h = target;

        ll ans = 0;

        while (l <= h) {
            ll mid = (l+h)/2;
            ll temp = (mid) * (mid+1);
            temp = temp/2;

            if (temp <= target) {
                ans = mid;
                l = mid+1;
            } else {
                h = mid-1;
            }
        }

        return ans;
    }
};