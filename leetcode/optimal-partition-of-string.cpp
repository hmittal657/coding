// https://leetcode.com/problems/optimal-partition-of-string

class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        
        int dp[n];

        for (int i =0; i < n; i++) {
            dp[i] = 0;
        }


        for (int i = 0; i < n; i++) {
            
            int ind = s[i] - 'a';

            unordered_map<int, int> m;

            m[ind] = 1;

            int z = i+1;

            bool breaks = false;

            for (int k = i-1; k >= 0; k--) {
                int x = s[k] - 'a';
                if (m.find(x) != m.end()) {
                    z = min(z, dp[k] + 1);
                    breaks = true;
                    break;
                }
                m[x] = 1;
                z = min(z, dp[k] + 1);
            }

            if (!breaks) {
                z = min(z, 1);
            }

            dp[i] = z;

        }

        return dp[n-1];
    }
};