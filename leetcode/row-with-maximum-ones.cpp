// https://leetcode.com/problems/row-with-maximum-ones/

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        int maxi = -1;
        int maxc = -1;
        
        for (int i =0; i < m; i++) {
            int ones = 0;
            for (int j = 0; j < n; j++) {
                ones += mat[i][j];
            }
            if (ones > maxc) {
                maxc = ones;
                maxi = i;
            }
        }
        
        vector<int> v;
        v.push_back(maxi);
        v.push_back(maxc);
        
        return v;
        
    }
};