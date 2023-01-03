// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for (int i =0; i < tasks.size(); i++) {
            m[tasks[i]]+=1;
        }

        int ans = 0;

        for (auto& it : m) {
            int t = it.second;
            if (t < 2) return -1;
            if (t == 2 || t == 3) {
                ans++;
            } else {
                int r = t%3;
                if (r == 0) {
                    ans += (t/3);
                } else if (r == 1) {
                    ans += 2;
                    ans += ((t/3) - 1);
                } else if (r == 2) {
                    ans += (t/3);
                    ans++;
                }
            }
        }

        return ans;
    }
};