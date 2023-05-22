// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

class Solution {
public:

    #define ll long long

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<ll>> f(n, vector<ll>(k, 0));
        vector<vector<ll>> s(n, vector<ll>(k, 0));

        ll mod = 1000000007;

        int r = grid[0][0] % k;

        f[0][r] = 1;

        for (int j = 1; j < n; j++) {
            for (int z = 0; z < k; z++) {
                f[j][(z + grid[0][j]) % k] = f[j-1][z];
            }
        }


        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int z = 0; z < k; z++) {
                    int t = (grid[i][j] + z) % k;
                    s[j][t] = (s[j][t] + f[j][z]) % mod;
                    // dp[i][j][t] = (dp[i][j][t] + dp[i-1][j][z]) % mod;
                    // dp[i][j][t] = (dp[i][j][t] + dp[i][j-1][z]) % mod;
                    if (j > 0) {
                        s[j][t] = (s[j][t] + s[j-1][z]) % mod;
                    }
                }
            }

            for (int j = 0; j < n; j++) {
                for (int z = 0; z < k; z++) {
                    f[j][z] = s[j][z];
                    s[j][z]= 0;
                }
            }
        }

        return f[n-1][0];
    }
};