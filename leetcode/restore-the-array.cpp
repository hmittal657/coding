// https://leetcode.com/problems/restore-the-array/

class Solution {
public:

    #define ll long long

    ll nums[100005];
    int n;

    ll dp[100005];

    ll mod = 1000000007;

    ll fun(int i, ll k) {
        
        if (i == n) return 1;

        if (nums[i] == 0) return 0;
        
        if (dp[i] != -1) return dp[i];

        ll cur = 0;

        ll ans = 0;

        int ind = i;

        while (ind < n) {
            cur = cur*10 + nums[ind];
            if (cur > k) break;
            ans  = (ans + fun(ind+1, k)) % mod;
            ind++;
        }

        dp[i] = ans;

        return dp[i];

    }

    int numberOfArrays(string s, int kal) {
        
        for (int i =0; i < s.size(); i++) {
            nums[i] = (ll)(s[i] - '0');  
            dp[i] = -1;    
        }
        ll k = kal;
        n = s.size();
        cout << n << endl;
        dp[n] = -1;

        return fun(0, k);

    
    }
};