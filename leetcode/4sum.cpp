// https://leetcode.com/problems/4sum/

class Solution {
public:

#define ll long long

    vector<vector<int>> solve(vector<int>& nums, int l, ll t) {

        int n = nums.size();
        int low = l;
        int high = n-1;
        vector<vector<int>> ans;
        while (low < high) {
            ll cur = (ll)(nums[low]) + (ll)(nums[high]);
            if (cur == t) {
                vector<int> t;
                t.push_back(nums[low]);
                t.push_back(nums[high]);
                ans.push_back(t);
                int temp = nums[low];
                while (low < high && nums[low] == temp) {
                    low++;
                }
            } else if (cur > t) {
                high--;
            } else {
                low++;
            }
        }

        return ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if (n < 4) {
            return vector<vector<int>>(0);
        }

        unordered_set<ll> s;
        vector<vector<int>> ans;
        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n - 2; j++) {
                ll hash = ((ll)(nums[i]) + 1000000000L) * 2000000001L + ((ll)(nums[j]) + 1000000000L);
                if (s.find(hash) != s.end()) continue;
                s.insert(hash);
                ll t = (ll)target - (ll)nums[i] - (ll)nums[j];
                vector<vector<int>> v = solve(nums, j+1, t);
                if (v.size() == 0) {
                    continue;
                } else {
                    for (int k = 0; k < v.size(); k++) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(v[k][0]);
                        temp.push_back(v[k][1]);
                        ans.push_back(temp);
                    }
                }
            }
        }

        return ans;
    }
};