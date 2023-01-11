// https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> m;
        unordered_map<string, int> visited;
        for (int i =0; i  < deadends.size(); i++) {
            m[deadends[i]] = 1;
        }

        if (m.find(target) != m.end()) return -1;
        if (m.find("0000") != m.end()) return -1;
        
        queue<pair<string, int>> q;
        visited["0000"] = 1;

        q.push({"0000", 0});

        while (!q.empty()) {
            pair<string, int> cur = q.front();
            q.pop();
            if (cur.first == target) {
                return cur.second;
            }

            string temp = cur.first;

            for (int i =0; i < 4; i++) {
                int t = temp[i]-'0';
                temp[i] = (char)((t+1)%10 + '0');
                if (visited.find(temp) == visited.end() && m.find(temp) == m.end())  {
                    visited[temp] = 1;
                    q.push({temp, cur.second+1});
                }
                temp[i] = (char)((t + 9) % 10 + '0');
                if (visited.find(temp) == visited.end() && m.find(temp) == m.end())  {
                    visited[temp] = 1;
                    q.push({temp, cur.second+1});
                }
                temp[i] = (char)(t + '0');
            }
        }

        return -1;

    }
};