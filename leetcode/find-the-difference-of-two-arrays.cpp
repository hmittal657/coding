// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for (int i =0; i < nums1.size(); i++) {
            m1[nums1[i]] = 1;
        }

        for (int i =0 ; i < nums2.size(); i++) {
            m2[nums2[i]] = 1;
        }

        vector<vector<int>> ans(2);

        for (auto& it : m1) {
            if (m2.find(it.first) == m2.end()) {
                ans[0].push_back(it.first);
            }
        }

        for (auto& it : m2) {
            if (m1.find(it.first) == m1.end()) {
                ans[1].push_back(it.first);
            }
        }

        return ans;
    }
};