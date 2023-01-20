// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();

        int carry = 0;

        int t = digits[n-1] + 1;
        if (t >= 10) {
            carry = 1;
            t = t%10;
        }

        digits[n-1] = t;

        for (int i = n-2; i >= 0; i--) {
            int temp = digits[i] + carry;
            if (temp >= 10) {
                carry = 1;
                temp = temp%10;
            } else {
                carry = 0;
            }
            digits[i] = temp;
            if (carry == 0) return digits;
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;

    }
};