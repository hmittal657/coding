// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> last(26, -1);

        for (int i =0; i < s.size(); i++) {
            last[s[i]-'a'] = max(last[s[i]-'a'], i);
        }

        int cur_start = -1;
        int cur_end = 0;

        vector<int> ans;

        for (int i =0; i < s.size(); i++) {
            if (cur_start == -1) {
                cur_start = i;
                cur_end = last[s[i]-'a'];
            } 

            if (i == cur_end) {
                ans.push_back(cur_end - cur_start + 1);
                cur_start = -1;
            } else {
                cur_end = max(cur_end, last[s[i]-'a']);
            }
        }

        return ans;

    }
};