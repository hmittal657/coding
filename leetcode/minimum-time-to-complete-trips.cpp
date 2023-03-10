// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
public:

#define ll long long

    bool possible(vector<int>& time, ll totalTrips, ll m) {

        ll trips = 0;

        for (int i = 0; i < time.size(); i++) {
            trips += (m/(ll)(time[i]));
            if (trips >= totalTrips) return true;
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1;
        ll h = 10000000000000L;

        ll mintime = time[0];

        for (int i = 1; i < time.size(); i++) {
            mintime = min(mintime, (ll)(time[i]));
        }

        h = mintime * (ll)totalTrips;
        ll res = h;

        while (l <= h) {
            ll m = (l+h)/2;
            if (possible(time, (ll)(totalTrips), m)) {
                res = min(res, m);
                h = m-1;
            } else {
                l = m+1;
            }
        }

        return res;

    }
};