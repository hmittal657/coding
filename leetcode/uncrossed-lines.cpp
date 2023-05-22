// https://leetcode.com/problems/uncrossed-lines/

class Solution {
public:

    int dp[501][501];

    int fun(int i, int j, vector<int>& nums1, vector<int>& nums2, unordered_map<int, vector<int>>& m1,
        unordered_map<int, vector<int>>& m2) {
        if (i >= nums1.size() || j >= nums2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int z = 0;

        int a = nums1[i];
        int b = nums2[j];

        if (m2.find(a) != m2.end()) {
            for (int k = 0; k < m2[a].size(); k++) {
                if (m2[a][k] >= j) {
                    z = max(z, 1 + fun(i+1, m2[a][k] + 1, nums1, nums2, m1, m2));
                }
            }
        }


        if (m1.find(b) != m1.end()) {
            for (int k = 0; k < m1[b].size(); k++) {
                if (m1[b][k] >= i) {
                    z = max(z, 1 + fun(m1[b][k] + 1, j+1, nums1, nums2, m1, m2));
                }
            }
        }

        z = max(z, fun(i, j+1, nums1, nums2, m1, m2));
        z = max(z, fun(i+1, j, nums1, nums2, m1, m2));

        dp[i][j] = z;

        return z;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        unordered_map<int, vector<int>> m1,m2;

        for (int i =0; i < m; i++) {
            m1[nums1[i]].push_back(i);
        }

        for (int j =0; j < n; j++) {
            m2[nums2[j]].push_back(j);
        }

        return fun(0, 0, nums1, nums2, m1, m2);
    }
};