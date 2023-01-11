// https://leetcode.com/problems/132-pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        vector<pair<int, int>> v;

        for (int i =0; i < nums.size(); i++) {
            if (v.size() == 0) {
                v.push_back({i, -1});
            } else {
                pair<int, int> temp = {-1, -1};
                for (int k = 0; k < v.size(); k++) {
                    if (v[k].first != -1 && v[k].second != -1) {
                        if (nums[i] > nums[v[k].first] && nums[i] < nums[v[k].second]) {
                            return true;
                        }
                        if (nums[i] < nums[v[k].first]) {
                            temp = {i, -1};
                        } else if (nums[i] > nums[v[k].second]) {
                            v[k].second = i;
                            break;
                        }
                    } else {
                        if (nums[v[k].first] < nums[i]) {
                            v[k].second = i;
                            break;
                        } else {
                            v[k].first = i;
                            break;
                        }
                    }
                }
                if (temp.first != -1) {
                    v.push_back(temp);
                }
            }
        }

        return false;

    }
};