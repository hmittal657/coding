// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        vector<int> lpt(nums2.size(),0);
        
        lpt[n-1] = -1;

        for (int i = n-2; i >= 0; i--) {
            int x = i+1;
            while (true) {
                if (x == -1) {
                    break;
                }
                if (nums2[x] > nums2[i]) {
                    break;
                }
                x = lpt[x];
            }
            lpt[i] = x;
        }

        for (int i = 0; i < n; i++) {
            if (lpt[i] == -1) continue;
            lpt[i] = nums2[lpt[i]];
        }

        unordered_map<int, int> m;
        for (int i =0; i < n; i++) {
            m[nums2[i]] = i;
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(lpt[m[nums1[i]]]);
        }

        return ans;

    }
};