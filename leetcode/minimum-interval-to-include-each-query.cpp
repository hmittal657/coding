// https://leetcode.com/problems/minimum-interval-to-include-each-query

class Solution {
public:

    class Comp {
        public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second > b.second;
        }
    };

    vector<int> minInterval(vector<vector<int>>& intervals,
        vector<int>& queries) {

        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());

        vector<int> Q = queries;
        vector<int> ans = queries;

        sort(Q.begin(), Q.end());

        unordered_map<int, int> m;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

        int ind = 0;

        for (int i = 0; i < Q.size(); i++) {
            while (ind < n) {
                if (intervals[ind][0] <= Q[i]) {
                    pq.push({intervals[ind][1] - intervals[ind][0] + 1, intervals[ind][1]});
                    ind++;
                } else {
                    break;
                }
            }

            while (pq.size() > 0) {
                pair<int, int> cur = pq.top();
                if (cur.second < Q[i]) {
                    pq.pop();
                } else {
                    break;
                }
            }

            if (pq.size() > 0) {
                pair<int, int> cur = pq.top();
                m[Q[i]] = cur.first;
            } else {
                m[Q[i]] = -1;
            }

        }

        for (int i =0; i < queries.size(); i++) {
            ans[i] = m[queries[i]];
        }

        return ans;

    }
};