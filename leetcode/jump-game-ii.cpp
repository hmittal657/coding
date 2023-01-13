// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        
        vector<bool> reached(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});

        reached[0] = true;

        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            int jumps = cur.first;
            int ind = cur.second;
            if (ind == n-1) return jumps;

            for (int i = ind + 1; i <= min(ind+nums[ind], n-1) ; i++) {
                if (!reached[i]) {
                    reached[i] = true;
                    pq.push({jumps+1, i});
                }
            }
        }

        return -1;

    }
};