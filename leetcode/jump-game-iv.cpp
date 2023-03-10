// https://leetcode.com/problems/jump-game-iv/

class Solution {
public:

    int minJumps(vector<int>& arr) {
        
        unordered_map<int, vector<int>> m;

        for (int i =0; i < arr.size(); i++) {
            m[arr[i]].push_back(i);
        }

        int n = arr.size();

        vector<int> dp(n, -1);
        
        queue<pair<int, int>> q;

        q.push({0, 0});
        dp[0] = 0;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first ==  n-1) {
                return cur.second;
            }
            int i = cur.first;

            if (i+1 >= 0 && dp[i+1] == -1) {
                q.push({i+1, cur.second+1});
                dp[i+1] = cur.second+1;
            }

            if (i-1 >= 0 && dp[i-1] == -1) {
                q.push({i-1, cur.second+1});
                dp[i-1] = cur.second+1;
            }

            for (int k = 0; k < m[arr[i]].size(); k++) {
                if (dp[m[arr[i]][k]] == -1 && m[arr[i]][k] != i) {
                    q.push({m[arr[i]][k], cur.second + 1});
                    dp[m[arr[i]][k]] = cur.second+1;
                }
            }

            m.erase(arr[i]);
        }

        return dp[n-1];

    }
};