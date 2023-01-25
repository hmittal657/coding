// https://leetcode.com/problems/best-team-with-no-conflicts

class Solution {
public:

    struct Player {
        int score;
        int age;
    };

    int fun(int prev, int i, vector<Player>& v, vector<vector<int>>& dp) {
        if (i == v.size()) return 0;
        if (dp[prev+1][i] != -1) return dp[prev+1][i];

        dp[prev+1][i] = fun(prev, i+1, v, dp);

        if (prev == -1 || v[i].score >= v[prev].score) {
            dp[prev+1][i] = max(v[i].score + fun(i, i+1, v, dp), 
                dp[prev+1][i]);
        }

        return dp[prev+1][i];

    }

    static bool comp(Player& a, Player& b) {
        if (a.age != b.age) {
            return a.age < b.age;
        }
        return a.score < b.score;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<Player> v(n);
        
        for (int i =0; i < n; i++) {
            v[i] = {scores[i], ages[i]};
        }

        sort(v.begin(), v.end(), comp);
        
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return fun(-1, 0, v, dp);
    }
};