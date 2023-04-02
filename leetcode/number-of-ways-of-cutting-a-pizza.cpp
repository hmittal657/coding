// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

class Solution {
public:

    #define ll long long

    ll MOD = 1000000007LL;

    ll dp[51][51][11];

    ll count[51][51];

    int m,n;

    ll fun(int i, int j, int k) {

        if (dp[i][j][k] != -1) return dp[i][j][k];

        if (k == 1) {
            if (count[i][j] > 0) {
                dp[i][j][k] = 1;
            } else {
                dp[i][j][k] = 0;
            }
            return dp[i][j][k];
        }

        ll a = count[i][j];

        ll ans = 0LL;

        for (int x = i+1; x < m; x++) {
            ll b = count[x][j];
            if (a - b > 0) {
                ans += fun(x, j, k-1);
                ans = ans % MOD;
            }
        }

        for (int y = j+1; y < n; y++) {
            ll b = count[i][y];
            if (a - b > 0) {
                ans += fun(i, y, k-1);
                ans = ans % MOD;
            }
        }

        
        dp[i][j][k] = ans;
        return ans;

    }

    int ways(vector<string>& pizza, int k) {
        
        m = pizza.size();
        n = pizza[0].size();
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) {
                    if (pizza[i][j] == 'A') {
                        count[i][j] = 1;
                    } else {
                        count[i][j] = 0;
                    }
                } else if (i == m-1) {
                    if (pizza[i][j] == 'A') {
                        count[i][j] = 1;
                    } else {
                        count[i][j] = 0;
                    }
                    count[i][j] += count[i][j+1];
                } else if (j == n-1) {
                    if (pizza[i][j] == 'A') {
                        count[i][j] = 1;
                    } else {
                        count[i][j] = 0;
                    }
                    count[i][j] += count[i+1][j];
                } else {
                    if (pizza[i][j] == 'A') {
                        count[i][j] = 1;
                    } else {
                        count[i][j] = 0;
                    }
                    count[i][j] += count[i+1][j];
                    count[i][j] += count[i][j+1];
                    count[i][j] -= count[i+1][j+1];
                }
            }
        }

        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int z =0; z <= k; z++) {
                    dp[i][j][z] = -1;
                }
            }
        }

        return fun(0, 0, k);

    }
};