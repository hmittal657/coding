// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        vector<int> f(n);
        vector<int> s(n);

        f[0] = triangle[0][0];
        s[0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            s[0] = f[0] + triangle[i][0];
            s[i] = f[i-1] + triangle[i][i];
            for (int j = 1; j < i; j++) {
                
                s[j] = f[j] + triangle[i][j];

                if (j-1 >= 0) {
                    s[j] = min(s[j], f[j-1] + triangle[i][j]);
                }
            }

            for (int j = 0; j <= i; j++) {
                f[j] = s[j];
            }

        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            ans = min(ans, s[i]);
        }

        return ans;
    }
};