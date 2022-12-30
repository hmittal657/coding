// https://leetcode.com/problems/process-tasks-using-servers/

class Solution {

#define ll long long

public:

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, 
        greater<pair<ll, ll>>> free;

        priority_queue<pair<ll,ll>, vector<pair<ll, ll>>,
        greater<pair<ll, ll>>> busy;

        for (ll i =0; i < (ll)(servers.size()); i++) {
            free.push(make_pair(servers[i], i));
        }

        ll time = 0;
        vector<int> ans;

        for (ll i =0; i < (ll)(tasks.size()); i++) {
            time = max(i, time);
            if (free.empty()) {
                pair<ll, ll> temp = busy.top();
                time = max(temp.first, time);
            }

            while (true) {
                if (busy.empty()) break;
                pair<ll, ll> temp = busy.top();
                if (temp.first <= time) {
                    free.push(make_pair(servers[temp.second], temp.second));
                    busy.pop();
                } else {
                    break;
                }
            }

            pair<ll, ll> cur = free.top();
            ans.push_back((int)cur.second);
            free.pop();
            busy.push(make_pair(time + tasks[i], cur.second));

        }

        return ans;

    }
};