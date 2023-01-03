// https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();

        int n = strs[0].size();
        int ans = 0;

        for (int j =0; j  < n; j++) {
            int last = 0;
            for (int i =0; i < m; i++) {
                if (strs[i][j] < last) {
                    ans++;
                    break;
                }
                last = strs[i][j];
            }
        }

        return ans;

    }
};