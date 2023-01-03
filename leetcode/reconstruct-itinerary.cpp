// https://leetcode.com/problems/reconstruct-itinerary

// Learning https://stackoverflow.com/a/41488178

class Solution {
public:

    struct ticket {
        int index;
        string dest;
        bool used = false;
    };

    static bool comp (ticket a, ticket b) {
        string u = a.dest;
        string v = b.dest;
        for (int  i =0; i < 3; i++) {
            int x = u[i] - 'A';
            int y = v[i] - 'A';
            if (x != y) {
                return (x < y);
            }
        }
        return a.index < b.index;
    }

    bool solved = false;

    void dfs(string s, unordered_map<string, vector<ticket>>& adj, int total, vector<string> &cur) {
        if (solved) return;
        cur.push_back(s);
        if (cur.size() == total + 1) {
            solved = true;
            return;
        }

        for (int i = 0; i < adj[s].size(); i++) {
            
            ticket x = adj[s][i];
            if (x.used == true) {
                continue;
            }
            x.used = true;
            adj[s][i] = x;
            dfs(x.dest, adj, total, cur);
            x.used = false;
            adj[s][i] = x;
            if (solved) return;
        }
        if (solved) return;
        cur.pop_back();
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<ticket>> adj;
        solved = false;
        for (int i = 0; i < tickets.size(); i++) {
            ticket x;
            x.dest = tickets[i][1];
            x.index = i;
            x.used = false;
            adj[tickets[i][0]].push_back(x);
        }

        for (auto it : adj) {
            
            vector<ticket> t = it.second;
            if (t.size() != 0) {
                sort(t.begin(), t.end(), comp);
                adj[it.first] = t;
            }
        }
        int total = tickets.size();

        vector<string> cur;

        dfs("JFK", adj, total, cur);

        return cur;

    }
};