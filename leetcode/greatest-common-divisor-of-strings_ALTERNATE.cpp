// https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:

    int gcd(int a, int b) {
        if (b == 0) return a;
        if (a == 0) return b;

        if (a == b) return a;

        return gcd(b, a%b);
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int m = str1.size();
        int n = str2.size();

        return str1.substr(0, gcd(m, n));
    }
};