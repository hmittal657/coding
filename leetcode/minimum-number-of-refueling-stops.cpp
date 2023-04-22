// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:

    #define ll long long

    class Comp {
        public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first > b.first;
            }
        }
    };

    int minRefuelStops(int t, int s, vector<vector<int>>& stations) {
        
        ll startFuel = s;

        ll target = t;


        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

        int ind = 0;

        ll maxStop = startFuel;

        int stops = 0;

        int n = stations.size();

        while (maxStop < target) {

            while (ind < n) {
                if (stations[ind][0] <= maxStop) {
                    pq.push({stations[ind][0], stations[ind][1]});
                    ind++;
                } else {
                    break;
                }
            }

            if (pq.size() > 0) {
                pair<int, int> cur = pq.top();
                maxStop += (ll)(cur.second);
                pq.pop();
                stops++;
            } else {
                return -1;
            }
        }

        return stops;

    }
};