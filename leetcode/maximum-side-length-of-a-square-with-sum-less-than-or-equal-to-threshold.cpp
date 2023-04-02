// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

class Solution {
public:

    int sums[305][305];

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        for (int i = 0; i <= m+1; i++) {
            for (int j = 0; j <= n+1; j++) {
                sums[i][j] = 0;
            }
        }

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (mat[i][j] <= threshold) {
                    ans = 1;
                }
                if (i == m-1 && j == n-1) {
                    sums[i][j] = mat[i][j];
                } else if (i == m-1) {
                    sums[i][j] = mat[i][j];
                    sums[i][j] += sums[i][j+1];
                } else if (j == n-1) {
                    sums[i][j] = mat[i][j];
                    sums[i][j] += sums[i+1][j];
                } else {
                    sums[i][j] = mat[i][j];
                    sums[i][j] += sums[i+1][j];
                    sums[i][j] += sums[i][j+1];
                    sums[i][j] -= sums[i+1][j+1];
                }
            }
        }

        // debug print
        // for (int i =0; i  < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << sums[i][j] << "\t";
        //     }
        //     cout << endl;
        // }


        if (ans == 0) return 0;

        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int l = 1;
                int h = min(m-i, n-j);
                int res = -1;
                while (l <= h) {
                    int mid = (l + h)/2;

                    int sum = sums[i][j];

                    sum -= sums[i+mid][j];
                    
                    sum -= sums[i][j+mid];

                    sum += sums[i+mid][j+mid];
                    
                    if (sum <= threshold) {
                        res = max(res, mid);
                        l = mid + 1;
                    } else {
                        h = mid - 1;
                    }

                }

                ans = max(ans, res);

            }
        }

        return ans;

    }
};