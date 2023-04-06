// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        int start = -1;

        int ans = 0;

        int opens = 0;
        int closes = 0;

        for (int i =0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (start == -1) {
                    start = i;
                    opens = 1;
                    closes = 0;
                } else {
                    opens++;
                }
            } else {
                if (start == -1) {
                    opens = 0;
                    closes = 0;
                } else {
                    closes++;
                    if (closes == opens) {
                        ans = max(ans, 2*closes);
                    } else if (closes > opens) {
                        start = -1;
                        opens = 0;
                        closes = 0;
                    }
                }
            }
        }

        opens = 0;
        closes = 0;

        start = -1;

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ')') {
                if (start == -1) {
                    start = i;
                    opens = 0;
                    closes = 0;
                }
                closes++;
            } else {
                if (start == -1) {
                    opens = 0;
                    closes = 0;
                } else {
                    opens++;
                    if (opens == closes) {
                        ans = max(ans, 2*closes);
                    } else if (opens > closes) {
                        start = -1;
                        opens = 0;
                        closes = 0;
                    }
                }
            }
        }

        return ans;

    }
};