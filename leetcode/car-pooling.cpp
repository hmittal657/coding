// https://leetcode.com/problems/car-pooling

class Solution {
public:

    struct point {
        int x;
        int delta;
    };

    static bool comp(point a, point b) {
        return a.x < b.x;
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<point> v;
        
        for (int i =0; i < trips.size(); i++) {
            if (trips[i][0] > capacity) return false;
            point a;
            a.x = trips[i][1];
            a.delta = trips[i][0];
            v.push_back(a);
            point b;
            b.x = trips[i][2];
            b.delta = -1 * trips[i][0];
            v.push_back(b);
        }

        sort(v.begin(), v.end(), comp);

        int cur = 0;
        int last = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].x == last) {
                cur += v[i].delta;
            } else {
                if (cur > capacity) {
                    return false;
                }
                last = v[i].x;
                cur += v[i].delta;
            }
        }

        return (cur <= capacity);

    }
};