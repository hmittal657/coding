// https://leetcode.com/problems/find-the-substring-with-maximum-cost/

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
     
        unordered_map<char, int> f;
        for (int i =0; i < chars.size(); i++) {
            f[chars[i]] = vals[i];
        }
        
        int n = s.size();
        
        vector<int> nums(n);
        
        for (int i =0; i < n; i++) {
            if (f.find(s[i]) != f.end()) {
                nums[i] = f[s[i]];
            } else {
                nums[i] = s[i] - 'a' + 1;
            }
        }
        
        vector<int> pre(n);
        
        
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (cur < 0) {
                cur = 0;
            }
            ans = max(cur, ans);
        }
        
        return ans;
        
    }
};