// https://leetcode.com/problems/bulb-switcher

class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0) return n;
        if (n == 1) return n;
        if (n == 2)  return 1;
        if (n == 3) return 1;
         
        return sqrt(n);
    }
};