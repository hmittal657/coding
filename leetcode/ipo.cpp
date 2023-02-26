// https://leetcode.com/problems/ipo

class Solution {
public:

    struct S {
        int c;
        int p;
    };

    static bool comp(S& a, S& b) {
        if (a.c != b.c) {
            return a.c < b.c;
        }
        return a.p > b.p;
    }

    class Comp2 {

        public:
        bool operator()(S& a, S& b) {
            if (a.p != b.p) {
                return a.p < b.p;
            }
            return a.c > b.c;
        }

    };

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans = w;
        int n = profits.size();
        vector<S> v;

        for (int i = 0; i < n; i++) {
            v.push_back({capital[i], profits[i]});
        }

        sort(v.begin(), v.end(), comp);

        int l = 0;

        priority_queue<S, vector<S>, Comp2> q;

        while (k > 0) {
            while (l < n) {
                if (v[l].c <= ans) {
                    q.push(v[l]);
                    l++;
                } else {
                    break;
                }
            }

            if (q.empty()) break;

            S cur = q.top();
            ans += cur.p;
            q.pop();
            k--;
        }

        return ans;

    }
};