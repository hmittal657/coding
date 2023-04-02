// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        unordered_map<int, int> m;
        
        for (int i=0; i < nums.size(); i++) {
            m[nums[i]]++;
            if (ans.size() < m[nums[i]]) {
                vector<int> t;
                t.push_back(nums[i]);
                ans.push_back(t);
            } else {
                ans[m[nums[i]]-1].push_back(nums[i]);
            }
        }
        
        return ans;
        
    }
};