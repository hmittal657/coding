// https://leetcode.com/problems/dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1,q2;
        int n = senate.size();
        for (int i =0; i < n; i++) {
            if (senate[i] == 'R') {
                q1.push(i);
            } else {
                q2.push(i);
            }
        }

        while (!q1.empty() && !q2.empty()) {
            int x = q1.front();
            int y = q2.front();
            q1.pop();
            q2.pop();
            if (x < y) {
                q1.push(x + n);
            } else {
                q2.push(y + n);
            }
        }

        if (q1.size() > q2.size()) {
            return "Radiant";
        } else {
            return "Dire";
        }

    }
};