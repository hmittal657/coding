// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:

    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n < 2) return n;

        sort(intervals.begin(), intervals.end(), comp);

        // case1 
        // [     ]
        //   [ ]
        // case 2 
        // [      ]
        //   [    ]

        // case 3

        // [      ]
        // [            ]

        // case 4
        //  [         ]
        //       [           ]

        // case 5
        //  [         ]
        //                [       ]

        int rem = 0;

        vector<int> cur = intervals[0];

        for (int i =1 ; i < n; i++) {
            int x1 = cur[0];
            int y1 = cur[1];

            int x2 = intervals[i][0];
            int y2 = intervals[i][1];

            if (y1 >= y2) {
                rem++;
            } else if (x1 == x2 && y2 > y1) {
                rem++;
                cur = intervals[i];
            } else {
                cur = intervals[i];
            }

        }

        return (n-rem);
    }
};