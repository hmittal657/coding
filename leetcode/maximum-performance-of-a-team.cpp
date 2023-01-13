// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    
#define ll long long

    struct Eng {
        ll s;
        ll e;
        int ind;
    };

    static bool comp(Eng a, Eng b) {
        return a.e < b.e;
    }

    static bool comp2(Eng a, Eng b) {
        return a.s < b.s;
    }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        ll MOD = 1000000007L;

        vector<Eng> v1;

        for (int i=0; i < n; i++) {
            Eng x;
            x.s = (ll)(speed[i]);
            x.e = (ll)(efficiency[i]);
            v1.push_back(x);
        }

        sort(v1.begin(), v1.end(), comp2);

        vector<Eng> v2;

        for (int i =0; i < v1.size(); i++) {
            v1[i].ind = i;
            v2.push_back(v1[i]);
        }

        ll ksum = 0;
        int last = n-k;
        for (int i = 0; i < k-1; i++) {
            ksum += v1[n-1-i].s;
        }

        sort(v2.begin(), v2.end(), comp);

        ll maxi = (ll)(speed[0])*(ll)(efficiency[0]);

        vector<bool> used(n, false);

        for (int i =0; i < v2.size(); i++) {
            int index = v2[i].ind;
            used[index] = true;
            if (index > last) {
                ksum -= v2[i].s;
                while (last >= 0 && used[last]) {
                    last--;
                }
                if (last >= 0) {
                    ksum += v1[last].s;
                }
                last--;
            }
            maxi = max(maxi, (ksum + v2[i].s)*v2[i].e);
        }

        return maxi % MOD;

    }
};