// https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        
        int n = s.size();
        int ans =0;
        
        int zeros = 0;
        int ones = 0;
        
        for (int i =0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (ones > 0) {
                    ans = max(ans, 2 * min(ones, zeros));
                    ones = 0;
                    zeros = 0;
                }
                zeros++;
            } else {
                if (zeros > 0) {
                    ans = max(ans, 2*min(ones, zeros));
                }
                ones++;
            }
        }
        
        
        ans = max(ans, 2*min(zeros, ones));
        
        return ans;
        
    }
};