// https://leetcode.com/problems/permutations-ii/

class Solution {
public:

    int arr[21];

    void travel(vector<int>& cur, vector<vector<int>>& ans, int n) {
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < 21; i++) {
            if (arr[i] > 0) {
                cur.push_back(i-10);
                arr[i]--;
                travel(cur, ans, n);
                arr[i]++;
                cur.pop_back();
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < 21; i++) {
            arr[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            arr[nums[i] + 10]++;
        }

        vector<int> cur;

        travel(cur, ans, n);

        return ans;

    }
};