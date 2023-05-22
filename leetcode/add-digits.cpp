// https://leetcode.com/problems/add-digits/

class Solution {
public:

    #define ll long long

    ll fun(ll x) {
        if (x < 10) return x;
        ll sum = 0;
        vector<ll> digits;
        while (x > 0) {
            sum += (x%10);
            x = x/10;
        }

        return fun(sum);
    }

    int addDigits(int num) {
        return fun(num);
    }
};