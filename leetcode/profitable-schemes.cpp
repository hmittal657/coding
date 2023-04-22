// https://leetcode.com/problems/profitable-schemes/

class Solution {
public:

    #define ll long long

    ll mod = 1000000007;

    ll dp[101][101][101];

    ll fun(int i, int remProfit, int remPeople, vector<int>& group, vector<int>& profit) {
      if (remPeople < 0) return 0;
      if (i-1 == profit.size()) {
          if (remProfit <= 0) return 1;
          return 0;
      }

      if (dp[i][remPeople][max(remProfit, 0)] != -1) {
        return dp[i][remPeople][max(remProfit, 0)];
      }

      ll a = 0,c=0;
      
      a = fun(i+1, max(0, remProfit - profit[i-1]), remPeople - group[i-1], group, profit);      
      c = fun(i+1, remProfit, remPeople, group, profit);
      ll ans = 0;
      ans = (ans+a) % mod;
      ans = (ans + c) % mod;

      dp[i][remPeople][max(remProfit, 0)] = ans;

      return ans;
    }
    

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
      for (int i = 0; i <= group.size(); i++) {
        for (int j = 0; j <= n; j++) {
          for (int k = 0; k <= minProfit; k++) {
            dp[i][j][k] = -1;
          }
        }
      }

      return fun(1, minProfit, n, group, profit);
    }
};