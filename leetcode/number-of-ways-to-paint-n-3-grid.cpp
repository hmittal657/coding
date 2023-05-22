// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:

    #define ll long long

    ll mod = 1000000007;

    int numOfWays(int n) {
        
        ll prev[3][3][3];
        ll cur[3][3][3];

        for (int i =0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i == j || j == k) {
                        cur[i][j][k] = 0;
                    } else {
                        cur[i][j][k] = 1;
                    }
                }
            }
        }

        for (int i =0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    prev[i][j][k] = cur[i][j][k];
                    cur[i][j][k] = 0;
                }
            }
        }

        for (int cnt = 2; cnt <= n; cnt++) {
            for (int i =0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;
                    for (int k = 0; k < 3; k++) {
                        if (k == j) continue;
                       for (int l = 0; l < 3; l++) {
                           if (l == i) continue;
                           for (int m = 0; m < 3; m++) {
                               if (m == l || m == j) continue;
                               for (int nn = 0; nn < 3; nn++) {
                                   if (nn == m || nn == k) continue;
                                  
                                   cur[l][m][nn] = (cur[l][m][nn] + prev[i][j][k]) % mod;
                               }
                           }
                       }
                    }
                }
            }

            for (int i =0; i < 3; i++) {
                for (int j = 0; j  < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        prev[i][j][k] = cur[i][j][k];
                        cur[i][j][k] = 0;
                    }
                }
            }
        }

        ll ans = 0;

        for (int i=0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    ans = (ans + prev[i][j][k]) % mod;
                }
            }
        }

        return ans;
    }
};