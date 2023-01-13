// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
        vector<int>& newInterval) {
        
        int n = intervals.size();
        vector<vector<int>> ans;
        if (n == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        if (newInterval[1] < intervals[0][0]) {
            ans.push_back(newInterval);
            for (int i = 0 ; i < n ; i++) {
                ans.push_back(intervals[i]);
            }
            return ans;
        } else if ( newInterval[0] > intervals[n-1][1]) {
            for (int i = 0 ; i < n ; i++) {
                ans.push_back(intervals[i]);
            }
            ans.push_back(newInterval);
            return ans;
        } 

        bool newAdded = false;
        for (int i = 0; i < n ; i++) {
            if (!newAdded) {
                if (newInterval[0] > intervals[i][1]) {
                    ans.push_back(intervals[i]);
                } else if (newInterval[0] > intervals[i][0]) {
                    ans.push_back(intervals[i]);
                    ans.push_back(newInterval);
                    newAdded = true;
                } else if (newInterval[0] == intervals[i][0]) {
                    if (newInterval[1] > intervals[i][1]) {
                        ans.push_back(intervals[i]);
                        ans.push_back(newInterval);
                        newAdded = true;
                    } else {
                        ans.push_back(newInterval);
                        ans.push_back(intervals[i]);
                        newAdded = true;
                    }
                } else if (newInterval[0] < intervals[i][0]) {
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    newAdded = true;
                }
            } else {
                ans.push_back(intervals[i]);
            }
        }

        vector<vector<int>> temp;

        vector<int> cur;
        cur.push_back(ans[0][0]);
        cur.push_back(ans[0][1]);

        for (int i = 1; i < ans.size(); i++) {
            if (ans[i][0] > cur[1]) {
                temp.push_back(cur);
                cur = ans[i];
            } else {
                cur[1] = max(ans[i][1], cur[1]);
            }
        }
        temp.push_back(cur);
        return temp;

    }
};