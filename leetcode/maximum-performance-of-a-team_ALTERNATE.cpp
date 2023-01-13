// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    
#define ll long long

    struct Eng {
        ll s;
        ll e;
    };

    static bool comp(Eng a, Eng b) {
        return a.e > b.e;
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

        sort(v1.begin(), v1.end(), comp);

        priority_queue<ll, vector<ll>, greater<ll>> pq;

        ll minE;

        ll curSum = 0;

        ll maxi = (v1[0].e * v1[0].s);

        for (int i = 0; i < k-1; i++) {
            minE = v1[i].e;
            curSum += v1[i].s;
            maxi = max(maxi, minE * (curSum));
            pq.push(v1[i].s);
        }

        for (int i = k-1; i < n; i++) {
            maxi = max((curSum + v1[i].s) * v1[i].e, maxi);
            curSum += v1[i].s;
            pq.push(v1[i].s);
            if (pq.size() > k-1) {
                curSum -= pq.top();
                pq.pop();
            }
        }

        return maxi % MOD;

    }
};