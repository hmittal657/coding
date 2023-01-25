// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:

    #define ll long long

    int ans = -1;

    void dfs(int i, ll side1, ll side2, ll side3, ll side4, 
        vector<int>& matchsticks) {
        if (ans != -1) return;
        
        if (i == matchsticks.size() && side1 == 0 && side2 == 0 && side3 == 0
            && side4 == 0) {
            ans = 1;
            return;
        } else if (i == matchsticks.size()) {
            return;
        }

        ll cur = (ll)(matchsticks[i]);

        if (cur <= side1) {
            dfs(i+1, side1-cur, side2, side3, side4, matchsticks);
        }

        if (cur <= side2) {
            dfs(i+1, side1, side2-cur, side3, side4, matchsticks);
        }

        if (cur <= side3) {
            dfs(i+1, side1, side2, side3-cur, side4, matchsticks);
        }

        if (cur <= side4) {
            dfs(i+1, side1, side2, side3, side4-cur, matchsticks);
        }
    }

    static bool comp(int a, int b) {
        return a > b;
    }

    bool makesquare(vector<int>& matchsticks) {
        ll total = 0;
        if (matchsticks.size() < 4) return false;
        for (int i = 0; i < matchsticks.size(); i++) {
            total += (ll)(matchsticks[i]);
        }

        if (total % 4 != 0) return false;
        ans = -1;
        ll side = total/4;
        sort(matchsticks.begin(), matchsticks.end(), comp);
        dfs(0, side, side, side, side, matchsticks);

        return (ans == 1);
    }
};