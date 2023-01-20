// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ind(n+1, 0);
        vector<int> out(n+1, 0);

        for (int i =0; i < trust.size(); i++) {
            ind[trust[i][1]]++;
            out[trust[i][0]]++;
        }

        int judge = -1;

        for (int i = 1; i <= n; i++) {
            if (ind[i] == n-1 && out[i] == 0) {
                if (judge != -1) return -1;
                judge = i;
            }
        }

        return judge;
    }
};