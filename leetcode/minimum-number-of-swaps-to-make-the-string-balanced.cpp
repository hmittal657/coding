// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution {
public:
    int minSwaps(string a) {
        
        int ssize = 0;

        int ops = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '[') {
                ssize++;
            } else {
                if (ssize == 0) {
                    ssize++;
                    ops++;
                } else {
                    ssize--;
                }
            }
        }

        ops += ssize/2;

        return ops/2;

    }
};