// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference

class Solution {
public:

    int count(int x, int n) {
        int cnt = 0;
        while (x > 0) {
            if (x%2 == 1) {
                cnt++;
            }
            x = x/2;
        }
        return cnt;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;

        int arrsum = 0;
        for (int i =0; i < nums.size(); i++) {
            arrsum += nums[i];
        }

        vector<vector<int>> adj(n+1);
        vector<vector<int>> suf(n+1);

        for (int i =0; i < (1<<n); i++) {
            int k = count(i, n);
            int cursum = 0;
            int sufsum = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    cursum += nums[j];
                    sufsum += nums[n + j];
                }
            }
            adj[k].push_back(cursum);
            suf[k].push_back(sufsum);
        }

        for (int i = 0; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
            sort(suf[i].begin(), suf[i].end());
        }

        int ans = INT_MIN;

        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int presum = adj[i][j];
                vector<int>::iterator  lower;
                lower = lower_bound(suf[n-i].begin(), suf[n-i].end(), (arrsum - 2 * presum)/2);
                if (lower != suf[n-i].end()) {
                    if (ans == INT_MIN) {
                        ans = abs((arrsum - presum - (*lower)) - (presum  + (*lower)));
                    } else {
                        ans = min(ans, abs((arrsum - presum - (*lower)) - (presum  + (*lower))));
                    }
                }
            }
        }

        return ans;

    }
};