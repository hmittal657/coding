// https://leetcode.com/problems/single-threaded-cpu/

class Solution {

#define ll long long

public:

    struct Task {
        int index;
        ll enqTime;
        ll procTime;
    };

    class Comp {
        public: 
        bool operator()(Task* a, Task* b) {
            if (a->procTime != b->procTime) {
                return (a->procTime) > (b->procTime);
            } else {
                return (a->index) > (b->index);
            }
        }
    };

    static bool comp(Task* a, Task* b) {
        return ((a->enqTime) < (b->enqTime));
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {

        ll n = tasks.size();

        priority_queue<Task*, vector<Task*>, Comp> pq;
        
        vector<Task*> v;

        for (ll i =0; i < n; i++) {
            Task* t = new Task();
            t->index = i;
            t->enqTime = (ll)tasks[i][0];
            t->procTime = (ll)(tasks[i][1]);
            v.push_back(t);
        }

        sort(v.begin(), v.end(), comp);

        vector<int> ans;

        ll curTime = 0;

        int ind = 0;

        while (ans.size() < n) {

            int temp = 0;
            for (int i = ind; i < n; i++) {
                if ((v[i]->enqTime) <= curTime) {
                    pq.push(v[i]);
                    temp++;
                } else {
                    break;
                }
            }

            ind += temp;

            if (pq.empty()) {
                curTime = v[ind]->enqTime;
            } else {
                Task* cur = pq.top();
                pq.pop();
                ans.push_back(cur->index);
                curTime += (cur->procTime);
            }

        }
        
        return ans;

    }
};