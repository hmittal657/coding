// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:

    #define ll long long

    ll dp[100003][2];

    ll fun(int i, int p, vector<vector<int>>& q) {
        if (i >= q.size()) return 0;

        if (dp[i][p] != -1) return dp[i][p];

        ll n = q.size();

        ll val = q[i][0];
        ll gap = q[i][1];

        if (p == 1) {
            ll ans = val;
            if ((ll)(i+1) + gap < n) {
                ll z = max(fun(i + 1 + (int)(gap), 0, q), fun(i + 1 + (int)(gap), 1, q));
                ans = ans + z;
            }
            dp[i][p] = ans;
            return ans;
        } else {
            ll ans = 0;
            ll z = max(fun(i+1, 1, q), fun(i+1, 0, q));
            ans = ans + z;
            dp[i][p] = ans;
            return ans;
        }

    }

    long long mostPoints(vector<vector<int>>& questions) {
        for (int i =0; i < questions.size(); i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }

        return max(fun(0, 0, questions), fun(0, 1, questions));
    }
};