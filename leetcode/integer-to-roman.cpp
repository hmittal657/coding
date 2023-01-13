// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        
        string ans = "";

        int thousands = num/1000;

        for (int i =0; i < thousands; i++) {
            ans.push_back('M');
        }

        num = num%1000;

        int hundreds = num/100;
        num = num%100;
        if (hundreds < 4) {
            for (int k = 0; k < hundreds; k++) {
                ans.push_back('C');
            }
        } else if (hundreds == 4) {
            ans.push_back('C');
            ans.push_back('D');
        } else if (hundreds == 9) {
            ans.push_back('C');
            ans.push_back('M');
        } else {
            ans.push_back('D');
            for (int k = 0; k < hundreds-5; k++) {
                ans.push_back('C');
            }
        }

        int tens = num/10;
        num = num % 10;
        if (tens < 4) {
            for (int k = 0; k < tens; k++) {
                ans.push_back('X');
            }
        } else if (tens == 4) {
            ans.push_back('X');
            ans.push_back('L');
        } else if (tens == 9) {
            ans.push_back('X');
            ans.push_back('C');
        } else {
            ans.push_back('L');
            for (int k = 0; k < tens-5; k++) {
                ans.push_back('X');
            }
        }

        if (num < 4) {
            for (int k = 0; k < num; k++) {
                ans.push_back('I');
            }
        } else if (num == 4) {
            ans.push_back('I');
            ans.push_back('V');
        } else if (num == 9) {
            ans.push_back('I');
            ans.push_back('X');
        } else {
            ans.push_back('V');
            for (int k = 0; k < num-5; k++) {
                ans.push_back('I');
            }
        }

        return ans;
    }
};