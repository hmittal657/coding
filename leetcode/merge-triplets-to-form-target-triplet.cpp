// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& target) {
        
        int discarded = 0;
        int max0 = 0, max1=0, max2= 0;

        for (int i = 0; i < t.size(); i++) {
            if (target[0] == t[i][0] && target[1] == t[i][1] && target[2] == t[i][2]) return true;

            if (t[i][0] > target[0]) {
                discarded++;
                continue;
            }
            if (t[i][1] > target[1]) {
                discarded++;
                continue;
            }
            if (t[i][2] > target[2]) {
                discarded++;
                continue;
            }

            max0 = max(max0, t[i][0]);
            max1 = max(max1, t[i][1]);
            max2 = max(max2, t[i][2]);
        }

        

        if (discarded == t.size()) return false;

        if (max0 == target[0] && max1 == target[1] && max2 == target[2]) return true;
        return false;

    }
};