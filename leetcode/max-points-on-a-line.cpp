class Solution {
public:

// https://leetcode.com/problems/max-points-on-a-line

#define ll long long

    int gcd(int a, int b) {
        if (b == 0) return a;
        if (a == 0) return b;
        int q = a/b;
        int r = a%b;
        return gcd(b, r);
    }

    vector<int> getslope(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            vector<int> t;
            t.push_back(0);
            return t;
        }

        if (a[1] == b[1]) {
            vector<int> t;
            t.push_back(55);
            return t;
        }

        int num = b[1] - a[1];
        int denom = b[0] - a[0];

        int g = gcd(abs(num), abs(denom));

        num = num/g;
        denom = denom/g;

        if (num < 0 && denom < 0) {
            vector<int> t;
            t.push_back(1);
            t.push_back(abs(num));
            t.push_back(abs(denom));
            return t;
        } else if (num < 0 || denom < 0) {
            vector<int> t;
            t.push_back(2);
            t.push_back(abs(num));
            t.push_back(abs(denom));
            return t;
        } else {
            vector<int> t;
            t.push_back(1);
            t.push_back(abs(num));
            t.push_back(abs(denom));
            return t;
        }
    }

    ll gethash(vector<int> slope) {
        ll hash = 0;
        for (ll i = (ll)(slope.size())-1L; i >= 0L; i--) {
            hash += (pow(10001, i) * (ll)(slope[i]));
        }
        return hash;
    }

    int maxPoints(vector<vector<int>>& points) {
       int n = points.size();
       if (n < 3) return n;
        int ans = 2;
        unordered_map<ll, int> m;
        for (int i=0; i < points.size(); i++) {
            for (int j = i+1 ; j < n; j++) {
                vector<int> slope = getslope(points[i], points[j]);
                ll hash = gethash(slope);
                cout << i << " " << j << " " << hash << endl;
                m[hash]++;
                if (m[hash] + 1 > ans) {
                    ans = m[hash] + 1;
                }                
            }
            m.clear();
        }
        return ans;
    }
};