// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:

    static bool comp(vector<int> a, vector<int> b) {
        int x1 = a[0];
        int y1 = a[1];
        int dist1 = (x1*x1) + (y1*y1);

        int x2 = b[0];
        int y2 = b[1];
        int dist2 = (x2*x2) + (y2*y2);

        return dist1 < dist2;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }

        return ans;
    }
};

