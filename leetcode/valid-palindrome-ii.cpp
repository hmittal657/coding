// https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:

    bool isPal(string& s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        if (n <= 2) return true;
        int l = 0;
        int h = n-1;

        while (l <= h) {
            if (s[l] != s[h]) {
                if (isPal(s, l+1, h) || isPal(s, l, h-1)) {
                    return true;
                }
                return false;
            } else {
                l++;
                h--;
            }
        }

        return true;
    }
};