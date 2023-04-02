// https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mina = nums1[0];
        int minb = nums2[0];
        
        set<int> n1;
        set<int> n2;
        
        
        
        for (int i = 0; i < nums1.size(); i++) {
            n1.insert(nums1[i]);
            mina = min(mina, nums1[i]);
            
        }
        int singfind = 10;
        for (int i =0; i < nums2.size(); i++) {
            if (n1.find(nums2[i]) != n1.end()) {
                singfind = min(nums2[i], singfind);
            }
            minb = min(minb, nums2[i]);
        }
        if (singfind < 10) return singfind;
        
        return min(10*mina + minb, 10*minb + mina);
        
    }
};