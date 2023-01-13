// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i =0;
        int cur = 0;
        int n = s.size();
        int last = 0;

        while (i < n) {
            if (s[i] == ' ') {
                if (cur > 0) {
                    last = cur;
                    cur = 0;
                }
                i++;
            } else {
                cur++;
                i++;
            }
        }

        if (cur > 0) return cur;
        return last;
    }
};