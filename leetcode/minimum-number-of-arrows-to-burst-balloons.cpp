// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int curx = -1;
        int cury = -1;

        int ans = 0;

        for (int i = 0; i < points.size(); i++) {
            if (curx == -1 && cury == -1) {
                curx = points[i][0];
                cury  = points[i][1];
                ans++;
            } else {
                int x = points[i][0];
                int y = points[i][1];
                if (x > cury) {
                    ans++;
                    curx = x;
                    cury = y;
                } else {
                    curx = max(x, curx);
                    cury = min(y, cury);
                }
            }
        }

        return ans;

    }
};