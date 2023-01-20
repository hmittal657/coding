// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";

        int ind = 0;
        while (true) {
            if (ind >= strs[0].size()) break;
            char common = strs[0][ind];
            bool append = true;
            for (int i =1; i < strs.size(); i++) {
                if (ind >= strs[i].size()) {
                    append = false;
                    break;
                }
                if (common != strs[i][ind]) {
                    append = false;
                    break;
                }
            }

            if (append) {
                ans.push_back(common);
                ind++;
            } else {
                break;
            }

        }
        
        return ans;

    }
};