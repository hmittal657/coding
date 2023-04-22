// https://leetcode.com/problems/count-anagrams

class Solution {
public:

    #define ll unsigned long long

    ll mod = 1000000007;

    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }

    ll modInv(ll x, ll y) {
        if(gcd(x,y) != 1) return -1;
        ll a = max(x,y);
        ll b = min(x,y);
        ll t1 = 0;
        ll t2 = 1;

        while (b != 0) {
            ll q = a/b;
            ll r = a%b;

            ll t = t1 - t2*q;

            a = b;
            b = r;

            t1 = t2;
            t2 = t;
        }
        return (t1 + y) % y;
    }

    ll fact(string& cur) {
        vector<ll> c(26, 0);
        ll ans = 1;
        ll total = 0;
        for (int i =0; i < cur.size(); i++) {
            c[cur[i]-'a']++;
            total++;
            ans  = (ans * total);
            ans = ans%mod;
            ans = (ans * modInv(c[cur[i]-'a'], mod));
            ans = ans%mod;
        }
        return (ans % mod);
    }

    int countAnagrams(string s) {

        int n = s.size();

        vector<ll> v;

        string cur = "";

        for (int i =0; i < n; i++) {
            if (s[i] == ' ') {
                v.push_back(fact(cur));
                cur = "";
            } else {
                cur.push_back(s[i]);            
            }
        }
        if (cur.size() > 0) {
            v.push_back(fact(cur));
        }

        ll ans = 1;

        for (int i = 0; i < v.size(); i++) {
            ans = (ans*v[i])%mod;
        }

        return ans;
    }
};