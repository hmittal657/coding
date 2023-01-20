// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;

        if (n == 0) {
            return ans;
        }
        vector<int> t(1, 1);

        ans.push_back(t);
        if (n == 1) return ans;

        vector<int> t2(2, 1);
        ans.push_back(t2);
        if (n == 2) return ans;

        for (int i = 2; i < n; i++) {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 0; j < ans[i-1].size()-1; j++) {
                temp.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }

        return ans;
    }
};