// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

#define ll long long

    int guessNumber(int n) {
        ll l = 1;
        ll h = (ll)n;

        int res = -1;

        while (l <= h) {
            ll mid = (l+h)/2;
            if (guess((int)mid) == 0) return mid;
            if (guess((int)mid) == 1) {
                l = mid+1;
            } else {
                h = mid-1;
            }
        }

        return -1;

    }
};